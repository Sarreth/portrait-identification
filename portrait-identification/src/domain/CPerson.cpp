#include "domain/CPerson.hpp"

CPerson::CPerson(std::string person_lastname, std::string person_firstname,
        std::string person_patronymic) {
    this->person_firstname = person_firstname;
    this->person_lastname = person_lastname;
    this->person_patronymic = person_patronymic;
}

const m_values *CPerson::getRow() {
    if (this->map->empty()) {
        std::stringstream ss;
        ss << this->person_firstname;
        (*this->map)["person_firstname"] = ss.str();
        ss.str("");
        ss << this->person_lastname;
        (*this->map)["person_lastname"] = ss.str();
        ss.str("");
        ss << this->person_patronymic;
        (*this->map)["person_patronymic"] = ss.str();
    }
    return this->map;
}

const std::string CPerson::getTableName() {
    return "persons";
}

const std::string CPerson::getFirstname() {
    return this->person_firstname;
}

const std::string CPerson::getLastname() {
    return this->person_lastname;
}

const std::string CPerson::getPatronymic() {
    return this->person_patronymic;
}
