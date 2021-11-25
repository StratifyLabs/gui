cmake_minimum_required (VERSION 3.12)

set(SDK_DIRECTORY ${CMAKE_SOURCE_DIR}/SDK)
set(SOS_SDK_PATH ${SDK_DIRECTORY}/StratifyLabs-SDK)

set(CMAKE_MODULE_PATH ${SOS_SDK_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_MODULE_PATH}/sos-toolchain.cmake)
include(sos-sdk)

set(CLI_PROJECT_VERSION 0.1 CACHE INTERNAL "gui application version")
project(gui
	LANGUAGES CXX C
	VERSION ${CLI_PROJECT_VERSION}
	)

include(CTest)

set(SOS_SDK_PULL_TARGET pull)

add_custom_target(pull
	COMMAND git pull
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(SDK SDK EXCLUDE_FROM_ALL)
add_subdirectory(gui)
add_subdirectory(fonts)
#add_subdirectory(tests)

