# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/d/learn_software/program_file/ClionProject/HttpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/thread-helloworld.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/thread-helloworld.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/thread-helloworld.dir/flags.make

src/CMakeFiles/thread-helloworld.dir/thread-helloworld.c.o: src/CMakeFiles/thread-helloworld.dir/flags.make
src/CMakeFiles/thread-helloworld.dir/thread-helloworld.c.o: ../src/thread-helloworld.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/thread-helloworld.dir/thread-helloworld.c.o"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/thread-helloworld.dir/thread-helloworld.c.o   -c /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/thread-helloworld.c

src/CMakeFiles/thread-helloworld.dir/thread-helloworld.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/thread-helloworld.dir/thread-helloworld.c.i"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/thread-helloworld.c > CMakeFiles/thread-helloworld.dir/thread-helloworld.c.i

src/CMakeFiles/thread-helloworld.dir/thread-helloworld.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/thread-helloworld.dir/thread-helloworld.c.s"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/thread-helloworld.c -o CMakeFiles/thread-helloworld.dir/thread-helloworld.c.s

# Object files for target thread-helloworld
thread__helloworld_OBJECTS = \
"CMakeFiles/thread-helloworld.dir/thread-helloworld.c.o"

# External object files for target thread-helloworld
thread__helloworld_EXTERNAL_OBJECTS =

bin/thread-helloworld: src/CMakeFiles/thread-helloworld.dir/thread-helloworld.c.o
bin/thread-helloworld: src/CMakeFiles/thread-helloworld.dir/build.make
bin/thread-helloworld: lib/libHttpServer.a
bin/thread-helloworld: src/CMakeFiles/thread-helloworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/thread-helloworld"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread-helloworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/thread-helloworld.dir/build: bin/thread-helloworld

.PHONY : src/CMakeFiles/thread-helloworld.dir/build

src/CMakeFiles/thread-helloworld.dir/clean:
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/thread-helloworld.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/thread-helloworld.dir/clean

src/CMakeFiles/thread-helloworld.dir/depend:
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/learn_software/program_file/ClionProject/HttpServer /mnt/d/learn_software/program_file/ClionProject/HttpServer/src /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src/CMakeFiles/thread-helloworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/thread-helloworld.dir/depend

