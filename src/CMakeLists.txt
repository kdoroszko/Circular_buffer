set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_run main.cpp circular_buffer.hpp)

add_library(${BINARY}_lib STATIC main.cpp circular_buffer.hpp)
