#include <iostream>
#include "RobotController.h"
using namespace std;

int main() {
    cout << "connecting..." << endl;
    RobotController controller;
    //controller.GetCurrentCarPos();
    //controller.GetCurrentAxisPos();
    vector<double> vpos{400.1875, 100.232, 510.003, 180.00032, 0.0003, 0};
    controller.MoveByCar(vpos);
    //cout << "success." << endl;
    //controller.ClosePaw();
    //controller.OpenPaw();
    return 0;
}