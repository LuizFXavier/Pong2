#include "Placar.h"

Placar::Placar(sf::Font& fonte, sf::Vector2u tamanhoJanela)
{
	tamanhoJaaj = static_cast<sf::Vector2f>(tamanhoJanela);

	placarST.setFont(fonte);
	placarST.setCharacterSize(30);
	placarST.setOrigin(sf::Vector2f(placarST.getCharacterSize() / 2, placarST.getCharacterSize() / 2));
	placarST.setPosition(sf::Vector2f((tamanhoJaaj.x / 2) + 50, 50));

	placarWS.setFont(fonte);
	placarWS.setCharacterSize(30);
	placarWS.setOrigin(sf::Vector2f(placarWS.getCharacterSize() / 2, placarWS.getCharacterSize() /2));
	placarWS.setPosition(sf::Vector2f((tamanhoJaaj.x / 2) - 50, 50));

	pontoST = 0;
	pontoWS = 0;

}

void Placar::mudarPlacar(int quem)
{
	if (quem == 1)
		pontoWS++;

	if (quem == 2)
		pontoST++;
}

void Placar::setPointText()
{
	std::stringstream ST;
	std::stringstream WS;

	ST << pontoST;
	WS << pontoWS;

	std::string SST;
	std::string WWS;

	ST >> SST;
	WS >> WWS;

	placarST.setString(SST);
	placarWS.setString(WWS);
}