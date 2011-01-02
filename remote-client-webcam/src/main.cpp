/* 
 * File:   main.cpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 14:09
 */

#include <stdlib.h>
#include "sender.hpp"
#include "capturer.hpp"
#include "detector.hpp"

/*
 * Данный проект является удаленным клиентом по отношению
 * к основной системе идентификации и представляет собой
 * сервер получения изображений.
 */
int main(void) {
    // Welcome message
    printf("Welcome! OpenCV version: %s (%d.%d.%d)\n", CV_VERSION,
            CV_MAJOR_VERSION, CV_MINOR_VERSION, CV_SUBMINOR_VERSION);

    CSender sender("127.0.0.1", 1212);
    CFacesDetector detector(
            "resources/haarcascade_frontalface_alt2.xml", &sender);
    CCapturer capturer(&detector);

    while (true) {
        capturer.next();
        usleep(33000);
    }

    return (EXIT_SUCCESS);
}
