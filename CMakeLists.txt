cmake_minimum_required(VERSION 3.19.2)
set(CMAKE_CXX_STANDARD 14)

project(Football-Manager-2K20)

#location of project's files
include_directories(${CMAKE_SOURCE_DIR})

#directory for excutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

#compiling & list the header and source files in the solution explorer
file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

#this will allow us to install an .exe file of the project
install(TARGETS ${PROJECT_NAME} DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
install(FILES Main.cpp DESTINATION src)          #${CMAKE_INSTALL_PREFIX}/src