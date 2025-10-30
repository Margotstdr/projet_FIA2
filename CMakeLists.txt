cmake_minimum_required(VERSION 4.0)
project(projet_FIA2 C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_FIA2 main.c
        initialisation.c
        initialisation.h
        pilotes.c
        pilotes.h
        ecuries.c
        ecuries.h
        classement.c
        classement.h
        grandprix.c
        grandprix.h)
