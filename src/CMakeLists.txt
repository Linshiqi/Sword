# CMakeList.txt : CMake project for Sword, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Sword")

MESSAGE("Identifying the OS...")
if(WIN32)
	MESSAGE("This is Windows.")
	message(STATUS "Setting MSVC flags")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
elseif(APPLE)
	MESSAGE("This is MacOS.")
elseif(UNIX)
	MESSAGE("This is Linux.")
	SET(CMAKE_BUILD_TYPE "Debug")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInf
	SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项
	SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

add_subdirectory("p1")
add_subdirectory("test")



# TODO: Add tests and install targets if needed.
