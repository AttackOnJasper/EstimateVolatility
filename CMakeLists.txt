cmake_minimum_required(VERSION 3.6)
project(StockVolatility)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp OptionFunction.cpp
    Makefile)

add_executable(StockVolatility ${SOURCE_FILES})