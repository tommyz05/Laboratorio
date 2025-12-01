//
// Created by tommy on 07/11/25.
//

#ifndef PROGETTO_ACTIVITY_H
#define PROGETTO_ACTIVITY_H
#include <stdexcept>
#include <string>

class Activity
{
    public:
        Activity(std::string const &descr, int const &sHour,int const &sMin, int const &eHour, int const &eMin): description(descr),startHour(sHour),startMin(sMin),endHour(eHour),endMin(eMin)
        {
            if (sHour > eHour || (sHour == eHour && sMin > eMin) )
                throw std::invalid_argument( "Start time must be before end time");
            if (sHour < 0 || sMin < 0 || eHour < 0 || eMin < 0)
                throw std::invalid_argument( "Time must be positive");
        }
        virtual ~Activity() = default;
        std::string getDescription() const {return description;}
        int getStartHour() const {return startHour;}
        int getStartMin() const {return startMin;}
        int getEndHour() const {return endHour;}
        int getEndMin() const {return endMin;}
    protected:
        std::string description;
        int startHour, startMin, endHour, endMin;
};
#endif //PROGETTO_ACTIVITY_H