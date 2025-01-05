#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gstrategoboard.h"
#include <string>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_controller ( new GStrategoBoard())
{

    ui->setupUi(this);
    isBlue = true;
    setGeometry(0, 0, 620, 670);
    ui->verticalLayout->addWidget(m_controller);
    m_controller->visiblePlayerColor(BLUE);
    connect(m_controller,
            SIGNAL(send_positions(std::pair<int, int>, std::pair<int, int>)),
            this,
            SLOT(on_board_signal(std::pair<int, int>, std::pair<int, int>))
            );
    game = new Game();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_board_signal(std::pair<int, int> source,
                                 std::pair<int, int> destination)
{
    auto text = QStringLiteral("Drag and drop. %1,%2 to %3,%4")
            .arg(source.first)
            .arg(source.second)
            .arg(destination.first)
            .arg(destination.second);
    ui->label->setText(text);

    if(!gameOver){
        Position from(source.first,source.second);
        Position to(destination.first,destination.second);
        if(isBlue){
        }

        if( (isBlue && m_controller->getColor(from.getRow(),from.getColumn())==BLUE) ||
                (!isBlue&&m_controller->getColor(from.getRow(),from.getColumn())==RED) ){

            if( game->isNotALake(from,to,m_controller->layout())&&
                    (!m_controller->getPiece(destination.first,destination.second)||
                     m_controller->getColor(source.first,source.second)!=m_controller->getColor(destination.first,destination.second))&&
                    game->isnbrWalkOk(from,to,m_controller->getSymbol(source.first,source.second)) ){

                if(m_controller->getPiece(destination.first,destination.second)){
                    if(game->moveAttackNull(from,to,m_controller->layout())){
                        Piece* lbl=m_controller->setSource(source.first, source.second);
                        m_controller->delDest(to.getRow(),to.getColumn());


                    }
                    else if(game->moveAttackOk(from,to,m_controller->layout())){
                        Piece* lbl=m_controller->setSource(source.first, source.second);
                        std::string symbol = m_controller->setDest(destination.first, destination.second,lbl);
                        if(isBlue && symbol=="D"){
                            isRedFlgTaken=true;
                        }
                        if(!isBlue && symbol=="D"){
                            isBlueFlgTaken=true;
                        }
                    }
                    else if(game->moveAttackFail(from,to,m_controller->layout())){
                        Piece* lbl=m_controller->setSource(source.first, source.second);
                    }
                }
                else{
                    Piece* lbl=m_controller->setSource(source.first, source.second);
                    m_controller->setDest(destination.first, destination.second,lbl);
                }
                if(isRedFlgTaken||isBlueFlgTaken){
                    std::string text= "The player who won is: ";
                    if(isBlue){
                        text=text+"Blue";
                    }
                    else{
                        text=text+"Red";
                    }
                    ui->label->setText(QString::fromStdString(text));
                    m_controller->allVisiblePlayer();
                    gameOver = true;
                }else{
                    if(isBlue){
                        isBlue=false;
                        m_controller->visiblePlayerColor(RED);
                    }
                    else{
                        isBlue=true;
                        m_controller->visiblePlayerColor(BLUE);
                    }
                }
            }

        }
    }
}

