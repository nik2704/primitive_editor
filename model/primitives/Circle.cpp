#include <fmt/core.h>
#include <iostream>
#include <string>
#include "Circle.h"


namespace vedt {

Circle::Circle(int x, int y, int radius) : x_(x), y_(y), radius_(radius) {}

Circle::Circle(const Circle& other) : x_(other.x_), y_(other.y_), radius_(other.radius_) {}

std::unique_ptr<Shape> Circle::clone() const {
    return std::make_unique<Circle>(*this);
}

std::string Circle::getBriefDescr() const {
    std::string brief = fmt::format("Окружность: x={0}, y={1}, radius={2}", x_, y_, radius_);

    return brief;
}

}
