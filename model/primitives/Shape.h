#pragma once

#include <iostream>
#include <memory>
#include <string>


namespace vedt {

/**
 * @class Shape
 * @brief Абстрактный класс - интерфейс для остальных фигур.
 *
 * Контракт содержит:
 * - метод клонирования
 * - метод getBriefDescr() для перегрузки операции вывода.
 * 
 * Перегружена операция вывода.
  */
class Shape {
public:
    /**
     * @brief Базовый метод для вывода примитива
     */
    void draw() const {
        std::cout << getBriefDescr() << std::endl;
    }

    /**
     * @brief Деструктор по умолчанию
     */
    virtual ~Shape() = default;

    /**
     * @brief Клонирование (должен быть переопределен в потомках)
     */
    virtual std::unique_ptr<Shape> clone() const = 0;


    /**
     * @brief Оператор вывода для объекта Shape.
     * @param os Поток вывода, в который будет записан результат.
     * @param shape Примитив.
     * @return std::ostream& Ссылка на поток вывода, для поддержки цепочки операций.
     */
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        os << shape.getBriefDescr();
        return os;
    }

private:
    /**
     * @brief Конструктор по умолчанию
     */
    // Shape() = default;

    /**
     * @brief Получение описания (должен быть переопределен в потомках)
     */
    virtual std::string getBriefDescr() const = 0;
};

}
