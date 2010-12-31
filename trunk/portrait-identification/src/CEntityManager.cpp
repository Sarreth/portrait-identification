#include "CEntityManager.hpp"
#include "CEntity.hpp"

CEntityManager *CEntityManager::instance = NULL;
char *CEntityManager::libname = NULL;

void CEntityManager::setLibname(char *libname) {
    CEntityManager::libname = libname;
}

CEntityManager *CEntityManager::getInstance() {
    if (CEntityManager::instance == NULL) {
        CEntityManager::instance = new CEntityManager();
    }
    return CEntityManager::instance;
}

CEntityManager::CEntityManager() {
    this->load();
}

void CEntityManager::check() {
    char *error;
    if ((error = dlerror()) != NULL) {
        puts(error);
        std::string message = "Fail to find function in the plug-in: ";
        throw message.append(error).c_str();
    }
}

void CEntityManager::load() {
    this->handle = dlopen(CEntityManager::libname, RTLD_LAZY);
    if (!handle) {
        puts(dlerror());
        throw "Fail to load DBConnector plug-in";
    }
    this->f_find = (FFind) dlsym(this->handle, "find_entity");
    this->check();
    this->f_merge = (FMerge) dlsym(this->handle, "merge_entity");
    this->check();
    this->f_persist = (FPersist) dlsym(this->handle, "persist_entity");
    this->check();
    this->f_remove = (FRemove) dlsym(this->handle, "remove_entity");
    this->check();
}

std::list<CEntity *> CEntityManager::find(CEntity *entity) {
    return this->f_find(entity);
}

void CEntityManager::merge(CEntity *entity) {
    this->f_merge(entity);
}

void CEntityManager::persist(CEntity *entity) {
    this->f_persist(entity);
}

void CEntityManager::remove(CEntity *entity) {
    this->f_remove(entity);
}
