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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Alexern/Desktop/CSCI 262/lab05"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mondrian.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mondrian.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mondrian.dir/flags.make

CMakeFiles/mondrian.dir/main.cpp.o: CMakeFiles/mondrian.dir/flags.make
CMakeFiles/mondrian.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mondrian.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mondrian.dir/main.cpp.o -c "/Users/Alexern/Desktop/CSCI 262/lab05/main.cpp"

CMakeFiles/mondrian.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mondrian.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Alexern/Desktop/CSCI 262/lab05/main.cpp" > CMakeFiles/mondrian.dir/main.cpp.i

CMakeFiles/mondrian.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mondrian.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Alexern/Desktop/CSCI 262/lab05/main.cpp" -o CMakeFiles/mondrian.dir/main.cpp.s

CMakeFiles/mondrian.dir/mondrian.cpp.o: CMakeFiles/mondrian.dir/flags.make
CMakeFiles/mondrian.dir/mondrian.cpp.o: ../mondrian.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mondrian.dir/mondrian.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mondrian.dir/mondrian.cpp.o -c "/Users/Alexern/Desktop/CSCI 262/lab05/mondrian.cpp"

CMakeFiles/mondrian.dir/mondrian.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mondrian.dir/mondrian.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Alexern/Desktop/CSCI 262/lab05/mondrian.cpp" > CMakeFiles/mondrian.dir/mondrian.cpp.i

CMakeFiles/mondrian.dir/mondrian.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mondrian.dir/mondrian.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Alexern/Desktop/CSCI 262/lab05/mondrian.cpp" -o CMakeFiles/mondrian.dir/mondrian.cpp.s

CMakeFiles/mondrian.dir/picture.cpp.o: CMakeFiles/mondrian.dir/flags.make
CMakeFiles/mondrian.dir/picture.cpp.o: ../picture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mondrian.dir/picture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mondrian.dir/picture.cpp.o -c "/Users/Alexern/Desktop/CSCI 262/lab05/picture.cpp"

CMakeFiles/mondrian.dir/picture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mondrian.dir/picture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Alexern/Desktop/CSCI 262/lab05/picture.cpp" > CMakeFiles/mondrian.dir/picture.cpp.i

CMakeFiles/mondrian.dir/picture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mondrian.dir/picture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Alexern/Desktop/CSCI 262/lab05/picture.cpp" -o CMakeFiles/mondrian.dir/picture.cpp.s

CMakeFiles/mondrian.dir/lodepng.cpp.o: CMakeFiles/mondrian.dir/flags.make
CMakeFiles/mondrian.dir/lodepng.cpp.o: ../lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mondrian.dir/lodepng.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mondrian.dir/lodepng.cpp.o -c "/Users/Alexern/Desktop/CSCI 262/lab05/lodepng.cpp"

CMakeFiles/mondrian.dir/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mondrian.dir/lodepng.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Alexern/Desktop/CSCI 262/lab05/lodepng.cpp" > CMakeFiles/mondrian.dir/lodepng.cpp.i

CMakeFiles/mondrian.dir/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mondrian.dir/lodepng.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Alexern/Desktop/CSCI 262/lab05/lodepng.cpp" -o CMakeFiles/mondrian.dir/lodepng.cpp.s

# Object files for target mondrian
mondrian_OBJECTS = \
"CMakeFiles/mondrian.dir/main.cpp.o" \
"CMakeFiles/mondrian.dir/mondrian.cpp.o" \
"CMakeFiles/mondrian.dir/picture.cpp.o" \
"CMakeFiles/mondrian.dir/lodepng.cpp.o"

# External object files for target mondrian
mondrian_EXTERNAL_OBJECTS =

mondrian: CMakeFiles/mondrian.dir/main.cpp.o
mondrian: CMakeFiles/mondrian.dir/mondrian.cpp.o
mondrian: CMakeFiles/mondrian.dir/picture.cpp.o
mondrian: CMakeFiles/mondrian.dir/lodepng.cpp.o
mondrian: CMakeFiles/mondrian.dir/build.make
mondrian: CMakeFiles/mondrian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mondrian"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mondrian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mondrian.dir/build: mondrian

.PHONY : CMakeFiles/mondrian.dir/build

CMakeFiles/mondrian.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mondrian.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mondrian.dir/clean

CMakeFiles/mondrian.dir/depend:
	cd "/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Alexern/Desktop/CSCI 262/lab05" "/Users/Alexern/Desktop/CSCI 262/lab05" "/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug" "/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug" "/Users/Alexern/Desktop/CSCI 262/lab05/cmake-build-debug/CMakeFiles/mondrian.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mondrian.dir/depend
