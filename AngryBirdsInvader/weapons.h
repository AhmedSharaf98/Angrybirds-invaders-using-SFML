#pragma once
#ifndef _Weapons_
#define _Weapons_


;using namespace std;
class Weapon
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	int power;
	int maxPower;
	WeaponType weaponType;
	int xboundry, yboundry;

	void redShot(int, int, int);
	void greenShot(int, int , int);
	void yellowShot(int, int, int);
public:
	Weapon(); //In case of select weapon before starting the game
	void changeWeapon(WeaponType); //Changing the maxPower also
	void powerUp(); //power++
	void powerToHalf(); //Power to its half
	void fire(int, int, int);
	void setBoundaries(int, int);
	void draw(sf::RenderWindow&);
	void setPower(int x) {
		power = x;
	}
	int getPower() {
		return power;
	}
	WeaponType getCurrentWeapon() {
		return weaponType;
	}
};

void Weapon::draw(sf::RenderWindow& win) {
	Position p;
	for (int i = 0; i < reds.size(); i++){
		p = reds[i].getPosition();
		if (p.x > xboundry || p.x < 0 || p.y > yboundry || p.y < 0) {
			reds.erase(reds.begin() + i);
			i--;
		} else {
			reds[i].go();
			win.draw(reds[i].getSprite());
		}
	}
}
Weapon::Weapon(){
	buffer.loadFromFile("Resources/redbullet.wav");
	power = 1;
	changeWeapon(red);
}
void Weapon::setBoundaries(int x, int y) {
	xboundry = x;
	yboundry = y;
}
void Weapon::changeWeapon(WeaponType t) {
	weaponType = t;
	switch (t)
	{
	case green:
		maxPower = 20;
		break;
	case yellow:
		maxPower = 25;
		break;
	case red:
		maxPower = 10;
		break;
	}
	if (power > maxPower)
		power = maxPower;
}
void Weapon::powerUp() {
	if (power < maxPower)
		power++;
}
void Weapon::powerToHalf() {
	power = ceil(double(power) / 2.0);
}
void Weapon::fire(int _x, int _y, int playerNumber) {
	switch (weaponType)
	{
	case red:
		sound.setBuffer(buffer);
		sound.play();
		redShot(_x - 5, _y , playerNumber);
		break;
	case green:
		//Sound
		greenShot( _x, _y, playerNumber);
		break;
	case yellow:
		//Sound
		yellowShot( _x, _y, playerNumber);
		break;
	}
}

void Weapon::redShot(int x, int y , int p) {
	_redbullet temp(p);
	switch (power) {
	case 1:
		temp.modify(x, y, 0);
		reds.push_back(temp);
		break;
	case 2:
		temp.modify(x - 8, y, 0);
		reds.push_back(temp);
		temp.modify(x + 8, y, 0);
		reds.push_back(temp);
		break;
	case 3:
		temp.modify(x, y - 5, 0);
		reds.push_back(temp);
		temp.modify(x - 16, y, 0);
		reds.push_back(temp);
		temp.modify(x + 16, y, 0);
		reds.push_back(temp);
		break;
	case 4:
		temp.modify(x, y - 5, 0);
		reds.push_back(temp);
		temp.modify(x - 2, y, 5);
		reds.push_back(temp);
		temp.modify(x + 2, y, -5);
		reds.push_back(temp);
		break;
	case 5:
		temp.modify(x - 2, y - 5, 5);
		reds.push_back(temp);
		temp.modify(x + 2, y - 5, -5);
		reds.push_back(temp);
		temp.modify(x - 4, y, 10);
		reds.push_back(temp);
		temp.modify(x + 4, y, -10);
		reds.push_back(temp);
		break;
	case 6:
		temp.modify(x, y - 15, 0);
		reds.push_back(temp);
		temp.modify(x - 2, y - 5, 5);
		reds.push_back(temp);
		temp.modify(x + 2, y - 5, -5);
		reds.push_back(temp);
		temp.modify(x - 4, y, 10);
		reds.push_back(temp);
		temp.modify(x + 4, y, -10);
		reds.push_back(temp);
		break;
	case 7:
		temp.modify(x - 8, y - 10, 0);
		reds.push_back(temp);
		temp.modify(x + 8, y - 10, 0);
		reds.push_back(temp);

		temp.modify(x - 2, y - 5, 5);
		reds.push_back(temp);
		temp.modify(x + 2, y - 5, -5);
		reds.push_back(temp);
		temp.modify(x - 4, y, 10);
		reds.push_back(temp);
		temp.modify(x + 4, y, -10);
		reds.push_back(temp);
		break;
	case 8:
		temp.modify(x - 10, y - 10, 0);
		reds.push_back(temp);
		
		temp.modify(x - 2, y - 5, 5);
		reds.push_back(temp);
		temp.modify(x - 18, y - 5, 5);
		reds.push_back(temp);

		temp.modify(x + 2, y - 5, -5);
		reds.push_back(temp);
		temp.modify(x + 18, y - 5, -5);
		reds.push_back(temp);

		temp.modify(x - 4, y, 10);
		reds.push_back(temp);
		temp.modify(x + 4, y, -10);
		reds.push_back(temp);
		break;
	case 9:
		temp.modify(x - 8, y - 10, 0);
		reds.push_back(temp);
		temp.modify(x + 8, y - 10, 0);
		reds.push_back(temp);

		temp.modify(x - 2, y - 5, 5);
		reds.push_back(temp);
		temp.modify(x - 18, y - 5, 5);
		reds.push_back(temp);

		temp.modify(x + 2, y - 5, -5);
		reds.push_back(temp);
		temp.modify(x + 18, y - 5, -5);
		reds.push_back(temp);

		temp.modify(x - 4, y, 10);
		reds.push_back(temp);
		temp.modify(x + 20, y, -10);
		reds.push_back(temp);
		break;
	case 10:
		temp.modify(x - 10, y - 10, 0);
		reds.push_back(temp);
		temp.modify(x + 10, y - 10, 0);
		reds.push_back(temp);

		temp.modify(x - 2, y - 5, 5);
		reds.push_back(temp);
		temp.modify(x - 18, y - 5, 5);
		reds.push_back(temp);

		temp.modify(x + 2, y - 5, -5);
		reds.push_back(temp);
		temp.modify(x + 18, y - 5, -5);
		reds.push_back(temp);

		temp.modify(x - 4, y, 10);
		reds.push_back(temp);
		temp.modify(x - 20, y, 10);
		reds.push_back(temp);

		temp.modify(x + 4, y, -10);
		reds.push_back(temp);
		temp.modify(x + 20, y, -10);
		reds.push_back(temp);
		break;
	}
}

void Weapon::greenShot(int x, int y, int p) {

}

void Weapon::yellowShot(int x, int y, int p) {

}
#endif // !_Weapons_
