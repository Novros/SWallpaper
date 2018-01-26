#######################################################################################################################
# Variables
#------------------------------------------- Compiler and linker ------------------------------------------------------
CXX = g++
LD = g++
RM = rm -f
DEBUGGER = valgrind
#--------------------------------------------- Compiling flags --------------------------------------------------------
# C++ 2011: -std=c++11, for older compiler -std=c++0x.
ISO_FLAGS = -std=c++11
WARNINGS_FLAGS = -Wall -c
OPTIMIZATION_FLAGS = -O3 -march=native
PROFILING_FLAGS = -fprofile-arcs -ftest-coverage -fprofile-arcs
DEBUGGIN_FLAGS = -ggdb
CXX_FLAGS = $(ISO_FLAGS) $(WARNING_FLAGS) $(OPTIMIZATION_FLAGS) $(shell imlib2-config --cflags)
#----------------------------------------------- Linking flags --------------------------------------------------------
LIN_PROFILING_FLAGS = -fprofile-arcs -pthread -pg
LD_FLAGS = $(LIN_PROFILING_FLAGS) $(CPPFLAGS)
LD_LIBS = -lX11 $(shell imlib2-config --libs)
#--------------------------------------------- Other variables --------------------------------------------------------
EXE = swallpaper
OBJECTS = objects/main.o objects/xWallpaperDisplay.o objects/imlibWallpaperDisplay.o objects/factory.o objects/wallpaperImage.o objects/fileManager.o objects/wallpaperManager.o
#######################################################################################################################
# Targets
all: $(EXE)

build: all

clean:
	$(RM) -r $(OBJS) objects

distclean: clean
	$(RM) swallpaper

run: build
	./$(EXE) $(image)

debug: build
	$(DEBUGGER) ./$(EXE)

debug-memory: build
	$(DEBUGGER) --leak-check=full --show-leak-kinds=all ./$(EXE) $(image)

test: build

rebuild: clean build

#######################################################################################################################
$(EXE): objectDir $(OBJECTS)
	$(LD) -o $(EXE) $(OBJECTS) $(LD_FLAGS) $(LD_LIBS)

objectDir: 
	mkdir -p objects

objects/main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

objects/xWallpaperDisplay.o: src/display/XWallpaperDisplay.cpp src/display/XWallpaperDisplay.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

objects/imlibWallpaperDisplay.o: src/display/ImlibWallpaperDisplay.cpp src/display/ImlibWallpaperDisplay.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

objects/wallpaperImage.o: src/wallpaper/ImlibWallpaperImage.cpp src/wallpaper/WallpaperImage.h src/wallpaper/ImlibWallpaperImage.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

objects/factory.o: src/factory/ImlibFactory.cpp src/factory/Factory.h src/factory/ImlibFactory.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

objects/fileManager.o: src/manager/FileManager.cpp src/manager/FileManager.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@

objects/wallpaperManager.o: src/manager/WallpaperManager.cpp src/manager/WallpaperManager.h
	$(CXX) $(CXX_FLAGS) -c $< -o $@