#include <stdio.h>
#include <stdlib.h>

// Game of Life, created with the C programming language.
// Created for the luls. - occabot

void game(int width, int height) {
	int grid[height][width];
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			grid[y][x] = (rand() % 10) ? 1 : 0;
		}
	}
}

int main(int argc, char *argv[]) {
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	game(width, height);
}
