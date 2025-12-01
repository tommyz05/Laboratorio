//
// Created by tommy on 07/11/25.
//

#ifndef PROGETTO_SPORT_H
#define PROGETTO_SPORT_H
#include "Activity.h"

class Sport:public Activity
{
public:
    Sport(std::string const &descr, int const &sHour, int const &sMin, int const &eHour, int const &eMin, int const &cal): Activity(descr,sHour,sMin,eHour,eMin),calories(cal)
    {
        if (cal < 0)
            throw std::invalid_argument( "Calories must be positive");
    }
    int getCalories() const {return calories;}
private:
    int calories;
};
#endif //PROGETTO_SPORT_H