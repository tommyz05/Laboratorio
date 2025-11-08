//
// Created by tommy on 08/11/25.
//

#ifndef PROGETTO_REGISTER_H
#define PROGETTO_REGISTER_H
#include "Activity.h"
#include <map>
#include <memory>
class Register
{
public:
    Register(){};
    ~Register(){};
    void add(std::string const &day, std::shared_ptr<Activity> const &a);
    void remove(std::string const &day, std::shared_ptr<Activity> const &a);
    void print(std::string const &day) const;
private:
    std::multimap<std::string, std::shared_ptr<Activity>> registry;
};
#endif //PROGETTO_REGISTER_H