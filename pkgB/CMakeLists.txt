add_library(pkgAlib SHARED pkgA.cc pkgA.h)
target_include_directories(pkgAlib
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

install(TARGETS pkgAlib EXPORT pkgATargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES pkgA.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/pkgA)

add_executable(pkgA main.cc)
target_include_directories(pkgA
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_link_libraries(pkgA pkgAlib)

install(TARGETS pkgA DESTINATION ${CMAKE_INSTALL_BINDIR})

