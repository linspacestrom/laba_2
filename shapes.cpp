#include "shapes.h"
#include <sstream>
#include <cmath>

static int globalId = 0;

const double PI = 3.141592653589793;

Point::Point() : x(0), y(0) {
    std::cout << "Point(): конструктор без параметров, объект\n" << this;
}

Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {
    std::cout << "Point: конструктор с параметрами ("
        << xVal << ", " << yVal
        << "), объект " << this << "\n";
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
    std::cout << "Point: копирующий конструктор, объект = " << this
        << ", копия с " << &other << "\n";
}

Point::~Point() {
    std::cout << "~Point: деструктор, объект " << this << "\n";
}

void Point::Move(double dx, double dy) {
    x += dx;
    y += dy;
    std::cout << "Point: метод Move (" << dx << ", " << dy << ")\n";
}

std::string Point::ToString() const {
    std::ostringstream s;
    s << "(" << x << "," << y << ")";
    return s.str();
}


Shape::Shape() : name("Shape"), id(++globalId) {
    std::cout << "Shape: конструктор, объект " << this << "\n";
}

Shape::Shape(const Shape& other) : name(other.name), id(++globalId) {
    std::cout << "Shape: копирующий, объект " << this
        << ", копия с " << &other << "\n";
}

Shape::~Shape() {
    std::cout << "Shape: деструктор, объект " << this << "\n";
}

void Shape::Describe() {
    std::cout << "Shape::Describe, объект " << this << "\n";
}


std::string Shape::GetName() const {
    return name;
}


Circle::Circle() : center(Point(0, 0)), radius(1.0) {
    name = "Circle";
    std::cout << "Circle: конструктор без параметров\n";
}

Circle::Circle(const Point& c, double r) : center(c), radius(r) {
    name = "Circle";
    std::cout << "Circle: конструктор, объект " << this
        << ", радиус = " << r << "\n";
}

Circle::Circle(const Circle& other)
    : Shape(other), center(other.center), radius(other.radius) {
    name = "Circle";
    std::cout << "Circle: копирующий, объект " << this
        << ", копия с " << &other << "\n";
}

Circle::~Circle() {
    std::cout << "Circle: деструктор, объект " << this << "\n";
}

void Circle::Describe() {
    std::cout << "Circle: доступ к protected полю name = " << name << "\n";
    Shape::Describe();
    std::cout << "Circle::Describe, объект " << this << "\n";
}



double Circle::Area() const {
    return PI * radius * radius;
}

Rectangle::Rectangle() : topLeft(Point(0, 0)), width(1), height(1) {
    name = "Rectangle";
    std::cout << "Rectangle: конструктор без параметров\n";
}

Rectangle::Rectangle(const Point& p, double w, double h)
    : topLeft(p), width(w), height(h) {
    name = "Rectangle";
    std::cout << "Rectangle: конструктор с параметрами (" << w << ", " << h << ")\n";
}

Rectangle::Rectangle(const Rectangle& other)
    : Shape(other), topLeft(other.topLeft), width(other.width), height(other.height) {
    name = "Rectangle";
    std::cout << "Rectangle: копирующий конструктор\n";
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle: деструктор, объект " << this << "\n";
}

void Rectangle::Describe() {
    std::cout << "Rectangle: метод Describe\n";
}

double Rectangle::Area() const {
    return width * height;
}