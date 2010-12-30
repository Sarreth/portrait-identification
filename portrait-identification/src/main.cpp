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

/*
 * Данный проект является ядром системы идентификации.
 * Содержит сетевые интрефейсы для получения изображений
 * и отображения результатов, а также позволяет динамически
 * поключать внешние модули для выделения ключевых точек
 * на изображении лица и соединения с БД для поиска личности
 */
int main(void) {

    //    CImageController image_controller;
    //    CReciever receiver(&image_controller, 1212);
    //    receiver.start(5);
    CEntityManager *em = CEntityManager::getInstance();
    CEntity *person = new CPerson("Иван", "Иванов", "Иванович");
    person->setId(5);
    for (int i = 0; i < 68; i++) {
        CEntity *point = new CPoint((CPerson*) person, i, i * 12, i * 34);
        em->persist(point);
        delete point;
    }
    delete person;

    return (EXIT_SUCCESS);
}

