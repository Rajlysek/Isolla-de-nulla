cmake_minimum_required(VERSION 3.15)
project(JustaGuyOnAFarm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pøidej všechny své hlavní zdrojáky
add_executable(JustaGuyOnAFarm 
    main.cpp        # tvùj hlavní cpp soubor
    pugixml.cpp     # pugixml se kompiluje pøímo, žádné .lib
    # sem mùžeš pøidat další cpp soubory tvé hry
)


# Pøidej složku s FindTMXLite.cmake a FindPugiXML.cmake
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/External/tmxlite-master/tmxlite/cmake/modules")

# Najdi knihovny
find_package(TMXLite REQUIRED)
find_package(PugiXML REQUIRED)

# Pøidej svùj projekt
add_executable(JustaGuyOnAFarm
    main.cpp
    # pugixml.cpp pokud chceš kompilovat pøímo
)

# Link knihovny
target_link_libraries(JustaGuyOnAFarm PRIVATE TMXLite::TMXLite PugiXML::PugiXML)