cmake_minimum_required(VERSION 3.10)

project(BlazingDarkness VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
    add_compile_definitions(_CRITICAL_SECURITY_CERTIFICATES_)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -Wpedantic)
    add_compile_definitions(POSIX)
endif()

file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/**/*.cpp"
)

set(SOURCES 
    ${SOURCES}
    "${CMAKE_SOURCE_DIR}/main.cpp"
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/src/entities
    ${CMAKE_SOURCE_DIR}/src/items
    ${CMAKE_SOURCE_DIR}/src/world
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/src/entities
    ${CMAKE_SOURCE_DIR}/src/items
    ${CMAKE_SOURCE_DIR}/src/world
)

# Link system libraries if needed
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
endif()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/main.cpp")

add_executable(common_tests
    tests/CommonTests.cpp
    ${SOURCES}
)

target_include_directories(common_tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${gtest_SOURCE_DIR}/include
)

target_link_libraries(common_tests PRIVATE 
    gtest_main
)

add_test(NAME common_tests COMMAND common_tests)
