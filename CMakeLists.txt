cmake_minimum_required(VERSION 3.0)
# Project info
project(im)
set(im_VERSION_MAJOR 0)
set(im_VERSION_MINOR 1)

# Load modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

find_package(Boost REQUIRED COMPONENTS filesystem system)

BISON_TARGET(imparser src/imparser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(imlexer src/imlexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp COMPILE_FLAGS "-+ --header")
ADD_FLEX_BISON_DEPENDENCY(imlexer imparser)

include_directories("${CMAKE_CURRENT_BINARY_DIR}" "include")

set(CMAKE_CXX_FLAGS "-g -Wall --std=c++14")

set(IM_SOURCES 
    src/imdriver.cpp
    src/main.cpp
    src/ast/tree.cpp
    src/ast/tree_list.cpp
    src/ast/exec.cpp
    src/ast/expr.cpp
    ${FLEX_imlexer_OUTPUTS} 
    ${BISON_imparser_OUTPUTS})

add_executable(im ${IM_SOURCES})
target_link_libraries(im "${Boost_LIBRARIES}")