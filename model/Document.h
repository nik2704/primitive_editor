#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "primitives/Shape.h"


namespace vedt {

/**
 * @class Document
 * @brief Хранит фигуры и управляет ими.
 *
 * - создание нового документа
 * - импорт документа из файла
 * - экспорт документа в файл
 * - создание графического примитива
 * - удаление графического примитива
 */
class Document {
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Document();

    /**
     * @brief Конструктор копирования
     */
    Document(const Document& other);

    /**
     * @brief Конструктор перемещения
     */
    Document(Document&& other) noexcept;

    /**
     * @brief Деструктор по умолчанию
     */
    ~Document();

    /**
     * @brief Оператор присваивания
     */
    Document& operator=(const Document& other);

    /**
     * @brief Оператор перемещения
     */
    Document& operator=(Document&& other) noexcept;

    /**
     * @brief создание нового документа
     */
    void newDocument();

    /**
     * @brief импорт документа из файла.
     * @param fileName имя файля, из которого импортировать документ.
     */
    void importFromFile(const std::string& fileName);

    /**
     * @brief экспорт документа в файл
     * @param fileName имя файля, в который экспортировать документ.
     */
    void exportToFile(const std::string& fileName) const;

    /**
     * @brief создание графического примитива
     * @param shape примитив для добавления в документ.
     */
    void addShape(std::unique_ptr<Shape>&& shape);

    /**
     * @brief удаление графического примитива
     * @param index индекс примитива для удаления.
     */
    void deleteShape(size_t index);

    /**
     * @brief Оператор вывода для объекта Document.
     * @param os Поток вывода, в который будет записан результат.
     * @param document Объект документа, который содержит коллекцию фигур.
     * @return std::ostream& Ссылка на поток вывода, для поддержки цепочки операций.
     */
    friend std::ostream& operator<<(std::ostream& os, const Document& document);

private:
    std::vector<std::unique_ptr<Shape>> shapes_;
};

}; // namespace vedt
