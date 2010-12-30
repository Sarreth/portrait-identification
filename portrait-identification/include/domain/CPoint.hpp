/* 
 * File:   CPoint.hpp
 * Author: Alex Judge
 *
 * Created on 28 Декабрь 2010 г., 21:33
 */

#pragma once

#include "CEntity.hpp"
#include "CPerson.hpp"

class CPoint : public CEntity {
private:
    int x;
    int y;
    int point_number;
    CPerson *person;
public:
    CPoint(CPerson *person, int point_number, int x, int y);
    const m_values *getRow();
    const std::string getTableName();
    int getX();
    int getY();
    const CPerson *getPerson();
};
