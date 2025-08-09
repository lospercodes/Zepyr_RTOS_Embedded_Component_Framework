cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(app CXX ASM)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-fexceptions)

include_directories( src/thread_component src/event src/application src/interface src/drivers src/components)

# Add our main executable
FILE(GLOB app_sources src/*.cpp 
                      src/thread_component/*.cpp 
                      src/thread_component/*.hpp
                      src/event/*hpp
                      src/application/*cpp
                      src/application/*.hpp
                      src/interface/*.cpp
                      src/interface/*.hpp
                      src/drivers/*.hpp
                      src/drivers/*.cpp
                      src/components/*.cpp
                      src/components/*.hpp)

target_sources(app PRIVATE ${app_sources}) 
