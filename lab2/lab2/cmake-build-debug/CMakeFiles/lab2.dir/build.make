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
CMAKE_SOURCE_DIR = "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2.dir/flags.make

CMakeFiles/lab2.dir/sources/main.cpp.o: CMakeFiles/lab2.dir/flags.make
CMakeFiles/lab2.dir/sources/main.cpp.o: ../sources/main.cpp
CMakeFiles/lab2.dir/sources/main.cpp.o: CMakeFiles/lab2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2.dir/sources/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2.dir/sources/main.cpp.o -MF CMakeFiles/lab2.dir/sources/main.cpp.o.d -o CMakeFiles/lab2.dir/sources/main.cpp.o -c "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/sources/main.cpp"

CMakeFiles/lab2.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/sources/main.cpp" > CMakeFiles/lab2.dir/sources/main.cpp.i

CMakeFiles/lab2.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/sources/main.cpp" -o CMakeFiles/lab2.dir/sources/main.cpp.s

CMakeFiles/lab2.dir/sources/dialog.cpp.o: CMakeFiles/lab2.dir/flags.make
CMakeFiles/lab2.dir/sources/dialog.cpp.o: ../sources/dialog.cpp
CMakeFiles/lab2.dir/sources/dialog.cpp.o: CMakeFiles/lab2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab2.dir/sources/dialog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2.dir/sources/dialog.cpp.o -MF CMakeFiles/lab2.dir/sources/dialog.cpp.o.d -o CMakeFiles/lab2.dir/sources/dialog.cpp.o -c "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/sources/dialog.cpp"

CMakeFiles/lab2.dir/sources/dialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2.dir/sources/dialog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/sources/dialog.cpp" > CMakeFiles/lab2.dir/sources/dialog.cpp.i

CMakeFiles/lab2.dir/sources/dialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2.dir/sources/dialog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/sources/dialog.cpp" -o CMakeFiles/lab2.dir/sources/dialog.cpp.s

# Object files for target lab2
lab2_OBJECTS = \
"CMakeFiles/lab2.dir/sources/main.cpp.o" \
"CMakeFiles/lab2.dir/sources/dialog.cpp.o"

# External object files for target lab2
lab2_EXTERNAL_OBJECTS =

lab2: CMakeFiles/lab2.dir/sources/main.cpp.o
lab2: CMakeFiles/lab2.dir/sources/dialog.cpp.o
lab2: CMakeFiles/lab2.dir/build.make
lab2: /mnt/c/iX\ НИЯУ\ МИФИ/3\ СЕМЕСТР/ООП/labs/lab2/task/lib/libtask.a
lab2: CMakeFiles/lab2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2.dir/build: lab2
.PHONY : CMakeFiles/lab2.dir/build

CMakeFiles/lab2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2.dir/clean

CMakeFiles/lab2.dir/depend:
	cd "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug" "/mnt/c/iX НИЯУ МИФИ/3 СЕМЕСТР/ООП/labs/lab2/lab2/cmake-build-debug/CMakeFiles/lab2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab2.dir/depend

