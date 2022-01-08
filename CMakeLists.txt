cmake_minimum_required(VERSION 3.21)
project(ControlAgent)

set(CMAKE_CXX_STANDARD 17)

add_executable(ControlAgent stdafx.h main.cpp Network.cpp Network.h main.cpp Status.cpp Status.h Threading.h)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
