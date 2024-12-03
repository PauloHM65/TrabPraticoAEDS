cmake_minimum_required(VERSION 3.28)
project(TrabalhoPraticoAEDs1 C)

set(CMAKE_C_STANDARD 17)

add_executable(TrabalhoPraticoAEDs1 main.c
        pizza.c
        headers/pizza.h
        ingrediente.c
        headers/ingrediente.h
        basics.c
        headers/basics.h
        venda.c
        headers/venda.h)
