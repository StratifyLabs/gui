set(DEPENDENCIES
  DesignAPI
  InetAPI
  JsonAPI
  TestAPI
  SysAPI
  FsAPI
  VarAPI
  ThreadAPI)

if(CMSDK_IS_LINK)
  list(APPEND DEPENDENCIES WindowAPI)
endif()

set(ICON_FILE icon.icns)
set(ICON_PATH ../designlab/assets/${ICON_FILE})

cmsdk2_add_executable(
  NAME ${PROJECT_NAME}
  ARCH ${CMSDK_ARCH}
  FLAT
  CONFIG release
  TARGET RELEASE_TARGET)

cmsdk2_add_sources(
  TARGET ${RELEASE_TARGET}
  DIRECTORY src)

if(CMSDK_IS_LINK)
  cmsdk2_add_sources(
    TARGET ${RELEASE_TARGET}
    DIRECTORY src/designlab)
endif()

target_sources(${RELEASE_TARGET} PRIVATE ${ICON_PATH})
target_compile_definitions(${RELEASE_TARGET}
  PRIVATE
  -DVERSION=\"${CMAKE_PROJECT_VERSION}\")

target_include_directories(${RELEASE_TARGET} PRIVATE src)
set_property(TARGET ${RELEASE_TARGET} PROPERTY CXX_STANDARD 17)
set_source_files_properties(${ICON_PATH} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
set_target_properties(${RELEASE_TARGET}
  PROPERTIES
  BUNDLE ON
  MACOSX_BUNDLE ON
  MACOSX_BUNDLE_GUI_IDENTIFIER stratifylabs.dev.style.identifier.${CUR_TARGET}
  MACOSX_BUNDLE_BUNDLE_NAME gui
  MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
  MACOSX_BUNDLE_ICON_FILE ${ICON_FILE}
  MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/MacOSXBundleInfo.plist.in)

cmsdk2_app_add_dependencies(
  TARGET ${RELEASE_TARGET}
  DEPENDENCIES ${DEPENDENCIES}
  RAM_SIZE 262144)

