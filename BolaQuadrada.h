#pragma once
#include <SFML/Graphics.hpp>
#include "Colisor.h"
#include "Placar.h"
#include <time.h>

class BolaQuadrada
{
public:
	BolaQuadrada();
	void rolar() { bola.move(move); }
	void checarCol(Colisor& outro);
	void checarGol(Colisor& gol, Placar &placar);
	void desenhar(sf::RenderWindow& janela) { janela.draw(bola); }
	float getEixoX() { return eixoX; }
	float getEixoY() { return eixoY ; }
	void setEixos(float ex, float ey) { eixoX = ex; eixoY = ey; }
//	void setSpeed(float spd) { speed = spd; }

	Colisor getColisor() { return Colisor(bola); }

private:
	sf::RectangleShape bola;
	float speedX = 0.09f;
	float speedY = 0.09f;
	float eixoX;
	float eixoY;
	sf::Vector2f move;
};

