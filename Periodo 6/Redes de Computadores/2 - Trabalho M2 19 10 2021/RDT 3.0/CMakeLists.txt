cmake_minimum_required(VERSION 3.20)
project(RDTProtocol)

set(CMAKE_CXX_STANDARD 14)

add_executable(RDTProtocol main.cpp Network/Application.h Network/Network.h Network/Transport.h Network/Clock.h Network/Log.h Network/Binary.h)
