/* 
 * File:   CGenericDAO.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 3:02
 */

#pragma once

#include <list>

#include "../CEntityManager.hpp"

class CGenericDAO {
protected:
    CEntityManager *em;
public:
    CGenericDAO(CEntityManager *em);
    virtual ~CGenericDAO();
    CEntity *getById(int id);
    std::list<CEntity *> getAll();
    void save(CEntity *entity);
    void remove(CEntity *entity);
};
