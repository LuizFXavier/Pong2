#pragma once
#include <SFML/Graphics.hpp>
#include "BolaQuadrada.h"
#include "Jogador.h"

class Skills
{
public:
	Skills(sf::Vector2u tamanhoJanela, sf::Font& fonte);
	void ativar(BolaQuadrada& bola, Jogador& player, sf::Clock& clock, sf::RenderWindow& janela);
	void OMUNDO(BolaQuadrada& bola, Jogador& player, sf::Clock& clock);

private:
	sf::Text skillUsada;
	bool TheWorld = false;
	bool pegarTempo = false;
	int qualP;
};

