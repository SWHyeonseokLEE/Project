cmake_minimum_required(VERSION 3.5)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/CAN_Access/include")
project(DBC_Edit VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-fpermissive -m32")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR}Widgets REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR}Charts REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Charts)
find_package(Qt6 REQUIRED COMPONENTS Core Concurrent)
find_package(Qt6 REQUIRED COMPONENTS Core Network)  # Network 모듈 추가
add_library(CAN_Access STATIC IMPORTED)
set_target_properties(CAN_Access PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/CAN_Access/lib/CAN_Access.lib")

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DBC_Edit
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        DBCParse.cpp
        DBCParse.h
        include/CAN_Access.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DBC_Edit APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DBC_Edit SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DBC_Edit
            ${PROJECT_SOURCES}
        )
    endif()
endif()




target_link_libraries(DBC_Edit PRIVATE Qt6::Core Qt6::Concurrent)
target_link_libraries(DBC_Edit PRIVATE Qt6::Charts)
target_link_libraries(DBC_Edit PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(DBC_Edit PRIVATE Qt6::Core Qt6::Network)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DBC_Edit)
endif()
set_target_properties(DBC_Edit PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DBC_Edit
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DBC_Edit)
endif()
