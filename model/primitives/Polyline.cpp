#include "Polyline.h"
#include <sstream>

namespace vedt {

Polyline::Polyline(const std::vector<std::pair<int, int>>& points) : points_(points) {}

Polyline::Polyline(const Polyline& other) : points_(other.points_) {}

std::unique_ptr<Shape> Polyline::clone() const {
    return std::make_unique<Polyline>(*this);
}

std::string Polyline::getBriefDescr() const {
    std::ostringstream oss;
    oss << "Ломаная линия из " << points_.size() << " точек: ";

    for (const auto& point : points_) {
        oss << "(" << point.first << ", " << point.second << ") ";
    }
    
    return oss.str();
}

}  // namespace vedt
