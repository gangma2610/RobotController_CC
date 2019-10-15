//////////////////////////////////////////////////////////
// @Project:        RobotController_CC
// @File:           RobotController.cpp
// @Author:         Louis
// @CreateTime:     2019-10-15 16:48
// @Description:    
//////////////////////////////////////////////////////////

#include "RobotController.h"
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>



RobotController::RobotController()
{
    memset(m_buffer, 0, sizeof(m_buffer));
    m_sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(this->m_sockfd == -1) // Socket failed!
    {
        PrintLog("Socket Error!");
        exit(-1);
    }

    struct sockaddr_in addr;
    addr.sin_family = PF_INET;
    addr.sin_port = htons(9876); //Port

    addr.sin_addr.s_addr = inet_addr("192.168.39.220"); //Ip
    int res = connect(m_sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(res == -1)  // connect failed!
    {
        PrintLog("Connect Error!");
        exit(-1);
    }

    this->SendOK();




}
RobotController::~RobotController()
{
    close(m_sockfd);
    PrintLog("connect is closed.");
}

void RobotController::PrintLog(const std::string& log) const
{
    std::cout << log << std::endl;
}

//
void RobotController::SendOK()
{
    //write(m_sockfd, "OK", 2);
    Send("OK");
    //char ret[3] = {};
    //read(m_sockfd, ret, sizeof(ret));
    std::string ret = Receive();
    //PrintLog("ret = " + ret);
    //if (!strcmp(ret, "OK"))
    if(ret == "OK")
    {
        PrintLog("Ok, connect success!");
    }
    else
    {
        PrintLog("Send Ok Error!");
        exit((-1));
    }
}

void RobotController::MoveByCar(const std::vector<double> &carPos) const
{
    PrintLog("CMD = 1 : move by car");
    memset((void*)m_buffer, 0, sizeof(m_buffer));
    sprintf((char*)m_buffer, "1,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,", carPos[0], carPos[1], carPos[2], carPos[3], carPos[4], carPos[5]);
    std::string msg(m_buffer);
    PrintLog("car pos =  " + msg);
    Send(msg);
}

void RobotController::MoveCarByOffset(const std::vector<double> & offset) const
{
    PrintLog("CMD = 3 : move by offset in car");
    memset((void*)m_buffer, 0, sizeof(m_buffer));
    sprintf((char*)m_buffer, "3,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,", offset[0], offset[1], offset[2], offset[3], offset[4], offset[5]);
    std::string msg(m_buffer);
    PrintLog("car offset =  " + msg);
    Send(msg);
}

std::vector<double> RobotController::GetCurrentCarPos() const
{
    PrintLog("CMD=7: Get current car position...");
    Send("7,");
    std::vector<double> pos;
    for (int i = 0; i < 6; ++i) {
        std::string data = Receive();
        std::cout << data << std::endl;
        pos.push_back(String2Double(data));
    }
}

void RobotController::MoveByAxis(const std::vector<double> &axisPos) const
{
    PrintLog("CMD = 0 : move by axis");
    memset((void*)m_buffer, 0, sizeof(m_buffer));
    sprintf((char*)m_buffer, "0,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,", axisPos[0], axisPos[1], axisPos[2], axisPos[3], axisPos[4], axisPos[5]);
    std::string msg(m_buffer);
    PrintLog("car pos =  " + msg);
    Send(msg);
}

void RobotController::MoveAxisByOffset(const std::vector<double> &offset) const
{
    PrintLog("CMD = 2 : move by offset in axis");
    memset((void*)m_buffer, 0, sizeof(m_buffer));
    sprintf((char*)m_buffer, "2,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,", offset[0], offset[1], offset[2], offset[3], offset[4], offset[5]);
    std::string msg(m_buffer);
    PrintLog("axis offset =  " + msg);
    Send(msg);
}

std::vector<double> RobotController::GetCurrentAxisPos() const
{
    PrintLog("CMD=6: Get current axis position...");
    Send("6,");
    std::vector<double> pos;
    for (int i = 1; i <= 6; ++i) {
        std::string data = Receive();
        std::cout << data << std::endl;
        pos.push_back(String2Double(data));
    }
}

void RobotController::OpenPaw(int pulseCnt) const
{
    PrintLog("CMD = 4 : open paw, pulse_cnt = " + std::to_string(pulseCnt));
    std::string msg = "4," + std::to_string(pulseCnt) + ",";
    Send(msg);
}

void RobotController::ClosePaw(int pulseCnt) const
{
    PrintLog("CMD = 5 : close paw, pulse_cnt = " + std::to_string(pulseCnt));
    std::string msg = "5," + std::to_string(pulseCnt) + ",";
    Send(msg);
}

void RobotController::SetSpeed(int rate)
{
    PrintLog("CMD = 8 : set speed, rate = " + std::to_string(rate));
    std::string msg = "8," + std::to_string(rate) + ",";
    Send(msg);
}

void RobotController::Send(const std::string& s) const
{
    write(m_sockfd, s.c_str(), s.length());
}


std::string RobotController::Receive() const
{
    memset((void*)m_buffer, 0, sizeof(m_buffer));
    read(m_sockfd, (void*)m_buffer, sizeof(m_buffer));
    //printf("m_buffer = %s\n", m_buffer);
    return std::string(m_buffer);
}

double RobotController::String2Double(const std::string& s) const
{
    std::istringstream is(s.c_str());
    double data;
    is >> data;
    return data;
}
