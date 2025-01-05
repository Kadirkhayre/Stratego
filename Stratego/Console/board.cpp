#include "board.h"
#include "squaretype.h"
#include "iostream"
#include "gametype.h"

Board::Board():m_squares{
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(LAKE), Square(LAKE), Square(GROUND), Square(GROUND), Square(LAKE), Square(LAKE), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(LAKE), Square(LAKE), Square(GROUND), Square(GROUND), Square(LAKE), Square(LAKE), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)},
{Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND), Square(GROUND)}
                   }
{}

Square& Board::getSquare(Position& position){
    return m_squares[position.getRow()][position.getColumn()];
}

int Board::getSize(){
    return SIZE;
}

bool Board::isInside(Position& position){
    return position.getRow() >= 0
            && position.getColumn() >= 0
            && position.getRow() < SIZE
            && position.getColumn() < SIZE;
}

std::vector <Movement> Board::movementPossibilities(Position& position){
    std::vector<Movement> possibilities;
    Movement w(WEST);
    Movement e(EAST);
    Movement n(NORTH);
    Movement s(SOUTH);

    if(getSquare(position).getPiece()->getSymbol()=="2"){
        Position pos2 = position;

        while(canMove(pos2,w)){
            Movement m(w.getDirection(),pos2.getColumn()-position.getColumn()+1);
            possibilities.push_back(m);
            pos2 = pos2.nextPosition(w.getDirection());
        }

        pos2 = position;
        while(canMove(pos2,e)){
            Movement m(e.getDirection(),pos2.getColumn()-position.getColumn()+1);
            possibilities.push_back(m);
            pos2 = pos2.nextPosition(e.getDirection());
        }

        pos2 = position;
        while(canMove(pos2,n)){
            Movement m(n.getDirection(),pos2.getRow()-position.getRow()+1);
            possibilities.push_back(m);
            pos2 = pos2.nextPosition(n.getDirection());
        }

        pos2 = position;
        while(canMove(pos2,s)){
            Movement m(s.getDirection(),pos2.getRow()-position.getRow()+1);
            possibilities.push_back(m);
            pos2 = pos2.nextPosition(s.getDirection());
        }
    }
    else{
        if(canMove(position, w)){
            possibilities.push_back(w);
        }
        if(canMove(position, e)){
            possibilities.push_back(e);
        }
        if(canMove(position, n)){
            possibilities.push_back((n));
        }
        if(canMove(position, s)){
            possibilities.push_back(s);
        }
    }

    return possibilities;
}

bool Board::isPieceInsideSquare(Position& position){
    return getSquare(position).getPiece() != nullptr;
}

bool Board::isDifferentPieceColor(Position& position, Position& newPosition){
    return getSquare(position).getPiece()->getColor()!=getSquare(newPosition).getPiece()->getColor();
}

bool Board::isLakeSquare(Position& position){
    return getSquare(position).getType() == LAKE;
}

bool Board:: isPieceMoveable(Position& position){
    return getSquare(position).getPiece()->isMoveable();
}

bool Board::canMove(Position& position, Movement& movement){
    if(!isPieceInsideSquare(position)){
        return false;
    }
    Position newPosition = position;
    for (int i = 0 ; i < movement.getSteps(); i++){
        newPosition = newPosition.nextPosition(movement.getDirection());
        if(!isInside(newPosition) || isLakeSquare(newPosition)){
            return false;
        }
        if(isPieceInsideSquare(newPosition) && !isDifferentPieceColor(position, newPosition)){
            return false;
        }

    }
    return true;
}

Piece* Board::move(Position& position, Movement& movement, GameType gameType){
    bool attackOk = false;
    Position newPosition = position;
    for (int i = 0 ; i < movement.getSteps() && !attackOk; i++){
        newPosition = newPosition.nextPosition(movement.getDirection());
        if (isPieceInsideSquare(newPosition)){
            attackOk = true;
        }
    }

    Piece* current = getSquare(position).getPiece();
    Piece* opponent = getSquare(newPosition).getPiece();
    Piece* pieceToDelete = nullptr;

    if(attackOk){
        std::cout << "You are attacking the opponent piece who has the value " << opponent->getSymbol() << std::endl;
        if(current->getSymbol() == opponent->getSymbol()){
            pieceToDelete = opponent;
            getSquare(position).setPiece(nullptr);
            getSquare(newPosition).setPiece(nullptr);
        }
        else if(!current->attack(*opponent)){
            pieceToDelete = current;
            getSquare(position).setPiece(nullptr);
            if (gameType == VISIBLE_AFTER_REVEAL){
                opponent->setHidden(false);
            }
        }
        else{
            pieceToDelete = opponent;
            getSquare(position).setPiece(nullptr);
            getSquare(newPosition).setPiece(current);
            if (gameType == VISIBLE_AFTER_REVEAL){
                current->setHidden(false);
            }
        }

    }
    else{
        getSquare(position).setPiece(nullptr);
        getSquare(newPosition).setPiece(current);
    }

    return pieceToDelete;
}

