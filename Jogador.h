#pragma once
#include <SFML/Graphics.hpp>
#include "Colisor.h"

class Jogador
{
public:
	Jogador(sf::Vector2f tamanho, sf::Vector2f quadraPos, sf::Vector2f quadraTam);
	void movimento();
	void desenhar(sf::RenderWindow& janela);
	void checkCol(Colisor& outroCorpo);
	void setTW1(bool tw1) { TW1 = tw1; }
	void setTW2(bool tw2) { TW2 = tw2; }

	Colisor getColisor1() { return Colisor(player1); }
	Colisor getColisor2() { return Colisor(player2); }

private:

private:
	sf::RectangleShape player1;
	sf::RectangleShape player2;

	bool TW1 = false;
	bool TW2 = false;

	float speed = 0.1f;

	sf::Vector2f inicialPos1;
	sf::Vector2f inicialPos2;
	sf::Vector2f tamanho;
};

