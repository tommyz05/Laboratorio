//
// Created by tommy on 09/11/25.
//
#include "Window.h"
#include <vector>
#include "Sport.h"

Window::Window(const Register &reg):wxFrame(nullptr,wxID_ANY,"Activity Register",wxDefaultPosition,wxSize(400,300)), wRegister(reg)
{
    auto *mainSizer=new wxBoxSizer(wxVERTICAL);

    chooseDay=new wxChoice(this,wxID_ANY);
    activityList=new wxListBox(this,wxID_ANY);

    mainSizer->Add(new wxStaticText(this,wxID_ANY,"Day:"),0,wxALL,5);
    mainSizer->Add(chooseDay,0,wxEXPAND | wxALL,5);
    mainSizer->Add(new wxStaticText(this,wxID_ANY,"Activity:"),0,wxALL,5);
    mainSizer->Add(activityList,1,wxEXPAND | wxALL,5);

    SetSizer(mainSizer);

    const std::vector<std::string> day={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (const auto &it:day)
        chooseDay->Append(it);

    chooseDay->Bind(wxEVT_CHOICE, &Window::onDaySelected, this);
}

void Window::onDaySelected(wxCommandEvent &event)
{
    activityList->Clear();

    std::string day=chooseDay->GetStringSelection().ToStdString();

   for (auto &it:wRegister.getRegistry())
       if(it.first==day)
       {
           auto act=it.second;

           auto sportAct=std::dynamic_pointer_cast<Sport>(act);
           wxString item;
           if (sportAct)
           {
               item=wxString::Format("%02d:%02d - %02d:%02d | %s | Calories: %d",sportAct->getStartHour(), sportAct->getStartMin(),sportAct->getEndHour(), sportAct->getEndMin(),sportAct->getDescription(),sportAct->getCalories());
           }
           else
           {
               item=wxString::Format("%02d:%02d - %02d:%02d | %s",act->getStartHour(), act->getStartMin(),act->getEndHour(), act->getEndMin(),act->getDescription());
           }
           activityList->Append(item);
       }
}
