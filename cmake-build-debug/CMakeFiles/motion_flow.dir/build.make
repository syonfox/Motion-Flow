# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/syonfox/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/syonfox/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/syonfox/github/Motion-Flow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/syonfox/github/Motion-Flow/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/motion_flow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motion_flow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motion_flow.dir/flags.make

CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o: ../imgui-sfml/imgui-SFML.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o -c /home/syonfox/github/Motion-Flow/imgui-sfml/imgui-SFML.cpp

CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/imgui-sfml/imgui-SFML.cpp > CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.i

CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/imgui-sfml/imgui-SFML.cpp -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.s

CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o: ../imgui-sfml/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o -c /home/syonfox/github/Motion-Flow/imgui-sfml/imgui.cpp

CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/imgui-sfml/imgui.cpp > CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.i

CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/imgui-sfml/imgui.cpp -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.s

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o: ../imgui-sfml/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o -c /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_demo.cpp

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_demo.cpp > CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.i

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_demo.cpp -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.s

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o: ../imgui-sfml/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o -c /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_draw.cpp

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_draw.cpp > CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.i

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_draw.cpp -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.s

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o: ../imgui-sfml/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o -c /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_widgets.cpp

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_widgets.cpp > CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.i

CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/imgui-sfml/imgui_widgets.cpp -o CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.s

CMakeFiles/motion_flow.dir/main.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/motion_flow.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/main.cpp.o -c /home/syonfox/github/Motion-Flow/main.cpp

CMakeFiles/motion_flow.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/main.cpp > CMakeFiles/motion_flow.dir/main.cpp.i

CMakeFiles/motion_flow.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/main.cpp -o CMakeFiles/motion_flow.dir/main.cpp.s

CMakeFiles/motion_flow.dir/slope.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/slope.cpp.o: ../slope.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/motion_flow.dir/slope.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/slope.cpp.o -c /home/syonfox/github/Motion-Flow/slope.cpp

CMakeFiles/motion_flow.dir/slope.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/slope.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/slope.cpp > CMakeFiles/motion_flow.dir/slope.cpp.i

CMakeFiles/motion_flow.dir/slope.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/slope.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/slope.cpp -o CMakeFiles/motion_flow.dir/slope.cpp.s

CMakeFiles/motion_flow.dir/engine.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/engine.cpp.o: ../engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/motion_flow.dir/engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/engine.cpp.o -c /home/syonfox/github/Motion-Flow/engine.cpp

CMakeFiles/motion_flow.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/engine.cpp > CMakeFiles/motion_flow.dir/engine.cpp.i

CMakeFiles/motion_flow.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/engine.cpp -o CMakeFiles/motion_flow.dir/engine.cpp.s

CMakeFiles/motion_flow.dir/player.cpp.o: CMakeFiles/motion_flow.dir/flags.make
CMakeFiles/motion_flow.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/motion_flow.dir/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion_flow.dir/player.cpp.o -c /home/syonfox/github/Motion-Flow/player.cpp

CMakeFiles/motion_flow.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion_flow.dir/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/syonfox/github/Motion-Flow/player.cpp > CMakeFiles/motion_flow.dir/player.cpp.i

CMakeFiles/motion_flow.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion_flow.dir/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/syonfox/github/Motion-Flow/player.cpp -o CMakeFiles/motion_flow.dir/player.cpp.s

# Object files for target motion_flow
motion_flow_OBJECTS = \
"CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o" \
"CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o" \
"CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o" \
"CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o" \
"CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o" \
"CMakeFiles/motion_flow.dir/main.cpp.o" \
"CMakeFiles/motion_flow.dir/slope.cpp.o" \
"CMakeFiles/motion_flow.dir/engine.cpp.o" \
"CMakeFiles/motion_flow.dir/player.cpp.o"

# External object files for target motion_flow
motion_flow_EXTERNAL_OBJECTS =

motion_flow_d: CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/main.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/slope.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/engine.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/player.cpp.o
motion_flow_d: CMakeFiles/motion_flow.dir/build.make
motion_flow_d: /usr/lib/x86_64-linux-gnu/libGL.so
motion_flow_d: /usr/lib/x86_64-linux-gnu/libGLU.so
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
motion_flow_d: ../SFML-2.5.1/include/SFML/../../lib/libsfml-audio.so
motion_flow_d: ../SFML-2.5.1/include/SFML/../../lib/libsfml-graphics.so
motion_flow_d: ../SFML-2.5.1/include/SFML/../../lib/libsfml-network.so
motion_flow_d: ../SFML-2.5.1/include/SFML/../../lib/libsfml-system.so
motion_flow_d: ../SFML-2.5.1/include/SFML/../../lib/libsfml-window.so
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
motion_flow_d: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
motion_flow_d: CMakeFiles/motion_flow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable motion_flow_d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motion_flow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motion_flow.dir/build: motion_flow_d

.PHONY : CMakeFiles/motion_flow.dir/build

CMakeFiles/motion_flow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motion_flow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motion_flow.dir/clean

CMakeFiles/motion_flow.dir/depend:
	cd /home/syonfox/github/Motion-Flow/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/syonfox/github/Motion-Flow /home/syonfox/github/Motion-Flow /home/syonfox/github/Motion-Flow/cmake-build-debug /home/syonfox/github/Motion-Flow/cmake-build-debug /home/syonfox/github/Motion-Flow/cmake-build-debug/CMakeFiles/motion_flow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motion_flow.dir/depend

