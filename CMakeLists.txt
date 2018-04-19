cmake_minimum_required(VERSION 3.0.0)
project(PKGB VERSION 2.0.0)

include(GNUInstallDirs)

add_subdirectory(pkgB)

include(CMakePackageConfigHelpers)

# * Versioning File (Same for Build/Install Trees)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/pkgBConfigVersion.cmake
  VERSION
  ${PKGB_VERSION}
  COMPATIBILITY
  ExactVersion)

# * Build Tree Config/Targets files
set(PKGB_CURRENT_INCLUDEDIR "${PROJECT_SOURCE_DIR}")
set(PKGB_CURRENT_LIBDIR "${PROJECT_BINARY_DIR}/pkgb")

configure_package_config_file(pkgBConfig.cmake.in
                              ${CMAKE_CURRENT_BINARY_DIR}/pkgBConfig.cmake
                              INSTALL_DESTINATION
                              ${CMAKE_CURRENT_BINARY_DIR}
                              INSTALL_PREFIX
                              ${CMAKE_CURRENT_BINARY_DIR}
                              PATH_VARS
                              PKGB_CURRENT_INCLUDEDIR
                              PKGB_CURRENT_LIBDIR)

# NB: must be called *after* EXPORT argument is created, hence move of
# add_subdirectory earlier.
export(EXPORT pkgBTargets NAMESPACE pkgb::)

# * Install Tree Config/Targets file
set(PKGB_CURRENT_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(PKGB_CURRENT_LIBDIR "${CMAKE_INSTALL_LIBDIR}")

configure_package_config_file(
  pkgBConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/pkgBConfig.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/pkgb/cmake
  PATH_VARS
  PKGB_CURRENT_INCLUDEDIR
  PKGB_CURRENT_LIBDIR)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/pkgBConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/pkgBConfigVersion.cmake
              DESTINATION
              ${CMAKE_INSTALL_LIBDIR}/cmake/pkgb)
install(EXPORT pkgBTargets
               NAMESPACE
               pkgb::
               DESTINATION
               ${CMAKE_INSTALL_LIBDIR}/cmake/pkgb)

# * Uninstall target
if(NOT TARGET uninstall)
  configure_file("${CMAKE_CURRENT_LIST_DIR}/uninstall.cmake.in"
                 "${CMAKE_BINARY_DIR}/uninstall.cmake" IMMEDIATE
                 @ONLY)

  add_custom_target(uninstall
                    COMMAND "${CMAKE_COMMAND}" -P
                            "${CMAKE_BINARY_DIR}/uninstall.cmake"
                    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()
