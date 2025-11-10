//
// Created by tommy on 08/11/25.
//
#include "Register.h"

#include <iostream>
#include <ostream>

#include "Sport.h"

void Register::add(std::string const &day,std::shared_ptr<Activity> const &a)
{
    if (day!="Monday" && day!="Tuesday" && day!="Wednesday" && day!="Thursday" && day!="Friday" && day!="Saturday" && day!="Sunday")
        throw std::invalid_argument( "Day must be Monday, Tuesday, Wednesday, Thursday, Friday, Saturday or Sunday");
    registry.insert({day,a});
}
void Register::remove(std::string const &day,std::shared_ptr<Activity> const &a)
{
    for(auto it = registry.begin();it!=registry.end();it++)
    {
        if(it->first==day)
        {
            if(it->second==a)
            {
                registry.erase(it);
                std::cout<<"activity removed"<<std::endl;
            }
        }
    }
}
void Register::print(std::string const &day) const
{
    for(auto it = registry.begin();it!=registry.end();it++)
    {
        std::cout<<"activity done on"<<day<<": "<<std::endl;
        if(it->first==day)
        {
            std::cout<<it->second->getDescription()<<std::endl;
            std::cout<<it->second->getStartHour()<<":"<<it->second->getStartMin()<<" - "<<it->second->getEndHour()<<":"<<it->second->getEndMin()<<std::endl;
            if(auto sport=std::dynamic_pointer_cast<Sport>(it->second))
                std::cout<<"Calories: "<<sport->getCalories()<<std::endl;
        }
    }
}

