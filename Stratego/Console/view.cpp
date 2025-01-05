#include "view.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <direction.h>

View::View(Game& game): m_game(game){}

void View::displayWelcome(){
    std::cout << "============================================" << std::endl;
    std::cout << "          Welcome to Stratego! " << std::endl;
    std::cout << "               Let's fight!" << std::endl;
    std::cout << "============================================" << std::endl;
}

void View::displayCurrentPlayer(){
    std::cout << "Current player: ";
    if (m_game.getCurrentPlayer()->getColor() == RED) {
        std::cout << "RED" << std::endl;
    }
    else{
        std::cout << "BLUE" << std::endl;
    }
}
void View::displayBoard(){
    std::vector <char> alphabet {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    std::vector <std::string> numbers {"1 ","2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10"};
    std::cout << "    ";
    for (int i = 0; i < m_game.getBoardSize(); i++) {
        std::cout << alphabet.at(i) << "  ";
    }
    std::cout << std::endl;
    makeLine(m_game.getBoardSize());

    for (int i = 0; i < m_game.getBoardSize(); i++) {
        std::cout << numbers.at(i) << "|" ;
        for (int j = 0; j < m_game.getBoardSize(); j++) {
            Position position(i,j);
            Square& currentSquare = m_game.getBoard().getSquare(position);

            if (currentSquare.getPiece() != nullptr) {
                if(currentSquare.getPiece()->getColor() == RED && m_game.getCurrentPlayer()->getColor() == RED){
                    color(4);

                    std::cout << std::setw(2) << currentSquare.getPiece()->getSymbol();
                }
                else if (currentSquare.getPiece()->getColor() == RED) {
                    color(4);
                    if(currentSquare.getPiece()->isHidden() == false){
                        std::cout << std::setw(2) << currentSquare.getPiece()->getSymbol();
                    }
                    else{
                        std::cout << std::setw(2) << "?";
                    }

                }
                if(currentSquare.getPiece()->getColor() == BLUE && m_game.getCurrentPlayer()->getColor() == BLUE){
                    color(1);
                    std::cout << std::setw(2) << currentSquare.getPiece()->getSymbol();
                }

                else if (currentSquare.getPiece()->getColor() == BLUE){
                    color(1);
                    if(currentSquare.getPiece()->isHidden() == false){
                        std::cout << std::setw(2) << currentSquare.getPiece()->getSymbol();
                    }
                    else{
                        std::cout << std::setw(2) << "?";
                    }
                }
                color(7);
                std::cout << " ";
            }
            else if (currentSquare.getType() == LAKE){
                std::cout << " x ";
            }

            else {
                std::cout << " . ";
            }
        }
        std::cout << " " << std::endl;
    }
    makeLine(m_game.getBoardSize());
}
void View::displayMovementPossibilities(Position& position){
    std::cout << "Movement possibilities : " << std::endl;
    auto possibilities = m_game.movementPossibilitiesPiece(position);
    for (size_t i = 0 ; i < possibilities.size() ; i++){
        std::cout << "Direction : ";
        switch(possibilities.at(i).getDirection()){
        case NORTH:
            std::cout << "NORTH";
            break;
        case SOUTH:
            std::cout << "SOUTH";
            break;
        case EAST:
            std::cout << "EAST";
            break;
        case WEST:
            std::cout << "WEST";
            break;

        }
        std::cout << " | Number of steps : " << possibilities.at(i).getSteps() << std::endl;
    }
}
Movement View::askMovement(Piece* piece){
    Direction direction = askDirection("Enter a direction");

    if (piece->getSymbol() == "2"){
        int steps = askNumberOfSteps("Enter number of steps");
        return Movement(direction, steps);
    }
    else {
        return Movement(direction);
    }
}

Direction View:: askDirection(std::string message){
    std::cout << message << std::endl;
    char direction;
    std::cin >> direction;

    while(true){
        switch (direction) {
        case 'N':
            return NORTH;
        case 'S':
            return SOUTH;
        case 'W':
            return WEST;
        case 'E':
            return EAST;

        default:
            std::cout << message << std::endl;
            std::cin >> direction;
        }
    }
}

int View::askNumberOfSteps(std::string message){
    return robustReadingOfInteger(message);
}

void View::displayError(std::string message){
    std::cout << message << std::endl;
}

void View::displayWinner(){
    std::cout << "The winner is player " << m_game.getWinner() << std::endl;
}
void View::displayAvailablePiecesOfPlayer(){
    std::cout << "Avaible pieces : ";
    for (Piece value : m_game.getAvailablePiecesPlayer()){
        std::cout << value.getSymbol();
    }
    std::cout << std::endl;
}

Position View::askPosition(){
    int row = robustReadingOfInteger("Enter the row : ")-1;
    int column = robustReadingOfChar("Enter the column : ");
    return Position(row, column);
}

int View::robustReadingOfInteger(std::string message){
    std::cout << message << std::endl;
    std::string number;
    std::cin >> number;

    while (!isNumber(number)){
        std::cout << "Error: this is not a number!" << std::endl;
        std::cout << message << std::endl;
        std::cin >> number;
    }
    return std::stoi(number);
}

int View::robustReadingOfChar(std::string message){
    std::cout << message << std::endl;
    char letter;
    std::cin >> letter;

    while(true){
        switch(letter){
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;

        case 'C':
            return 2;
            break;

        case 'D':
            return 3;
            break;

        case 'E':
            return 4;
            break;


        case 'F':
            return 5;
            break;

        case 'G':
            return 6;
            break;

        case 'H':
            return 7;
            break;

        case 'I':
            return 8;
            break;

        case 'J':
            return 9;
            break;

        default:
            std::cout << "Error : this is not a letter!" << std::endl;
            std::cout << message << std::endl;
            std::cin >> letter;
            break;
        }
    }
}

GameType View::askGameType(std::string message){
    std::cout << message << std::endl;
    int choice = 0;
    std::cin >> choice;

    while (choice != 1 && choice !=2 ){
        std::cout << "this not a game type!" << std::endl;
        std::cout << message << std::endl;
    }

    if(choice == 1){
        return NORMAL;
    }
    return VISIBLE_AFTER_REVEAL;
}


bool View::isNumber(const std::string& str){
    return !str.empty() &&
            std::find_if(str.begin(), str.end(),
                         [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}

void View::makeLine(int sizeBoard) {
    std::string displayLine = "";
    for (int i = 0 ; i < (sizeBoard*3)+3 ; i++){
        displayLine += "-";
    }
    std::cout << displayLine<< std::endl;
}

void View::color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


