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
include lib/CMakeFiles/HttpServer.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/HttpServer.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/HttpServer.dir/flags.make

lib/CMakeFiles/HttpServer.dir/tcp_server.cpp.o: lib/CMakeFiles/HttpServer.dir/flags.make
lib/CMakeFiles/HttpServer.dir/tcp_server.cpp.o: ../lib/tcp_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/HttpServer.dir/tcp_server.cpp.o"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HttpServer.dir/tcp_server.cpp.o -c /mnt/d/learn_software/program_file/ClionProject/HttpServer/lib/tcp_server.cpp

lib/CMakeFiles/HttpServer.dir/tcp_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/tcp_server.cpp.i"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/learn_software/program_file/ClionProject/HttpServer/lib/tcp_server.cpp > CMakeFiles/HttpServer.dir/tcp_server.cpp.i

lib/CMakeFiles/HttpServer.dir/tcp_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/tcp_server.cpp.s"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/learn_software/program_file/ClionProject/HttpServer/lib/tcp_server.cpp -o CMakeFiles/HttpServer.dir/tcp_server.cpp.s

# Object files for target HttpServer
HttpServer_OBJECTS = \
"CMakeFiles/HttpServer.dir/tcp_server.cpp.o"

# External object files for target HttpServer
HttpServer_EXTERNAL_OBJECTS =

lib/libHttpServer.a: lib/CMakeFiles/HttpServer.dir/tcp_server.cpp.o
lib/libHttpServer.a: lib/CMakeFiles/HttpServer.dir/build.make
lib/libHttpServer.a: lib/CMakeFiles/HttpServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHttpServer.a"
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/HttpServer.dir/cmake_clean_target.cmake
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HttpServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/HttpServer.dir/build: lib/libHttpServer.a

.PHONY : lib/CMakeFiles/HttpServer.dir/build

lib/CMakeFiles/HttpServer.dir/clean:
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/HttpServer.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/HttpServer.dir/clean

lib/CMakeFiles/HttpServer.dir/depend:
	cd /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/learn_software/program_file/ClionProject/HttpServer /mnt/d/learn_software/program_file/ClionProject/HttpServer/lib /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib /mnt/d/learn_software/program_file/ClionProject/HttpServer/cmake-build-debug/lib/CMakeFiles/HttpServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/HttpServer.dir/depend
