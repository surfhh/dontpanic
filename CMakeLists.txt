project(dontpanic)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
include(Qt4Support)
include(AssertOutOfSourceBuild)
find_package(KDE4 REQUIRED)
include (KDE4Defaults)

set(DBUS_INTERFACES_PATH ${CMAKE_SOURCE_DIR}/src/interfaces)

option(DP_INSTALL_SYSTEM_FILES ON "Allows disabling the installation of files which needs root access and are rarely changed")

include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} )
include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_subdirectory( doc )
add_subdirectory( src )
add_subdirectory( icons )
