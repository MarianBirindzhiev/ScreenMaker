# Sample static library
add_library(screenmaker STATIC)

set_target_properties(screenmaker PROPERTIES OUTPUT_NAME "maker")

target_sources(
    screenmaker

    PRIVATE
        "Factory.cpp"
        "Factory.h"
        "Helper.cpp"
        "Helper.h"
        "LEDVideoWall.cpp"
        "LEDVideoWall.h"
        "Screen.h"
        "TV.cpp"
        "TV.h"
)

add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "app")

target_link_libraries(
    application
    PRIVATE
        screenmaker
    
)

target_sources(
    application
    PRIVATE
        "application.cpp"
)