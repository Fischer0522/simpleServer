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
include src/CMakeFiles/thread02.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/thread02.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/thread02.dir/flags.make

src/CMakeFiles/thread02.dir/thread02.c.o: src/CMakeFiles/thread02.dir/flags.make
src/CMakeFiles/thread02.dir/thread02.c.o: ../src/thread02.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/thread02.dir/thread02.c.o"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/thread02.dir/thread02.c.o   -c /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/thread02.c

src/CMakeFiles/thread02.dir/thread02.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/thread02.dir/thread02.c.i"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/thread02.c > CMakeFiles/thread02.dir/thread02.c.i

src/CMakeFiles/thread02.dir/thread02.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/thread02.dir/thread02.c.s"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/thread02.c -o CMakeFiles/thread02.dir/thread02.c.s

src/CMakeFiles/thread02.dir/echo.c.o: src/CMakeFiles/thread02.dir/flags.make
src/CMakeFiles/thread02.dir/echo.c.o: ../src/echo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/thread02.dir/echo.c.o"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/thread02.dir/echo.c.o   -c /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/echo.c

src/CMakeFiles/thread02.dir/echo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/thread02.dir/echo.c.i"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/echo.c > CMakeFiles/thread02.dir/echo.c.i

src/CMakeFiles/thread02.dir/echo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/thread02.dir/echo.c.s"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/learn_software/program_file/ClionProject/HttpServer/src/echo.c -o CMakeFiles/thread02.dir/echo.c.s

# Object files for target thread02
thread02_OBJECTS = \
"CMakeFiles/thread02.dir/thread02.c.o" \
"CMakeFiles/thread02.dir/echo.c.o"

# External object files for target thread02
thread02_EXTERNAL_OBJECTS =

bin/thread02: src/CMakeFiles/thread02.dir/thread02.c.o
bin/thread02: src/CMakeFiles/thread02.dir/echo.c.o
bin/thread02: src/CMakeFiles/thread02.dir/build.make
bin/thread02: lib/libHttpServer.a
bin/thread02: src/CMakeFiles/thread02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../bin/thread02"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/thread02.dir/build: bin/thread02

.PHONY : src/CMakeFiles/thread02.dir/build

src/CMakeFiles/thread02.dir/clean:
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/thread02.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/thread02.dir/clean

src/CMakeFiles/thread02.dir/depend:
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/learn_software/program_file/ClionProject/HttpServer /mnt/d/learn_software/program_file/ClionProject/HttpServer/src /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/src/CMakeFiles/thread02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/thread02.dir/depend

