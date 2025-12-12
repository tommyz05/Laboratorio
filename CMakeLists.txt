cmake_minimum_required(VERSION 4.0)
project(Progetto)

set(CMAKE_CXX_STANDARD 20)


set(SOURCE_FILES Activity.h Sport.h Register.h Register.cpp)
add_library(core ${SOURCE_FILES})
add_subdirectory(googletests)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
add_executable(Progetto main.cpp
        Activity.h
        Sport.h
        Register.h
        Register.cpp
        Window.h
        Window.cpp)
target_link_libraries(${PROJECT_NAME} core ${wxWidgets_LIBRARIES})

