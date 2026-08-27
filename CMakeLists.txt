cmake_minimum_required(VERSION 4.3)
project(modular_CLI_inventory C)

set(CMAKE_C_STANDARD 11)

add_executable(modular_CLI_inventory
        main.c
        inventory.h
        inventory.c)
