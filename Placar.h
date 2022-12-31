#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Placar
{
public:
	Placar(sf::Font& fonte, sf::Vector2u tamanhoJanela);
	void mudarPlacar(int quem);
	void setPointText();
	void desenhar(sf::RenderWindow& janela) { janela.draw(placarST); janela.draw(placarWS);}

private:
	sf::Text placarST;
	sf::Text placarWS;
	sf::Vector2f tamanhoJaaj;

	int pontoST;
	int pontoWS;
};

