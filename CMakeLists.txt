cmake_minimum_required(VERSION 3.28)
project(agar_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -- SFML

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(SFML)

# -- Boost

set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/boost_1_92_0")

# -- Общие настройки
add_library(agar_common INTERFACE)
target_include_directories(agar_common INTERFACE "${CMAKE_SOURCE_DIR}/common")
target_compile_definitions(agar_common INTERFACE
    BOOST_ERROR_CODE_HEADER_ONLY
)

# -- Сервер

add_executable(agar_server
    server/main.cpp
    server/udp_server.cpp
    server/tcp_session.cpp
)
target_include_directories(agar_server PRIVATE 
    "${CMAKE_SOURCE_DIR}/server" 
    ${BOOST_ROOT}
)
find_package(Threads REQUIRED)
target_link_libraries(agar_server PRIVATE agar_common Threads::Threads)

# -- Клиент

add_executable(agar_client client/main.cpp client/client.cpp)
target_include_directories(agar_client PRIVATE "${CMAKE_SOURCE_DIR}/client")
target_link_libraries(agar_client PRIVATE
    agar_common
    SFML::Graphics
    SFML::Network
    SFML::Window
    SFML::System
)
