cmake_minimum_required (VERSION 3.12)

set(SDK_DIRECTORY ${CMAKE_SOURCE_DIR}/SDK)
set(CMSDK_LOCAL_PATH ${SDK_DIRECTORY}/local)

set(CMSDK_MACOS_VERSION_MIN 10.14 CACHE INTERNAL "Override default min OS for MacOS")

set(CMAKE_MODULE_PATH ${CMSDK_LOCAL_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_MODULE_PATH}/cmsdk-toolchain.cmake)
include(cmsdk)

set(GUI_PROJECT_VERSION 0.2 CACHE INTERNAL "gui application version")
project(gui
	LANGUAGES CXX C
	VERSION ${GUI_PROJECT_VERSION}
	)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -D__SANITIZE_THREAD__=0")

include(CTest)

set(CMSDK_PULL_TARGET pull)
option(LINUX_HAL_API "use the raspberry/linux hal API" OFF)

add_custom_target(pull
	COMMAND git pull
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(SDK SDK EXCLUDE_FROM_ALL)
add_subdirectory(gui)

