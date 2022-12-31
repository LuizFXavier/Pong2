#include "BolaQuadrada.h"

BolaQuadrada::BolaQuadrada()
{
	srand(time(NULL));
	bola.setSize(sf::Vector2f(20.f, 20.f));
	bola.setOrigin(bola.getSize() / 2.f);

	bola.setPosition(sf::Vector2f(300.f, 200.f));

	bola.setFillColor(sf::Color::Magenta);
	
	int randomX = std::rand() % 2;
	int randomY = std::rand() % 2;

	eixoX = 1;
	eixoY = 1;

	if (randomX) {
		eixoX = -1;
	}
	if (randomY) {
		eixoY = -1;
	}

	move.x = eixoX * speedX;
	move.y = eixoY * speedY;
}

void BolaQuadrada::checarCol(Colisor& outro)
{
	srand(time(NULL));

	float randomX = std::rand() % 3 +1;
	float randomX2 = std::rand() % 2;

	float randomY = std::rand() % 3 + 1;
	float randomY2 = std::rand() % 2;

	randomX *= 0.01;
	randomY *= 0.01;

	if (randomX2)
		randomX *= -1;

	if (randomY2)
		randomY *= -1;

	if (getColisor().checarColisao(outro) == 1 || getColisor().checarColisao(outro) == 2) {
		speedX += randomX;
		bola.move(sf::Vector2f((eixoX * -1) * speedX, 0));
		eixoX *= -1;

		if (speedX > 0.12) {
			speedX = 0.12;
		}
		if (speedX < 0.08) {
			speedX = 0.08;
		}
//		std::cout<< "\nSpeedX:" << speedX;
//		std::cout << "\nSpeedY:" << speedY;
//		std::cout << "\n-------";
		
	} 

	if (getColisor().checarColisao(outro) == 3 || getColisor().checarColisao(outro) == 4) {
		speedY += randomY;
		bola.move(sf::Vector2f(0, (eixoY * -1) * speedY));
		eixoY *= -1;

		if (speedY > 0.12) {
			speedY = 0.12;
		}
		if (speedY < 0.05) {
			speedY = 0.05;
		}
//		std::cout << "\nSpeedX:" << speedX;
	//	std::cout << "\nSpeedY:" << speedY;
//		std::cout << "\n-------";
		
	} 

	move.x = eixoX * speedX;
	move.y = eixoY * speedY;
}

void BolaQuadrada::checarGol(Colisor& gol, Placar& placar)
{
	srand(time(NULL));
	int randomP = std::rand() % 37 + 2;
	int randomY = std::rand() % 2;

	if (randomY)
		eixoY *= -1;

	randomP *= 10;

	if (getColisor().checarColisao(gol)) {

		if (getColisor().checarColisao(gol) == 1) {
			bola.setPosition(sf::Vector2f(250, randomP));
			placar.mudarPlacar(1);
		}	

		if (getColisor().checarColisao(gol) == 2) {
			bola.setPosition(sf::Vector2f(350, randomP));
			placar.mudarPlacar(2);
		}
		
	}
	

}
