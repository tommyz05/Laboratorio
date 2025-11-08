//
// Created by tommy on 08/11/25.
//
#include "Register.h"

#include <iostream>
#include <ostream>

void Register::add(std::string const &day,std::shared_ptr<Activity> const &a)
{
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
        }
    }
}

