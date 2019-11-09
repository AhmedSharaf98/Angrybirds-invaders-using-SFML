#pragma once
#ifndef LEVELS
#define LEVELS



void makeWave1() {																													//UPDATE2	
	SmallChicken s;																													//UPDATE2
	for (int i = 0; i < 3; i++) {																									//UPDATE2
		for (int j = 0; j < 11; j++) {																								//UPDATE2
			switch ((j + i) % 2) {																									//UPDATE2
			case 0:																													//UPDATE2
				s.setPosition(100 * j + 50, 100 * i + 70); //70 => 50 is the half of the heigh + 20 margin for the score above.		//UPDATE2
				smallChickens.push_back(s);																							//UPDATE2
				break;																												//UPDATE2
			case 1:																													//UPDATE2
																																	//UPDATE2
				if (i == 1) {																										//UPDATE2
					BigChicken b(bigGreen); //Insert gwa																			//UPDATE2
					b.setPosition(100 * j + 50, 100 * i + 70);																		//UPDATE2
					bigChickens.push_back(b);																						//UPDATE2
				}																													//UPDATE2
				else {																												//UPDATE2
					BigChicken b(bigRed);																							//UPDATE2
					b.setPosition(100 * j + 50, 100 * i + 70);																		//UPDATE2
					bigChickens.push_back(b);																						//UPDATE2
				}																													//UPDATE2
																																	//UPDATE2
				break;																												//UPDATE2
			}																														//UPDATE2
		}																															//UPDATE2
	}																																//UPDATE2
}


void makeWave2() {
	for (int i = 0; i < 50; i++) {
		stone s(false);
		stones.push_back(s);
		sf::sleep(sf::milliseconds(300));
	}
}

void makewave5(int n) {																								 //UPDATE
	srand(time(NULL));																								 //UPDATE
	for (int i = 0; i < n; i++) {																					 //UPDATE
		int delay = rand() % 1500 + 500;																			 //UPDATE
		int randomX = rand() % gameMenue.getSize().x - 50;															 //UPDATE
		while (descendingChickens.size() != 0 && (abs(randomX - descendingChickens.back().getPosition().x) < 100)) 	 //UPDATE
			randomX = rand() % gameMenue.getSize().x - 50;															 //UPDATE
		descendingChickens.push_back(DescendingChicken(randomX, -200));												 //UPDATE
		sleep(sf::milliseconds(delay));																				 //UPDATE
	}																												 //UPDATE
}


void makeWave3() {
	for (int i = 0; i < 2; i++) {
		srand(std::time(NULL));
		stone s(3);
		stones.push_back(s);
		sf::sleep(sf::milliseconds(150));
	}
}

void makeBeast1() {
	beast b(0, 0, beast1, 1);																	
	b.setPosition((gameMenue.getSize().x - b.getSprite().getGlobalBounds().width) / 2, 0);		
	beasts.push_back(b);																		
}																																													//UPDATE//UPDATE
void makeBeast2() {																				
	beast b(0, 0, beast2, 2);																	
	b.setPosition((gameMenue.getSize().x - b.getSprite().getGlobalBounds().width) / 2, 0);		
	beasts.push_back(b);																		
}																								

void makeBeast3() {																				
	beast b(0, 0, beast3, 3);																	
	b.setPosition((gameMenue.getSize().x - b.getSprite().getGlobalBounds().width) / 2, 0);		
	beasts.push_back(b);																		
}

void wave4() {
	for (int i = 0; i < 50; i++) {
		stone s(true);
		stones.push_back(s);
		sf::sleep(sf::milliseconds(300));
	}
}

void wave5() {
	for (int i = 0; i < 2; i++) {
		stone s(3);
		stones.push_back(s);
		sf::sleep(sf::milliseconds(300));
	}
}


#endif // !LEVELS
