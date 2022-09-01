set(SDK_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SDK)
set(DEPENDENCIES_DIRECTORY ${SDK_DIRECTORY}/dependencies)

file(MAKE_DIRECTORY ${DEPENDENCIES_DIRECTORY})
file(REMOVE_RECURSE ${DEPENDENCIES_DIRECTORY}/CMakeSDK)

message(STATUS "cloning CMakeSDK project")

execute_process(
  COMMAND git clone --branch v2.0 https://github.com/StratifyLabs/CMakeSDK.git
  WORKING_DIRECTORY ${DEPENDENCIES_DIRECTORY}
)

option(IS_ARM_CROSS_COMPILE "Setup the system to cross compile to Stratify OS" OFF)

# This is used on the CI server, but can be run locally as well
# This is currently NOT used with IS_ARM_CROSS_COMPILE=ON
option(IS_BUILD_AND_TEST "Build and run the API tests" OFF)

if(IS_ARM_CROSS_COMPILE)
  set(BOOTSTRAP_SCRIPT sos-bootstrap)
else()
  set(BOOTSTRAP_SCRIPT bootstrap)
endif()

message(STATUS "Running ${BOOTSTRAP_SCRIPT} using SDK path: ${SDK_DIRECTORY}")

execute_process(
  COMMAND cmake -DCMSDK_SDK_PATH=${SDK_DIRECTORY} -P ${DEPENDENCIES_DIRECTORY}/CMakeSDK/scripts/${BOOTSTRAP_SCRIPT}.cmake
)



