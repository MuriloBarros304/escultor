cmake_minimum_required(VERSION 3.0.0)
project(escultor VERSION 0.1.0 LANGUAGES C CXX)

add_executable(escultor 
                src/cutbox.cpp
                src/cutellipsoid.cpp
                src/cutsphere.cpp
                src/cutvoxel.cpp
                src/figurageometrica.cpp 
                src/main.cpp 
                src/putbox.cpp 
                src/putellisoid.cpp 
                src/putsphere.cpp 
                src/putvoxel.cpp 
                src/sculptor.cpp
                src/readtxt.cpp
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
