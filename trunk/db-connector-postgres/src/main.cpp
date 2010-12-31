/* 
 * File:   main.cpp
 * Author: Alex Judge
 *
 * Created on 29 Декабрь 2010 г., 1:05
 */

#include <stdlib.h>
#include <list>

#include "IEntityManager.hpp"
#include "CEntityManager.hpp"

void persist_entity(CEntity *entity) {
    CEntityManager *em = CEntityManager::getInstance();
    return em->persist(entity);
}

void merge_entity(CEntity *entity) {
    CEntityManager *em = CEntityManager::getInstance();
    em->merge(entity);
}

void remove_entity(CEntity *entity) {
    CEntityManager *em = CEntityManager::getInstance();
    em->remove(entity);
}

std::list<CEntity *> find_entity(CEntity *entity) {
    CEntityManager *em = CEntityManager::getInstance();
    return em->find(entity);
}
