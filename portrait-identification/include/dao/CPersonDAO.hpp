/* 
 * File:   CPersonDAO.hpp
 * Author: Alex Judge
 *
 * Created on 30 Декабрь 2010 г., 3:00
 */

#pragma once

#include "CGenericDAO.hpp"
#include "../domain/CPerson.hpp"

class CPersonDAO : public CGenericDAO {
private:

public:
    CPersonDAO(CEntityManager *em);
};
