# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/dialog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dialog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dialog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dialog.dir/flags.make

CMakeFiles/dialog.dir/sources/dialog.cpp.o: CMakeFiles/dialog.dir/flags.make
CMakeFiles/dialog.dir/sources/dialog.cpp.o: ../sources/dialog.cpp
CMakeFiles/dialog.dir/sources/dialog.cpp.o: CMakeFiles/dialog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dialog.dir/sources/dialog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dialog.dir/sources/dialog.cpp.o -MF CMakeFiles/dialog.dir/sources/dialog.cpp.o.d -o CMakeFiles/dialog.dir/sources/dialog.cpp.o -c "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/sources/dialog.cpp"

CMakeFiles/dialog.dir/sources/dialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dialog.dir/sources/dialog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/sources/dialog.cpp" > CMakeFiles/dialog.dir/sources/dialog.cpp.i

CMakeFiles/dialog.dir/sources/dialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dialog.dir/sources/dialog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/sources/dialog.cpp" -o CMakeFiles/dialog.dir/sources/dialog.cpp.s

CMakeFiles/dialog.dir/sources/main.cpp.o: CMakeFiles/dialog.dir/flags.make
CMakeFiles/dialog.dir/sources/main.cpp.o: ../sources/main.cpp
CMakeFiles/dialog.dir/sources/main.cpp.o: CMakeFiles/dialog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dialog.dir/sources/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dialog.dir/sources/main.cpp.o -MF CMakeFiles/dialog.dir/sources/main.cpp.o.d -o CMakeFiles/dialog.dir/sources/main.cpp.o -c "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/sources/main.cpp"

CMakeFiles/dialog.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dialog.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/sources/main.cpp" > CMakeFiles/dialog.dir/sources/main.cpp.i

CMakeFiles/dialog.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dialog.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/sources/main.cpp" -o CMakeFiles/dialog.dir/sources/main.cpp.s

# Object files for target dialog
dialog_OBJECTS = \
"CMakeFiles/dialog.dir/sources/dialog.cpp.o" \
"CMakeFiles/dialog.dir/sources/main.cpp.o"

# External object files for target dialog
dialog_EXTERNAL_OBJECTS =

dialog: CMakeFiles/dialog.dir/sources/dialog.cpp.o
dialog: CMakeFiles/dialog.dir/sources/main.cpp.o
dialog: CMakeFiles/dialog.dir/build.make
dialog: /mnt/c/iX\ НИЯУ\ МИФИ/3\ СЕМЕСТР/ООП/labs/lab3/task1/task/cmake-build-debug/libtask.a
dialog: CMakeFiles/dialog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable dialog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dialog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dialog.dir/build: dialog
.PHONY : CMakeFiles/dialog.dir/build

CMakeFiles/dialog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dialog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dialog.dir/clean

CMakeFiles/dialog.dir/depend:
	cd "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab3/task1/dialog/cmake-build-debug/CMakeFiles/dialog.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dialog.dir/depend

