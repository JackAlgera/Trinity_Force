#include "Grid.h"


Grid::Grid()
{
}


Grid::~Grid()
{
}

void Grid::update()
{
	tempTriangleList.clear();
	for (Triangle triangle : triangleList)
	{
		triangle.middleTriangles(tempTriangleList);
	}
	for (Triangle triangle : tempTriangleList)
	{
		triangleList.push_back(triangle);
	}
}

void Grid::draw(sf::RenderWindow& window)
{
	for (Triangle triangle : triangleList)
	{
		triangle.draw(window);
	}
}
