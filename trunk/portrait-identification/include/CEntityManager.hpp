/* 
 * File:   CEntityManager.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 2:24
 */

#pragma once

#include <stdio.h>
#include <string>
#include <list>
#include <dlfcn.h>

#include "CEntity.hpp"

typedef std::list<CEntity *>(*FFind)(CEntity *);
typedef void(*FMerge)(CEntity *);
typedef void(*FPersist)(CEntity *);
typedef void(*FRemove)(CEntity *);

class CEntityManager {
private:
    static CEntityManager *instance;
    static char *libname;
    void *handle;
    FFind f_find;
    FMerge f_merge;
    FPersist f_persist;
    FRemove f_remove;
    void load();
    CEntityManager();
    void check();
public:
    static void setLibname(char *libname);
    static CEntityManager *getInstance();
    void persist(CEntity *entity);
    void merge(CEntity *entity);
    void remove(CEntity *entity);
    std::list<CEntity *> find(CEntity *entity);
};
