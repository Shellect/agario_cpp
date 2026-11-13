cmake_minimum_required(VERSION 3.16)
project(agar_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/boost_1_92_0")
add_executable(agar_server server/main.cpp)
target_include_directories(agar_server PRIVATE ${BOOST_ROOT})
