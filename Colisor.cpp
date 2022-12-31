#include "Colisor.h"

Colisor::Colisor(sf::RectangleShape& corpo):
	corpo(corpo)
{

}

int Colisor::checarColisao(Colisor& outra)
{
	sf::Vector2f outraPos = outra.getPos();
	sf::Vector2f outraMet = outra.getMetadeTam();
	sf::Vector2f essaPos = getPos();
	sf::Vector2f essaMet = getMetadeTam();

	float deltaX = outraPos.x - essaPos.x;
	float deltaY = outraPos.y - essaPos.y;

	float intersectX = abs(deltaX) - (outraMet.x + essaMet.x);
	float intersectY = abs(deltaY) - (outraMet.y + essaMet.y);

	if (intersectX < 0 && intersectY < 0) {

		if (intersectX > intersectY) {

			if (deltaX > 0.0f) { //Pela direita
				return 1;
			}
			else { //Pela esquerda
				return 2;
			}
		}
		else {
			if (deltaY > 0.0f) { //Por baixo
				return 3;
			}
			else { ///Por cima
				return 4;
			}
		}
	}

	return false;
}
