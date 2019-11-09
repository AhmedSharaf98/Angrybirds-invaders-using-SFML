#pragma once
#ifndef GAME
#define GAME


void gameLevels(int s) {
	for (int i = 0; i < s; i++)
		levels[i] = 1;

	

	if(!levels[0]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 1", "ARE YOU READY FOR CHICKENS!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		makeWave1();
		while (true) {
			if (smallChickens.size() == 0 && bigChickens.size() == 0 && parts.size() == 0 && Eggs.size() == 0) {
				levels[0] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}
	if (!levels[1]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 2", "ARE YOU READY FOR THE ROCKS NEHAHAHAH!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		makeWave2();
		while (true) {
			if (stones.size() == 0 ) {
				levels[1] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}

	if (!levels[2]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 3", "ARE YOU READY FOR THE FIRST BOSS!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		makeBeast1();
		while (true) {
			if (beasts.size() == 0) {
				levels[2] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}

	if (!levels[3]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 4", "Descending Checkens!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		makewave5(20);
		while (true) {
			if (descendingChickens.size() == 0) {
				levels[3] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}

	if (!levels[4]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 5", "Fast Stones Nehahahah!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		wave4();
		while (true) {
			if (stones.size() == 0) {
				levels[4] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}

	if (!levels[5]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 6", "One Stone!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		wave5();
		while (true) {
			if (stones.size() == 0) {
				levels[5] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}

	if (!levels[6]) {
		sf::sleep(sf::milliseconds(1000));
		setLevelText("WAVE 7", "ARE YOU READY FOR THE Second BOSS!");
		msg_alpha = 255.0;
		while (msg_alpha > 0) {
			sf::sleep(sf::milliseconds(500));
		}
		bg_speed = 30;
		makeBeast2();
		while (true) {
			if (beasts.size() == 0 && bigChickens.size() == 0 && Eggs.size() == 0) {
				levels[7] = 1;
				break;
			}
			sf::sleep(sf::milliseconds(1000));
		}
	}

	win = true;
}


void startGame(int start = 0, bool cont = false) {
	bgmuzic.stop();
	gameMenue.setMouseCursorVisible(false);
	makeplayer(desktop, 0);
	makeplayer(desktop, 1);
	
	if (cont) {
		players[0].setContinueUserData(__data.Getscore(loggedInIndex), __data.GetLives(loggedInIndex), __data.GetRockets(loggedInIndex), __data.GetChickenParts(loggedInIndex), __data.GetWeaponPower(loggedInIndex));
	}
	//players[0].setContinueUserData(500, 5, 9, 9, 9);
	players[0].setPlayerState(playing);
	/*sf::Thread bgThread(&processbg, &newBg);
	bgThread.launch();*/
	sf::Thread gamelevel(&gameLevels, start);
	gamelevel.launch();
	//makeBeast1();
	//makeWave1();
	/*sf::Thread lvl3(&makeWave3);
	lvl3.launch();*/
	//Thread wave2Thread(&makewave2, 20);
	//wave2Thread.launch();
	Thread eggThread(&EggFuncion);
	eggThread.launch();
	Thread beastsEggThread(&beastsEggFunction);
	beastsEggThread.launch();
	Thread animations(&animate);
	animations.launch();
	gameMenue.setFramerateLimit(350);
	while (gameMenue.isOpen()) {
		Event event;
		while (gameMenue.pollEvent(event)) {
			if (event.type == Event::KeyPressed && (players[0].getPlayerState() == playing || players[0].getPlayerState() == sheild)) {
				if (event.key.code == Keyboard::S)	players[0].gainlife();
				if (event.key.code == Keyboard::Up)	p_movement_y = up;
				if (event.key.code == Keyboard::Down) p_movement_y = down;
				if (event.key.code == Keyboard::Right) p_movement_x = movement::right;
				if (event.key.code == Keyboard::Left) p_movement_x = movement::left;
				if (event.key.code == Keyboard::Space) players[0].fire();
				if (event.key.code == Keyboard::LAlt) players[0].fireRocket();
			}
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (players[1].getPlayerState() == deactivated) {
						sf::Mouse::setPosition(Vector2i(players[1].getPosition().x, players[1].getPosition().y));
						players[1].setPlayerState(playing);
					}
					else if (players[1].getPlayerState() == playing || players[1].getPlayerState() == sheild)
						players[1].fire();
				}
				if (event.mouseButton.button == Mouse::Right && (players[1].getPlayerState() == playing || players[1].getPlayerState() == sheild))
					players[1].fireRocket();
			}
			if (event.type == Event::MouseMoved) {
				if (players[1].getPlayerState() == playing || players[1].getPlayerState() == sheild) {
					players[1].move(event.mouseMove.x - players[1].getPosition().x, event.mouseMove.y - players[1].getPosition().y);
				}
			}
			if (event.type == Event::KeyReleased) {
				velocity = 1;
				switch (event.key.code)
				{
				case Keyboard::Left: case Keyboard::Right: p_movement_x = stop; break;
				case Keyboard::Up: case Keyboard::Down: p_movement_y = stop; break;

				default:
					break;
				}
			}
		}
		
		gameMenue.clear();
		gameMenue.draw(newBg.bg1);
		gameMenue.draw(newBg.bg2);
		if (!win) {
			observe();
			drawEggs();
			drawParts();
			drawFog();
			drawExplosion();
			drawRockExplosion();
			drawGifts();
			drawSheildGifts();
			drawStones();
			players[1].drawPlayer(gameMenue);
			players[0].drawPlayer(gameMenue);
			drawVector <SmallChicken>(smallChickens);
			drawVector <BigChicken>(bigChickens);
			drawDescendingChickens();
			drawVector <ChickenPart>(parts);
			drawVector <beast>(beasts);
			mooooove();											//UPDATE
			wave1Movement();	//if level 1
			BeastsActions();
			beastsMovement();displayLevelMessage();
		}
		else {
			setLevelText("Congratulations!!", "You WON THE GAME.....");
			level_txt.setPosition(WIDTH / 2 - (level_txt.getGlobalBounds().width / 2), HEIGHT + 30);
			lvl_number.setPosition(WIDTH / 2 - (lvl_number.getGlobalBounds().width / 2), HEIGHT);
		}
		if (win || lose)
			return;
		gameMenue.display();
	}
}



#endif // !GAME
