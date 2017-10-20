#include <iostream>
#include "NamedTypes.h"

using Width = NamedType<double, struct WidthParameter>;
using Height = NamedType<double, struct HeightParameter>;

class Rectangle {
public:
    explicit Rectangle(Width w, Height h) 
		: width_(w)
		, height_(h) {}

    double getArea() const { return width_.get() * height_.get(); }

private:
	Width width_;
	Height height_;
};

int main()
{
	Rectangle rec(Width(10), Height(12));
	std::cout << "Area: " << rec.getArea() << std::endl;

    return 0;
}