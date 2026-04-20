#include "shapes.h"
#include <iostream>

class CompositeOwner {
public:
    CompositeOwner() : point(Point(1, 2)), shape(nullptr) {
        std::cout << "CompositeOwner: конструктор, this = " << this << "\n";

        shape = new Circle(Point(5, 5), 2);
    }

    CompositeOwner(const CompositeOwner& other) : point(other.point) {
        std::cout << "CompositeOwner: копирующий, this = " << this
            << ", копия с " << &other << "\n";

        if (other.shape) {
            std::string name = other.shape->GetName();

            if (name == "Circle") {
                shape = new Circle(*(Circle*)other.shape);
            }
            else if (name == "Rectangle") {
                shape = new Rectangle(*(Rectangle*)other.shape);
            }
        }
        else {
            shape = nullptr;
        }
    }

    CompositeOwner& operator=(const CompositeOwner& other) {
        if (this == &other) return *this;

        delete shape;

        point = other.point;

        if (other.shape) {
            std::string name = other.shape->GetName();

            if (name == "Circle") {
                shape = new Circle(*(Circle*)other.shape);
            }
            else if (name == "Rectangle") {
                shape = new Rectangle(*(Rectangle*)other.shape);
            }
        }

        return *this;
    }

    ~CompositeOwner() {
        std::cout << "CompositeOwner: деструктор, объект " << this << "\n";
        delete shape;
    }

    void Show() {
        std::cout << "CompositeOwner: объект " << this << "\n";

        std::cout << "  Point (встроенный объект): " << point.ToString() << "\n";

        if (shape) {
            std::cout << "  Shape (указатель): " << shape << "\n";
            shape->Describe();
        }
        std::cout << "  (point и shape — private, доступ только внутри класса)\n";

    }


private:
    Point point;
    Shape* shape;
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "\n 1. Создание статических объектов \n";
    Point p1(2, 3);
    std::cout << "p1 = " << p1.ToString() << "\n";
    p1.Move(1, 1);
    std::cout << "После Move p1 = " << p1.ToString() << "\n";


    std::cout << "\n 2. Создание динамических объектов \n";
    Point* p2 = new Point(10, 10);
    std::cout << "Удаление объекта p2\n";
    delete p2;

    std::cout << "\n 3. Объекты классов-наследников \n";

    {
        std::cout << "\n Создание объекта Circle\n";
        Circle c1(Point(0, 0), 2);

        std::cout << "\n Создание объекта Rectangle\n";
        Rectangle r1(Point(0, 0), 3, 4);

        std::cout << "\n Выход из блока (будут вызваны деструкторы)\n";
    }

    std::cout << "\n 4. Указатель базового класса указывает на объект производного класса\n";
    std::cout << "\n Создание указателя Circle new\n";
    Shape* s1 = new Circle(Point(1, 1), 5);
    std::cout << "\n Создание указателя Rectangle new\n";
    Shape* s2 = new Rectangle(Point(2, 2), 2, 2);

    s1->Describe();

    std::cout << "\n 5. Копирование указателей \n";
    std::cout << "\n Создание указателя 'a' Circle new\n";
    Shape* a = new Circle(Point(0, 0), 1);
    std::cout << "\n Присваивание указателя 'b' указателю 'a'\n";
    Shape* b = a;

    std::cout << "Адрес объекта a: " << a << "\n";
    std::cout << "Адрес объекта b: " << b << "\n";

    std::cout << "a и b указывают на один и тот же объект\n";

    std::cout << "Удаляем объект через a\n";
    delete a;
    b = nullptr;

    std::cout << "\n 6. Композиция объектов \n";
    {
        std::cout << "\n Создание объекта o1 \n";
        CompositeOwner o1;

        std::cout << "\n Копирование объекта o1 в o2 \n";
        CompositeOwner o2 = o1;

        std::cout << "\n Присваивание объекта o2 в o3 \n";
        CompositeOwner o3;
        o3 = o2;

        std::cout << "\n Состояние объектов \n";
        std::cout << "\n o1 \n";
        o1.Show();
        std::cout << "\n o2 \n";
        o2.Show();
        std::cout << "\n o3 \n";
        o3.Show();

        std::cout << "\n Выход из блока (будут вызваны деструкторы) \n";

    }

    std::cout << "\n 7. Проверка копирования объектов \n";
    std::cout << "\n Создание объекта c2 Circle\n";
    Circle c2(Point(7, 7), 3);
    std::cout << "\n Копирование объекта o1 в o2 \n";
    Circle c3 = c2;

    std::cout << "c2:\n";
    c2.Describe();

    std::cout << "c3 (копия):\n";
    c3.Describe();
    std::cout << "Адрес c2: " << &c2 << "\n";
    std::cout << "Адрес c3: " << &c3 << "\n";


    std::cout << "\n 8. Уничтожение динамических объектов \n";
    delete s1;
    delete s2;

    return 0;
}

