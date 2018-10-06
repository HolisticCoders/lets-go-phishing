cmake_minimum_required (VERSION 3.0)
project (lets-go-phishing)

include_directories(include)
set(CMAKE_CXX_STANDARD 17)
SET(GCC_COMPILE_FLAGS "-lraylib -lGL -lm -lpthread -ldl -lrt -lX11")
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(lets-go-phishing ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib)
