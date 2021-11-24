set(SDK_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SDK)
set(SDK_PATH ${SDK_DIRECTORY}/StratifyLabs-SDK)

file(MAKE_DIRECTORY ${SDK_PATH})
set(DEPENDENCIES_DIRECTORY ${SDK_DIRECTORY}/dependencies)
file(MAKE_DIRECTORY ${DEPENDENCIES_DIRECTORY})

file(REMOVE_RECURSE ${DEPENDENCIES_DIRECTORY}/CMakeSDK)

set(CMAKE_SDK_DIRECTORY ${DEPENDENCIES_DIRECTORY}/CMakeSDK)
execute_process(
  COMMAND git clone --branch main https://github.com/StratifyLabs/CMakeSDK.git
  WORKING_DIRECTORY ${DEPENDENCIES_DIRECTORY}
)

option(IS_ARM_CROSS_COMPILE "Setup the system to cross compile to Stratify OS" OFF)

# This is used on the CI server, but can be run locally as well
# This is currently NOT used with IS_ARM_CROSS_COMPILE=ON
option(IS_BUILD_AND_TEST "Build and run the API tests" OFF)

if(IS_ARM_CROSS_COMPILE)
  set(BUILD_DIR cmake_arm)
  execute_process(
    COMMAND cmake -DSDK_DIRECTORY=${SDK_DIRECTORY} -P ${DEPENDENCIES_DIRECTORY}/CMakeSDK/scripts/bootstrap.cmake
  )
else()
  set(BUILD_DIR cmake_link)

  file(REMOVE_RECURSE ${CMAKE_SDK_DIRECTORY}/${BUILD_DIR})
  file(MAKE_DIRECTORY ${CMAKE_SDK_DIRECTORY}/${BUILD_DIR})

  set(ENV{SOS_SDK_PATH} ${SDK_PATH})
  execute_process(
    COMMAND cmake ..
    WORKING_DIRECTORY ${CMAKE_SDK_DIRECTORY}/${BUILD_DIR}
    RESULT_VARIABLE CMAKE_SDK_CMAKE_RESULT
  )

  if(${CMAKE_SDK_CMAKE_RESULT})
    message(FATAL_ERROR "Failed to run cmake for CMakeSDK project")
  endif()

  execute_process(
    COMMAND cmake --build . --target install
    WORKING_DIRECTORY ${CMAKE_SDK_DIRECTORY}/${BUILD_DIR}
    RESULT_VARIABLE CMAKE_SDK_INSTALL_RESULT
  )

  if(${CMAKE_SDK_INSTALL_RESULT})
    message(FATAL_ERROR "Failed to install CMakeSDK project")
  endif()

  file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR})
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR})

  if(IS_BUILD_AND_TEST)
    message(STATUS "Build and run API Tests")

    execute_process(
      COMMAND cmake -DSDK_IS_TEST=ON ..
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR}
      RESULT_VARIABLE CMAKE_SDK_RESULT
    )

    if(${CMAKE_SDK_RESULT})
      message(FATAL_ERROR "Failed to run CMake")
    endif()

    execute_process(
      COMMAND cmake --build . --target all -- -j8
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR}
      RESULT_VARIABLE BUILD_SDK_RESULT
    )

    if(${BUILD_SDK_RESULT})
      message(FATAL_ERROR "Failed to build")
    endif()

    execute_process(
      COMMAND cmake --build . --target API_test -- -j8
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR}
      RESULT_VARIABLE BUILD_API_TEST_RESULT
    )

    if(${BUILD_API_TEST_RESULT})
      message(FATAL_ERROR "Failed to build API test")
    endif()

    execute_process(
      COMMAND ctest -VV
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR}
      RESULT_VARIABLE TEST_OUTPUT_RESULT
    )

    if(NOT ${TEST_OUTPUT_RESULT} EQUAL "0")
      message(FATAL_ERROR "Test failed to complete successfully")
    endif()

  endif()
endif()

if(IS_BUILD_AND_TEST)

endif()


