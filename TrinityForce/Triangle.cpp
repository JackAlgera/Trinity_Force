#include "Triangle.h"
#include <stdio.h>



Triangle::Triangle(sf::Vector2f cornerA, sf::Vector2f cornerB, sf::Vector2f cornerC)
{
	this->cornerA = cornerA;
	this->cornerB = cornerB;
	this->cornerC = cornerC;
}


Triangle::~Triangle()
{
}

sf::Vector2f Triangle::getMiddleAB()
{
	if ((int) cornerB.y == (int) cornerC.y)
	{
		sf::Vector2f newCornerA = sf::Vector2f(cornerB.x + (abs(cornerA.x - cornerB.x) / 2), cornerA.y + (abs(cornerA.y - cornerB.y) / 2));
		return newCornerA;
	}
	else
	{
		sf::Vector2f newCornerA = sf::Vector2f(cornerA.x + (abs(cornerA.x - cornerB.x) / 2), cornerA.y + (abs(cornerA.y - cornerB.y) / 2));
		return newCornerA;
	}
}

sf::Vector2f Triangle::getMiddleBC()
{
	if ((int)cornerB.y == (int)cornerC.y)
	{
		sf::Vector2f newCornerB = sf::Vector2f(cornerB.x + (abs(cornerB.x - cornerC.x) / 2), cornerB.y);
		return newCornerB;
	}
	else
	{
		sf::Vector2f newCornerB = sf::Vector2f(cornerB.x + (abs(cornerC.x - cornerB.x) / 2), cornerC.y + (abs(cornerC.y - cornerB.y) / 2));
		return newCornerB;
	}
}

sf::Vector2f Triangle::getMiddleCA()
{
	if ((int)cornerB.y == (int)cornerC.y)
	{
		sf::Vector2f newCornerC = sf::Vector2f(cornerA.x + (abs(cornerC.x - cornerA.x) / 2), cornerA.y + (abs(cornerC.y - cornerA.y) / 2));
		return newCornerC;
	}
	else
	{
		sf::Vector2f newCornerC = sf::Vector2f(cornerA.x + (abs(cornerA.x - cornerC.x) / 2), cornerA.y);
		return newCornerC;
	}
}

void Triangle::middleTriangles(std::vector<Triangle>& temp)
{
	sf::Vector2f midAB = this->getMiddleAB();
	sf::Vector2f midBC = this->getMiddleBC();
	sf::Vector2f midCA = this->getMiddleCA();

	Triangle triangle1(cornerA, midAB, midCA);
	Triangle triangle2(midAB, cornerB, midBC);
	Triangle triangle3(midCA, midBC, cornerC);
	//Triangle triangleMid(midAB, midBC, midCA);

	temp.push_back(triangle1);
	temp.push_back(triangle2);
	temp.push_back(triangle3);
	//temp.push_back(triangleMid);

}

void Triangle::draw(sf::RenderWindow& window)
{
	sf::VertexArray triangle(sf::LineStrip, 4);
	triangle[0].position = cornerA;
	triangle[1].position = cornerB;
	triangle[2].position = cornerC;
	triangle[3].position = cornerA;

	triangle[0].color = sf::Color::Blue;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Blue;
	triangle[3].color = sf::Color::Blue;

	window.draw(triangle);
}
