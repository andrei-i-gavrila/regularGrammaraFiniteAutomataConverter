cmake_minimum_required(VERSION 3.10)
project(REFALftc)

set(CMAKE_CXX_STANDARD 17)

add_executable(REFALftc main.cpp Grammar.h FiniteAutomata.h Converter.h streamOps.h)
