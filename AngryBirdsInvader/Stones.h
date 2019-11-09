#pragma once
#ifndef _STONES_
#define _STONES_
class stone{
private:
	int type;
	int currentGeneration;
	bool exitable;
	Sprite sprite;
	int size; //Width Equal to Height
	int strength;
	int maxSpeed;
	int xFactor, yFactor;

public:
	stone(int, int , int); //COnstructor for unExitable Stone
	stone(bool); //COnstructor for Exitable Stone
	int getGeneration() {
		return currentGeneration;
	}
	void go();
	Sprite getSprite() {
		return sprite;
	}
	int getSize() {
		return size;
	}																				
	bool explode();
	bool damage(int x);
	void rotate();
};


void stone::rotate() {
	sprite.rotate(2);
}
	
bool stone::damage(int x) {
	strength -= x;
	if (strength <= 0)
		return true;
	return false;
}

stone::stone(int generation, int x = 0 , int y = 0) {
	srand(seeder);
	seeder++;
	type = 1;
	strength = generation * 2;
	currentGeneration = generation;
	do {
		xFactor = std::rand() % 5 - 2;
		yFactor = std::rand() % 5 - 2;
	} while (xFactor == 0 || yFactor == 0);
	sprite.setTexture(rock);
	float scale = (.25 * float(currentGeneration));
	size = ceil(100.0 * scale);
	sprite.setScale(scale, scale);
	sprite.setPosition(x , y);
}
stone::stone(bool agressive) {
	type = 0;
	sprite.setTexture(rock);
	currentGeneration = 1;
	float scale = (25.0 + double(rand() % 101)) / 100.0;
	sprite.setScale(scale, scale);
	size = ceil(100.0 * scale);
	strength = ceil(scale * 7 + .1);
	if (!agressive) {
		xFactor = 1;
		maxSpeed = 1;
		if (rand() % 2)
			sprite.setPosition(WIDTH, rand() % (HEIGHT + 1));
		else
			sprite.setPosition(rand() % (WIDTH + 1), 0 - size);
	}
	else {
		xFactor = 0;
		maxSpeed = 5;
		sprite.setPosition(rand() % (WIDTH + 1), 0 - size);
	}
	
}

void stone::go() {
	if (type) {
		sprite.move(xFactor, yFactor);
		if (sprite.getPosition().x  + size> WIDTH || sprite.getPosition().x < 0) xFactor *= -1;
		if (sprite.getPosition().y + size > HEIGHT || sprite.getPosition().y < 0) yFactor *= -1;
	}
	else {
		int speed = rand() % maxSpeed + 1;
		sprite.move(-1 * speed * xFactor, speed);
	}
	
}
bool stone::explode() {
	//sound for explosion
	Explosions temp;
	temp.sprite.setTexture(RockExplosion);
	temp.sprite.setTextureRect(IntRect(0, 0, 119, 118));
	temp.sprite.setScale(sprite.getScale());
	//temp.sprite.setOrigin(55 * sprite.getScale().x, 55 * sprite.getScale().y);
	temp.sprite.setPosition(sprite.getPosition().x , sprite.getPosition().y );
	rockexplosion.push_back(temp);
	rock_explosion_sound[rand() % 3].play();
	if (currentGeneration > 1) return true;
	return false;
}

vector <stone> stones;
#endif
