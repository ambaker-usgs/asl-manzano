cmake_minimum_required(VERSION 3.0)
project(mzn_config)

# CMake include guard
if(mzn_config_included)
  return()
endif(mzn_config_included)
set(mzn_config_included true)

message("\n###### config(manzano) #######")

set(DIR_MZN ${CMAKE_CURRENT_LIST_DIR})
message("Manzano code directory:" ${DIR_MZN})

# ----- CHECK FLOAT SIZE ----- #
# this requirement comes from the message serialization inside commands
include(CheckTypeSize)
check_type_size("float" SIZEOF_FLOAT)
message("float size: " ${SIZEOF_FLOAT})
if(NOT ${SIZEOF_FLOAT} EQUAL 4)
    message(FATAL_ERROR "*** Manzano library written for 32-bit float type. ***")
endif()

check_type_size("double" SIZEOF_DOUBLE)
message("double size: " ${SIZEOF_DOUBLE})
if(NOT ${SIZEOF_DOUBLE} EQUAL 8)
    message(FATAL_ERROR "*** Manzano library written for 64-bit double type. ***")
endif()

# ----- DATE LIBRARY ----- #
include_directories(${DIR_MZN}/libs/date/)

# ----- MD5 LIBRARY ----- #
include_directories(${DIR_MZN}/libs/md5/inc)
set(SOURCES_md5 ${DIR_MZN}/libs/md5/src/md5.cpp)

# ----- JSON NLOHMANN C++ LIBRARY ----- #
include_directories(${DIR_MZN}/libs/json)

# ----- SERIAL WJWWOOD C++ LIBRARY ----- #
if(UNIX AND NOT APPLE)

    set(DIR_serial ${DIR_MZN}/libs/serial)
    include_directories(${DIR_serial}/include/serial)
    include_directories(${DIR_serial}/include/serial/impl)

    set(SOURCES_serial ${DIR_serial}/src/serial.cc
                       ${DIR_serial}/src/impl/serial_unix.cc
                       ${DIR_serial}/src/impl/list_ports/list_ports_linux.cc
                       ${DIR_serial}/src/impl/list_ports/list_ports_osx.cc)

    add_library(serial_library STATIC ${SOURCES_serial})
    target_link_libraries(serial_library rt pthread)

endif()

# ----- MANZANO EXCEPTIONS ----- #
include_directories(${DIR_MZN}/exceptions/inc)
include(${DIR_MZN}/exceptions/exceptions.cmake)

# ----- COMPILER FLAGS ----- #
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthreads -Wall -Qunused-arguments -Wno-missing-braces -Wmissing-field-initializers")

# ----- CONFIGURATION VARIABLE ----- #
include_directories(${DIR_MZN})

set(k_mzn_code_DIR ${DIR_MZN})
set(k_mzn_runtime_config_DIR "${DIR_MZN}/../runtime_config")
set(k_mzn_runtime_scripts_DIR "${DIR_MZN}/../runtime_scripts")

configure_file("${DIR_MZN}/mzn_cmake_config.h.in"
               "${DIR_MZN}/mzn_cmake_config.h")
