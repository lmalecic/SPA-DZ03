#include "Board.h"
#include <iostream>
#include <set>

std::vector<Point> Board::getNeighbours(Point p)
{
	std::vector<Point> neighbours;

	for (int i = p.first - 1; i <= p.first + 1; i++)
	{
		for (int j = p.second - 1; j <= p.second + 1; j++)
		{
			if (i == p.first && j == p.second) continue;
			if (i < 0 || j < 0 || i >= ROWS || j >= COLUMNS) continue;
			if (!graph[i][j]) continue;

			neighbours.emplace_back(i, j);
		}
	}

	return neighbours;
}

bool Board::isPointOnGrid(int row, int col)
{
	return (row >= 0 && row < ROWS && col >= 0 && col < COLUMNS);;
}

bool Board::isPointValid(int row, int col)
{
	return graph[row][col] == 1;
}

Board::Board(bool graph[ROWS][COLUMNS])
{
	setStart(0, 0);
	setGoal(ROWS - 1, COLUMNS - 1);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			this->graph[i][j] = graph[i][j] != 0;
		}
	}
}

aStarSearch Board::findPath(Point start, Point goal)
{
	return aStarSearch(this, start, goal);
}

void Board::draw()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (i == start.first && j == start.second)
			{
				std::cout << "A";
				continue;
			}

			if (i == goal.first && j == goal.second)
			{
				std::cout << "B";
				continue;
			}

			std::cout << (graph[i][j] ? '.' : '#');
		}

		std::cout << '\n';
	}

	std::cout << "\n";
}

void Board::draw(aStarSearch search, Point currentStep)
{
	Point start = search.getStart(), goal = search.getGoal();

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (currentStep.first == i && currentStep.second == j)
			{
				std::cout << "x";
				continue;
			}

			if (i == start.first && j == start.second)
			{
				std::cout << "A";
				continue;
			}

			if (i == goal.first && j == goal.second)
			{
				std::cout << "B";
				continue;
			}

			std::cout << (graph[i][j] ? '.' : '#');
		}

		std::cout << '\n';
	}

	std::cout << "\n";
}

Point Board::getStart()
{
	return start;
}

Point Board::getGoal()
{
	return goal;
}

void Board::setStart(int row, int col)
{
	start = { row, col };
}

void Board::setGoal(int row, int col)
{
	goal = { row, col };
}

void Board::setObstacle(int row, int col)
{
	graph[row][col] = 0;
}

void Board::removeObstacle(int row, int col)
{
	graph[row][col] = 1;
}
