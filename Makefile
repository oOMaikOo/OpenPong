gcc -o OpenPong `sdl-config --libs` `sdl-config --cflags` -lSDL_mixer -lSDL_net -lSDL_ttf -lpthread *.cpp
