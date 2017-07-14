#pragma once
#include <SFML\Graphics.hpp>
#include "Triangle.h"

/*
Class that handles the different triangles by use of a vector.
*/


class Grid
{
public:
	Grid();
	~Grid();

	void update();
	void draw(sf::RenderWindow& window);
	void addTriangle(Triangle tri) { triangleList.push_back(tri); }

private:
	std::vector<Triangle> triangleList;
	std::vector<Triangle> tempTriangleList;
};

