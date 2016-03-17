COMPILE		=	g++ -g -Wall -O2 -c
LINK		=	g++ -g -Wall -O2
SDL_FLAGS	= 	`sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf


# Visual Studio
# Include SDL_image.h and add SDL2_image.lib to your linker dependencies.
#
# GCC or Clang on Linux and MinGW on Windows
# Include SDL2/SDL_image.h and add -lSDL2_image to the SDLLIB variable in your makefile.
#
# Clang on Mac
# Include SDL2_image/SDL_image.h and add -framework SDL2_image to the SDL variable in your makefile.
#
# - http://www.willusher.io/sdl2%20tutorials/2013/08/18/lesson-3-sdl-extension-libraries/


all: game

game: bin/game.o bin/graphics.o bin/input.o bin/wrapper.o
	$(LINK) bin/game.o bin/graphics.o bin/input.o bin/wrapper.o $(SDL_FLAGS) -o game

bin/game.o: src/game.cxx src/game.hxx
	$(COMPILE) src/game.cxx $(SDL_FLAGS) -o bin/game.o

bin/graphics.o: src/graphics/graphics.cxx src/graphics/graphics.hxx
	$(COMPILE) src/graphics/graphics.cxx $(SDL_FLAGS) -o bin/graphics.o

bin/input.o: src/graphics/input.cxx src/graphics/input.hxx
	$(COMPILE) src/graphics/input.cxx $(SDL_FLAGS) -o bin/input.o

bin/wrapper.o: src/graphics/wrapper.cxx src/graphics/wrapper.hxx
	$(COMPILE) src/graphics/wrapper.cxx $(SDL_FLAGS) -o bin/wrapper.o

clean:
	rm *.o game
	rm bin/*
