#pragma once
#ifndef _RED_
#define _RED_
class _redbullet : public baseBullet {
private:
	int accelarator;
	int dx; //delta x - Relative to angle of shotting
public:
	_redbullet(int);
	void go();
	Position getPosition() {
		return currentPosition;
	}
	sf::Sprite getSprite() {
		return spri;
	}
	void accelrate() {
		if(!(stepNumber % 35))
			accelarator++;
	}
	void modify(int, int, int);
};

void _redbullet::modify(int x, int y, int angle) {
	currentPosition.x = x;
	currentPosition.y = y;
	spri.setPosition(x, y);
	dx = angle / 5;  //change in X-Axes for each bullet will depend on the angle of shot
	spri.rotate(-1 * angle); //Angle will be multiples of 30, -ve or +ve relative to vertical line of the player
}
_redbullet::_redbullet(int produ) {
	accelarator = 1;
	spri.setScale(.1, .1);
	spri.setTexture(g_redbulllet);
	delay = std::chrono::milliseconds(7);
	producer = produ;
}
void _redbullet::go() {
	if (system_clock::now() > crearted + stepNumber * delay){
		accelrate();
		stepNumber++;
		currentPosition.x -= dx * (stepNumber % 2) * accelarator;
		currentPosition.y -= accelarator;
		spri.setPosition(currentPosition.x, currentPosition.y);
	}
}

vector<_redbullet> reds;
#endif 