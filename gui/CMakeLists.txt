
set(DEPENDENCIES
  DesignAPI
  InetAPI
  JsonAPI
  TestAPI
  SysAPI
  FsAPI
  VarAPI
  ThreadAPI)

set(LOCAL_NAME gui)

cmsdk_add_subdirectory(PRIVATE_SOURCELIST ${CMAKE_CURRENT_SOURCE_DIR}/src)
if(CMSDK_IS_LINK)
  list(APPEND DEPENDENCIES WindowAPI)
  cmsdk_add_subdirectory(DESIGNLAB_SOURCELIST ${CMAKE_CURRENT_SOURCE_DIR}/src/designlab)
else()
  set(DESIGNLAB_SOURCELIST "")
endif()

cmsdk_app_target(RELEASE ${LOCAL_NAME} "" release ${CMSDK_ARCH})

set(ICON_FILE icon.icns)
set(ICON_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../designlab/assets/${ICON_FILE})
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

cmsdk_app_add_arch_targets("${RELEASE_OPTIONS}" "${DEPENDENCIES}" 262144)

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

