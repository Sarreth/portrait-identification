/* 
 * File:   CPerson.hpp
 * Author: Alex Judge
 *
 * Created on 28 Декабрь 2010 г., 21:33
 */

#pragma once

#include <string>

#include "CEntity.hpp"

class CPerson : public CEntity {
private:
    std::string person_firstname;
    std::string person_lastname;
    std::string person_patronymic;
public:
    CPerson(std::string person_firstname, std::string person_lastname,
            std::string person_patronymic);
    const m_values *getRow();
    const std::string getTableName();
    const std::string getFirstname();
    const std::string getLastname();
    const std::string getPatronymic();
};
