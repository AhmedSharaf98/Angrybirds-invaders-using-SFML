#pragma once
#ifndef _PLAYER_
#define _PLAYER_
class player{
private:
	time_point<system_clock>died_In , sheild_in;
	double alpha, alpha_factor;
	int lives, rockets, chickenparts, score;
	Text t_lives, t_rockets, t_power, t_parts, t_score, t_activate;
	int playerNumber;//This is going to be number 1 or 2. textures names will be include that number, also startup location will be function of it.
	int horizontalBoundary, VerticalBoundary; //Will Filled by game Window Dimensions to control player's boundaries
	int width, height; //Gonna be placed by scalling the sprite relative to window Dimensions
	Position p_position;
	sf::Sprite p_sprite, panelSprite, p_sheild;
	int currnetSheildFrame;
	playerState player_state;
	Weapon weapon;
	void setupTexts();
public:
	player(RECT, int);
	int getPlayerNumber();
	void drawPlayer(sf::RenderWindow&);
	void fireRocket();
	void move(int , int);
	void explode(); 
	void reborn();
	void gainlife();
	void loselife();
	void gainrocket();
	void increaseScore(int);
	void collectChikkenPart(ChickenLegType);
	void setPosition();
	void powerUp(WeaponType);
	void animateSpaceship();
	void animateSheild();
	void putSheild();
	int getScore() { return score; }
	void setContinueUserData(int, int, int, int, int);
	void setPlayerState(playerState x) {
		player_state = x;
	}
	playerState getPlayerState() {
		return player_state;
	}
	Position getPosition() {
		return p_position;
	}
	void fire();
	Sprite getSprite() {
		return p_sprite;
	}
};

void player::putSheild() {
	sheild_in = system_clock::now();
	setPlayerState(sheild);
}

void player::setContinueUserData(int _score, int _lives, int _rockets, int _chickenPart, int _weaponPower) {
	score = _score;
	lives = _lives;
	rockets = _rockets;
	chickenparts = _chickenPart;
	weapon.setPower(_weaponPower);
}

void player::animateSheild() {
	p_sheild.setTextureRect(IntRect(++currnetSheildFrame * 75,0,75,180));
	if (currnetSheildFrame == 6) currnetSheildFrame = -1;
}


void player::powerUp(WeaponType x) {
	//Sound to Power Up
	if (x == all || x == weapon.getCurrentWeapon()) weapon.powerUp();
	else weapon.changeWeapon(x);
	t_power.setString(to_string(weapon.getPower()));
}
void player::setupTexts() {
	int center = WIDTH / 2;
	t_lives.setFont(userDataFont);
	t_lives.setCharacterSize(15);
	t_lives.setOrigin(playerNumber * 12 , 0);
	t_lives.setFillColor(sf::Color(255, 255,255,150));
	t_lives.setPosition(center + (playerNumber * 2 - 1) * (center - 35), HEIGHT - 24);
	
	t_parts = t_lives;
	t_power = t_lives;
	t_rockets = t_lives;
	t_score = t_lives;

	
	
	t_rockets.move((playerNumber * 2 - 1) * - 45, 0);
	t_power.move((playerNumber * 2 - 1) * - 85, 0);
	t_parts.move((playerNumber * 2 - 1) * - 130, 0);
	t_score.move(0, -1 * (HEIGHT - 25));

	alpha = 150.0;
	alpha_factor = .5;
	t_activate = t_lives;
	t_activate.setString("Please Press Left Mouse To Join..");
	t_activate.setOrigin(t_activate.getGlobalBounds().width * playerNumber, 0);
	t_lives.setString(to_string(lives));
	t_parts.setString(to_string(chickenparts));
	t_rockets.setString(to_string(rockets));
	t_power.setString(to_string(weapon.getPower()));
	t_score.setString(to_string(score));

	
}
player::player(RECT size, int p_num){
	panelSprite.setTexture(playerBanel[p_num]);
	panelSprite.setOrigin(p_num * 200 , 0);
	panelSprite.setPosition(p_num * WIDTH, HEIGHT - 36);
	player_state = deactivated;
	playerNumber = p_num;
	lives = 5;
	rockets = 0;
	chickenparts = 0;
	score = 0;
	//float scale = float(size.right) / (75 * 20.0); //Making the rocket width 1/20 screen width (713 is ship orginal width)
	//width = 713 * scale;
	//height =  180 * scale; //Keeping the same ration
	//p_sprite.setScale(scale, scale);
	width = 75 * .5;
	height = 180 * .5;
	currnetSheildFrame = -1;
	p_sprite.setTextureRect(IntRect(playerNumber * 225 + 75, 0, 75, 180));
	p_sheild.setScale(.75, 1);
	p_sprite.setScale(.5, .5);
	horizontalBoundary = size.right - width;
	int margin_Down = 50; // 50 Is the Default margin from bottom
	VerticalBoundary = size.bottom - (height + margin_Down); // 50 Is the Default margin from bottom
	p_position.x = size.right / 3 * (playerNumber+1); //Setting the Player one in the third and plauer two on the second third
	p_position.y = size.bottom - (height + margin_Down);
	p_sprite.setTexture(spaceship);
	p_sheild.setTexture(playersheild);
	setPosition();
 	weapon.setBoundaries(horizontalBoundary, VerticalBoundary);
	setupTexts();
}
void player::setPosition() {
	p_sprite.setPosition(p_position.x, p_position.y);
}
int player::getPlayerNumber() {
	return playerNumber;
}
void player::drawPlayer(sf::RenderWindow& wind) {
	if (player_state == deactivated) {
		if (alpha >= 255.0) alpha_factor = -0.5;
		else if (alpha <= 0.0) alpha_factor = 0.5;
		alpha += alpha_factor;
		t_activate.setFillColor(sf::Color(255, 255, 255, int(alpha)));
		wind.draw(t_activate);
	} else {
		if (player_state == playing) {
			weapon.draw(wind);
			wind.draw(p_sprite);
		}
		else if (player_state == sheild) {
			if (died_In > sheild_in) {
				if (system_clock::now() > died_In + std::chrono::milliseconds(2000)) {
					p_sheild.setPosition(p_sprite.getPosition().x - 9, p_sprite.getPosition().y - 15);
					wind.draw(p_sprite);
					wind.draw(p_sheild);
					weapon.draw(wind);
					if (system_clock::now() > died_In + std::chrono::milliseconds(7000)) {
						p_sprite.setTexture(spaceship);
						currnetSheildFrame = -1;
						setPlayerState(playing);
					}
				}
			}
			else {
				p_sheild.setPosition(p_sprite.getPosition().x - 9, p_sprite.getPosition().y - 15);	
				wind.draw(p_sprite);
				wind.draw(p_sheild);
				weapon.draw(wind);
				if (system_clock::now() > sheild_in + std::chrono::milliseconds(10000)) {
					p_sprite.setTexture(spaceship);
					currnetSheildFrame = -1;
					setPlayerState(playing);
				}
					
			}
		}
		wind.draw(panelSprite);
		wind.draw(t_parts);
		wind.draw(t_lives);
		wind.draw(t_rockets);
		wind.draw(t_power);
		wind.draw(t_score);
	}
}
void player::fireRocket() {

}
void player::move(int x, int y) {
	if (p_position.x + x < 0) p_position.x = 0;
	else if (p_position.x + x > horizontalBoundary) p_position.x = horizontalBoundary;
	else p_position.x += x;

	if (p_position.y + y < 0) p_position.y = 0;
	else if (p_position.y + y > VerticalBoundary) p_position.y = VerticalBoundary;
	else p_position.y += y;
	setPosition();
}
void player::explode() {
	weapon.powerToHalf();
	Explosions temp;
	temp.sprite.setTexture(Explosion);
	temp.sprite.setOrigin(49, 45);
	temp.sprite.setTextureRect(IntRect(0, 0, 99, 90));
	temp.sprite.setPosition(Vector2f(p_sprite.getPosition().x + width / 2, p_sprite.getPosition().y + height / 2));
	explosion.push_back(temp);
	explosion_sound.play();
	loselife();
}
void player::reborn() {
	died_In = system_clock::now();
	p_sprite.setTexture(spaceship);
	p_position.x = gameMenue.getSize().x / 3 * (playerNumber + 1);
	p_position.y = gameMenue.getSize().y - (height + 50);
	p_sprite.setPosition(p_position.x , p_position.y );
	setPlayerState(sheild);
	if(playerNumber == 1)
		sf::Mouse::setPosition(Vector2i(getPosition().x, getPosition().y));
	//Animation for Reborn
	//Sound for Reborn
}
void player::gainlife() {
	lives++;
	t_lives.setString(to_string(lives));
}
void player::loselife() {
	lives--;
	t_lives.setString(to_string(lives));
	if (lives <= 0) {
		setPlayerState(dead);
	}
	else reborn();
}
void player::gainrocket() {
	if (chickenparts >= 50) {
		gainRocket.play();
		chickenparts %= 50;
		rockets++;
		t_rockets.setString(to_string(rockets));
	}
	t_parts.setString(to_string(chickenparts));
}
void player::increaseScore(int x) {
	score += x;
	t_score.setString(to_string(score));
	t_score.setOrigin(t_score.getGlobalBounds().width * playerNumber, 0);
}
void player::collectChikkenPart(ChickenLegType x) {
	switch (x)
	{
	case leg:
		//Music
		chickenparts += 1;
		increaseScore(250);
		break;
	case sandwich:
		chickenparts += 5;
		increaseScore(500);
		break;
	case chicken:
		chickenparts += 10;
		increaseScore(1000);
		break;
	default:
		break;
	}
	gainrocket();
}

void player::fire() {
	weapon.fire(p_position.x + width / 2, p_position.y, playerNumber);
}

vector <player> players;
#endif // !_PLAYER_
