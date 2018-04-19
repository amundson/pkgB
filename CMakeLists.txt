cmake_minimum_required(VERSION 3.0.0)
project(PKGA VERSION 2.0.0)

include(GNUInstallDirs)

add_subdirectory(pkgA)

include(CMakePackageConfigHelpers)

# * Versioning File (Same for Build/Install Trees)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/pkgAConfigVersion.cmake
  VERSION
  ${PKGA_VERSION}
  COMPATIBILITY
  ExactVersion)

# * Build Tree Config/Targets files
set(PKGA_CURRENT_INCLUDEDIR "${PROJECT_SOURCE_DIR}")
set(PKGA_CURRENT_LIBDIR "${PROJECT_BINARY_DIR}/pkga")

configure_package_config_file(pkgAConfig.cmake.in
                              ${CMAKE_CURRENT_BINARY_DIR}/pkgAConfig.cmake
                              INSTALL_DESTINATION
                              ${CMAKE_CURRENT_BINARY_DIR}
                              INSTALL_PREFIX
                              ${CMAKE_CURRENT_BINARY_DIR}
                              PATH_VARS
                              PKGA_CURRENT_INCLUDEDIR
                              PKGA_CURRENT_LIBDIR)

# NB: must be called *after* EXPORT argument is created, hence move of
# add_subdirectory earlier.
export(EXPORT pkgATargets NAMESPACE pkga::)

# * Install Tree Config/Targets file
set(PKGA_CURRENT_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(PKGA_CURRENT_LIBDIR "${CMAKE_INSTALL_LIBDIR}")

configure_package_config_file(
  pkgAConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/pkgAConfig.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/pkga/cmake
  PATH_VARS
  PKGA_CURRENT_INCLUDEDIR
  PKGA_CURRENT_LIBDIR)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/pkgAConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/pkgAConfigVersion.cmake
              DESTINATION
              ${CMAKE_INSTALL_LIBDIR}/cmake/pkga)
install(EXPORT pkgATargets
               NAMESPACE
               pkga::
               DESTINATION
               ${CMAKE_INSTALL_LIBDIR}/cmake/pkga)

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
