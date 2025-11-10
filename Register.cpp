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

