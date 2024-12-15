#include <cassert>
#include <iostream>
#include <fstream>
#include "Controller.h"


namespace vedt {

Controller::Controller(std::unique_ptr<Document> document, std::unique_ptr<Renderer> renderer)
    : document_(std::move(document)), renderer_(std::move(renderer)) {}

Controller::Controller(Controller&& other) noexcept : document_(std::move(other.document_)), renderer_(std::move(other.renderer_)) {}

Controller& Controller::operator=(Controller&& other) noexcept {
    if (this != &other) {
        document_ = std::move(other.document_);
        renderer_ = std::move(other.renderer_);
    }
    return *this;
}

void Controller::createNewDocument() {
    document_ = std::make_unique<Document>();
}

void Controller::importDocument(const std::string& fileName) {
    std::cout << "Document imported from " << fileName << "." << std::endl;
}

void Controller::exportDocument(const std::string& fileName) {
    std::cout << "Document exported to " << fileName << "." << std::endl;
}

void Controller::addShape(std::unique_ptr<Shape> shape) {
    assert(document_);
    document_->addShape(std::move(shape));
}

void Controller::deleteShape(size_t index) {
    assert(document_);
    document_->deleteShape(index);
}

void Controller::renderDocument() const {
    assert (renderer_ && document_);
    renderer_->render(*document_);
}

}
