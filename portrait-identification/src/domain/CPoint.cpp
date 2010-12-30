#include "domain/CPoint.hpp"

CPoint::CPoint(CPerson* person, int point_number, int x, int y) {
    this->person = person;
    this->point_number = point_number;
    this->x = x;
    this->y = y;
}

const m_values *CPoint::getRow() {
    if (this->map->empty()) {
        std::stringstream ss;
        ss << this->x;
        (*this->map)["x"] = ss.str();
        ss.str("");
        ss << this->y;
        (*this->map)["y"] = ss.str();
        ss.str("");
        ss << this->point_number;
        (*this->map)["point_number"] = ss.str();
        ss.str("");
        ss << this->person->getId();
        (*this->map)["person_id"] = ss.str();
    }
    return this->map;
}

const std::string CPoint::getTableName() {
    return "points";
}

const CPerson *CPoint::getPerson() {
    return this->person;
}

int CPoint::getX() {
    return this->x;
}

int CPoint::getY() {
    return this->y;
}
