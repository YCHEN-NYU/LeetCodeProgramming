# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\eason\Dropbox\CS\C++\malloc2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\malloc2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\malloc2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\malloc2.dir\flags.make

CMakeFiles\malloc2.dir\main.cpp.obj: CMakeFiles\malloc2.dir\flags.make
CMakeFiles\malloc2.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/malloc2.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\malloc2.dir\main.cpp.obj /FdCMakeFiles\malloc2.dir\ /FS -c C:\Users\eason\Dropbox\CS\C++\malloc2\main.cpp
<<

CMakeFiles\malloc2.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/malloc2.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\malloc2.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\eason\Dropbox\CS\C++\malloc2\main.cpp
<<

CMakeFiles\malloc2.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/malloc2.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\malloc2.dir\main.cpp.s /c C:\Users\eason\Dropbox\CS\C++\malloc2\main.cpp
<<

CMakeFiles\malloc2.dir\main.cpp.obj.requires:

.PHONY : CMakeFiles\malloc2.dir\main.cpp.obj.requires

CMakeFiles\malloc2.dir\main.cpp.obj.provides: CMakeFiles\malloc2.dir\main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\malloc2.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\malloc2.dir\main.cpp.obj.provides.build
.PHONY : CMakeFiles\malloc2.dir\main.cpp.obj.provides

CMakeFiles\malloc2.dir\main.cpp.obj.provides.build: CMakeFiles\malloc2.dir\main.cpp.obj


# Object files for target malloc2
malloc2_OBJECTS = \
"CMakeFiles\malloc2.dir\main.cpp.obj"

# External object files for target malloc2
malloc2_EXTERNAL_OBJECTS =

malloc2.exe: CMakeFiles\malloc2.dir\main.cpp.obj
malloc2.exe: CMakeFiles\malloc2.dir\build.make
malloc2.exe: CMakeFiles\malloc2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable malloc2.exe"
	"C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\malloc2.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\malloc2.dir\objects1.rsp @<<
 /out:malloc2.exe /implib:malloc2.lib /pdb:C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug\malloc2.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\malloc2.dir\build: malloc2.exe

.PHONY : CMakeFiles\malloc2.dir\build

CMakeFiles\malloc2.dir\requires: CMakeFiles\malloc2.dir\main.cpp.obj.requires

.PHONY : CMakeFiles\malloc2.dir\requires

CMakeFiles\malloc2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\malloc2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\malloc2.dir\clean

CMakeFiles\malloc2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\eason\Dropbox\CS\C++\malloc2 C:\Users\eason\Dropbox\CS\C++\malloc2 C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug C:\Users\eason\Dropbox\CS\C++\malloc2\cmake-build-debug\CMakeFiles\malloc2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\malloc2.dir\depend

