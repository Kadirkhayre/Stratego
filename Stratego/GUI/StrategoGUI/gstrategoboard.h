#ifndef GSTRATEGOBOARD_H
#define GSTRATEGOBOARD_H

#include <QLabel>
#include "position.h"
#include "square.h"
#include "obj.h"
#include <iostream>

// forward declaration
class GImageCell;
class objet;

class QPoint;
class QDragEnterEvent;
class QDropEvent;
class QMouseEvent;


/**
 * @brief The GStrategoBoard class represent a stratego board.
 *
 * It's just a POC (proof of concept) to try drag and drop.
 *
 * The board is clickable and support drag and drop. When a drag and drop
 * is done, component emit a signal.
 */
class GStrategoBoard : public QLabel
{
    Q_OBJECT

public:
    static int N;

    explicit GStrategoBoard();
    ~GStrategoBoard() = default;
    static const int SIZE = 10;
    obj m_squares[SIZE][SIZE];

    /**
     * Method isInside()
     * @brief set color on cell at position
     * @param row the given row
     * @param col the given column
     * @return true if is inside, otherwise false
     */
    bool isInside(int row, int col);

    /**
     * Method setDest()
     * @brief sets the piece into a new position
     * @param row the given row
     * @param col the given column
     * @param piece the given piece
     * @return the symbol of the piece
     */
    std::string setDest(int row, int col, Piece* piece);

    /**
     * Method getSource()
     * @brief gets the piece at the given position
     * @param row the given row
     * @param col the given column
     * @return the piece at the position
     */
    Piece* setSource(int row, int col);

    /**
     * Method getSymbol()
     * @brief gets the symbol at the given position
     * @param row the given row
     * @param col the given column
     * @return the symbol at the position
     */
    std::string getSymbol(int row, int col);

    /**
     * Method getColor()
     * @brief gets the color at the given position
     * @param row the given row
     * @param col the given column
     * @return the color at the position
     */
    Color getColor(int row, int col);

    /**
     * Method getType()
     * @brief gets the type at the given position
     * @param row the given row
     * @param col the given column
     * @return the type at the given position
     */
    SquareType getType(int row, int col);

    /**
     * Method getPiece()
     * @brief gets the piece at the given position
     * @param row the given row
     * @param col the given column
     * @return the piece at the given position
     */
    Piece* getPiece(int row, int col);

    /**
     * Method delDest()
     * @brief deletes the piece at the given position
     * @param row the given row
     * @param col the given column
     */
    void delDest(int row, int col);

    /**
     * Method visiblePlayerColor()
     * @brief make pieces visible depending on the color
     * @param color the given color
     */
    void visiblePlayerColor(Color color);

    /**
     * Method allVisiblePlayer()
     * @brief reveal all pieces of player
     */
    void allVisiblePlayer();

protected:

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    /**
     * @brief target convert x.y "pixel position" into position on board.
     * row, col position. This is strongly dependant of background picture
     * size and cell side.
     * @param position x,y "pixel position"
     * @return row, col "grid position" in std::pair
     */
    const std::pair<int, int> target(const QPoint & position);

signals:
    void send_positions(std::pair<int, int> source,
                        std::pair<int, int> destination);

};

#endif // GSTRATEGOBOARD_H
