cmake_minimum_required(VERSION 3.10)
project(argify VERSION 1.0 DESCRIPTION "A lightweight C library for parsing strings into arguments")

set(SOURCES
    argify.c
)

add_library(argify STATIC ${SOURCES})

target_include_directories(argify PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})