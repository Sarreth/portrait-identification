/* 
 * File:   IDBConnect.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 0:16
 */

#pragma once

#include <list>

#include "CEntity.hpp"

extern "C" void persist_entity(CEntity *entity);
extern "C" void merge_entity(CEntity *entity);
extern "C" void remove_entity(CEntity *entity);
extern "C" std::list<CEntity *> find_entity(CEntity *entity);
