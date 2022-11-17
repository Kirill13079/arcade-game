#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const char hero = '@';
const char barrier = 'X';

int posHeroRow = 1;
int posHeroColumn = 1;

const int rows = 10;
const int columns = 20;

bool isGameRunning = true;

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

bool moveHeroRight()
{
	bool result = true;

	int nextColumn = posHeroColumn + 1;

	if (map[posHeroRow][nextColumn] == ' ')
	{
		posHeroColumn = nextColumn;
		map[posHeroRow][posHeroColumn] = hero;
	}

	return result;
}

bool moveHeroLeft()
{
	bool result = true;

	int previosColumn = posHeroColumn - 1;

	if (map[posHeroRow][previosColumn] == ' ')
	{
		posHeroColumn = previosColumn;
		map[posHeroRow][posHeroColumn] = hero;
	}

	return result;
}

int main()
{
	while (isGameRunning)
	{
		system("cls");

		generateMap();
		generateHero();
		generateBarriers();
		draw();

		if (_kbhit())
		{
			switch (_getch())
			{
			case 'd':
				isGameRunning = moveHeroRight();
				break;
			case 'a':
				isGameRunning = moveHeroLeft();
				break;
			}
		}

		Sleep(100);
	}

	system("pause");
}
