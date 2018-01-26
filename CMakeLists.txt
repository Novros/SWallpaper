#----------------------------------------------- Common info -----------------------------------------------------------
cmake_minimum_required(VERSION 3.9)
project(SWallpaper)

#--------------------------------------------- Compiling flags ---------------------------------------------------------
set(CMAKE_CXX_STANDARD 11)
SET(WARNINGS_FLAGS "-Wall -c")
SET(OPTIMIZATION_FLAGS "-O3 -march=native")
SET(PROFILING_FLAGS "-fprofile-arcs -ftest-coverage -fprofile-arcs")
SET(DEBUGGIN_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS "${ISO_FLAGS} ${WARNING_FLAGS} ${OPTIMIZATION_FLAGS}") #${shell imlib2-config --cflags}
SET(CMAKE_CXX_FLAGS_DEBUG  "-D_DEBUG")

#----------------------------------------------- Linking flags ---------------------------------------------------------
SET(LIN_PROFILING_FLAGS "-fprofile-arcs -pthread -pg")
SET(LD_FLAGS "${LIN_PROFILING_FLAGS} ${CPPFLAGS}")
SET(LD_LIBS "-lX11 -L/usr/lib -lImlib2") #${shell imlib2-config --libs}
SET(CMAKE_EXE_LINKER_FLAGS "${LD_FLAGS} ${LD_LIBS}")

#--------------------------------------------------- Sources -----------------------------------------------------------
add_executable(SWallpaper
        src/display/XWallpaperDisplay.cpp
        src/display/XWallpaperDisplay.h
        src/display/WallpaperDisplay.h
        src/factory/ImlibFactory.cpp
        src/factory/ImlibFactory.h
        src/factory/Factory.h
        src/wallpaper/ImlibWallpaperImage.cpp
        src/wallpaper/ImlibWallpaperImage.h
        src/wallpaper/WallpaperImage.h
        src/manager/FileManager.cpp
        src/manager/FileManager.h
        src/main.cpp
        src/manager/WallpaperManager.cpp
        src/manager/WallpaperManager.h src/display/ImlibWallpaperDisplay.cpp src/display/ImlibWallpaperDisplay.h)
