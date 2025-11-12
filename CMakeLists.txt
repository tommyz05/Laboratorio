cmake_minimum_required(VERSION 4.0)
project(Progetto)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
add_executable(Progetto main.cpp
        Activity.h
        Sport.h
        Register.h
        Register.cpp
        Window.h
        Window.cpp)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


