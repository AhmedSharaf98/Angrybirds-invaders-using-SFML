#include "dependencies.h"

int main(){
	highScores.ReadFromFile();
	__data.ReadFromFile();
	load();
	InitializeMenus();
	initializeLogo();
	initializeUserMenuStuff();
	Menu menu_CreateOrLogin(gameMenue.getSize().x, gameMenue.getSize().y, __data.getNumberOfUsers() + 1);
	initializeCreateOrLoginMenu(menu_CreateOrLogin);
	sf::Thread bgThread(&processbg, &newBg);
	bgThread.launch();
	if (__data.getNumberOfUsers() == 0) currentMenu = CreateUser;
	else currentMenu = CreateOrLogin;

	while (gameMenue.isOpen())
	{
		HandleEvents(gameMenue, menu_CreateOrLogin);
		gameMenue.draw(newBg.bg1);
		gameMenue.draw(newBg.bg2);
		switch (currentMenu)
		{
		case mainMenu:
			menu_main.draw(gameMenue);
			MouseHoverUpdate(menu_main);
			gameMenue.draw(Spr_logo);
			gameMenue.draw(welcomeMessage);
			break;
		case playMenu:
			menu_play.draw(gameMenue);
			MouseHoverUpdate(menu_play);
			gameMenue.draw(Spr_logo);
			break;
		case HighscoresMenu:
			highScores.PrintToScreen(gameMenue, font);
			menu_Highscores.draw(gameMenue);
			MouseHoverUpdate(menu_Highscores);
			break;
		case CreateUser:
			menu_createUser.draw(gameMenue);
			gameMenue.draw(Spr_logo);
			gameMenue.draw(text_username);
			gameMenue.draw(text_password);
			gameMenue.draw(UserCreatedOrNot);
			MouseHoverUpdate(menu_createUser);
			break;
		case Login:		
			menu_login.draw(gameMenue);
			gameMenue.draw(Spr_logo);
			gameMenue.draw(text_username);
			gameMenue.draw(text_password);
			gameMenue.draw(UserCreatedOrNot);
			MouseHoverUpdate(menu_login);
			break;
		case CreateOrLogin:
			menu_CreateOrLogin.draw(gameMenue);
			drawTextsUsers();
			MouseHoverUpdate(menu_CreateOrLogin);
		default:
			break;
		}
		if (win || lose) {
			//setEndingText();
			highScores.CheckAndInsert(__data.GetUsername(loggedInIndex), players[0].getScore());
			highScores.PrintToScreen(gameMenue, font);
			highScores.UpdateInFile();
		}
		gameMenue.display();
		gameMenue.clear();
	}
	highScores.UpdateInFile();
	system("pause");
}