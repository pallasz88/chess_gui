cmake_minimum_required(VERSION 3.1.0)

set(generator_HDRS
      include/adapter/adapter.h
)

set(generator_SRCS
      src/adapter/adapter.cpp
)

include_directories(include/adapter)

add_library(generator SHARED ${generator_HDRS} ${generator_SRCS})