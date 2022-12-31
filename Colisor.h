#pragma once
#include <SFML/Graphics.hpp>
class Colisor
{
public:
	Colisor(sf::RectangleShape& corpo);

	int checarColisao(Colisor& outra);
	void move(float dx, float dy) { corpo.move(dx, dy); }

	sf::Vector2f getPos() { return corpo.getPosition(); }
	sf::Vector2f getMetadeTam() { return corpo.getSize() / 2.f; }

private:
	sf::RectangleShape& corpo;

};

