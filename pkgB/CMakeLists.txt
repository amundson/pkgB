add_library(pkgBlib SHARED pkgB.cc pkgB.h)
target_include_directories(pkgBlib
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

install(TARGETS pkgBlib EXPORT pkgBTargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES pkgB.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/pkgB)

add_executable(pkgB main.cc)
target_include_directories(pkgB
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_link_libraries(pkgB pkgBlib)

install(TARGETS pkgB DESTINATION ${CMAKE_INSTALL_BINDIR})

