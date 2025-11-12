//
// Created by tommy on 09/11/25.
//

#ifndef PROGETTO_WINDOW_H
#define PROGETTO_WINDOW_H
#include <wx/wx.h>
#include "Register.h"

class Window:public wxFrame
{
public:
    explicit Window(const Register &reg);
private:
    const Register &wRegister;
    wxChoice *chooseDay;
    wxListBox *activityList;
    void onDaySelected(wxCommandEvent &event);
};
#endif //PROGETTO_WINDOW_H