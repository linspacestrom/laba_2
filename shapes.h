#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <string>

class Point {
public:
    double x;
    double y;

    Point();
    Point(double x, double y);
    Point(const Point& other);
    ~Point();

    void Move(double dx, double dy);
    std::string ToString() const;
};

class Shape {
public:
    Shape();
    Shape(const Shape& other);
    virtual ~Shape();

    void Describe();

    std::string GetName() const;

protected:
    std::string name;

private:
    int id;
};

class Circle : public Shape {
public:
    Circle();
    Circle(const Point& center, double radius);
    Circle(const Circle& other);
    ~Circle();

    void Describe();
    double Area() const;

private:
    Point center;
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle(const Point& topLeft, double width, double height);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    void Describe();
    double Area() const;

private:
    Point topLeft;
    double width;
    double height;
};



#endif
 