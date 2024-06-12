#pragma once

class aStarSearch;

#include<vector>
#include"aStarSearch.h"
#include"Constants.h"

class Board
{
private:
	bool graph[ROWS][COLUMNS];
	Point start, goal;
public:
	Board(bool graph[ROWS][COLUMNS]);
	aStarSearch findPath(Point start, Point goal);
	std::vector<Point> getNeighbours(Point p);

	bool isPointOnGrid(int row, int col);
	bool isPointValid(int row, int col);

	void draw();
	void draw(aStarSearch search, Point currentStep);

	Point getStart();
	Point getGoal();

	void setStart(int row, int col);
	void setGoal(int row, int col);

	void setObstacle(int row, int col);
	void removeObstacle(int row, int col);
};

