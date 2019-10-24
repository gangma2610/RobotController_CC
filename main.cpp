#include <iostream>
#include "RobotController.h"
using namespace std;

int main() {
    cout << "connecting..." << endl;
    RobotController controller;

    // 路点运动测试
    vector< vector<double> > trajectoryPoints;
    trajectoryPoints.push_back({0.1,0.0,0.0,0.0,0.1,0.0});
    trajectoryPoints.push_back({0.00, -14.06, 10.6, -4.24, 0, 83.56});
    trajectoryPoints.push_back({-5.24, 29.8278, -2.8457, -2.5016, 42.3023, -5.4144});
    trajectoryPoints.push_back({-5.2401, 29.8278, -13.636, 22.7127, 33.4995, -19.779});
    trajectoryPoints.push_back({-5.2402, 19.4049, -13.635, 33.8398, -11.159, -19.779});
    trajectoryPoints.push_back({-1.682, 15.8749, 2.71824, 40.6639, 5.90515, -35.315});
    trajectoryPoints.push_back({3.90351, 12.5561, -2.8333, 37.8003, -0.1391, -43.919});
    trajectoryPoints.push_back({5.08003, 18.9835, -1.0944, 33.2095, 8.09205, -41.616});

    controller.MoveByJointTrajectory(trajectoryPoints);
    // 获取笛卡尔坐标
    //vector<double> carpos = controller.GetCurrentCarPos();
    /*
    for (int i = 0; i < 6; ++i) {
        cout << carpos[i] << " ";
    }
    cout << endl;
     */

    // 获取关节坐标
    //vector<double> axispos = controller.GetCurrentAxisPos();
    /*
    for (int i = 0; i < 6; ++i) {
        cout << axispos[i] << " ";
    }
    cout << endl;
     */

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