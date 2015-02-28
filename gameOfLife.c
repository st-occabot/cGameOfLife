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
	printf("\n");
}

void evolve(void *grid, int width, int height) {
	int (*evolveGrid)[width] = grid;
	int newGrid[height][width];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int nearbyLives = 0;
			for (int nX = x - 1; nX < x + 2; nX++) {
				for (int nY = y - 1; nY < y + 2; nY++) {
					if (evolveGrid[(nY + height) % height][(nX + width) % width]) {
						nearbyLives++;					
					}
				}
			}		
			if (evolveGrid[y][x]) {
				nearbyLives--;
			}
			newGrid[y][x] = (nearbyLives == 3 || (nearbyLives == 2 && evolveGrid[y][x]));
		}
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			evolveGrid[y][x] = newGrid[y][x];
		}
	}
}

void game(int width, int height) {
	unsigned grid[height][width];
	
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			grid[y][x] = (rand() % 10) ? 0 : 1;
		}
	}
	while (1) {
		show(grid, width, height);
		evolve(grid, width, height);
		usleep(500000);
	}
}
int main(int argc, char *argv[]) {
	srand(time(0));
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	
	game(width, height);
}
