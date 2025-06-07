cmake_minimum_required(VERSION 3.21)

PROJECT(dmstringtest)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMSTRINGTEST_VERSION_MAJOR "1")
SET(DMSTRINGTEST_VERSION_MINOR "0")
SET(DMSTRINGTEST_VERSION_PATCH "1")
SET(DMSTRINGTEST_VERSION "${DMSTRINGTEST_VERSION_MAJOR}.${DMSTRINGTEST_VERSION_MINOR}.${DMSTRINGTEST_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMSTRINGTEST_VERSION}")

OPTION(USE_DMSTRINGTEST "use dmstringtest" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmstringtest_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmstringtest_config.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ModuleImportAll("thirdparty")

LibImport("libdmstringtest" "src/libdmstringtest")

if(PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "libdmstringtest;dmtest;dmstring")
endif()

AddInstall("libdmstringtest" "${CMAKE_CURRENT_SOURCE_DIR}/include")
