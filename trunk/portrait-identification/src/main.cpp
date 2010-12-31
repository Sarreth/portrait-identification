/* 
 * File:   main.cpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 14:07
 */

#include <stdlib.h>

#include "CReciever.hpp"
#include "CEntityManager.hpp"
#include "domain/CPerson.hpp"
#include "domain/CPoint.hpp"
#include "dao/CGenericDAO.hpp"
#include "dao/CPersonDAO.hpp"
#include "dao/CPointDAO.hpp"

/*
 * Данный проект является ядром системы идентификации.
 * Содержит сетевые интрефейсы для получения изображений
 * и отображения результатов, а также позволяет динамически
 * поключать внешние модули для выделения ключевых точек
 * на изображении лица и соединения с БД для поиска личности
 */
int main(void) {
    char *libname = "libdb-connector-postgres.dll";
    int n_points = 68;

    CEntityManager::setLibname(libname);
    CEntityManager *em = CEntityManager::getInstance();

    CPersonDAO *personDAO = new CPersonDAO(em);
    CPointDAO *pointDAO = new CPointDAO(em);

    CPerson *person = new CPerson("Иванов", "Иван", "Иванович");
    personDAO->save((CEntity *) person);

    for (int i = 0; i < 68; i++) {
        CPoint *point = new CPoint(person, i, i * 12, i * 23);
        pointDAO->save((CEntity *) point);
        delete point;
    }

    delete person;
    delete pointDAO;
    delete personDAO;

    return (EXIT_SUCCESS);
}

