cmake_minimum_required(VERSION 3.28)
project(TrabalhoPraticoAEDs1 C)

set(CMAKE_C_STANDARD 17)

add_executable(TrabalhoPraticoAEDs1 main.c
        ingrediente.c
        ingrediente.h
        pizza.c
        pizza.h
        basics.c
        basics.h
        venda.c
        venda.h)
