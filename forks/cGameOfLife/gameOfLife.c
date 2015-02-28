#include <stdio.h>
#include <stdlib.h>

// Game of Life, created with the C programming language.
// Created for the luls. - occabot

void show(void *grid, int width, int height) {
	int (*displayGrid)[width] = grid;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			printf("%i", displayGrid[y][x]);
		}
		printf("\n");
	}
}

void evolve(void *grid, int width, int height) {
	int (*evolveGrid)[width] = grid;
	int newGrid[height][width];
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
		
		}
	}
}

void game(int width, int height) {
	unsigned grid[height][width];
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			grid[y][x] = (rand() % 10) ? 1 : 0;
		}
	}
	show(grid, width, height);
	evolve(grid, width, height);
	show(grid, width, height);
}

int main(int argc, char *argv[]) {
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	game(width, height);
}
