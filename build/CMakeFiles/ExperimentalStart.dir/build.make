# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\jetbrains_tools\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\jetbrains_tools\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects-linux\algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects-linux\algorithm\build

# Utility rule file for ExperimentalStart.

# Include the progress variables for this target.
include CMakeFiles\ExperimentalStart.dir\progress.make

CMakeFiles\ExperimentalStart:
	D:\jetbrains_tools\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\ctest.exe -D ExperimentalStart

ExperimentalStart: CMakeFiles\ExperimentalStart
ExperimentalStart: CMakeFiles\ExperimentalStart.dir\build.make

.PHONY : ExperimentalStart

# Rule to build all files generated by this target.
CMakeFiles\ExperimentalStart.dir\build: ExperimentalStart

.PHONY : CMakeFiles\ExperimentalStart.dir\build

CMakeFiles\ExperimentalStart.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExperimentalStart.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ExperimentalStart.dir\clean

CMakeFiles\ExperimentalStart.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Projects-linux\algorithm D:\Projects-linux\algorithm D:\Projects-linux\algorithm\build D:\Projects-linux\algorithm\build D:\Projects-linux\algorithm\build\CMakeFiles\ExperimentalStart.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ExperimentalStart.dir\depend

