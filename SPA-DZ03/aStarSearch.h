#pragma once

class Board;

#include"Board.h"
#include"Constants.h"
#include<queue>

class aStarSearch
{
private:
	Board* board;
	Point parents[ROWS][COLUMNS];
	double distances[ROWS][COLUMNS];
	std::priority_queue<fPair, std::vector<fPair>, std::greater<fPair>> queue;
	Point start, goal;
	double heuristic(Point current);
public:
	aStarSearch(Board* board, Point start, Point goal);
	bool run();
	std::vector<Point> getPath();
	bool isDone();
	bool pathExists();
	Point getStart();
	Point getGoal();
};

