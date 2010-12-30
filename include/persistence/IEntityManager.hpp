/* 
 * File:   IDBConnect.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 0:16
 */

#pragma once

#include "CEntity.hpp"

extern "C" void persist_entity(CEntity *entity);
extern "C" void merge_entity();
extern "C" void remove_entity();
extern "C" void find_entity();
