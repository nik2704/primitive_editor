#include <fmt/core.h>
#include <iostream>
#include <string>
#include "Rectangle.h"


namespace vedt {

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

Rectangle::Rectangle(const Rectangle& other) : x1_(other.x1_), y1_(other.y1_), x2_(other.x2_), y2_(other.y2_) {}

std::unique_ptr<Shape> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

std::string Rectangle::getBriefDescr() const {
    std::string brief = fmt::format("Прямоугольник: x1={0}, y1={1}, x2={2}, y2={3}", x1_, y1_, x2_, y2_);

    return brief;
}

}
