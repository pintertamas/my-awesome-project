# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Documents\BME\Prog1\my-awesome-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Documents\BME\Prog1\my-awesome-project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HeadBall.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HeadBall.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HeadBall.dir/flags.make

CMakeFiles/HeadBall.dir/main.c.obj: CMakeFiles/HeadBall.dir/flags.make
CMakeFiles/HeadBall.dir/main.c.obj: CMakeFiles/HeadBall.dir/includes_C.rsp
CMakeFiles/HeadBall.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Documents\BME\Prog1\my-awesome-project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HeadBall.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HeadBall.dir\main.c.obj   -c F:\Documents\BME\Prog1\my-awesome-project\main.c

CMakeFiles/HeadBall.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HeadBall.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Documents\BME\Prog1\my-awesome-project\main.c > CMakeFiles\HeadBall.dir\main.c.i

CMakeFiles/HeadBall.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HeadBall.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Documents\BME\Prog1\my-awesome-project\main.c -o CMakeFiles\HeadBall.dir\main.c.s

# Object files for target HeadBall
HeadBall_OBJECTS = \
"CMakeFiles/HeadBall.dir/main.c.obj"

# External object files for target HeadBall
HeadBall_EXTERNAL_OBJECTS =

HeadBall.exe: CMakeFiles/HeadBall.dir/main.c.obj
HeadBall.exe: CMakeFiles/HeadBall.dir/build.make
HeadBall.exe: CMakeFiles/HeadBall.dir/linklibs.rsp
HeadBall.exe: CMakeFiles/HeadBall.dir/objects1.rsp
HeadBall.exe: CMakeFiles/HeadBall.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Documents\BME\Prog1\my-awesome-project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable HeadBall.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HeadBall.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HeadBall.dir/build: HeadBall.exe

.PHONY : CMakeFiles/HeadBall.dir/build

CMakeFiles/HeadBall.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HeadBall.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HeadBall.dir/clean

CMakeFiles/HeadBall.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Documents\BME\Prog1\my-awesome-project F:\Documents\BME\Prog1\my-awesome-project F:\Documents\BME\Prog1\my-awesome-project\cmake-build-debug F:\Documents\BME\Prog1\my-awesome-project\cmake-build-debug F:\Documents\BME\Prog1\my-awesome-project\cmake-build-debug\CMakeFiles\HeadBall.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HeadBall.dir/depend

