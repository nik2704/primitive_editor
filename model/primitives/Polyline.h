#pragma once

#include "Shape.h"
#include <vector>

namespace vedt {

/**
 * @class Polyline
 * @brief Ломаная линия.
 *
 * Хранит список координат точек, через которые проходит ломаная линия.
 */
class Polyline : public Shape {
public:
    /**
     * @brief Конструктор.
     * @param points вектор точек (каждая точка - пара координат).
     */
    explicit Polyline(const std::vector<std::pair<int, int>>& points);

    /**
     * @brief Конструктор копирования.
     */    
    Polyline(const Polyline& other);

    /**
     * @brief Клонирование.
     * 
     * @return std::unique_ptr<Shape> указатель на новый примитив.
     */    
    std::unique_ptr<Shape> clone() const override;

private:
    std::vector<std::pair<int, int>> points_;  ///< Вектор точек ломаной линии.
    
    /**
     * @brief Получить краткое описание ломаной линии.
     * 
     * @return строка с кратким описанием.
     */
    std::string getBriefDescr() const override;
};

}  // namespace vedt
