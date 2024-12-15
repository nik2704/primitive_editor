#pragma once

#include "Shape.h"

namespace vedt {

/**
 * @class Circle
 * @brief Окружность.
 *
 * Необходимые данные:
 * - координата x
 * - координата y
 * - радиус.
  */
class Circle : public Shape {
public:
    /**
     * @brief Конструктор.
     * @param x координата X.
     * @param y координата Y.
     * @param radius радиус.
     */
    explicit Circle(int x, int y, int radius);

    /**
     * @brief Конструктор копирования
     */    
    Circle(const Circle& other);

    /**
     * @brief Клонирование
     * 
     * @return std::unique_ptr<Shape> указатель на новый примитив.
     */    
    std::unique_ptr<Shape> clone() const override;

private:
    int x_, y_, radius_;
    std::string getBriefDescr() const override;
};

}
