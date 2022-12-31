#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogador.h"
#include "Estadio.h"
#include "Colisor.h"
#include "BolaQuadrada.h"
#include "Placar.h"
#include "Skills.h"


int main() {
	sf::RenderWindow janela(sf::VideoMode(600, 400), "PONG 2", sf::Style::Default);

	sf::Event evnt;

	const sf::Vector2f playerSize = sf::Vector2f(20, 60);

	Estadio quadra(janela.getSize());

	Jogador players(playerSize, quadra.getCenarioPos(), quadra.getCenarioTam());

	sf::Font fonte;
	fonte.loadFromFile("Fonte/Mine.ttf");

	Placar placar(fonte, janela.getSize());

	Colisor paredeCima = quadra.getColisor1();
	Colisor paredeBaixo = quadra.getColisor2();
	Colisor golE = quadra.getColisorGolE();
	Colisor golD = quadra.getColisorGolD();

	Colisor Cplayer1 = players.getColisor1();
	Colisor Cplayer2 = players.getColisor2();

	BolaQuadrada bolaMassa;

	Skills skill(janela.getSize(), fonte);
	sf::Clock clock;

	while (janela.isOpen()) {
		
		sf::Time tempo = clock.getElapsedTime();

		while (janela.pollEvent(evnt)) {

			if (evnt.type == sf::Event::Closed)
				janela.close();
		}
//		std::cout << "\nTempo: " << tempo.asSeconds();

		janela.clear();

		quadra.desenharCenario(janela);
		placar.desenhar(janela);
		players.movimento();

		skill.ativar(bolaMassa, players, clock, janela);
		skill.OMUNDO(bolaMassa, players, clock);

		players.checkCol(paredeCima);
		players.checkCol(paredeBaixo);

		bolaMassa.rolar();
		bolaMassa.desenhar(janela);
		bolaMassa.checarCol(paredeCima);
		bolaMassa.checarCol(paredeBaixo);
		bolaMassa.checarCol(Cplayer1);
		bolaMassa.checarCol(Cplayer2);
		bolaMassa.checarGol(golE, placar);
		bolaMassa.checarGol(golD, placar);

		players.desenhar(janela);

		placar.setPointText();

		janela.display();
	}
}