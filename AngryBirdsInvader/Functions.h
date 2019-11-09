#pragma once
#ifndef Functions_H
#define Functions_H


int counter_2 = 0;																							//UPDATE2
int direction_2 = 1;

void beastsMovement() {
	if (beasts.size() == 0) return;											//UPDATE2
	if (beasts[0].getPosition().x == 50) direction_2 = 1;																		//UPDATE2
	else if (beasts[0].getPosition().x + beasts[0].getSprite().getGlobalBounds().width == gameMenue.getSize().x - 50) direction_2 = -1;
	if (counter_2 % 4 == 0 && beasts[0].getBeastNumber() != 3) {																					//UPDATE2
		beasts[0].move(direction_2, 0);					//UPDATE2																		//UPDATE2
	}																										//UPDATE2
	counter_2++;																							//UPDATE2
	if (beasts[0].getBeastNumber() == 3 && counter_2 % 6 == 0) {
		for (int i = 0; i < Eggs.size(); i++) {
			switch (i % 3)
			{
			case 0: Eggs[i].move(0, 3); break;
			case 1: Eggs[i].move(3, 3); break;
			case 2: Eggs[i].move(-3, 3); break;
			default:
				break;
			}
		}
	}
}

int counter_beast_2 = 0;
void BeastsActions() {
	if (beasts.size() == 0) return;
	if (beasts[0].getBeastNumber() == 2) {
		if (counter_beast_2 % 3000 == 0 && bigChickens.size() < 5) {
			BigChicken b(bigRed);
			b.setPosition(beasts[0].getPosition().x + beasts[0].getSprite().getGlobalBounds().width / 2, beasts[0].getPosition().y + beasts[0].getSprite().getGlobalBounds().height / 2);
			bigChickens.push_back(b);
		}
		if (bigChickens.size() > 0 && bigChickens.back().getPosition().y - beasts[0].getPosition().y < beasts[0].getSprite().getGlobalBounds().height + 50) {
			bigChickens.back().move(0, 1);
		}
	}
	else if (beasts[0].getBeastNumber() == 3 && counter_beast_2 % 1000 == 0) {
		int x, y;
		x = beasts[0].getPosition().x + beasts[0].getSprite().getGlobalBounds().width / 2;
		y = beasts[0].getPosition().y + beasts[0].getSprite().getGlobalBounds().height / 2;
		Eggs.push_back(Egg(x, y, EggType::shit));
		Eggs.push_back(Egg(x, y, EggType::shit));
		Eggs.push_back(Egg(x, y, EggType::shit));
	}
	counter_beast_2++;
}

void beastsEggFunction() {
	//int x, y;
	/*while (gameMenue.isOpen())
	{
		if (beasts.size() != 0 && beasts[0].getBeastNumber() != 3) {
			x = beasts[0].getPosition().x + rand() % (int)beasts[0].getSprite().getGlobalBounds().width;
			y = beasts[0].getPosition().y + beasts[0].getSprite().getGlobalBounds().height / 2;
			Egg tempEgg(x, y, EggType::Eggg);
			Eggs.push_back(tempEgg);
			int temp = rand() % 4 + 2;
			sleep(sf::milliseconds(150 * temp));
		}
	}*/
}







void mooooove() {															//UPDATE
	if (velocity < maxV) {													//UPDATE
		velocity++;															//UPDATE
	}																		//UPDATE
	switch (p_movement_x)													//UPDATE
	{																		//UPDATE
	case movement::left: players[0].move(-velocity, 0); break;				//UPDATE
	case movement::right: players[0].move(velocity, 0); break;				//UPDATE
	default:																//UPDATE
		break;																//UPDATE
	}																		//UPDATE
																			//UPDATE
	switch (p_movement_y)													//UPDATE
	{																		//UPDATE
	case movement::up:  players[0].move(0, -velocity); break;				//UPDATE
	case movement::down:  players[0].move(0, velocity); break;				//UPDATE
	default:																//UPDATE
		break;																//UPDATE
	}																		//UPDATE																			//UPDATE
}


void setLevelText(String num, string txt) {
	bg_speed = 1;
	suspense.play();
	lvl_number.setString(num);
	level_txt.setString(txt);
}

void displayLevelMessage() {
	if (msg_alpha < 0) return;
	msg_alpha -= 0.18;
	level_txt.setFillColor(Color(255, 255, 255, msg_alpha));
	lvl_number.setFillColor(Color(255, 255, 255, msg_alpha));
	level_txt.setPosition(WIDTH / 2 - (level_txt.getGlobalBounds().width / 2), HEIGHT / 4 + 30);
	lvl_number.setPosition(WIDTH / 2 - (lvl_number.getGlobalBounds().width / 2), HEIGHT / 4 );
	gameMenue.draw(level_txt);
	gameMenue.draw(lvl_number);
}


int remMoves = gameMenue.getSize().x - 1100;																//UPDATE2
int counter_1 = 0;																							//UPDATE2
int direction_1 = 1;																							//UPDATE2
void wave1Movement() {																						//UPDATE2
	if (smallChickens.size() != 0 && bigChickens.size() != 0) {
		if (remMoves == 0) direction_1 = -1;																		//UPDATE2
		else if (remMoves == gameMenue.getSize().x - 1100) direction_1 = 1;										//UPDATE2
		if (counter_1 % 4 == 0) {																					//UPDATE2
			for (int i = 0; i < smallChickens.size(); i++) smallChickens[i].move(direction_1, 0);					//UPDATE2
			for (int i = 0; i < bigChickens.size(); i++) bigChickens[i].move(direction_1, 0);						//UPDATE2
			remMoves -= direction_1;																				//UPDATE2
		}																										//UPDATE2
		counter_1++;																								//UPDATE2
	}
}



void processbg(BackgroundData *bg) {
	while (gameMenue.isOpen()) {
		if (bg->bg1.getPosition().y >= bg->limit)
			bg->bg1.setPosition(bg->bg1.getPosition().x, 0 - bg->limit);
		if (bg->bg2.getPosition().y >= bg->limit)
			bg->bg2.setPosition(bg->bg2.getPosition().x, 0 - bg->limit);
		bg->bg1.setPosition(bg->bg1.getPosition().x, bg->bg1.getPosition().y + 1.0);
		bg->bg2.setPosition(bg->bg2.getPosition().x, bg->bg2.getPosition().y + 1.0);
		sf::sleep(sf::milliseconds(bg_speed));
	}
}

template <class t>		// ONLY for chicken
void drawVector(std::vector <t> x) {
	for (int i = 0; i < x.size(); i++) {
		x[i].drawSprite();
	}
}

void drawFog() {
	for (int i = 0; i < fog.size(); i++) {
		gameMenue.draw(fog[i].sprite);
	}
}
void drawExplosion() {
	for (int i = 0; i < explosion.size(); i++) {
		gameMenue.draw(explosion[i].sprite);
	}
}

void drawRockExplosion() {
	for (int i = 0; i < rockexplosion.size(); i++) {
		gameMenue.draw(rockexplosion[i].sprite);
	}
}



void drawGifts() {
	for (int i = 0; i < gifts.size(); i++) {
		gifts[i].sprite.move(0, 1);
		gameMenue.draw(gifts[i].sprite);
	}
}

void drawSheildGifts() {
	for (int i = 0; i < Sheilds.size(); i++) {
		Sheilds[i].sprite.move(0, 1);
		gameMenue.draw(Sheilds[i].sprite);
	}
}
void drawStones() {
	for (int i = 0; i < stones.size(); i++) {
		stones[i].go();
		gameMenue.draw(stones[i].getSprite());
	}
}
void EggFuncion() {
	int x, y;
	while (gameMenue.isOpen())
	{
		if (bigChickens.size() != 0) {
			int rnd = rand() % (bigChickens.size() + smallChickens.size());
			if (rnd < bigChickens.size()) {
				x = bigChickens[rnd].getPosition().x - 12;
				y = bigChickens[rnd].getPosition().y + 42;
				Egg tempEgg(x, y, EggType::Eggg);
				Eggs.push_back(tempEgg);
			}
			else {
				x = smallChickens[rnd - bigChickens.size()].getPosition().x - 15;
				y = smallChickens[rnd - bigChickens.size()].getPosition().y + 30;
				Egg tempEgg(x, y, EggType::shit);
				Eggs.push_back(tempEgg);
			}
			int temp = rand() % 4 + 2;
			sleep(sf::milliseconds(800 * temp));
		}
		else if (beasts.size() != 0) {
			x = beasts[0].getPosition().x + rand() % (int)beasts[0].getSprite().getGlobalBounds().width;
			y = beasts[0].getPosition().y + 100;
			Egg tempEgg(x, y, EggType::Eggg);
			Eggs.push_back(tempEgg);
			int temp = rand() % 4 + 2;
			sleep(sf::milliseconds(150 * temp));
		}
	}
}

void drawDescendingChickens() {														 //UPDATE
	for (int i = 0; i < descendingChickens.size(); i++) {							 //UPDATE
		if (descendingChickens[i].getPosition().y > HEIGHT) {						 //UPDATE
			descendingChickens.erase(descendingChickens.begin() + i);				 //UPDATE
			i--;																	 //UPDATE
		}																			 //UPDATE
		else {																		 //UPDATE
			descendingChickens[i].go();												 //UPDATE
			descendingChickens[i].drawSprite();										 //UPDATE
		}																			 //UPDATE
	}																				 //UPDATE
}

void drawEggs() {
	for (int i = 0; i < Eggs.size(); i++) {
		if (Eggs[i].getPosition().y > HEIGHT) {
			Eggs.erase(Eggs.begin() + i);
			i--;
			//sound of egg break
		}
		else {
			Eggs[i].go();
			Eggs[i].drawSprite();
		}
	}
}

void drawParts() {
	for (int i = 0; i < parts.size(); i++) {
		if (parts[i].getJumps() == 3) {
			parts.erase(parts.begin() + i);
			i--;
			continue;
		}
		else if (parts[i].getPosition().y + 50 >= HEIGHT) {
			parts[i].setPosition(parts[i].getPosition().x, HEIGHT - 50);	////////////// error??!
			parts[i].reverseY();
			parts[i].incrementJumps();
		}
		else if (parts[i].getPosition().x <= 0) {
			parts[i].setPosition(0, parts[i].getPosition().y);	////////////// error??!
			parts[i].reverseX();
		}
		else if (parts[i].getPosition().x + 50 >= WIDTH) {
			parts[i].setPosition(WIDTH - 50, parts[i].getPosition().y);	////////////// error??!
			parts[i].reverseX();
		}
		parts[i].go();
		parts[i].drawSprite();
	}
}

void makeplayer(RECT rec, int num) {
	player temp(rec, num);
	players.push_back(temp);
}




void observe() {
	bool isEgg, isPart, isGift, isSheild;

	for (int i = 0; i < stones.size(); i++) {
		if (players[0].getPlayerState() == playing)
			if (stones[i].getSprite().getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds()))
				players[0].explode();
		if (players[1].getPlayerState() == playing)
			if (stones[i].getSprite().getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds()))
				players[1].explode();
	}

	for (int i = 0; i < stones.size(); i++) {
		for (int j = 0; j < reds.size(); j++) {
			if (stones[i].getSprite().getGlobalBounds().intersects(reds[j].getSprite().getGlobalBounds())) { //Change Reds to green
				players[reds[j].getProducer()].increaseScore(50);

				if (stones[i].damage(1)) {
					players[reds[j].getProducer()].increaseScore(50);
					if (stones[i].explode()) {
						for (int k = 0; k < 3; k++) {
							stone s1(stones[i].getGeneration() - 1, stones[i].getSprite().getPosition().x, stones[i].getSprite().getPosition().y);
							stones.push_back(s1);
						}
					}
					stones.erase(stones.begin() + i);
					i--;
					break;
				}
				reds.erase(reds.begin() + j);
				j--;
			}
		}
	}


	for (int i = 0; i < descendingChickens.size(); i++) {
		for (int j = 0; j < reds.size(); j++) {
			if (descendingChickens[i].getSprite().getGlobalBounds().intersects(reds[j].getSprite().getGlobalBounds())) { //Change Reds to green
				players[reds[j].getProducer()].increaseScore(50);
				descendingChickens[i].hit();
				if (descendingChickens[i].damage(1)) {
					Fogs temp;
					temp.sprite.setTexture(Fog);
					temp.sprite.setOrigin(50, 46);
					temp.sprite.setTextureRect(IntRect(0, 0, 99, 93));
					temp.sprite.setPosition(Vector2f(descendingChickens[i].getSprite().getPosition().x + descendingChickens[i].getSprite().getGlobalBounds().width / 2, descendingChickens[i].getSprite().getPosition().y + descendingChickens[i].getSprite().getGlobalBounds().height / 2));
					fog.push_back(temp);
					players[reds[j].getProducer()].increaseScore(50);
					descendingChickens.erase(descendingChickens.begin() + i);
					SbigDies[rand() % 3].play();
					i--;
					break;
				}
				reds.erase(reds.begin() + j);
				j--;
			}
		}
	}


	for (int i = 0; i < bigChickens.size(); i++) {
		if (players[0].getPlayerState() == playing)
			if (bigChickens[i].getSprite().getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds()))
				players[0].explode();
		if (players[1].getPlayerState() == playing)
			if (bigChickens[i].getSprite().getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds()))
				players[1].explode();



		for (int j = 0; j < reds.size(); j++) {
			if (bigChickens[i].getSprite().getGlobalBounds().intersects(reds[j].getSprite().getGlobalBounds())) {
				players[reds[j].getProducer()].increaseScore(100);
				if (bigChickens[i].damage(1)) { //TODO add bullet power //Note Red power is jsut their number
					players[reds[j].getProducer()].increaseScore(100);
					bigChickens[i].die();


					if (rand() % 4) { //75% f died chicken will give you part of gift
						if (rand() % 2) //98% of chicken that will give you something will give your part
							parts.push_back(ChickenPart(bigChickens[i].getPosition().x, bigChickens[i].getPosition().y));
						else { //2% will give you Gift
							if (rand() % 2) {
								Gifts temp;
								int r = rand() % 4;
								temp.sprite.setScale(.5, .5);
								temp.sprite.setTexture(redGift);
								temp.type = red;
								temp.sprite.setPosition(bigChickens[i].getPosition().x, bigChickens[i].getPosition().y);
								gifts.push_back(temp);
							}
							else {
								SheildGifts temp;
								temp.sprite.setScale(.5, .5);
								temp.sprite.setTexture(TexSheild);
								temp.sprite.setPosition(bigChickens[i].getPosition().x, bigChickens[i].getPosition().y);
								Sheilds.push_back(temp);
							}
						}
					}



					bigChickens.erase(bigChickens.begin() + i);
					SbigDies[rand() % 3].play();
					i--;
					reds.erase(reds.begin() + j);
					break;
				}
				else {
					bigChickens[i].hit();
					reds.erase(reds.begin() + j);
					j--;
				}
			}
		}
	}










		for (int i = 0; i < beasts.size(); i++) {
			if (players[0].getPlayerState() == playing)
				if (beasts[i].getSprite().getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds()))
					players[0].explode();
			if (players[1].getPlayerState() == playing)
				if (beasts[i].getSprite().getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds()))
					players[1].explode();



			for (int j = 0; j < reds.size(); j++) {
				if (beasts[i].getSprite().getGlobalBounds().intersects(reds[j].getSprite().getGlobalBounds())) {
					players[reds[j].getProducer()].increaseScore(100);
					if (beasts[i].hit(1)) { //TODO add bullet power //Note Red power is jsut their number
						players[reds[j].getProducer()].increaseScore(100);
						for (int m = 0; m < 20; m++) {
							parts.push_back(ChickenPart(beasts[i].getPosition().x, beasts[i].getPosition().y));
						}

						Gifts _temp;
						int r = rand() % 4;
						_temp.sprite.setScale(.5, .5);
						_temp.sprite.setTexture(redGift);
						_temp.type = red;
						_temp.sprite.setPosition(beasts[i].getPosition().x, beasts[i].getPosition().y);
						gifts.push_back(_temp);

						Explosions temp;
						temp.sprite.setTexture(Explosion);
						temp.sprite.setOrigin(49, 45);
						temp.sprite.setScale(3, 3);
						temp.sprite.setTextureRect(IntRect(0, 0, 99, 90));
						temp.sprite.setPosition(beasts[i].getPosition().x, beasts[i].getPosition().y);
						explosion.push_back(temp);
						explosion_sound.play();
						beasts.erase(beasts.begin() + i);
						i--;
						reds.erase(reds.begin() + j);
						break;
					}
					else {
						reds.erase(reds.begin() + j);
						j--;
					}
				}
			}
	}

	for (int i = 0; i < smallChickens.size(); i++) {
		if (players[0].getPlayerState() == playing)
			if (smallChickens[i].getSprite().getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds()))
				players[0].explode();
		if (players[1].getPlayerState() == playing)
			if (smallChickens[i].getSprite().getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds()))
				players[1].explode();
		for (int j = 0; j < reds.size(); j++) {
			if (smallChickens[i].getSprite().getGlobalBounds().intersects(reds[j].getSprite().getGlobalBounds())) { //Change Reds to green
				players[reds[j].getProducer()].increaseScore(50);
				if (smallChickens[i].damage(1)) { //TODO add bullet power //Note Red power is jsut their number
					players[reds[j].getProducer()].increaseScore(50);
					SsmallDies[rand() % 3].play();
					smallChickens[i].die();


					if (rand() % 2) { //75% f died chicken will give you part of gift
						if (rand() % 2) //98% of chicken that will give you something will give your part
							parts.push_back(ChickenPart(smallChickens[i].getPosition().x, smallChickens[i].getPosition().y));
						else { //2% will give you 
							if (rand() % 2) {
								Gifts temp;
								int r = rand() % 4;
								temp.sprite.setScale(.5, .5);
								temp.sprite.setTexture(redGift);
								temp.type = red;
								temp.sprite.setPosition(smallChickens[i].getPosition().x, smallChickens[i].getPosition().y);
								gifts.push_back(temp);
							}
							else {
								SheildGifts temp;
								temp.sprite.setScale(.5, .5);
								temp.sprite.setTexture(TexSheild);
								temp.sprite.setPosition(smallChickens[i].getPosition().x, smallChickens[i].getPosition().y);
								Sheilds.push_back(temp);
							}
						}
					}


					smallChickens.erase(smallChickens.begin() + i);
					i--;
					reds.erase(reds.begin() + j);
					break;
				}
				else {
					smallChickens[i].hit();
					reds.erase(reds.begin() + j);
					j--;
				}
			}
		}




		//TODO add Yellow and Green Similar to above
	}
	for (int i = 0; i < Eggs.size(); i++) {
		isEgg = false;
		if (players[0].getPlayerState() == playing)
			if (Eggs[i].getSprite().getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds())) {
				players[0].explode();
				isEgg = true;
			}
		if (players[1].getPlayerState() == playing)
			if (Eggs[i].getSprite().getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds())) {
				players[1].explode();
				isEgg = true;		
			}
		if (isEgg) {
			Eggs.erase(Eggs.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < parts.size(); i++) {
		isPart = false;
		if (players[0].getPlayerState() == playing || players[0].getPlayerState() == sheild)
			if (parts[i].getSprite().getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds())) {
				players[0].collectChikkenPart(parts[i].getType());
				isPart = true;
			}
		if (players[1].getPlayerState() == playing || players[1].getPlayerState() == sheild)
			if (parts[i].getSprite().getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds())) {
				players[1].collectChikkenPart(parts[i].getType());
				isPart = true;
			}
		if (isPart) {
			parts.erase(parts.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < gifts.size(); i++) {
		isGift = false;
		if (players[0].getPlayerState() == playing || players[0].getPlayerState() == sheild)
			if (gifts[i].sprite.getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds())) {
				players[0].powerUp(gifts[i].type);
				isGift = true;
			}
		if (players[1].getPlayerState() == playing || players[1].getPlayerState() == sheild)
			if (gifts[i].sprite.getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds())) {
				players[1].powerUp(gifts[i].type);
				isGift = true;
			}
		if (isGift) {
			gifts.erase(gifts.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < Sheilds.size(); i++) {
		isSheild = false;
		if (players[0].getPlayerState() == playing || players[0].getPlayerState() == sheild)
			if (Sheilds[i].sprite.getGlobalBounds().intersects(players[0].getSprite().getGlobalBounds())) {
				//players[0].powerUp(gifts[i].type);
				players[0].putSheild();
				isSheild = true;
			}
		if (players[1].getPlayerState() == playing || players[1].getPlayerState() == sheild)
			if (Sheilds[i].sprite.getGlobalBounds().intersects(players[1].getSprite().getGlobalBounds())) {
				//players[1].powerUp(gifts[i].type);
				players[1].putSheild();
				isSheild = true;
			}
		if (isSheild) {
			Sheilds.erase(Sheilds.begin() + i);
			i--;
		}
	}
}

void animate() {
	while (gameMenue.isOpen()) {

		for (int i = 0; i < beasts.size(); i++) {
			beasts[i].returnn();
		}

		for (int i = 0; i < descendingChickens.size(); i++) {
			descendingChickens[i].returnn();
		}


		for (int i = 0; i < bigChickens.size(); i++) {
			bigChickens[i].animate(rand() % 4);
		}
		for (int i = 0; i < smallChickens.size(); i++) {
			smallChickens[i].animate(rand() % 4);
		}
		for (int i = 0; i < Eggs.size(); i++) {
			//Eggs[i].animate();
		}

		for (int i = 0; i < gifts.size(); i++) {//TODO Edit info based on sprite sheet
			if(gifts[i].type == all){
				gifts[i].sprite.setTextureRect(IntRect(++gifts[i].currnet * 99, 0, 99, 93));
				if (gifts[i].currnet == 4) gifts[i].currnet = -1;
			}
			if (gifts[i].sprite.getPosition().y >= HEIGHT) {
				gifts.erase(gifts.begin() + i);
				i--;
			}
		}


		for (int i = 0; i < Sheilds.size(); i++) {
			if (Sheilds[i].sprite.getPosition().y >= HEIGHT) {
				Sheilds.erase(Sheilds.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < fog.size(); i++) {
			if (fog[i].currnet >= 4) {
				fog.erase(fog.begin() + i);
				i--;
			}
			else {
				fog[i].sprite.setTextureRect(IntRect(++fog[i].currnet * 99, 0, 99, 93));
			}
		}
		for (int i = 0; i < explosion.size(); i++) {
			if (explosion[i].currnet >= 8) {
				explosion.erase(explosion.begin() + i);
				i--;
			}
			else {
				explosion[i].sprite.setTextureRect(IntRect(++explosion[i].currnet * 99, 0, 99, 90));
			}
		}

		for (int i = 0; i < rockexplosion.size(); i++) {
			if (rockexplosion[i].currnet >= 5) {
				rockexplosion.erase(rockexplosion.begin() + i);
				i--;
			}
			else {
				rockexplosion[i].sprite.setTextureRect(IntRect(++rockexplosion[i].currnet * 119, 0, 119, 118));
			}
		}

		for (int i = 0; i < stones.size(); i++) {
			if (stones[i].getSprite().getPosition().y > HEIGHT || stones[i].getSprite().getPosition().x < 0 - stones[i].getSprite().getGlobalBounds().width) {
				stones.erase(stones.begin() + i);
				i--;
			}
			else {
				stones[i].rotate();
			}
		}

		if (players[0].getPlayerState() == playerState::sheild)
			players[0].animateSheild();
		if (players[1].getPlayerState() == playerState::sheild)
			players[1].animateSheild();
		sf::sleep(sf::milliseconds(100));
	}
}
#endif // !Functions_H
