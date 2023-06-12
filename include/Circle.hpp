#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"

class Circle : public Shape
{
public:
  void draw() const override;
};

#endif
