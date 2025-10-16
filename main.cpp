#include <iostream>
#include "Point.h"
#include "Square.h"
#include <vector>

Point::Point(int px, int py)
    :x(px), y(py)
{
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}


Square::Square(const string name, int x, int y, unsigned int side)
    : Point(x, y)
{
    setName(name);
    setSide(side);
    setArea(side * side);
}

unsigned int Square::getSide() const
{
    return side;
}

unsigned int Square::getArea() const
{
    return area;
}

string Square::getName() const
{
    return name;
}

void Square::setSide(unsigned int side)
{
    this->side = side;
}

void Square::setArea(unsigned int area)
{
    this->area = area;
}

void Square::setName(string name)
{
    this->name = name;
}

void printAll(vector<Square> s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i].getName() << "(" << s[i].getX() << ", "
            << s[i].getY() << ") side=" << s[i].getSide()
            << ", area=" << s[i].getArea() << endl;

    }
}

int main()
{
    int n;
    cin >> n;
    string name;
    int x, y;
    unsigned int side;
    vector<Square> squares;
    for (int i = 0; i < n; i++) {
        cin >> name >> x >> y >> side;
        Square s(name, x, y, side);
        squares.push_back(s);
    }

    cout << "\nSquares in increasing order of area\n";
    for (int i = 0; i < squares.size() - 1;i++) {
        for (int j = 0; j < squares.size() - 1 - i; j++) {
            if (squares[j].getArea() > squares[j + 1].getArea()) {
                Square tmp = squares[j];
                squares[j] = squares[j + 1];
                squares[j + 1] = tmp;
            }
        }
    }
    printAll(squares);
    for (int i = 0; i < squares.size(); i++) {
        squares[i].setX(squares[i].getX() + squares[i].getSide());
    }

    

    cout << "\nSquares in increasing order of max x-coordinate\n";
    for (int i = 0; i < squares.size() - 1; i++) {
        for (int j = 0; j < squares.size() - 1 - i; j++) {
            if (squares[j].getX() > squares[j + 1].getX()) {
                Square tmp = squares[j];
                squares[j] = squares[j + 1];
                squares[j + 1] = tmp;
            }
        }
    }
    printAll(squares);
    for (int i = 0; i < squares.size(); i++) {
        squares[i].setX(squares[i].getX() - squares[i].getSide());
        squares[i].setY(squares[i].getY() + squares[i].getSide());
    }

    cout << "\nSquares in increasing order of max y-coordinate\n";
    for (int i = 0; i < squares.size() - 1; i++) {
        for (int j = 0; j < squares.size() - 1 - i; j++) {
            if (squares[j].getY() > squares[j + 1].getY()) {
                Square tmp = squares[j];
                squares[j] = squares[j + 1];
                squares[j + 1] = tmp;
            }
        }
    }
    printAll(squares);
}
