#include "sender.hpp"

CSender::CSender(char *addr, uint16_t port) {
    memset(&this->addr, 0, sizeof (this->addr));
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(port);
    this->addr.sin_addr.s_addr = inet_addr(addr);
}

void CSender::log(const char* message) {
    puts(message);
}

bool CSender::begin() {
    this->log("\nStarting transaction");
    this->sock = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == connect(this->sock,
            (sockaddr *) & this->addr, sizeof (this->addr))) {
        this->log("Connection failed\n");
        close(this->sock);
        this->sock = -1;
        return false;
    }

    if (s_packet::MES_ACK != this->send(s_packet::MES_SYN)) {
        this->log("No answer for SYN\n");
        shutdown(this->sock, SHUT_RDWR);
        close(this->sock);
        this->sock = -1;
        return false;
    }

    this->log("Transaction started\n");
    return true;
}

void CSender::finish() {
    this->send(s_packet::MES_FIN);

    shutdown(this->sock, SHUT_RDWR);
    close(this->sock);

    this->log("Transaction closed\n");
}

bool CSender::check_answer() {
    s_packet packet;
    memset((void *) & packet, 0, sizeof (packet));
    int n_readed = read(sock, (char *) & packet, sizeof (packet));

    return n_readed == sizeof (packet) && s_packet::MES_ACK == packet.mes;
}

s_packet::e_mes CSender::send(s_packet::e_mes mes) {
    s_packet packet;
    memset((void *) & packet, 0, sizeof (packet));
    packet.mes = mes;
    write(this->sock, (void *) & packet, sizeof (packet));
    packet.mes = s_packet::MES_ERR;
    read(this->sock, (void *) & packet, sizeof (packet));
    return packet.mes;
}

bool CSender::send(e_image_type image_type, IplImage *image) {
    this->log("Sending info");
    s_packet packet;
    memset((void *) & packet, 0, sizeof (packet));

    if (image_type == this->SEND_IMAGE) {
        packet.mes = s_packet::MES_IMAGE_INFO;
    } else if (image_type == this->SEND_FACE) {
        packet.mes = s_packet::MES_FACE_INFO;
    }
    packet.image_info.width = image->width;
    packet.image_info.height = image->height;
    packet.image_info.depth = image->depth;
    packet.image_info.channels = image->nChannels;
    int n_writed = write(this->sock, (char *) & packet, sizeof (packet));
    if (n_writed != sizeof (packet)) {
        this->log("Fail to send info. Data not be sended.\n");
        return false;
    }

    if (!this->check_answer()) {
        this->log("Server rejected info-packet. Image not be sended.\n");
        return false;
    }

    this->log("Sending data");
    for (int w = 0, n = -1; w != image->imageSize; w += n) {
        n = write(sock, (void *) & image->imageData[w], image->imageSize - w);
        printf("Total writed: %d\n", w);
        printf("Writed: %d\n", n);
        if (n <= 0) {
            this->log("Fail to send data\n");
            return false;
        }
    }

    if (this->check_answer()) {
        this->log("Data successfuly sended\n");
        return true;
    }

    this->log("Server rejected data\n");
    return false;
}

bool CSender::send_image(IplImage *image) {
    return this->send(this->SEND_IMAGE, image);
}

bool CSender::send_face(IplImage *image) {
    return this->send(this->SEND_FACE, image);
}
