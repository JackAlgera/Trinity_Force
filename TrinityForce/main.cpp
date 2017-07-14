#include <SFML\Graphics.hpp>
#include <stdio.h>
#include "Grid.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
#include <cstdlib> 

/*
Program that repeats a given triangle in a way that I like to call "Trinity Force", because each triangle is divided into 4 smaller triangles, but only the triangles in the corners are cut into 4 more triangles, and so on.

Author : Jacobus ALGERA
*/

const int size = 1000;
const sf::Vector2i screenDimensions(size,(int) (sqrt(3) * (size/2)) + 50);

sf::VertexArray background(sf::Color color)						//Sets the background to a given color
{
	sf::VertexArray background(sf::Quads, 4);
	background[0].position = sf::Vector2f(0, 0);
	background[1].position = sf::Vector2f(0, screenDimensions.y);
	background[2].position = sf::Vector2f(screenDimensions.x, screenDimensions.y);
	background[3].position = sf::Vector2f(screenDimensions.x, 0);

	background[0].color = color;
	background[1].color = color;
	background[2].color = color;
	background[3].color = color;

	return background;
}
const int numberOfTriangles = 8;
const int delay = 200;


int main()
{
	sf::RenderWindow window(sf::VideoMode(screenDimensions.x,screenDimensions.y),"Trinity Force",sf::Style::Close | sf::Style::Titlebar);		//Creates the window used to display the Trinity Force.

	Grid newGrid;
	newGrid.addTriangle(Triangle(sf::Vector2f(screenDimensions.x/2, 0), sf::Vector2f(0, screenDimensions.y), sf::Vector2f(screenDimensions.x, screenDimensions.y)));
	
	int counter = 0;

	while (window.isOpen())													//Main program loop
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))										//Handles the events
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (counter < numberOfTriangles)									//Used to limit the number of times the program repeats itself, and thus the number of times we cut each triangle into 4 smaller triangles.
		{
			window.draw(background(sf::Color::White));
			newGrid.update();
			newGrid.draw(window);
			window.display();
			Sleep(delay);
			window.clear();
			counter++;
		}
	}
	return 0;;
}