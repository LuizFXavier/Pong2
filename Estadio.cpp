#include "Estadio.h"

Estadio::Estadio(sf::Vector2u tamanhoJanela)
{
	tamanhoJaaj = static_cast<sf::Vector2f>(tamanhoJanela);

	cenario.setSize(sf::Vector2f(tamanhoJaaj.x -10, tamanhoJaaj.y -10));
	cenario.setOrigin(sf::Vector2f(cenario.getSize().x / 2, cenario.getSize().y / 2));
	cenario.setPosition(tamanhoJaaj.x / 2, tamanhoJaaj.y / 2);
	cenario.setFillColor(sf::Color::Black);
	cenario.setOutlineThickness(10);
	cenario.setOutlineColor(sf::Color{200, 200, 200 });

	meio.resize(32, sf::RectangleShape());

	for (int i = 0; i < 32; i++) {
		meio[i].setSize(tamanhoMeio);
		meio[i].setOrigin(tamanhoMeio / 2.f);
		meio[i].setPosition(sf::Vector2f(tamanhoJaaj.x / 2, 14 + i * 12));
		meio[i].setFillColor(sf::Color::White);
	}

	paredes.resize(2, sf::RectangleShape());

	for (int j = 0; j < 2; j++) {
		paredes[j].setSize(sf::Vector2f(tamanhoJaaj.x, 10));
		paredes[j].setOrigin(paredes[j].getSize() / 2.f);
	}
	paredes[0].setPosition(sf::Vector2f(tamanhoJaaj.x / 2.f, 0));
	paredes[0].setFillColor(sf::Color::Red);

	paredes[1].setPosition(sf::Vector2f(tamanhoJaaj.x / 2.f, tamanhoJaaj.y));
	paredes[1].setFillColor(sf::Color::Red);

	golDireita.setSize(sf::Vector2f(10.f, tamanhoJaaj.y));
	golDireita.setOrigin(golDireita.getSize() / 2.f);
	golDireita.setPosition(tamanhoJaaj.x, tamanhoJaaj.y / 2.f);

	golEsquerda.setSize(sf::Vector2f(10.f, tamanhoJaaj.y));
	golEsquerda.setOrigin(golEsquerda.getSize() / 2.f);
	golEsquerda.setPosition(0, tamanhoJaaj.y / 2.f);

}

void Estadio::desenharCenario(sf::RenderWindow& janela)
{
	janela.draw(cenario);
	
//	janela.draw(paredes[0]);
//	janela.draw(paredes[1]);

//	janela.draw(golDireita);
//	janela.draw(golEsquerda);

	for (int i = 0; i < 32; i++)
		janela.draw(meio[i]);
}
