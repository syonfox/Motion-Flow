# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /snap/clion/67/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/67/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raf/Motion-Flow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raf/Motion-Flow

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/snap/clion/67/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/raf/Motion-Flow/CMakeFiles /home/raf/Motion-Flow/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/raf/Motion-Flow/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named motion_flow

# Build rule for target.
motion_flow: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 motion_flow
.PHONY : motion_flow

# fast build rule for target.
motion_flow/fast:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/build
.PHONY : motion_flow/fast

engine.o: engine.cpp.o

.PHONY : engine.o

# target to build an object file
engine.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/engine.cpp.o
.PHONY : engine.cpp.o

engine.i: engine.cpp.i

.PHONY : engine.i

# target to preprocess a source file
engine.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/engine.cpp.i
.PHONY : engine.cpp.i

engine.s: engine.cpp.s

.PHONY : engine.s

# target to generate assembly for a file
engine.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/engine.cpp.s
.PHONY : engine.cpp.s

fonts.o: fonts.cpp.o

.PHONY : fonts.o

# target to build an object file
fonts.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/fonts.cpp.o
.PHONY : fonts.cpp.o

fonts.i: fonts.cpp.i

.PHONY : fonts.i

# target to preprocess a source file
fonts.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/fonts.cpp.i
.PHONY : fonts.cpp.i

fonts.s: fonts.cpp.s

.PHONY : fonts.s

# target to generate assembly for a file
fonts.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/fonts.cpp.s
.PHONY : fonts.cpp.s

imgui-sfml/imgui-SFML.o: imgui-sfml/imgui-SFML.cpp.o

.PHONY : imgui-sfml/imgui-SFML.o

# target to build an object file
imgui-sfml/imgui-SFML.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.o
.PHONY : imgui-sfml/imgui-SFML.cpp.o

imgui-sfml/imgui-SFML.i: imgui-sfml/imgui-SFML.cpp.i

.PHONY : imgui-sfml/imgui-SFML.i

# target to preprocess a source file
imgui-sfml/imgui-SFML.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.i
.PHONY : imgui-sfml/imgui-SFML.cpp.i

imgui-sfml/imgui-SFML.s: imgui-sfml/imgui-SFML.cpp.s

.PHONY : imgui-sfml/imgui-SFML.s

# target to generate assembly for a file
imgui-sfml/imgui-SFML.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui-SFML.cpp.s
.PHONY : imgui-sfml/imgui-SFML.cpp.s

imgui-sfml/imgui.o: imgui-sfml/imgui.cpp.o

.PHONY : imgui-sfml/imgui.o

# target to build an object file
imgui-sfml/imgui.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.o
.PHONY : imgui-sfml/imgui.cpp.o

imgui-sfml/imgui.i: imgui-sfml/imgui.cpp.i

.PHONY : imgui-sfml/imgui.i

# target to preprocess a source file
imgui-sfml/imgui.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.i
.PHONY : imgui-sfml/imgui.cpp.i

imgui-sfml/imgui.s: imgui-sfml/imgui.cpp.s

.PHONY : imgui-sfml/imgui.s

# target to generate assembly for a file
imgui-sfml/imgui.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui.cpp.s
.PHONY : imgui-sfml/imgui.cpp.s

imgui-sfml/imgui_demo.o: imgui-sfml/imgui_demo.cpp.o

.PHONY : imgui-sfml/imgui_demo.o

# target to build an object file
imgui-sfml/imgui_demo.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.o
.PHONY : imgui-sfml/imgui_demo.cpp.o

imgui-sfml/imgui_demo.i: imgui-sfml/imgui_demo.cpp.i

.PHONY : imgui-sfml/imgui_demo.i

# target to preprocess a source file
imgui-sfml/imgui_demo.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.i
.PHONY : imgui-sfml/imgui_demo.cpp.i

imgui-sfml/imgui_demo.s: imgui-sfml/imgui_demo.cpp.s

.PHONY : imgui-sfml/imgui_demo.s

# target to generate assembly for a file
imgui-sfml/imgui_demo.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_demo.cpp.s
.PHONY : imgui-sfml/imgui_demo.cpp.s

imgui-sfml/imgui_draw.o: imgui-sfml/imgui_draw.cpp.o

.PHONY : imgui-sfml/imgui_draw.o

# target to build an object file
imgui-sfml/imgui_draw.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.o
.PHONY : imgui-sfml/imgui_draw.cpp.o

imgui-sfml/imgui_draw.i: imgui-sfml/imgui_draw.cpp.i

.PHONY : imgui-sfml/imgui_draw.i

# target to preprocess a source file
imgui-sfml/imgui_draw.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.i
.PHONY : imgui-sfml/imgui_draw.cpp.i

imgui-sfml/imgui_draw.s: imgui-sfml/imgui_draw.cpp.s

.PHONY : imgui-sfml/imgui_draw.s

# target to generate assembly for a file
imgui-sfml/imgui_draw.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_draw.cpp.s
.PHONY : imgui-sfml/imgui_draw.cpp.s

imgui-sfml/imgui_widgets.o: imgui-sfml/imgui_widgets.cpp.o

.PHONY : imgui-sfml/imgui_widgets.o

# target to build an object file
imgui-sfml/imgui_widgets.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.o
.PHONY : imgui-sfml/imgui_widgets.cpp.o

imgui-sfml/imgui_widgets.i: imgui-sfml/imgui_widgets.cpp.i

.PHONY : imgui-sfml/imgui_widgets.i

# target to preprocess a source file
imgui-sfml/imgui_widgets.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.i
.PHONY : imgui-sfml/imgui_widgets.cpp.i

imgui-sfml/imgui_widgets.s: imgui-sfml/imgui_widgets.cpp.s

.PHONY : imgui-sfml/imgui_widgets.s

# target to generate assembly for a file
imgui-sfml/imgui_widgets.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/imgui-sfml/imgui_widgets.cpp.s
.PHONY : imgui-sfml/imgui_widgets.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/main.cpp.s
.PHONY : main.cpp.s

motion.o: motion.cpp.o

.PHONY : motion.o

# target to build an object file
motion.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/motion.cpp.o
.PHONY : motion.cpp.o

motion.i: motion.cpp.i

.PHONY : motion.i

# target to preprocess a source file
motion.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/motion.cpp.i
.PHONY : motion.cpp.i

motion.s: motion.cpp.s

.PHONY : motion.s

# target to generate assembly for a file
motion.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/motion.cpp.s
.PHONY : motion.cpp.s

player.o: player.cpp.o

.PHONY : player.o

# target to build an object file
player.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/player.cpp.o
.PHONY : player.cpp.o

player.i: player.cpp.i

.PHONY : player.i

# target to preprocess a source file
player.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/player.cpp.i
.PHONY : player.cpp.i

player.s: player.cpp.s

.PHONY : player.s

# target to generate assembly for a file
player.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/player.cpp.s
.PHONY : player.cpp.s

slope.o: slope.cpp.o

.PHONY : slope.o

# target to build an object file
slope.cpp.o:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/slope.cpp.o
.PHONY : slope.cpp.o

slope.i: slope.cpp.i

.PHONY : slope.i

# target to preprocess a source file
slope.cpp.i:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/slope.cpp.i
.PHONY : slope.cpp.i

slope.s: slope.cpp.s

.PHONY : slope.s

# target to generate assembly for a file
slope.cpp.s:
	$(MAKE) -f CMakeFiles/motion_flow.dir/build.make CMakeFiles/motion_flow.dir/slope.cpp.s
.PHONY : slope.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... edit_cache"
	@echo "... motion_flow"
	@echo "... install"
	@echo "... rebuild_cache"
	@echo "... list_install_components"
	@echo "... install/local"
	@echo "... engine.o"
	@echo "... engine.i"
	@echo "... engine.s"
	@echo "... fonts.o"
	@echo "... fonts.i"
	@echo "... fonts.s"
	@echo "... imgui-sfml/imgui-SFML.o"
	@echo "... imgui-sfml/imgui-SFML.i"
	@echo "... imgui-sfml/imgui-SFML.s"
	@echo "... imgui-sfml/imgui.o"
	@echo "... imgui-sfml/imgui.i"
	@echo "... imgui-sfml/imgui.s"
	@echo "... imgui-sfml/imgui_demo.o"
	@echo "... imgui-sfml/imgui_demo.i"
	@echo "... imgui-sfml/imgui_demo.s"
	@echo "... imgui-sfml/imgui_draw.o"
	@echo "... imgui-sfml/imgui_draw.i"
	@echo "... imgui-sfml/imgui_draw.s"
	@echo "... imgui-sfml/imgui_widgets.o"
	@echo "... imgui-sfml/imgui_widgets.i"
	@echo "... imgui-sfml/imgui_widgets.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... motion.o"
	@echo "... motion.i"
	@echo "... motion.s"
	@echo "... player.o"
	@echo "... player.i"
	@echo "... player.s"
	@echo "... slope.o"
	@echo "... slope.i"
	@echo "... slope.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

