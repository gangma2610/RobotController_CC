#include <iostream>
#include "RobotController.h"
using namespace std;

int main() {
    cout << "connecting..." << endl;
    RobotController controller;
    // 获取笛卡尔坐标
    //controller.GetCurrentCarPos();

    // 获取关节坐标
    //controller.GetCurrentAxisPos();

    // 笛卡尔运动
    //vector<double> initPos{400.1875, 100.232, 510.003, 180.00032, 0.0003, 0};
    //controller.MoveByCar(initPos);

    // 关节运动
    //vector<double> axisPos{0, 0, 0, 0, 0, 0};
    //controller.MoveByAxis(axisPos);

    // 笛卡尔偏移运动
    //vector<double> offsetCar{0, -100, 0, 0, 0.000, 0.0000};
    //controller.MoveCarByOffset(offsetCar);

    // 关节偏移运动
    //vector<double> offsetAxis{0, 0, 0, 0,20, 0};
    //controller.MoveAxisByOffset(offsetAxis);

    // 手抓闭合
    //controller.ClosePaw();

    // 手抓张开
    //controller.OpenPaw();
    return 0;
}