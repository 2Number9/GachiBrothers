cmake_minimum_required(VERSION 3.14)

# задаем используемый стандарт С++
set(CMAKE_CXX_STANDARD 17)

# TODO: переименовать проект
project(games)

# задаем имя исполняемого файла основной программы
set(exe_name ${PROJECT_NAME})

if(WIN32 OR MSVC)
    include(FetchContent)
    FetchContent_Declare(
        PDcurses
        GIT_REPOSITORY https://github.com/dsavenko/PDCurses.git
        GIT_TAG        dfbac0fe5ef90a40a67d6b13cc7d9c69bf40a5f5
    )
    FetchContent_MakeAvailable(PDcurses)
endif()


# описываем основную библиотеку, т.е. библиотеку, содержащую все cpp-файлы, кроме main.cpp
# TODO: отредактировать список cpp-файлов
add_library(corelib OBJECT Ground.cpp Shelter.cpp Man.cpp Bullet.cpp Enemy.cpp Intro.cpp GamePlay.cpp Ending.cpp)

# описываем исполняемый файл основной программы: это main.cpp + основная библиотека
add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)

target_link_libraries(${exe_name} PDcurses)


# if(WIN32 OR MSVC)
    # target_link_libraries(${exe_name} PDcurses)
# else()
    # target_link_libraries(${exe_name} curses)
# endif()