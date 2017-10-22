#include <iostream>
#include "NamedTypes.h"


using FirstName = NamedType<std::string&, struct FirstNameRefParameter>;
using Age = NamedTyped<int, struct AgeParameter>;

class Person
{
public:
  explicit Person(FirstName firstname, Age age) 
    : firstname_(firstname)
    , age_(age) {}

  void Introduction() 
  {
    std::cout << "I'm " << firstname_.get();
     << " and " << age_.get() << " years old." << std::endl;
  }
private:
  FirstName firstname_;
  Age age_;
};

int main()
{
  Person john("Ping", 20);
  john.Introduction();

  return 1;
}