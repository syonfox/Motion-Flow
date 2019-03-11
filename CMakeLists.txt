

# Only tested in 3.1, may work in older versions.
cmake_minimum_required(VERSION 3.1)



project(motion_flow)
find_package(SFML 2 REQUIRED network audio graphics window system)
find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
message("OpenCV Libs ${OpenCV_LIBS}")
#set(IMGUI_ROOT ${CMAKE_CURRENT_LIST_DIR}/imgui-sfml)

#set(SFML_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/include/SFML/)
#file(GLOB SFML_HEADERS "${SFML_INCLUDE_DIR}/*.hpp" )
#file(GLOB SFML_LIBRARIES "${SFML_INCLUDE_DIR}/../../lib/*.so")

#message(status "** SFML Include: ${SFML_INCLUDE_DIR}")
#message(status "** SFML Libraries: ${SFML_LIBRARIES}")

message(status "** IMGUI Root: ${IMGUI_ROOT}")


#endif()
set(IMGUI_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/imgui-sfml")
# Glob up both source and headers as sources for VS users.
file(GLOB IMGUI_SFML_FILES "${IMGUI_INCLUDE_DIR}/*.cpp" "${IMGUI_INCLUDE_DIR}/*.h")

# Set these for users to use
set(IMGUI_SFML_INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}
        ${IMGUI_INCLUDE_DIR}
        ${SFML_INCLUDE_DIR} )

message( "Imgui Incluses imgui-sfml ${IMGUI_SFML_INCLUDE_DIRS} \n" )


#set(IMGUI_SOURCES
#        ${IMGUI_FILES} )
#message(status "** imgui sources: ${IMGUI_SOURCES}")
set(IMGUI_SFML_SOURCES
        ${IMGUI_SFML_FILES} )

message(status "** imgui-sfml sources: ${IMGUI_SFML_SOURCES}")
set(IMGUI_SFML_DEPENDENCIES
        ${SFML_DEPENDENCIES}
        ${SFML_LIBRARIES} )

#add_subdirectory("imgui-sfml")
message(status "**imgui-sfml/SFML Incluses Dirs ${IMGUI_SFML_INCLUDE_DIRS} \n" )
include_directories("${IMGUI_SFML_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})

#add_subdirectory(imgui-sfml/examples)

file(TO_CMAKE_PATH "main.cpp" EXAMPLE_FILES)
set(SRCS "imconfig.h" ${IMGUI_SFML_SOURCES} ${EXAMPLE_FILES} slope.cpp slope.hpp engine.cpp engine.hpp player.cpp player.hpp)

add_executable(motion_flow ${SRCS})

# Detect and add SFML
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions

#if(SFML_FOUND)
#  include_directories(${SFML_INCLUDE_DIR})
#  target_link_libraries(motion_flow ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#endif()

target_compile_definitions(motion_flow PRIVATE IMGUI_INCLUDE_IMCONFIG_H)
# FIXME(SMA) : Wrong header used here when IMGUI_ROOT contains a imconfig.h
target_include_directories(motion_flow PRIVATE
        ${PROJECT_SOURCE_DIR} # needed for imgui.h to find our imconfig.h
        ${IMGUI_SFML_INCLUDE_DIRS}
        )

target_link_libraries(motion_flow ${OPENGL_LIBRARIES} ${OpenCV_LIBS} ${IMGUI_SFML_DEPENDENCIES} sfml-graphics sfml-window sfml-system )
install(TARGETS motion_flow DESTINATION bin)
set_target_properties(motion_flow PROPERTIES DEBUG_POSTFIX _d)

