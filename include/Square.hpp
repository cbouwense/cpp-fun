#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.hpp"

class Square : public Shape
{
public:
  void draw() const override;
};

#endif
// Path: src\Circle.cpp