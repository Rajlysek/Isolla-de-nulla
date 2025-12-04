cmake_minimum_required(VERSION 3.16)

project(JustaGuyOnAFarm VERSION 1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------
# Pøidání všech cpp souborù z tvé složky
set(SOURCES
    JustaGuyOnAFarm/game.cpp
    JustaGuyOnAFarm/player.cpp
    JustaGuyOnAFarm/map.cpp
    JustaGuyOnAFarm/items.cpp
    JustaGuyOnAFarm/hitbox.cpp
    JustaGuyOnAFarm/functions.cpp
    JustaGuyOnAFarm/camera.cpp
    JustaGuyOnAFarm/animation.cpp

)
add_executable(JustaGuyOnAFarm ${SOURCES})

set(TMXLITE_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(TMXLITE_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
# -----------------------------------------
# Pøidání tmxlite ze source
# -----------------------------------------
add_subdirectory(external/tmxlite-master/tmxlite)

# Linkujeme tmxlite
target_link_libraries(JustaGuyOnAFarm PRIVATE tmxlite)

# -----------------------------------------
# Pøidání include cest
# -----------------------------------------
target_include_directories(JustaGuyOnAFarm PRIVATE
    external/tmxlite-master/tmxlite/include
    external/SFML/include
)
target_include_directories(JustaGuyOnAFarm PRIVATE
    ${CMAKE_SOURCE_DIR}/external/SFML/include
)
# Linkování statických knihoven SFML 3
target_link_libraries(JustaGuyOnAFarm PRIVATE
    debug     ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-system-d.lib
    optimized ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-system.lib

    debug     ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-window-d.lib
    optimized ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-window.lib

    debug     ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-graphics-d.lib
    optimized ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-graphics.lib

    debug     ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-audio-d.lib
    optimized ${CMAKE_SOURCE_DIR}/external/SFML/lib/sfml-audio.lib
)
