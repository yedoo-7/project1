#include <iostream>
#include "vehicle_prediction.h"

int main()
{
    State truck1;
    truck1.x=0;
    truck1.y=0;
    truck1.theta=M_PI_2;//y轴正向
    truck1.length=10;
    truck1.width=5;
    truck1.v=10;
    State truck2={0,-5,M_PI_2,10,5,10};
    std::cout << truck1.length << std::endl;
    std::cout << truck1.theta << std::endl;
    State states=PredictSafetyState(truck1,truck2);
    std::cout << truck2.length << std::endl;
    std::cout << truck2.theta << std::endl;
    std::cout << "坐标是"<<states.x <<","<<states.y<< std::endl;
    std::cout << states.length << std::endl;
    return 0;
}