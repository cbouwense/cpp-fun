#include "../include/Circle.hpp"
#include "../include/Square.hpp"

int main()
{
  Circle circle;
  Square square;

  Shape *shapePtr = nullptr;

  // Drawing a circle
  shapePtr = &circle;
  shapePtr->draw();

  // Drawing a square
  shapePtr = &square;
  shapePtr->draw();

  return 0;
}