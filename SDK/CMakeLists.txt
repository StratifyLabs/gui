cmake_minimum_required(VERSION 3.12)

project(${PROJECT_NAME}-SDK)

set(API_IS_SDK TRUE CACHE INTERNAL "Build SDK projects")

set(BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
file(MAKE_DIRECTORY ${BASE_DIRECTORY})

message(STATUS "Base directory ${BASE_DIRECTORY}")

# refresh the bootstrap code if needed
execute_process(
  COMMAND git pull
  WORKING_DIRECTORY ${BASE_DIRECTORY}/CMakeSDK
)

execute_process(
  COMMAND cmake --build . --target install
  WORKING_DIRECTORY ${BASE_DIRECTORY}/CMakeSDK/cmake_link
)

macro(sdk_add_subdirectory NAME BRANCH)
  sos_sdk_git_clone_or_pull_branch(${BASE_DIRECTORY} ${NAME} https://github.com/StratifyLabs/${NAME}.git ${BRANCH})
  add_subdirectory(${BASE_DIRECTORY}/${NAME} ${NAME} EXCLUDE_FROM_ALL)
endmacro()

include(CTest)

option(SDK_IS_TEST "Enable all SDK API tests" OFF)
message(STATUS "Enable all tests? " ${SDK_IS_TEST})
if(SDK_IS_TEST)
  message(STATUS "Enabling tests for Api, Inet, Json, and Crypto")
  set(API_IS_TEST ON CACHE INTERNAL "Enable API Test")
  set(INET_API_IS_TEST ON CACHE INTERNAL "Enable InetAPI Test")
  set(JSON_API_IS_TEST ON CACHE INTERNAL "Enable JsonAPI Test")
  set(CRYPTO_API_IS_TEST ON CACHE INTERNAL "Enable CryptoAPI Test")
endif()


set(LODEPNG_DEFINITIONS "__lodepng;LODEPNG_NO_COMPILE_ENCODER=1;LODEPNG_NO_COMPILE_CPP=1;LODEPNG_NO_COMPILE_DISK=1" CACHE INTERNAL "Defintions for compiling lodepng")

set(SOS_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/config CACHE INTERNAL "StratifyOS config directory")
set(LWIP_STRATIFYOS_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/StratifyOS/include
  CACHE INTERNAL "LWIP StratifyOS INCLUDE PATHS")

sdk_add_subdirectory(API main)
include(${BASE_DIRECTORY}/API/libraries/API.cmake)

set(LVGL_API_IS_QT_SIMULATOR OFF CACHE INTERNAL "Enable QT Simulator")
set(LVGL_QT_PATH "/Users/tgil/Qt/6.1.0/clang_64/lib/cmake" CACHE INTERNAL "Enable QT Simulator")
set(LVGL_NO_STRATIFY_OS ON CACHE INTERNAL "No dependecies on Stratify OS")
set(LVGL_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/config CACHE INTERNAL "LVGL config path")

set(LWIP_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/config CACHE INTERNAL "LWIP config path")
set(MBEDTLS_CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/config/mbedtls/config.h CACHE INTERNAL "MBEDTLS config file")

add_subdirectory(dependencies/CMakeSDK CMakeSDK)

if(SOS_IS_ARM)
  sdk_add_subdirectory(StratifyOS main)
  sdk_add_subdirectory(SosAPI v1.2)
  sdk_add_subdirectory(HalAPI v1.2)
endif()

sdk_add_subdirectory(JsonAPI v1.2)
sdk_add_subdirectory(InetAPI v1.2)
sdk_add_subdirectory(CryptoAPI v1.2)
sdk_add_subdirectory(CloudAPI v1.1)

#These are still in pre-release
if(LINUX_HAL_API)
  sdk_add_subdirectory(LinuxHalAPI main)
endif()
sdk_add_subdirectory(WindowAPI main)
sdk_add_subdirectory(LvglAPI main)
sdk_add_subdirectory(DesignAPI main)






