/* 
 * File:   protocol.hpp
 * Author: Alex Judge
 *
 * Created on 26 December 2010, 3:25
 */

#pragma once

/* ��������� ������, ������� ������������ ��� ��������
 * ��������� � ���������� �����������, �������������
 * � ��������� �������
 */
struct s_packet {

    enum e_mes {
        MES_ERR, // ���������� ������ �������
        MES_SYN, // ������ ��������
        MES_ACK, // �������� �����
        MES_IMAGE_INFO, // ������ �� �������� �����������
        MES_FACE_INFO, // ������ �� �������� ����������� ����
        MES_FIN, // ��������� ��������������
        MES_WAIT, // ������ �������� �����
        MES_BKN_IMG, // Broken image
        MES_UNK, // ����������� �������
        MES_UNF // ������ �������
    } mes;

    struct s_image_info {
        int height;
        int width;
        int depth;
        int channels;
    } image_info;
};
