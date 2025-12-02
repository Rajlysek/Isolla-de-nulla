cmake_minimum_required(VERSION 3.16)

project(JustaGuyOnAFarm VERSION 1.0 LANGUAGES CXX)

# Nastavení C++ standardu
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Hlavní zdrojové soubory hry
add_executable(JustaGuyOnAFarm
    src/main.cpp
    src/player.cpp
    src/game.cpp
    # ... sem pøidej všechny další .cpp soubory
)

# Pøidání tmxlite jako subdirectory
add_subdirectory(external/tmxlite)

# Linkujeme tmxlite k projektu
target_link_libraries(JustaGuyOnAFarm PRIVATE tmxlite-s)

# Pøidání include cest
target_include_directories(JustaGuyOnAFarm PRIVATE
    include
    external/tmxlite/include
)