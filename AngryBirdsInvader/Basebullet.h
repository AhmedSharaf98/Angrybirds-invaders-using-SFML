#pragma once
#ifndef _BaseBullet_
#define _BaseBullet_
using namespace std::chrono;
class baseBullet {
protected:
	int producer; //0 or 1 (Player Number)
	Position currentPosition;
	sf::Sprite spri;
	duration<double> delay;
	int stepNumber;
	time_point<system_clock>crearted;
	baseBullet() {
		stepNumber = 1;
		crearted = system_clock::now();
	}
	Sprite getSprite() {
		return spri;
	}
public:
	int getProducer() {
		return producer;
	}
};
#endif // !_BaseBullet_
