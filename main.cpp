#include <chrono>
#include <iostream>

#include "Activity.h"
#include "Sport.h"
#include "Register.h"
int main()
{
    std::shared_ptr<Activity> attivita1;
    std::shared_ptr<Activity> attivita2;
    std::shared_ptr<Sport> sport1;
    std::shared_ptr<Sport> sport2;
    try
    {
        attivita1=std::make_shared<Activity>("Riunione di lavoro",10,0,12,30);
        attivita2=std::make_shared<Activity>("Pulizia casa",18,0,19,0);
        sport1=std::make_shared<Sport>("corsa",15,0,16,15,-300);
        sport2=std::make_shared<Sport>("nuoto",21,0,22,0,425);
    }catch (const std::invalid_argument &e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }
    Register registry;
    registry.add("Monday",attivita1);
    registry.add("Sunday",attivita2);
    registry.add("Tuesday",sport2);
    registry.add("Thursday",sport2);
    registry.add("Saturday",sport2);
    registry.add("Monday",sport1);
    registry.add("Sunday",sport1);
    return 0;
}