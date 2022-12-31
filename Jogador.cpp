#include "Jogador.h"

Jogador::Jogador(sf::Vector2f tamanho, sf::Vector2f quadraPos, sf::Vector2f quadraTam)
{
	this->tamanho = tamanho;
	
	inicialPos1.x = quadraPos.x + 50;
	inicialPos2.x = quadraTam.x - 50;

	inicialPos1.y = quadraPos.y;
	inicialPos2.y = quadraPos.y;

	player1.setSize(tamanho);
	player1.setOrigin(sf::Vector2f(tamanho.x / 2, tamanho.y / 2));
	player1.setPosition(inicialPos1);
	player1.setFillColor(sf::Color::White);

	player2.setSize(tamanho);
	player2.setOrigin(sf::Vector2f(tamanho.x / 2, tamanho.y / 2));
	player2.setPosition(inicialPos2);
	player2.setFillColor(sf::Color::White);

}

void Jogador::movimento()
{
	sf::Vector2f move1 = sf::Vector2f(0.f, 0.f);
	sf::Vector2f move2 = sf::Vector2f(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move1.y = -1 * speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move1.y = 1 * speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		move2.y = -1 * speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		move2.y = 1 * speed;

if(!TW1)
	player1.move(move1);

if(!TW2)
	player2.move(move2);
}

void Jogador::desenhar(sf::RenderWindow& janela)
{
	janela.draw(player1);
	janela.draw(player2);
}

void Jogador::checkCol(Colisor& outroCorpo)
{
	if (getColisor1().checarColisao(outroCorpo) == 3) {
		player1.move(0, -1 * speed);
	}
	if (getColisor1().checarColisao(outroCorpo) == 4) {
		player1.move(0, 1 * speed);
	}

	if (getColisor2().checarColisao(outroCorpo) == 3) {
		player2.move(0, -1 * speed);
	}
	if (getColisor2().checarColisao(outroCorpo) == 4) {
		player2.move(0, 1 * speed);
	}
	
}


