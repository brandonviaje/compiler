cmake_minimum_required(VERSION 3.20)

project(semp)

set(CMAX_CXX_STANDARD_20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(semp
  src/main.cpp
  src/lexer.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  lexer_test
  tests/lexer_test.cpp
)

target_link_libraries(
  lexer_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lexer_test)