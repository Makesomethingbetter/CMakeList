#cmake_minimum_required(VERSION 3.12)
#project(untitled C)
#
#set(CMAKE_C_STANDARD 99)
#
#add_executable(untitled main.c main.c)
#cmake_minimum_required(VERSION 3.12)
#project(testGTK C)
#
#set(CMAKE_C_STANDARD 99)
#
#add_executable(testGTK main.c)


# Set the name and the supported language of the project
PROJECT(untitled C)
# Set the minimum version of cmake required to build this project
CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from hello.c
ADD_EXECUTABLE(untitled main.c main.c sendMail.c sendMail.h displayRcMail.c displayRcMail.h disPlayWindow.c disPlayWindow.h set_font_size.c set_font_size.h initialize.c initialize.h logcheck.c logcheck.h regist.c regist.h)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(untitled ${GTK3_LIBRARIES})