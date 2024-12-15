#include "Document.h"

namespace vedt {

Document::Document() = default;

Document::Document(const Document& other) {
    for (const auto& shape : other.shapes_) {
        shapes_.emplace_back(shape->clone());
    }
}

Document::Document(Document&& other) noexcept : shapes_(std::move(other.shapes_)) {}

Document::~Document() = default;

Document& Document::operator=(const Document& other) {
    if (this == &other) {
        return *this;
    }

    shapes_.clear();

    for (const auto& shape : other.shapes_) {
        shapes_.emplace_back(shape->clone());
    }

    return *this;
}

Document& Document::operator=(Document&& other) noexcept {
    if (this != &other) {
        shapes_ = std::move(other.shapes_);
    }

    return *this;
}

void Document::newDocument() {
    shapes_.clear();
}

void Document::importFromFile(const std::string& fileName) {
    std::cout << "importFromFile() - документ импортирован из файла: " << fileName << std::endl;
}

void Document::exportToFile(const std::string& fileName) const {
    std::cout << "exportToFile() документ экспортирован в файл: " << fileName << std::endl;
}

void Document::addShape(std::unique_ptr<Shape>&& shape) {
    shapes_.emplace_back(std::move(shape));
}

void Document::deleteShape(size_t index) {
    if (index < shapes_.size()) {
        shapes_.erase(shapes_.begin() + index);
    } else {
        std::cout << "Индекс превышает размер вектора фигур. index=" << index << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Document& document) {
    for (const auto& shape : document.shapes_) {
        os << *shape << std::endl;
    }

    return os;
}

}
