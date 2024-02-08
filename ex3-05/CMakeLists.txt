cmake_minimum_required(VERSION 3.5)

project(exam)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBNAME newton)

# Create the library
add_library(${LIBNAME} STATIC lib/newton.cpp)

# Add some compile options
target_compile_options(${LIBNAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    # -Werror
)

# Executable main
add_executable(main main.cpp)
target_link_libraries(main ${LIBNAME})


# Add the pybind requirement  COMMENTED BY DEFAULT
find_package(Python 3 COMPONENTS Interpreter Development REQUIRED)  # Note 3 or 3.9
find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(newtonsolver bindings/lib_bindings.cpp)  # exam_lib must match in lib_bindings.cpp
target_link_libraries(newtonsolver PRIVATE ${LIBNAME})