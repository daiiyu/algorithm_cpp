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

# Utility rule file for NightlyMemoryCheck.

# Include the progress variables for this target.
include CMakeFiles\NightlyMemoryCheck.dir\progress.make

CMakeFiles\NightlyMemoryCheck:
	D:\jetbrains_tools\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\ctest.exe -D NightlyMemoryCheck

NightlyMemoryCheck: CMakeFiles\NightlyMemoryCheck
NightlyMemoryCheck: CMakeFiles\NightlyMemoryCheck.dir\build.make

.PHONY : NightlyMemoryCheck

# Rule to build all files generated by this target.
CMakeFiles\NightlyMemoryCheck.dir\build: NightlyMemoryCheck

.PHONY : CMakeFiles\NightlyMemoryCheck.dir\build

CMakeFiles\NightlyMemoryCheck.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NightlyMemoryCheck.dir\cmake_clean.cmake
.PHONY : CMakeFiles\NightlyMemoryCheck.dir\clean

CMakeFiles\NightlyMemoryCheck.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Projects-linux\algorithm D:\Projects-linux\algorithm D:\Projects-linux\algorithm\build D:\Projects-linux\algorithm\build D:\Projects-linux\algorithm\build\CMakeFiles\NightlyMemoryCheck.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\NightlyMemoryCheck.dir\depend

