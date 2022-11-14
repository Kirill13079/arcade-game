#include <iostream>

using namespace std;

const char hero = '@';
const char barrier = 'X';

int posHeroRow = 1;
int posHeroColumn = 1;

const int rows = 10;
const int columns = 20;

char map[rows][columns];

void generateMap()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			if (row == 0)
			{
				map[row][column] = '#';
			}
			else if (row == rows - 1)
			{
				map[row][column] = '#';
			}
			else if (column == 0)
			{
				map[row][column] = '#';
			}
			else if (column == columns - 1)
			{
				map[row][column] = '#';
			}
			else
			{
				map[row][column] = ' ';
			}
		}
	}
}

void draw()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			cout << map[row][column];
		}

		cout << "\n";
	}
}

void generateHero()
{
	map[posHeroRow][posHeroColumn] = hero;
}

void generateBarriers()
{
	int max = columns / 2;

	srand(time(NULL));

	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			if (map[row][column] == ' ' && row % 2 == 0)
			{
				int random = rand() % 10;

				if (random % 2 == 0)
				{
					map[row][column] = barrier;
				}
			}
		}
	}
}

int main()
{
	generateMap();
	generateHero();
	generateBarriers();
	draw();
}
