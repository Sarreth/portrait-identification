/* 
 * File:   main.cpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 14:09
 */

#include <stdlib.h>
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "sender.hpp"
#include "capturer.hpp"
#include "detector.hpp"

/*
 * Данный проект является удаленным клиентом по отношению
 * к основной системе идентификации и представляет собой
 * сервер получения изображений.
 */
int main2(int argc, char** argv) {
    // Welcome message
    printf("Welcome! OpenCV version: %s (%d.%d.%d)\n", CV_VERSION,
            CV_MAJOR_VERSION, CV_MINOR_VERSION, CV_SUBMINOR_VERSION);

    CSender *sender = new CSender();
    CFacesDetector *detector = new CFacesDetector(
            "D:\\Tools\\Img\\haarcascade_frontalface_alt2.xml", sender);
    CCapturer *capturer = new CCapturer(detector);

    pthread_t tcapturer;
    int id1 = 1;
    result = pthread_create(&tcapturer, NULL, , &id1);

    capturer->start();

    delete sender;
    delete detector;
    delete capturer;

    return (EXIT_SUCCESS);
}
