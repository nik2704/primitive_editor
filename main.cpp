#include "model/Document.h"
#include "model/primitives/Shape.h"
#include "model/primitives/Circle.h"
#include "model/primitives/Rectangle.h"
#include "model/primitives/Line.h"
#include "model/primitives/Polyline.h"
#include "view/Renderer.h"
#include "controller/Controller.h"

#include <memory>

using namespace vedt;

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
