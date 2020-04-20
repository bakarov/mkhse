cmake_minimum_required(VERSION 3.15)
project(beam)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT "/usr/local/boost/include")

find_package(Boost 1.72.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} src/den/beam.cpp src/den/beam.h src/test/beam_test.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
endif()
