cmake_minimum_required(VERSION 3.17)
project(PA14)

set(CMAKE_CXX_STANDARD 11)

add_executable(PA14 mainSchach.cpp Feld.h Figur.cpp Figur.h Koenig.h Laeufer.h Springer.h Turm.h Schachbrett.h)