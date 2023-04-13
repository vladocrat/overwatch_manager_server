cmake_minimum_required(VERSION 3.14)

project(overwatch_manager_server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

add_executable(overwatch_manager_server
  main.cpp
  tcpserver.h tcpserver.cpp
  pendingconnection.h pendingconnection.cpp
  connection.h connection.cpp
  protocol.h
  configurer.h configurer.cpp
  config.h config.cpp
  networkconfig.h networkconfig.cpp
  dbconfig.h dbconfig.cpp
)

target_link_libraries(overwatch_manager_server
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS overwatch_manager_server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
