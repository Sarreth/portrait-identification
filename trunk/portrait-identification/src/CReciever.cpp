/* 
 * File:   CReciever.cpp
 * Author: Judge
 * 
 * Created on 26 Декабрь 2010 г., 19:43
 */

#include "CReciever.hpp"

CReciever::CReciever(CImageController *image_controller, uint16_t port) {
    this->image_controller = image_controller;
    memset(&this->addr, 0, sizeof (this->addr));
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(port);
    this->addr.sin_addr.s_addr = INADDR_ANY;
}

CReciever::~CReciever() {
}

void CReciever::log(const char* message) {
    puts(message);
}

void CReciever::start(int max_conn) {
    int server = socket(PF_INET, SOCK_STREAM, 0);
    bind(server, (struct sockaddr *) & this->addr, sizeof (this->addr));
    listen(server, max_conn);
    for (;;) {
        this->log("Server waiting for connection.");
        int sock = accept(server, NULL, NULL);
        this->run(sock);
    }
}

int CReciever::answer(int sock, s_packet::e_mes mes) {
    s_packet packet;
    memset((void *) & packet, 0, sizeof (packet));
    packet.mes = mes;
    return write(sock, (char *) & packet, sizeof (packet));
}

void CReciever::run(int sock) {
    s_packet packet;
    this->log("Start");
    int n_readed = read(sock, (char *) & packet, sizeof (packet));
    if (n_readed != sizeof (packet) || s_packet::MES_SYN != packet.mes) {
        this->log("Not a SYN packet.\n");
        shutdown(sock, SHUT_RDWR);
        close(sock);
        return;
    }
    this->answer(sock, s_packet::MES_ACK);

    for (bool flag = true; flag;) {
        n_readed = read(sock, (char *) & packet, sizeof (packet));
        if (0 >= n_readed) {
            this->log("Connection closed");
            break;
        }
        if (n_readed != sizeof (packet)) {
            this->log("Framing error");
            this->answer(sock, s_packet::MES_UNF);
            continue;
        }

        switch (packet.mes) {
            case s_packet::MES_IMAGE_INFO:
                this->answer(sock, s_packet::MES_ACK);
                this->log("\nReceiving image");

                IplImage *image = this->recv_img(sock, packet.image_info);
                if (NULL == image) {
                    this->log("Broken image");
                    break;
                }

                this->image_controller->image(image);
                this->answer(sock, s_packet::MES_ACK);
                break;
            case s_packet::MES_FACE_INFO:
                this->answer(sock, s_packet::MES_ACK);
                this->log("\nReceiving face image");

                IplImage *face = this->recv_img(sock, packet.image_info);
                if (NULL == image) {
                    this->log("Broken face image");
                    break;
                }

                this->image_controller->face(face);
                this->answer(sock, s_packet::MES_ACK);
                break;
            case s_packet::MES_FIN:
                this->answer(sock, s_packet::MES_ACK);
                flag = false;
                break;
            default:
                this->log("Unknown command");
                this->answer(sock, s_packet::MES_UNK);
        }
    }

    this->log("Finish\n");

    shutdown(sock, SHUT_RDWR);
    close(sock);
}

IplImage *CReciever::recv_img(int sock, s_packet::s_image_info info) {
    IplImage *retval = cvCreateImage(
            cvSize(info.width, info.height),
            info.depth, info.channels);

    for (int r = 0, n = -1; r != retval->imageSize; r += n) {
        n = read(sock, (void*) & retval->imageData[r], retval->imageSize - r);
        printf("Total readed: %d\n", r);
        printf("Readed: %d\n", n);
        if (n <= 0) {
            this->answer(sock, s_packet::MES_BKN_IMG);
            cvReleaseImage(&retval);
            return NULL;
        }
    }
    return retval;
}
