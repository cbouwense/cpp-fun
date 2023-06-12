#include "Circle.hpp"

int main() {
  Circle circle;
  // Rectangle rectangle;

  Shape* shapePtr = nullptr;

  // Drawing a circle
  shapePtr = &circle;
  shapePtr->draw();

  // Drawing a rectangle
  // shapePtr = &rectangle;
  // shapePtr->draw();

  return 0;
}