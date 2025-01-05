#include "game.h"

Game::Game()
{}

bool Game::isOneStep(Position from, Position to){

    if((to.getColumn()-from.getColumn()==-1||to.getColumn()-from.getColumn()==1)&&to.getRow()==from.getRow()){
        return true;
    }
    if((to.getRow()-from.getRow()==-1||to.getRow()-from.getRow()==1)&&to.getColumn()==from.getColumn()){
        return true;
    }
    return false;
}

bool Game::isOnSameLine(Position from, Position to){
    return to.getRow()==from.getRow()||to.getColumn()==from.getColumn();
}

bool Game::isnbrWalkOk(Position from, Position to, std::string symbol){
    if(symbol=="2"){
        return this->isOnSameLine(from,to);
    }
    if(symbol!="B"&&symbol!="D"){
        return this->isOneStep(from, to);
    }
    return false;
}

bool Game::isNotALake(Position from, Position to, QLayout* layout){
    QGridLayout * Glayout = dynamic_cast<QGridLayout *>(layout);
    if(isOneStep(from,to)){
        if(to.getColumn()-from.getColumn()==-1&&to.getRow()==from.getRow()){
            Square * cell = dynamic_cast<Square *>(
                                        Glayout->itemAtPosition(from.getRow(), from.getColumn()-1)->widget());
            if(cell->getType()==LAKE){
                return false;
            }
        }
        if(to.getColumn()-from.getColumn()==+1&&to.getRow()==from.getRow()){
            Square * cell = dynamic_cast<Square *>(
                                        Glayout->itemAtPosition(from.getRow(), from.getColumn()+1)->widget());
            if(cell->getType()==LAKE){
                return false;
            }
        }
        if(to.getRow()-from.getRow()==-1&&to.getColumn()==from.getColumn()){
            Square * cell = dynamic_cast<Square *>(
                                        Glayout->itemAtPosition(from.getRow()-1, from.getColumn())->widget());
            if(cell->getType()==LAKE){
                return false;
            }
        }

        if(to.getRow()-from.getRow()==1&&to.getColumn()==from.getColumn()){
            Square * cell = dynamic_cast<Square *>(
                                        Glayout->itemAtPosition(from.getRow()+1, from.getColumn())->widget());
            if(cell->getType()==LAKE){
                return false;
            }
        }

    }
    else{
        if(to.getColumn()-from.getColumn()>1){
            for(int i = 1; i<=to.getColumn()-from.getColumn();i++){
                Square * cell = dynamic_cast<Square *>(
                                            Glayout->itemAtPosition(from.getRow(), from.getColumn()+i)->widget());
                if(cell->getType()==LAKE){
                    return false;
                }
            }
        }
        if(to.getColumn()-from.getColumn()<-1){
            for(int i = 1; i<=from.getColumn()-to.getColumn();i++){
                Square * cell = dynamic_cast<Square *>(
                                            Glayout->itemAtPosition(from.getRow(), to.getColumn()+i)->widget());
                if(cell->getType()==LAKE){
                    return false;
                }
            }
        }
        if(to.getRow()-from.getRow()>1){
            for(int i = 1;i<=to.getRow()-from.getRow();i++){
                Square * cell = dynamic_cast<Square *>(
                                            Glayout->itemAtPosition(from.getRow()+i, from.getColumn())->widget());
                if(cell->getType()==LAKE){
                    return false;
                }
            }
        }
        if(to.getRow()-from.getRow()<-1){
            for(int i=1; i<= from.getRow()-to.getRow();i++){
                Square * cell = dynamic_cast<Square *>(
                                            Glayout->itemAtPosition(to.getRow()+i, from.getColumn())->widget());
                if(cell->getType()==LAKE){
                    return false;
                }
            }
        }
    }

    return true;
}

bool Game::moveAttackNull(Position &from, Position &to, QLayout* layout){
    QGridLayout * Glayout = dynamic_cast<QGridLayout *>(layout);
    Square * sFrom = dynamic_cast<Square *>(
                                Glayout->itemAtPosition(from.getRow(), from.getColumn())->widget());
    Square * sTo = dynamic_cast<Square *>(
                                Glayout->itemAtPosition(to.getRow(), to.getColumn())->widget());

        if(sTo->getPiece()&&
                sFrom->getPiece()->getSymbol()==sTo->getPiece()->getSymbol()){
            return true;
        }
        return false;

}

bool Game::moveAttackOk(Position &from, Position &to, QLayout *layout){
    QGridLayout * Glayout = dynamic_cast<QGridLayout *>(layout);
    Square * sFrom = dynamic_cast<Square *>(
                                Glayout->itemAtPosition(from.getRow(), from.getColumn())->widget());
    Square * sTo = dynamic_cast<Square *>(
                                Glayout->itemAtPosition(to.getRow(), to.getColumn())->widget());
    std::string symbolFrom = sFrom->getPiece()->getSymbol();
    std::string symbolTo = sTo->getPiece()->getSymbol();
    if(symbolTo=="D"||
             (symbolFrom=="2" && symbolTo=="B") ||(symbolFrom == "1" && symbolTo == "10") ||
            std::stoi(symbolFrom)>std::stoi(symbolTo)  ){
        return true;
    }

    return false;
}

bool Game::moveAttackFail(Position &from, Position &to, QLayout *layout){
    QGridLayout * Glayout = dynamic_cast<QGridLayout *>(layout);
    Square * sFrom = dynamic_cast<Square *>(
                                Glayout->itemAtPosition(from.getRow(), from.getColumn())->widget());
    Square * sTo = dynamic_cast<Square *>(
                                Glayout->itemAtPosition(to.getRow(), to.getColumn())->widget());
    std::string symbolFrom = sFrom->getPiece()->getSymbol();
    std::string symbolTo = sTo->getPiece()->getSymbol();
    if(symbolTo!="D"&&
            ( (symbolFrom!="2" && symbolTo=="B") ||
            std::stoi(symbolFrom)<std::stoi(symbolTo) ) ){
        return true;
    }
    return false;
}
