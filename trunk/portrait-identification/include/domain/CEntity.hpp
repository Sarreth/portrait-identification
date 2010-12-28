/* 
 * File:   CEntity.hpp
 * Author: Judge
 *
 * Created on 28 Декабрь 2010 г., 15:13
 */

#pragma once

class CEntity {
private:
    int id;
public:
    CEntity();
    ~CEntity();
    int getId();
    void setId(int id);
};
