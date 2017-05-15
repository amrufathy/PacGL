cmake_minimum_required(VERSION 3.6)
project(PacGL)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp GameObjects/Maze.cpp GameObjects/Maze.h GameObjects/IDrawable.h GameObjects/Tile.cpp
        GameObjects/Tile.h GameObjects/Pacman.cpp GameObjects/Pacman.h GameObjects/definitions.h GameObjects/IMoveable.h
        GameObjects/Monster.cpp GameObjects/Monster.h)

add_executable(PacGL ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Threads REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})