#pragma once
#include <SFML/Graphics.hpp>
#include "Colisor.h"

class Estadio
{
public:
	Estadio(sf::Vector2u tamanhoJanela);
	void desenharCenario(sf::RenderWindow& janela);
	sf::Vector2f getCenarioPos() { return sf::Vector2f(cenario.getPosition().x -(cenario.getSize().x / 2), cenario.getPosition().y); }
	sf::Vector2f getCenarioTam() { return cenario.getSize(); }

	Colisor getColisor1() { return Colisor(paredes[0]); }
	Colisor getColisor2() { return Colisor(paredes[1]); }

	Colisor getColisorGolD() { return Colisor(golDireita); }
	Colisor getColisorGolE() { return Colisor(golEsquerda); }

private:
	sf::RectangleShape cenario;
	std::vector<sf::RectangleShape> meio;
	std::vector<sf::RectangleShape> paredes;

	sf::RectangleShape golDireita;
	sf::RectangleShape golEsquerda;

	sf::Vector2f tamanhoJaaj;
	sf::Vector2f tamanhoMeio = sf::Vector2f(3, 6);

};

