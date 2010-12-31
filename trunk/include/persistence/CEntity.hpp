/* 
 * File:   CEntity.hpp
 * Author: Alex Judge
 *
 * Created on 28 Декабрь 2010 г., 15:13
 */

#pragma once

#include <string>
#include <sstream>
#include <map>

typedef std::map<std::string, std::string> m_values;

class CEntity {
private:
    void init(int id);
protected:
    int id;
    m_values *map;
    std::string id_name;
public:
    CEntity();
    CEntity(int id);
    virtual ~CEntity();
    virtual const m_values *getRow() = 0;
    virtual const std::string getTableName() = 0;
    virtual const std::string getIdName();
    virtual int getId();
    virtual void setId(int id);
};
