cmake_minimum_required(VERSION 3.0.0)
project(escultor VERSION 0.1.0 LANGUAGES C CXX)

add_executable(escultor 
                cutbox.cpp
                cutellipsoid.cpp
                cutsphere.cpp
                cutvoxel.cpp
                figurageometrica.cpp 
                main.cpp 
                putbox.cpp 
                putellisoid.cpp 
                putsphere.cpp 
                putvoxel.cpp 
                sculptor.cpp
                readtxt.cpp
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
