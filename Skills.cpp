#include "Skills.h"

Skills::Skills(sf::Vector2u tamanhoJanela, sf::Font &fonte)
{
	sf::Vector2f tamanhoJaaj = static_cast<sf::Vector2f>(tamanhoJanela);
	skillUsada.setPosition(sf::Vector2f(tamanhoJaaj.x /2 - 70, tamanhoJaaj.y -50));
	skillUsada.setCharacterSize(25);
	skillUsada.setFont(fonte);
}

void Skills::ativar(BolaQuadrada& bola, Jogador& player, sf::Clock& clock, sf::RenderWindow& janela)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//		OMUNDO(bola, player, 1, clock);
		qualP = 1;
		TheWorld = true;
		pegarTempo = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
		//		OMUNDO(bola, player, 1, clock);
		qualP = 2;
		TheWorld = true;
		pegarTempo = true;
	}
	if (TheWorld == true) {
		if (qualP == 1)
			skillUsada.setFillColor(sf::Color::Blue);

		if (qualP == 2)
			skillUsada.setFillColor(sf::Color::Red);
		skillUsada.setString("O MUNDO!");
		janela.draw(skillUsada);
	}
}

void Skills::OMUNDO(BolaQuadrada& bola, Jogador& player, sf::Clock& clock)
{
static sf::Time tempoI;
sf::Time tempoF;
float eixoX;
float eixoY;

if (bola.getEixoX() != 0) {
	eixoX = bola.getEixoX();
}
if (bola.getEixoY() != 0) {
	eixoY = bola.getEixoY();
}

/*
if (bola.getEixoX() != 0 && bola.getEixoX() != eixoX) {
	eixoX = bola.getEixoX();
}
if (bola.getEixoY() != 0 && bola.getEixoY() != eixoY) {
	eixoX = bola.getEixoY();
} */

	if (TheWorld) {
		if (pegarTempo) {
			tempoI = clock.getElapsedTime();		
			pegarTempo = false;
		}
		else {
//			eixoX = eixoX;
//			eixoY = eixoX;
		}
		tempoF = clock.getElapsedTime();
		float deltaT = tempoF.asSeconds() - tempoI.asSeconds();
//		std::cout << eixoX << "      " << eixoY << "       " << pegarTempo << "\n";
//		std::cout << "\n" << deltaT<<"      " << tempoI.asSeconds() << "      " << tempoF.asSeconds()<<"\n";
//		std::cout << eixoX << "      " << eixoY<<"\n";
		if (deltaT < 2) {
			bola.setEixos(0, 0);
		}
		else if(deltaT >= 2) {
			
			bola.setEixos(eixoX, eixoY);
			TheWorld = false;
			
		}
		if (qualP == 1) {
			player.setTW2(true);
		}
		if (qualP == 2) {
			player.setTW1(true);
		}
	}
	else {
		player.setTW2(false);
		player.setTW1(false);
	}
/*	float eixoX = bola.getEixoX();
	float eixoY = bola.getEixoY();

	bola.setEixos(0, 0);

	sf::Time tempoI = clock.getElapsedTime();
	sf::Time tempoF = clock.getElapsedTime();

	float deltaT = tempoF.asSeconds() - tempoI.asSeconds();

	while (!(deltaT >= 2)) {
		std::cout << deltaT << "\n";
		tempoF = clock.getElapsedTime();
		deltaT = tempoF.asSeconds() - tempoI.asSeconds();
	}
	bola.setEixos(eixoX, eixoY); */
}
