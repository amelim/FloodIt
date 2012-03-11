project(FloodIt)

cmake_minimum_required(VERSION 2.6)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source build not allowed.")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

#GTSAM Requirements
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(GTSAM REQUIRED)
find_package(GTSAM2 REQUIRED)
#find_package(CppUnitLite REQUIRED)
find_package(Boost 1.40 COMPONENTS serialization REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIR}
    ${GTSAM_INCLUDE_DIR}
    ${GTSAM2_INCLUDE_DIR}
    ${CPPUNITLITE_INCLUDE_DIR})

link_directories(
    ${CMAKE_SOURCE_DIR}/lib
    ${GTSAM_LIBS}
    ${GTSAM2_LIBS})

add_subdirectory(src)
