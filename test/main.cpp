#include <iostream>
#include "vehicle_prediction.h"

int main()
{
    State truck1;
    truck1.x=0;
    truck1.y=0;
    truck1.theta=0;
    truck1.length=10;
    truck1.width=5;
    truck1.v=10;
    State truck2={0,0,0,10,5,10};
    std::cout << truck1.length << std::endl;
    std::cout << truck1.theta << std::endl;
    std::cout << truck2.length << std::endl;
    std::cout << truck2.theta << std::endl;
    
    return 0;
}