#include "CEntity.hpp"

void CEntity::init(int id) {
    this->map = new m_values();
    this->id_name = "id";
    this->id = id;
}

CEntity::CEntity() {
    this->init(0);
}

CEntity::CEntity(int id) {
    this->init(id);
}

CEntity::~CEntity() {
    delete this->map;
}

int CEntity::getId() {
    return this->id;
}

void CEntity::setId(int id) {
    this->id = id;
}

const std::string CEntity::getIdName() {
    return this->id_name;
}
