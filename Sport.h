//
// Created by tommy on 07/11/25.
//

#ifndef PROGETTO_SPORT_H
#define PROGETTO_SPORT_H
#include "Activity.h"

class Sport:public Activity
{
public:
    Sport(std::string const &descr, int const &sHour, int const &sMin, int const &eHour, int const &eMin, int const &cal): Activity(descr,sHour,sMin,eHour,eMin),calories(cal){}
    int getCalories() const {return calories;}
    void setCalories(int const &cal) {calories = cal;}
private:
    int calories;
};
#endif //PROGETTO_SPORT_H