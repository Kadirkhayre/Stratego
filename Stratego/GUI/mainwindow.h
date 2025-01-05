#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GStrategoBoard;
/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GStrategoBoard* m_controller;
    Game* game;
    bool isBlue;
    bool isRedFlgTaken= false;
    bool isBlueFlgTaken = false;
    bool gameOver = false;

private slots:
    /**
     * @brief on_board_signal is the slot for signal receive from board
     * when a drag and drop is done.
     */
    void on_board_signal(std::pair<int, int>, std::pair<int, int>);
};
#endif // MAINWINDOW_H
