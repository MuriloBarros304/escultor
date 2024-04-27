cmake_minimum_required(VERSION 3.0.0)
project(Escultor VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Escultor main.cpp
              sculptor.cpp
              voxel.h
              sculptor.h
              )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
