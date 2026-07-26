cmake_minimum_required(VERSION 3.21)
project(ROMImporterMod)

find_package(Geode REQUIRED)

add_geode_mod(ROMImporterMod
    MAIN main.cpp
)
