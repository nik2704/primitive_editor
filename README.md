## Каркас графического редактора

Простейший графический векторный редактор. Подготовлены макеты классов, отражающих структуру будущего проекта. 

**Функционал макета следующий:**
- создание нового документа
- импорт документа из файла
- экспорт документа в файл
- создание графического примитива
- удаление графического примитива

#### Пример использования
```cpp
int main() {

    auto document = std::make_unique<Document>();
    auto renderer = std::make_unique<Renderer>();
    std::vector<std::pair<int, int>> points = {
        {1, 1},
        {5, 7},
        {10, 10},
        {15, 5},
        {20, 20}
    };

    Controller controller(std::move(document), std::move(renderer));

    controller.createNewDocument();

    controller.addShape(std::make_unique<Circle>(5, 5, 10));
    controller.addShape(std::make_unique<Circle>(10, 10, 3));
    controller.addShape(std::make_unique<Rectangle>(1, 1, 20, 20));
    controller.addShape(std::make_unique<vedt::Polyline>(points));
    controller.addShape(std::make_unique<Line>(1, 1, 20, 20));

    controller.deleteShape(1);

    controller.renderDocument();
    controller.exportDocument("output.file");

    return 0;
}
```
