# Executable target for the unit tests
add_executable(unit-tests)

target_link_libraries(
    unit-tests
    PRIVATE
        screenmaker
        Catch2::Catch2WithMain
)

target_sources(
    unit-tests
    PRIVATE
        "test-tv.cpp"
        "test-aspects.cpp"
        "test-freeform.cpp"
)

# Automatically register all tests
catch_discover_tests(unit-tests)
