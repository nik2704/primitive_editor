#pragma once

#include <memory>
#include "../model/Document.h"
#include "../model/primitives/Shape.h"
#include "../view/Renderer.h"


namespace vedt {

/**
 * @class Controller
 * @brief Управляет документом и выводом.
 *
 * - создание нового документа
 * - импорт документа из файла
 * - экспорт документа в файл
 * - создание графического примитива
 * - удаление графического примитива
 * - вывод документа
 */
class Controller {
public:
    explicit Controller(std::unique_ptr<Document> document, std::unique_ptr<Renderer> renderer);

    /**
     * @brief Запрет конструктора копирования
     */
    Controller(const Controller&) = delete;

    /**
     * @brief Запрет операции присваивания
     */
    Controller& operator=(const Controller&) = delete;

    /**
     * @brief Конструктор перемещения
     */
    Controller(Controller&& other) noexcept;

    /**
     * @brief Присваивание перемещением
     */
    Controller& operator=(Controller&& other) noexcept;

    /**
     * @brief создание нового документа
     */
    void createNewDocument();

    /**
     * @brief импорт документа из файла.
     * @param fileName имя файля, из которого импортировать документ.
     */    
    void importDocument(const std::string& fileName);

    /**
     * @brief экспорт документа в файл
     * @param fileName имя файля, в который экспортировать документ.
     */    
    void exportDocument(const std::string& fileName);

    /**
     * @brief создание графического примитива
     * @param shape примитив для добавления в документ.
     */    
    void addShape(std::unique_ptr<Shape> primitive);

    /**
     * @brief удаление графического примитива
     * @param index индекс примитива для удаления.
     */    
    void deleteShape(size_t index);

    /**
     * @brief вывод документа.
     */    
    void renderDocument() const;

private:
    std::unique_ptr<Document> document_;
    std::unique_ptr<Renderer> renderer_;
};

}
