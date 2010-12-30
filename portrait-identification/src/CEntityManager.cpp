#include "CEntityManager.hpp"
#include "CEntity.hpp"

CEntityManager *CEntityManager::instance = NULL;

CEntityManager *CEntityManager::getInstance() {
    if (CEntityManager::instance == NULL) {
        std::string libname = "libdb-connector-postgres.dll";
        CEntityManager::instance = new CEntityManager(libname);
    }
    return CEntityManager::instance;
}

CEntityManager::CEntityManager(std::string libname) {
    this->load(libname);
}

void CEntityManager::check() {
    char *error;
    if ((error = dlerror()) != NULL) {
        puts(error);
        std::string message = "Fail to find function in the plug-in: ";
        throw message.append(error).c_str();
    }
}

void CEntityManager::load(std::string libname) {
    this->handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (!handle) {
        puts(dlerror());
        throw "Fail to load DBConnector plug-in";
    }
    this->f_find = (FFind) dlsym(handle, "find_entity");
    this->check();
    this->f_merge = (FMerge) dlsym(handle, "merge_entity");
    this->check();
    this->f_persist = (FPersist) dlsym(handle, "persist_entity");
    this->check();
    this->f_remove = (FRemove) dlsym(handle, "remove_entity");
    this->check();
}

void CEntityManager::find() {
    this->f_find();
}

void CEntityManager::merge() {
    this->f_merge();
}

void CEntityManager::persist(CEntity *entity) {
    this->f_persist(entity);
}

void CEntityManager::remove() {
    this->f_remove();
}
