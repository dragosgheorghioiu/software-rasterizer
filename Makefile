PKGS=raylib
CFLAGS=-Wall -Wextra -g -std=c99 `pkg-config --cflags --static $(PKGS)`
LIBS=`pkg-config --libs --static $(PKGS)` -lm

rasterizer: main.c helpers.c
	$(CC) $(CFLAGS) -o rasterizer helpers.c main_loop.c main.c $(LIBS)
