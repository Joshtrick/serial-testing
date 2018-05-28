cmake_minimum_required(VERSION 2.8)

project(my_project)

include_directories(${CMAKE_SOURCE_DIR}/inc/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)

set(CMAKE_C_COMPILER g++)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)

#Add external include directories
include_directories(
  /usr/local/include/
  )

#Link external libraries diectories
link_directories(
  )

#Link external libraries
link_libraries(
  )

#Add project source codes to project
set(SRC "" CACHE INTERNAL "")
file(GLOB SRC
  src/utility/*.c src/utility/*.cpp
  src/engine/*.c src/engine/*.cpp
  src/parser/*.c src/parser/*.cpp
  )

#Create project library
if(NOT "${SRC}" STREQUAL "")
  #Create the library
  message("[CORERAIN] Creating project library")
  add_library(${PROJECT_NAME} SHARED ${SRC})
elseif("${SRC}" STREQUAL "")
  message("[CORERAIN] No internal dependencies")
endif()

#Add sub-directories of the project
add_subdirectory(test/)
