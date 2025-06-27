cmake_minimum_required(VERSION 3.31)
project(cpp-quarium
    VERSION 1.0.0
    DESCRIPTION "Project made to create a virtual aquarium"
    LANGUAGES CXX)

add_executable(cpp-quarium src/Main.cpp src/Aquarium.cpp src/Entities/Entity.cpp
        src/Entities/EntityContainer.inl
        lib/Entities/EntityContainer.hpp
        src/Entities/EntityContainer.cpp)