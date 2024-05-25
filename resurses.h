#ifndef RESURSES_H
#define RESURSES_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class Point {
protected:
    int x, y;
    string color;

public:
    Point(int x = 0, int y = 0, string color = "black") : x(x), y(y), color(color) {}

    virtual void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    virtual void setColor(const string& newColor) {
        color = newColor;
    }

    virtual void display() const {
        cout << "Point at (" << x << ", " << y << ") with color " << color << endl;
    }

    virtual ~Point() = default;
};


class Rectangle : public Point {
private:
    int width, height;
    double angle; 

public:
    Rectangle(int x, int y, int width, int height, string color = "black")
        : Point(x, y, color), width(width), height(height), angle(0) {}

    void resize(int newWidth, int newHeight) {
        width = newWidth;
        height = newHeight;
    }

    void rotate(double newAngle) {
        angle = fmod(newAngle, 360.0); 
    }

    void move(int dx, int dy) override {
        x += dx;
        y += dy;
    }

    void setColor(const string& newColor) override {
        color = newColor;
    }

    void display() const override {
        cout << "Rectangle at (" << x << ", " << y << ") with width " << width
            << ", height " << height << ", color " << color << " and rotated by " << angle << " degrees" << endl;
    }
};

#endif 
