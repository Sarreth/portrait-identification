#include "CEntity.hpp"

void CEntity::init(int id) {
    this->map = new m_values();
    this->pk_name = "id";
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

const std::string CEntity::getPkName() {
    return this->pk_name;
}
