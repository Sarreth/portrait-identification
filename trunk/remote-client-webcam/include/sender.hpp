/* 
 * File:   sender.hpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 17:22
 */

#pragma once
#include "protocol.hpp"
#include "cxtypes.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

class CSender {
private:

    enum e_image_type {
        SEND_IMAGE,
        SEND_FACE
    };
    sockaddr_in addr;
    int sock;
    void log(const char *message);
    s_packet::e_mes send(s_packet::e_mes mes);
    bool check_answer();
    bool send(e_image_type image_type, IplImage *image);
public:
    CSender(char *addr, uint16_t port);
    bool send_image(IplImage *image);
    bool send_face(IplImage *image);
    bool begin();
    void finish();
};
