/* 
 * File:   CReciever.hpp
 * Author: Judge
 *
 * Created on 26 Декабрь 2010 г., 19:43
 */

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "cxcore.h"

#include "protocol.hpp"
#include "CImageController.hpp"

class CReciever {
private:
    CImageController *image_controller;
    struct sockaddr_in addr;
    void log(const char *message);
    void run(int sock);
    int answer(int sock, s_packet::e_mes mes);
    IplImage *recv_img(int sock, s_packet::s_image_info info);
public:
    CReciever(CImageController *image_controller, uint16_t port);
    ~CReciever();
    void start(int max_conn);
};
