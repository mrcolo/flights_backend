# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/flights_backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/flights_backend/build

# Include any dependencies generated for this target.
include CMakeFiles/https_examples.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/https_examples.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/https_examples.dir/flags.make

CMakeFiles/https_examples.dir/https_examples.cpp.o: CMakeFiles/https_examples.dir/flags.make
CMakeFiles/https_examples.dir/https_examples.cpp.o: ../https_examples.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flights_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/https_examples.dir/https_examples.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/https_examples.dir/https_examples.cpp.o -c /root/flights_backend/https_examples.cpp

CMakeFiles/https_examples.dir/https_examples.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/https_examples.dir/https_examples.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flights_backend/https_examples.cpp > CMakeFiles/https_examples.dir/https_examples.cpp.i

CMakeFiles/https_examples.dir/https_examples.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/https_examples.dir/https_examples.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flights_backend/https_examples.cpp -o CMakeFiles/https_examples.dir/https_examples.cpp.s

CMakeFiles/https_examples.dir/https_examples.cpp.o.requires:

.PHONY : CMakeFiles/https_examples.dir/https_examples.cpp.o.requires

CMakeFiles/https_examples.dir/https_examples.cpp.o.provides: CMakeFiles/https_examples.dir/https_examples.cpp.o.requires
	$(MAKE) -f CMakeFiles/https_examples.dir/build.make CMakeFiles/https_examples.dir/https_examples.cpp.o.provides.build
.PHONY : CMakeFiles/https_examples.dir/https_examples.cpp.o.provides

CMakeFiles/https_examples.dir/https_examples.cpp.o.provides.build: CMakeFiles/https_examples.dir/https_examples.cpp.o


# Object files for target https_examples
https_examples_OBJECTS = \
"CMakeFiles/https_examples.dir/https_examples.cpp.o"

# External object files for target https_examples
https_examples_EXTERNAL_OBJECTS =

https_examples: CMakeFiles/https_examples.dir/https_examples.cpp.o
https_examples: CMakeFiles/https_examples.dir/build.make
https_examples: /usr/lib/x86_64-linux-gnu/libboost_system.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_thread.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
https_examples: /usr/lib/x86_64-linux-gnu/libpthread.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_system.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_thread.so
https_examples: /usr/lib/x86_64-linux-gnu/libssl.so
https_examples: /usr/lib/x86_64-linux-gnu/libcrypto.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
https_examples: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
https_examples: /usr/lib/x86_64-linux-gnu/libpthread.so
https_examples: CMakeFiles/https_examples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/flights_backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable https_examples"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/https_examples.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/https_examples.dir/build: https_examples

.PHONY : CMakeFiles/https_examples.dir/build

CMakeFiles/https_examples.dir/requires: CMakeFiles/https_examples.dir/https_examples.cpp.o.requires

.PHONY : CMakeFiles/https_examples.dir/requires

CMakeFiles/https_examples.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/https_examples.dir/cmake_clean.cmake
.PHONY : CMakeFiles/https_examples.dir/clean

CMakeFiles/https_examples.dir/depend:
	cd /root/flights_backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/flights_backend /root/flights_backend /root/flights_backend/build /root/flights_backend/build /root/flights_backend/build/CMakeFiles/https_examples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/https_examples.dir/depend

