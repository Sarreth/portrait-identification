/* 
 * File:   CConnector.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 0:26
 */

#pragma once

#include <string>
#include <sstream>
#include <list>
#include <libpq-fe.h>
#include "CEntity.hpp"

class CEntityManager {
private:
    static CEntityManager *instance;
    PGconn *conn;
    CEntityManager();
    void connect(std::string, std::string, std::string, std::string);
public:
    static CEntityManager *getInstance();
    void persist(CEntity *emtity);
    void merge(CEntity *emtity);
    void remove(CEntity *emtity);
    std::list<CEntity *> find(CEntity *emtity);
};
