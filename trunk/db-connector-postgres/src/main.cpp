/* 
 * File:   main.cpp
 * Author: Alex Judge
 *
 * Created on 29 Декабрь 2010 г., 1:05
 */

#include <stdlib.h>

#include "IEntityManager.hpp"
#include "CEntityManager.hpp"

void persist_entity(CEntity *entity) {
    CEntityManager *connector = CEntityManager::getInstance();
    connector->persist(entity);
}

void merge_entity() {
    CEntityManager *connector = CEntityManager::getInstance();
    connector->merge();
}

void remove_entity() {
    CEntityManager *connector = CEntityManager::getInstance();
    connector->remove();
}

void find_entity() {
    CEntityManager *connector = CEntityManager::getInstance();
    connector->find();
}
