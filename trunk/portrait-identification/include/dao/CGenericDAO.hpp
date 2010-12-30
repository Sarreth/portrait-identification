/* 
 * File:   CGenericDAO.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 3:02
 */

#pragma once
#include "../CEntityManager.hpp"

class CGenericDAO {
protected:
    CEntityManager *em;
public:
    CGenericDAO(CEntityManager *em);
};
