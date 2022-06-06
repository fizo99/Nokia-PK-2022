project(UeApplication)
cmake_minimum_required(VERSION 3.12)

aux_source_directory(. SRC_LIST)
aux_source_directory(Ports SRC_LIST)
aux_source_directory(States SRC_LIST)
aux_source_directory(Models SRC_LIST)

add_library(${PROJECT_NAME} ${SRC_LIST} States/DialNumberState.cpp States/DialNumberState.hpp States/CallState.cpp States/CallState.hpp States/InCallState.cpp States/InCallState.hpp)
target_link_libraries(${PROJECT_NAME} Common)
