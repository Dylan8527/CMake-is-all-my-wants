cmake_minimum_required(VERSION 3.12)
project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "A cmake template project")

##--------------------- Version file -------------------------------------##
configure_file(src/c/cmake_template_version.h.in "${PROJECT_SOURCE_DIR}/src/c/cmake_template_version.h")

# Specified the language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

##--------------------- Compile options ----------------------------------##
# Configure compile options 
add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

# Set build type
set(CMAKE_BUILD_TYPE Debug) # Release, RelWithDebInfo, Debug
                            # Use 'cmake -DCMAKE_BUILD_TYPE=Debug' better
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Compile options for Debug variant
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -O0")

# Compile options for Release variant
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

message(STATUS "Compile options for c: ${CMAKE_C_FLAGS}")
message(STATUS "Compile options for c++: ${CMAKE_CXX_FLAGS}")

##--------------------- Global Macros ------------------------------------##
add_definitions(-DDEBUG -DDYLANOFFICIAL)

##--------------------- Include directories ------------------------------##
include_directories(src/c)

##--------------------- Source files -------------------------------------##
file(GLOB_RECURSE MATH_LIB_SRC
        src/c/*.c
    )
add_library(math STATIC ${MATH_LIB_SRC})

##--------------------- Build executable ---------------------------------##
add_executable(demo src/c/main.c)
target_link_libraries(demo PRIVATE math)

##--------------------- Install headers ----------------------------------##
file(GLOB_RECURSE MATH_LIB_HEADERS src/c/math/*.h)
install(FILES ${MATH_LIB_HEADERS} DESTINATION include/math)
install(TARGETS math demo
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)

##--------------------- Package target -----------------------------------##
include(CPack)
set(CPACK_GENERATOR "ZIP")
set(CPACK_SET_DESTDIR ON)
set(CPACK_INSTALL_PREFIX "")
set(CPACK_PACKAGE_NAME "CMakeTemplate")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})


