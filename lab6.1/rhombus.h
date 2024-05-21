#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>

class Point {
protected:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    virtual void draw() const = 0; 
};

class Rhombus : public Point {
private:
    double side;

public:
    Rhombus(int x = 0, int y = 0, double side = 1.0) : Point(x, y), side(side) {}

    void setSide(double side) {
        this->side = side;
    }

    double getSide() const {
        return side;
    }

    void draw() const override {
        drawRhombus(x, y, side);
    }

    static void drawRhombus(int x, int y, int side) {
        int n = side; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++)
                std::cout << " ";
            for (int j = 0; j < 2 * i + 1; j++)
                std::cout << "*";
            std::cout << std::endl;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n - i - 1; j++)
                std::cout << " ";
            for (int j = 0; j < 2 * i + 1; j++)
                std::cout << "*";
            std::cout << std::endl;
        }
    }
};

#endif 
