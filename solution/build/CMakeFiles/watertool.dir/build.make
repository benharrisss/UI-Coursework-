# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build

# Include any dependencies generated for this target.
include CMakeFiles/watertool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/watertool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/watertool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/watertool.dir/flags.make

watertool_autogen/timestamp: /usr/local/share/qt/libexec/moc
watertool_autogen/timestamp: /usr/local/share/qt/libexec/uic
watertool_autogen/timestamp: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target watertool"
	/usr/local/Cellar/cmake/3.30.5/bin/cmake -E cmake_autogen /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles/watertool_autogen.dir/AutogenInfo.json ""
	/usr/local/Cellar/cmake/3.30.5/bin/cmake -E touch /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/watertool_autogen/timestamp

CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o: watertool_autogen/mocs_compilation.cpp
CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o -MF CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/watertool_autogen/mocs_compilation.cpp

CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/watertool_autogen/mocs_compilation.cpp > CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.i

CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/watertool_autogen/mocs_compilation.cpp -o CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.s

CMakeFiles/watertool.dir/main.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/main.cpp.o: /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/main.cpp
CMakeFiles/watertool.dir/main.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/watertool.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/main.cpp.o -MF CMakeFiles/watertool.dir/main.cpp.o.d -o CMakeFiles/watertool.dir/main.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/main.cpp

CMakeFiles/watertool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/main.cpp > CMakeFiles/watertool.dir/main.cpp.i

CMakeFiles/watertool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/main.cpp -o CMakeFiles/watertool.dir/main.cpp.s

CMakeFiles/watertool.dir/water.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/water.cpp.o: /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/water.cpp
CMakeFiles/watertool.dir/water.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/watertool.dir/water.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/water.cpp.o -MF CMakeFiles/watertool.dir/water.cpp.o.d -o CMakeFiles/watertool.dir/water.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/water.cpp

CMakeFiles/watertool.dir/water.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/water.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/water.cpp > CMakeFiles/watertool.dir/water.cpp.i

CMakeFiles/watertool.dir/water.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/water.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/water.cpp -o CMakeFiles/watertool.dir/water.cpp.s

CMakeFiles/watertool.dir/dataset.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/dataset.cpp.o: /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/dataset.cpp
CMakeFiles/watertool.dir/dataset.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/watertool.dir/dataset.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/dataset.cpp.o -MF CMakeFiles/watertool.dir/dataset.cpp.o.d -o CMakeFiles/watertool.dir/dataset.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/dataset.cpp

CMakeFiles/watertool.dir/dataset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/dataset.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/dataset.cpp > CMakeFiles/watertool.dir/dataset.cpp.i

CMakeFiles/watertool.dir/dataset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/dataset.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/dataset.cpp -o CMakeFiles/watertool.dir/dataset.cpp.s

CMakeFiles/watertool.dir/model.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/model.cpp.o: /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/model.cpp
CMakeFiles/watertool.dir/model.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/watertool.dir/model.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/model.cpp.o -MF CMakeFiles/watertool.dir/model.cpp.o.d -o CMakeFiles/watertool.dir/model.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/model.cpp

CMakeFiles/watertool.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/model.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/model.cpp > CMakeFiles/watertool.dir/model.cpp.i

CMakeFiles/watertool.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/model.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/model.cpp -o CMakeFiles/watertool.dir/model.cpp.s

CMakeFiles/watertool.dir/window.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/window.cpp.o: /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/window.cpp
CMakeFiles/watertool.dir/window.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/watertool.dir/window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/window.cpp.o -MF CMakeFiles/watertool.dir/window.cpp.o.d -o CMakeFiles/watertool.dir/window.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/window.cpp

CMakeFiles/watertool.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/window.cpp > CMakeFiles/watertool.dir/window.cpp.i

CMakeFiles/watertool.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/window.cpp -o CMakeFiles/watertool.dir/window.cpp.s

CMakeFiles/watertool.dir/stats.cpp.o: CMakeFiles/watertool.dir/flags.make
CMakeFiles/watertool.dir/stats.cpp.o: /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/stats.cpp
CMakeFiles/watertool.dir/stats.cpp.o: CMakeFiles/watertool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/watertool.dir/stats.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/watertool.dir/stats.cpp.o -MF CMakeFiles/watertool.dir/stats.cpp.o.d -o CMakeFiles/watertool.dir/stats.cpp.o -c /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/stats.cpp

CMakeFiles/watertool.dir/stats.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/watertool.dir/stats.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/stats.cpp > CMakeFiles/watertool.dir/stats.cpp.i

CMakeFiles/watertool.dir/stats.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/watertool.dir/stats.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/stats.cpp -o CMakeFiles/watertool.dir/stats.cpp.s

# Object files for target watertool
watertool_OBJECTS = \
"CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/watertool.dir/main.cpp.o" \
"CMakeFiles/watertool.dir/water.cpp.o" \
"CMakeFiles/watertool.dir/dataset.cpp.o" \
"CMakeFiles/watertool.dir/model.cpp.o" \
"CMakeFiles/watertool.dir/window.cpp.o" \
"CMakeFiles/watertool.dir/stats.cpp.o"

# External object files for target watertool
watertool_EXTERNAL_OBJECTS =

watertool: CMakeFiles/watertool.dir/watertool_autogen/mocs_compilation.cpp.o
watertool: CMakeFiles/watertool.dir/main.cpp.o
watertool: CMakeFiles/watertool.dir/water.cpp.o
watertool: CMakeFiles/watertool.dir/dataset.cpp.o
watertool: CMakeFiles/watertool.dir/model.cpp.o
watertool: CMakeFiles/watertool.dir/window.cpp.o
watertool: CMakeFiles/watertool.dir/stats.cpp.o
watertool: CMakeFiles/watertool.dir/build.make
watertool: /usr/local/lib/QtWidgets.framework/Versions/A/QtWidgets
watertool: /usr/local/lib/QtGui.framework/Versions/A/QtGui
watertool: /usr/local/lib/QtCore.framework/Versions/A/QtCore
watertool: CMakeFiles/watertool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable watertool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/watertool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/watertool.dir/build: watertool
.PHONY : CMakeFiles/watertool.dir/build

CMakeFiles/watertool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/watertool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/watertool.dir/clean

CMakeFiles/watertool.dir/depend: watertool_autogen/timestamp
	cd /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build /Users/fred/Documents/GitHub/Year2/UI-Coursework-fred/solution/build/CMakeFiles/watertool.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/watertool.dir/depend

