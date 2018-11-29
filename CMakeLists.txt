cmake_minimum_required(VERSION 3.1.0)

project(chess_gui)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(movegenerator)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
# set(CMAKE_AUTOUIC ON)
# Create code from a list of Qt resource files
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Widgets)

# Populate a CMake variable with the sources
set(chess_SRCS
        src/main.cpp
        src/frame.cpp
        src/history.cpp
        src/mainwindow.cpp
        src/move.cpp
        src/piece.cpp
        src/position.cpp
        src/square.cpp
        res.qrc)

set(chess_HDRS
        include/frame.h
        include/history.h
        include/mainwindow.h
        include/move.h
        include/piece.h
        include/position.h
        include/square.h
        movegenerator/include/adapter/adapter.h)

include_directories(
        include
        movegenerator/include/adapter)

set(chess_LIBS
        Qt5::Widgets
        generator)

add_executable(chess ${chess_SRCS} ${chess_HDRS})

target_link_libraries(chess ${chess_LIBS})