// StrongTypedConstructors.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>

const double Pi = 3.14159265;

class Radius {
public:
    explicit Radius(double value) : value_(value) {}
    double get() const { return value_; }
private:
    double value_;
};

class Diameter {
public:
    explicit Diameter(double value) : value_(value) {}
    double get() const { return value_; }
private:
    double value_;
};

class Circle {
public:
    explicit Circle(Radius radius) : radius_(radius.get()) {}
    explicit Circle(Diameter diameter) : radius_(diameter.get() / 2) {}

    double getCircumference() const { return 2 * Pi * radius_; }
    double getArea() const { return Pi * radius_ * radius_; }

private:
    double radius_;
};

int main()
{
    Circle circle1(Radius(7));
    Circle circle2(Diameter(14));

    std::cout << circle1.getCircumference() << "\n";
    std::cout << circle2.getCircumference() << "\n";
    return 0;
}

