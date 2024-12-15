#pragma once

#include "Shape.h"

namespace vedt {

/**
 * @class Line
 * @brief Линия.
 *
 * Необходимые данные:
 * - координата x1
 * - координата y1
 * - координата x2
 * - координата y2
  */
class Line : public Shape {
public:
    /**
     * @brief Конструктор.
     * @param x1 координата X1.
     * @param y1 координата Y1.
     * @param x2 координата X2.
     * @param y2 координата Y2.
     */
    explicit Line(int x1, int y1, int x2, int y2);

    /**
     * @brief Конструктор копирования
     */    
    Line(const Line& other);

    /**
     * @brief Клонирование
     * 
     * @return std::unique_ptr<Shape> указатель на новый примитив.
     */    
    std::unique_ptr<Shape> clone() const override;

private:
    int x1_, y1_, x2_, y2_;
    std::string getBriefDescr() const override;
};

}
