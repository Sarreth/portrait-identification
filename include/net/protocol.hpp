/* 
 * File:   protocol.hpp
 * Author: Alex Judge
 *
 * Created on 26 December 2010, 3:25
 */

#pragma once

/* Структура пакета, который используется для передачи
 * сообщений и параметров изображения, передаваемого
 * в следующем запросе
 */
struct s_packet {

    enum e_mes {
        MES_ERR, // Внутренняя ошибка сервера
        MES_SYN, // Начало передачи
        MES_ACK, // Успешный ответ
        MES_IMAGE_INFO, // Запрос на передачу изображения
        MES_FACE_INFO, // Запрос на передачу изображения лица
        MES_FIN, // Окончание взаимодействия
        MES_WAIT, // Сервер временно занят
        MES_BKN_IMG, // Broken image
        MES_UNK, // Неизвестная команда
        MES_UNF // Ошибка формата
    } mes;

    struct s_image_info {
        int height;
        int width;
        int depth;
        int channels;
    } image_info;
};
