cmake_minimum_required(VERSION 3.1.0)

project(chess_gui)

set(CMAKE_CXX_STANDARD 17)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
# set(CMAKE_AUTOUIC ON)
# Create code from a list of Qt resource files
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Widgets Multimedia)

# Populate a CMake variable with the sources
set(chess_SRCS
    main.cpp
    frame.cpp
    mainwindow.cpp
    piece.cpp
	pawn.cpp
	knight.cpp
	bishop.cpp
	rook.cpp
	queen.cpp
	king.cpp
	square.cpp
    res.qrc
)

set(chess_HDRS
    frame.h
    mainwindow.h
	pawn.h
	knight.h
	bishop.h
	rook.h
	queen.h
	king.h
    piece.h
	square.h
)

set(chess_LIBS
    Qt5::Widgets)

add_executable(chess WIN32 ${chess_SRCS} ${chess_HDRS})

target_link_libraries(chess ${chess_LIBS})