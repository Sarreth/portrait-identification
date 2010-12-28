/* 
 * File:   main.cpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 14:07
 */

#include <stdlib.h>

#include "CReciever.hpp"

/*
 * Данный проект является ядром системы идентификации.
 * Содержит сетевые интрефейсы для получения изображений
 * и отображения результатов, а также позволяет динамически
 * поключать внешние модули для выделения ключевых точек
 * на изображении лица и соединения с БД для поиска личности
 */
int main(void) {

    CImageController image_controller;
    CReciever receiver(&image_controller, 1212);
    receiver.start(5);

    return (EXIT_SUCCESS);
}

