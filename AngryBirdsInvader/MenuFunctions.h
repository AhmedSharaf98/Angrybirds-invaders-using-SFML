#pragma once
#ifndef MenuFunctions
#define MenuFunctions

void continueGame() {
	startGame(__data.GetCurrentLevel(loggedInIndex) , true);
}

void NewGame() {
	__data.reset(loggedInIndex);
	startGame(__data.GetCurrentLevel(loggedInIndex));
}
void initializeTextsUsers() {
	for (int i = 0; i < __data.getNumberOfUsers(); i++) {
		sf::Text temp;
		temp.setFont(font);
		temp.setCharacterSize(20);
		temp.setFillColor(sf::Color::White);
		temp.setString(__data.GetUsername(i));
		Texts_users.push_back(temp);
	}
}

void drawTextsUsers() {
	for (int i = 0; i < Texts_users.size(); i++) {
		gameMenue.draw(Texts_users[i]);
	}
}


bool isPointOverSprite(const sf::Sprite sprite)
{
	sf::Mouse mouse;
	sf::Vector2i mousePosition = mouse.getPosition(gameMenue);
	return (sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y));
}

void tryToCreateUser() {
	if (__data.CheckAndInsert(username, password)) {
		__data.UpdateInFile();
		UserCreatedOrNot.setString("Get ready to save the world!");
		UserCreatedOrNot.setPosition((gameMenue.getSize().x - UserCreatedOrNot.getGlobalBounds().width) / 2, 650);
		UserCreatedOrNot.setFillColor(sf::Color::Green);
		currentMenu = mainMenu;
		loggedInIndex = __data.getNumberOfUsers() - 1;
		welcomeMessage.setString("Welcome, " + __data.GetUsername(loggedInIndex));
		welcomeMessage.setPosition((gameMenue.getSize().x - welcomeMessage.getGlobalBounds().width) / 2, 440);
	}
	else {
		UserCreatedOrNot.setString("Already Exists!");
		UserCreatedOrNot.setPosition((gameMenue.getSize().x - UserCreatedOrNot.getGlobalBounds().width) / 2, 650);
		UserCreatedOrNot.setFillColor(sf::Color::Red);
	}
}
void tryToLogin() {
	int userIndex = __data.CheckUserFound(username, password);
	if (userIndex == -1) {
		UserCreatedOrNot.setString("No user found with these credentials!");
		UserCreatedOrNot.setPosition((gameMenue.getSize().x - UserCreatedOrNot.getGlobalBounds().width) / 2, 650);
		UserCreatedOrNot.setFillColor(sf::Color::Red);
	}
	else {
		loggedInIndex = userIndex;
		UserCreatedOrNot.setString("Get ready to save the world!");
		UserCreatedOrNot.setPosition((gameMenue.getSize().x - UserCreatedOrNot.getGlobalBounds().width) / 2, 650);
		UserCreatedOrNot.setFillColor(sf::Color::Green);
		currentMenu = mainMenu;
		welcomeMessage.setString("Welcome, " + __data.GetUsername(loggedInIndex));
		welcomeMessage.setPosition((gameMenue.getSize().x - welcomeMessage.getGlobalBounds().width) / 2, 440);
	}
}

void HandleMainMenu(sf::Event event) {
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			menu_main.MoveUp();
			break;

		case sf::Keyboard::Down:
			menu_main.MoveDown();
			break;

		case sf::Keyboard::Return:
			switch (menu_main.GetPressedItem())
			{
			case 0:	//Save the World Menu
				currentMenu = playMenu;
				break;
			case 1:	//Hall of Fame Menu/list
				currentMenu = HighscoresMenu;
				break;
			case 2:	//Options Menu
				break;
			case 3:	//Credits
				break;
			case 4:	//Close
				gameMenue.close();
				break;
			}
			break;
		}
		break;
	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < menu_main.GetNumberOFItems(); i++) {
			if (isPointOverSprite(menu_main.GetSprite(i))) {
				switch (i)
				{
				case 0:	//Save the World Menu
					currentMenu = playMenu;
					break;
				case 1:	//Hall of Fame Menu/list
					currentMenu = HighscoresMenu;
					break;
				case 2:	//Options
					break;
				case 3:	//Credits
					break;
				case 4:
					gameMenue.close();	//Close
					break;
				default:
					break;
				}
			}
		}
		break;
	case sf::Event::Closed:
		gameMenue.close();
		break;
	}
}
void HandlePlayMenu(sf::Event event) {
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			menu_play.MoveUp();
			break;

		case sf::Keyboard::Down:
			menu_play.MoveDown();
			break;

		case sf::Keyboard::Return:
			switch (menu_play.GetPressedItem())
			{
			case 0:	//new Game Function
				startGame();
				break;
			case 1:	//Continue 
				continueGame();
				break;
			case 2:	//Back
				currentMenu = mainMenu;
				break;
			}
			break;
		}
		break;

	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < menu_play.GetNumberOFItems(); i++) {
			if (isPointOverSprite(menu_play.GetSprite(i))) {
				switch (i)
				{
				case 0:	//New Game Function
					startGame();
					break;
				case 1:	//Continue Function
					continueGame();
					break;
				case 2:	//Back
					currentMenu = mainMenu;
					break;
				default:
					break;
				}
			}
		}
		break;
	case sf::Event::Closed:
		gameMenue.close();
		break;
	}
}
void HandleCreateUserMenu(sf::Event event) {
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			menu_createUser.MoveUp();
			break;

		case sf::Keyboard::Down:
			menu_createUser.MoveDown();
			break;

		case sf::Keyboard::Return:
			switch (menu_createUser.GetPressedItem())
			{
			case 0:
				if (username != "") menu_createUser.MoveDown();
				break;
			case 1:
				if (password != "") menu_createUser.MoveDown();
				break;
			case 2:	//Create
				tryToCreateUser();
				break;
			}
			break;
		}
		break;
	case sf::Event::TextEntered:
		if (event.text.unicode < 0x80) // it's printable
		{
			switch (menu_createUser.GetPressedItem())
			{
			case 0:
				if ((char)event.text.unicode == 13) {}
				else if ((char)event.text.unicode == 8) {
					username = username.substr(0, username.size() - 1);
					text_username.setString(username);
				}
				else if (username.size() < 21) {
					username += (char)event.text.unicode;
					text_username.setString(username);
				}
				break;
			case 1:
				if ((char)event.text.unicode == 13) {}
				else if ((char)event.text.unicode == 8) {
					password = password.substr(0, password.size() - 1);
					if (password.size() != 0) {
						string temp(password.length() - 1, '*');
						text_password.setString(temp);
					}
				}
				else if (password.size() < 21) {
					password += (char)event.text.unicode;
					string temp(password.length() - 1, '*');
					temp += (char)event.text.unicode;
					text_password.setString(temp);
				}
				break;
			default:
				break;
			}
		}
		break;
	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < menu_createUser.GetNumberOFItems(); i++) {
			if (isPointOverSprite(menu_createUser.GetSprite(i))) {
				switch (i)
				{
				case 0:	//Nothing
					break;
				case 1:	//nothing
					break;
				case 2:	//create
					tryToCreateUser();
					break;
				default:
					break;
				}
			}
		}
		break;
	case sf::Event::Closed:
		gameMenue.close();
		break;
	}
}
void HandleLoginMenu(sf::Event event) {
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			menu_login.MoveUp();
			break;

		case sf::Keyboard::Down:
			menu_login.MoveDown();
			break;

		case sf::Keyboard::Return:
			switch (menu_login.GetPressedItem())
			{
			case 0:
				if (username != "") menu_login.MoveDown();
				break;
			case 1:
				if (password != "") menu_login.MoveDown();
				break;
			case 2:	//Login
				tryToLogin();
				break;
			}
			break;
		}
		break;
	case sf::Event::TextEntered:
		if (event.text.unicode < 0x80) // it's printable
		{
			switch (menu_login.GetPressedItem())
			{
			case 0:
				if ((char)event.text.unicode == 13) {}
				else if ((char)event.text.unicode == 8) {
					username = username.substr(0, username.size() - 1);
					text_username.setString(username);
				}
				else if (username.size() < 21) {
					username += (char)event.text.unicode;
					text_username.setString(username);
				}
				break;
			case 1:
				if ((char)event.text.unicode == 13) {}
				else if ((char)event.text.unicode == 8) {
					password = password.substr(0, password.size() - 1);
					if (password.size() != 0) {
						string temp(password.length() - 1, '*');
						text_password.setString(temp);
					}
				}
				else if (password.size() < 21) {
					password += (char)event.text.unicode;
					string temp(password.length() - 1, '*');
					temp += (char)event.text.unicode;
					text_password.setString(temp);
				}
				break;
			default:
				break;
			}
		}
		break;
	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < menu_login.GetNumberOFItems(); i++) {
			if (isPointOverSprite(menu_login.GetSprite(i))) {
				switch (i)
				{
				case 0:	//Nothing
					break;
				case 1:	//nothing
					break;
				case 2:	//Login
					tryToLogin();
					break;
				default:
					break;
				}
			}
		}
		break;
	case sf::Event::Closed:
		gameMenue.close();
		break;
	}
}
void HandleHighScoresMenu(sf::Event event) {
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Return:
			switch (menu_Highscores.GetPressedItem())
			{
			case 0:
				currentMenu = mainMenu;
				break;
			}
			break;
		}
		break;

	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < menu_Highscores.GetNumberOFItems(); i++) {
			if (isPointOverSprite(menu_Highscores.GetSprite(i))) {
				switch (i)
				{
				case 0:	//Back
					currentMenu = mainMenu;
					break;
				}
			}
		}
		break;
	case sf::Event::Closed:
		gameMenue.close();
		break;
	}
}
void HandleCreateOrLoginMenu(sf::Event event, Menu &menu) {
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			menu.MoveUp();
			break;

		case sf::Keyboard::Down:
			menu.MoveDown();
			break;

		case sf::Keyboard::Return:
			if (menu.GetPressedItem() == __data.getNumberOfUsers()) currentMenu = CreateUser;
			else if (__data.GetPassword(menu.GetPressedItem()) == "") {
				username = __data.GetUsername(menu.GetPressedItem());
				currentMenu = mainMenu;
				loggedInIndex = menu.GetPressedItem();
				welcomeMessage.setString("Welcome, " + __data.GetUsername(loggedInIndex));
				welcomeMessage.setPosition((gameMenue.getSize().x - welcomeMessage.getGlobalBounds().width) / 2, 440);
			}
			else {
				username = __data.GetUsername(menu.GetPressedItem());
				currentMenu = Login;
				text_username.setString(username);
				menu_login.SetSelectedItem(1);
			}
		}
		break;

	case sf::Event::MouseButtonPressed:
		for (int i = 0; i < menu.GetNumberOFItems(); i++) {
			if (isPointOverSprite(menu.GetSprite(i))) {
				if (i == __data.getNumberOfUsers()) currentMenu = CreateUser;
				else if (__data.GetPassword(menu.GetPressedItem()) == "") {
					username = __data.GetUsername(menu.GetPressedItem());
					currentMenu = mainMenu;
					loggedInIndex = menu.GetPressedItem();
					welcomeMessage.setString("Welcome, " + __data.GetUsername(loggedInIndex));
					welcomeMessage.setPosition((gameMenue.getSize().x - welcomeMessage.getGlobalBounds().width) / 2, 440);
				}
				else {
					username = __data.GetUsername(i);
					currentMenu = Login;
					text_username.setString(username);
					menu_login.SetSelectedItem(1);
				}
			}
		}
		break;
	case sf::Event::Closed:
		gameMenue.close();
		break;
	}
}


void HandleEvents(sf::RenderWindow &window, Menu &_CreateOrLogin) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (currentMenu)
		{
		case mainMenu:
			HandleMainMenu(event);
			break;
		case playMenu:
			HandlePlayMenu(event);
			break;
		case HighscoresMenu:
			HandleHighScoresMenu(event);
			break;
		case CreateUser:
			HandleCreateUserMenu(event);
			break;
		case Login:
			HandleLoginMenu(event);
			break;
		case CreateOrLogin:
			HandleCreateOrLoginMenu(event, _CreateOrLogin);
			break;
		default:
			break;
		}
	}
}
void InitializeMenus() {

	menu_main.AddMenuItem(0, Tex_SaveTheWorld, Tex_SaveTheWorld_P);
	menu_main.AddMenuItem(1, Tex_HallOfFame, Tex_HallOfFame_P);
	menu_main.AddMenuItem(2, Tex_Options, Tex_Options_P);
	menu_main.AddMenuItem(3, Tex_Credits, Tex_Credits_p);
	menu_main.AddMenuItem(4, Tex_Quit, Tex_Quit_P);
	menu_main.ShiftMenu(0, 450);
	for (int i = 0; i < menu_main.GetNumberOFItems(); i++) menu_main.SetSelectedItem(i); //keep it
	menu_main.SetSelectedItem(0);

	menu_play.AddMenuItem(0, Tex_NewGame, Tex_NewGame_P);
	menu_play.AddMenuItem(1, Tex_Continue, Tex_Continue_P);
	menu_play.AddMenuItem(2, Tex_Back, Tex_Back_P);
	menu_play.ShiftMenu(0, 450);
	for (int i = 0; i < menu_play.GetNumberOFItems(); i++) menu_play.SetSelectedItem(i); //keep it
	menu_play.SetSelectedItem(0);

	menu_Highscores.AddMenuItem(0, Tex_Back, Tex_Back_P);
	menu_Highscores.ShiftMenu(0, 300);
	for (int i = 0; i < menu_Highscores.GetNumberOFItems(); i++) menu_Highscores.SetSelectedItem(i); //keep it
	menu_Highscores.SetSelectedItem(0);

	menu_createUser.AddMenuItem(0, Tex_UsernameBox, Tex_UsernameBox_P);
	menu_createUser.AddMenuItem(1, Tex_PasswordBox, Tex_PasswordBox_P);
	menu_createUser.AddMenuItem(2, Tex_Create, Tex_Create_P);
	menu_createUser.ShiftMenu(0, 400);
	for (int i = 0; i < menu_createUser.GetNumberOFItems(); i++) menu_createUser.SetSelectedItem(i); //keep it
	menu_createUser.SetSelectedItem(0);

	menu_login.AddMenuItem(0, Tex_UsernameBox, Tex_UsernameBox_P);
	menu_login.AddMenuItem(1, Tex_PasswordBox, Tex_PasswordBox_P);
	menu_login.AddMenuItem(2, Tex_Login, Tex_Login_P);
	menu_login.ShiftMenu(0, 400);
	for (int i = 0; i < menu_login.GetNumberOFItems(); i++) menu_login.SetSelectedItem(i); //keep it
	menu_login.SetSelectedItem(0);
}

void MouseHoverUpdate(Menu &menu) {
	for (int i = 0; i < menu.GetNumberOFItems(); i++) {
		if (isPointOverSprite(menu.GetSprite(i))) {
			menu.SetSelectedItem(i);
		}
	}
}

void initializeLogo() {
	Spr_logo.setTexture(Tex_logo);
	Spr_logo.setOrigin(Spr_logo.getTextureRect().width / 2, Spr_logo.getTextureRect().height / 2);
	Spr_logo.setPosition(sf::Vector2f(gameMenue.getSize().x / 2, 250));
	Spr_logo.setScale(0.6, 0.6);
}
userState getUserState() { //must read from file first
	if (__data.getNumberOfUsers() == 0) return userState::FirstTime;
	else if (__data.getNumberOfUsers() == 1) return userState::SingleUser;
	else return userState::MultipleUsers;
}
void initializeUserMenuStuff() {
	text_username.setFont(font);
	text_username.setCharacterSize(20);
	text_username.setFillColor(sf::Color::White);
	text_username.setPosition(menu_createUser.GetSprite(0).getGlobalBounds().left + 150, menu_createUser.GetSprite(0).getGlobalBounds().top + 20);
	//text_username.setPosition(100, 100);
	text_password = text_username;
	UserCreatedOrNot = text_username;
	welcomeMessage = text_username;
	text_password.move(0, 65);
	UserCreatedOrNot.move(0, 550);
}
void initializeCreateOrLoginMenu(Menu &menu) {
	for (int i = 0; i < __data.getNumberOfUsers(); i++) {
		menu.AddMenuItem(i, Tex_Empty, Tex_Empty_P);
	}
	menu.AddMenuItem(__data.getNumberOfUsers(), Tex_NewUser, Tex_NewUser_P);
	initializeTextsUsers();
	//menu.ShiftMenu(0, 450);
	for (int i = 0; i < menu.GetNumberOFItems(); i++) {
		menu.SetSelectedItem(i); //keep it
	}
	for (int i = 0; i < __data.getNumberOfUsers(); i++) Texts_users[i].setPosition(menu.GetItemPosition(i).x - Texts_users[i].getGlobalBounds().width / 2, menu.GetItemPosition(i).y - Texts_users[i].getGlobalBounds().height / 2);
	menu.SetSelectedItem(0);
}


#endif // !MenuFunctions
