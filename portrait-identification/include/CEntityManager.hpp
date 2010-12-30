/* 
 * File:   CEntityManager.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 2:24
 */

#pragma once

#include <stdio.h>
#include <string>
#include <dlfcn.h>

#include "CEntity.hpp"

typedef void(*FFind)(void);
typedef void(*FMerge)(void);
typedef void(*FPersist)(CEntity *entity);
typedef void(*FRemove)(void);

class CEntityManager {
private:
    static CEntityManager *instance;
    void *handle;
    FFind f_find;
    FMerge f_merge;
    FPersist f_persist;
    FRemove f_remove;
    void load(std::string libname);
    CEntityManager(std::string libname);
    void check();
public:
    static CEntityManager *getInstance();
    void persist(CEntity *entity);
    void merge();
    void remove();
    void find();
};
