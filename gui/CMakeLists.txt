
set(DEPENDENCIES
  DesignAPI
  WindowAPI
  InetAPI
  JsonAPI
  TestAPI
  SysAPI
  FsAPI
  VarAPI
  ThreadAPI)

set(LOCAL_NAME ${PROJECT_NAME})

sos_sdk_add_subdirectory(PRIVATE_SOURCELIST ${CMAKE_CURRENT_SOURCE_DIR}/src)
sos_sdk_add_subdirectory(DESIGNLAB_SOURCELIST ${CMAKE_CURRENT_SOURCE_DIR}/src/designlab)

sos_sdk_app_target(RELEASE ${LOCAL_NAME} "" release ${SOS_ARCH})

set(ICON_FILE  icon.icns)
set(ICON_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/../assets/${ICON_FILE})
add_executable(${RELEASE_TARGET} MACOSX_BUNDLE ${ICON_PATH})
target_sources(${RELEASE_TARGET}
  PRIVATE
  ${PRIVATE_SOURCELIST}
  ${DESIGNLAB_SOURCELIST}
  )


target_compile_definitions(${RELEASE_TARGET}
  PRIVATE
  -DVERSION=\"${CMAKE_PROJECT_VERSION}\"
  )

target_include_directories(${RELEASE_TARGET}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  )

target_compile_options(${RELEASE_TARGET}
  PRIVATE
  -O3
  )

set_property(TARGET ${RELEASE_TARGET} PROPERTY CXX_STANDARD 17)

sos_sdk_app_add_arch_targets("${RELEASE_OPTIONS}" "${DEPENDENCIES}" 0)

set_source_files_properties(${ICON_PATH} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
set_target_properties(${RELEASE_TARGET}
  PROPERTIES
  BUNDLE True
  MACOSX_BUNDLE_GUI_IDENTIFIER stratifylabs.dev.style.identifier.${CUR_TARGET}
  MACOSX_BUNDLE_BUNDLE_NAME gui
  MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
  MACOSX_BUNDLE_ICON_FILE ${ICON_FILE}
  MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/MacOSXBundleInfo.plist.in
  )


install(
  PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/build_release_link/${LOCAL_NAME}_release_link.elf${SOS_SDK_EXEC_SUFFIX}
  DESTINATION ${SOS_SDK_PATH}/bin RENAME ${LOCAL_NAME}${SOS_SDK_EXEC_SUFFIX})
