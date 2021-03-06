#pragma once
#include <SFML\Graphics.hpp>

/*
Class that handles each triangle
A triangle consisting of 3 corners ; A, B and C.
*/
class Triangle
{
public:
	Triangle(sf::Vector2f cornerA, sf::Vector2f cornerB, sf::Vector2f cornerC);
	~Triangle();
	sf::Vector2f getMiddleAB();
	sf::Vector2f getMiddleBC();
	sf::Vector2f getMiddleCA();

	void middleTriangles(std::vector<Triangle>& temp);
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f cornerA, cornerB, cornerC;
};

