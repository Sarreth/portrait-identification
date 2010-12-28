/* 
 * File:   CEntity.cpp
 * Author: Judge
 * 
 * Created on 28 Декабрь 2010 г., 15:13
 */

#include "domain/CEntity.hpp"

CEntity::CEntity() {
}

CEntity::~CEntity() {
}

int CEntity::getId() {
    return this->id;
}

void CEntity::setId(int id) {
    this->id = id;
}
