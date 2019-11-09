#pragma once
#ifndef GlobalHeader_h
#define GlobalHeader_h


int bg_speed = 30;
bool win = false , lose = false;
int levels[9] = { 0 }; //True and false flag for levels to detect if level is complete
int seeder = 1;
int WIDTH, HEIGHT;
sf::RenderWindow gameMenue(sf::VideoMode(1, 1), "Chicken Invaders", Style::Fullscreen);
Menu menu_main(gameMenue.getSize().x, gameMenue.getSize().y / 2.5, 5);
Menu menu_play(gameMenue.getSize().x, gameMenue.getSize().y / 3.7, 3);
Menu menu_Highscores(gameMenue.getSize().x, gameMenue.getSize().y, 1);
Menu menu_createUser(gameMenue.getSize().x, gameMenue.getSize().y / 3, 3);
Menu menu_login(gameMenue.getSize().x, gameMenue.getSize().y / 3, 3);
HighScores highScores("HighScores.txt");
Data __data("Data.txt");


enum menuType { mainMenu, playMenu, optionsMenu, HighscoresMenu, CreateUser, Login, CreateOrLogin };
menuType currentMenu = CreateOrLogin;


Texture bg, g_redbulllet; //Must Be declared here befre includeing bullets cause it is used there..
enum ChickenType { smaall, bigRed, bigGreen };
enum ChickenLegType { leg, sandwich, chicken };
enum EggType { Eggg, shit };
enum playerState { deactivated, playing, dead, weapon_Deactivated, sheild };
enum movement { left, right, up, down, stop };								//UPDATE
movement p_movement_x = stop;												//UPDATE
movement p_movement_y = stop;												//UPDATE
float velocity = 1;															//UPDATE
float maxV = 2;

double msg_alpha = 255.0;
Text level_txt, lvl_number;




struct Position
{
	int x, y;
};
struct BackgroundData {
public:
	Sprite bg1, bg2, table1, table2;
	int limit;
};
BackgroundData newBg;
RECT desktop;

//Following 3 Structs Can be Combined Later (e.g Animatable struct)
struct Fogs
{
	Sprite sprite;
	int currnet = -1; //Because Auto Increament will make it zero which is the first sprite
};
vector <Fogs> fog;
struct Explosions {
	Sprite sprite;
	int currnet = -1;
};
vector <Explosions> explosion, rockexplosion;

struct Gifts {
	WeaponType type;
	Sprite sprite;
	int currnet = -1;
};
vector <Gifts> gifts;


struct SheildGifts {
	Sprite sprite;
	int currnet = -1;
};
vector <SheildGifts> Sheilds;


SoundBuffer bf_gainrocket;
SoundBuffer bigHits[3];
SoundBuffer bigDies[3];
SoundBuffer smallHits[3];
SoundBuffer smallDies[3];
SoundBuffer explosion_buffer;
SoundBuffer rock_explosion_buffer[3];
SoundBuffer suspenseBuffer;



Sound SbigHits[3];
Sound SbigDies[3];
Sound SsmallHits[3];
Sound SsmallDies[3];
Sound explosion_sound;
Sound rock_explosion_sound[3];
Sound suspense;

Sound gainRocket;
Music bgmuzic;

Texture BigChickenTexRed;
Texture BigChickenTexGreen;

Texture SmallChickenTex;
Texture EggTex;
Texture ShitTex;
Texture Fog;
Texture Explosion;
Texture RockExplosion;
Texture ChickenPartTex1;
Texture ChickenPartTex2;
Texture ChickenPartTex3;
Texture spaceship;
Texture playersheild;
Texture rock;
Texture playerBanel[2];
Font userDataFont;
Texture redGift;

string username = "";
string password = "";
sf::Text text_username;
sf::Text text_password;
sf::Text UserCreatedOrNot;
sf::Text welcomeMessage;
int loggedInIndex = 0;
vector <sf::Text> Texts_users;
enum userState { FirstTime, SingleUser, MultipleUsers };


sf::Texture Tex_SaveTheWorld;
sf::Texture Tex_SaveTheWorld_P;
sf::Texture Tex_HallOfFame;
sf::Texture Tex_HallOfFame_P;
sf::Texture Tex_Options;
sf::Texture Tex_Options_P;
sf::Texture Tex_Credits;
sf::Texture Tex_Credits_p;
sf::Texture Tex_Quit;
sf::Texture Tex_Quit_P;
sf::Texture Tex_NewGame;
sf::Texture Tex_NewGame_P;
sf::Texture Tex_Continue;
sf::Texture Tex_Continue_P;
sf::Texture Tex_Back;
sf::Texture Tex_Back_P;
sf::Texture Tex_Create;
sf::Texture Tex_Create_P;
sf::Texture Tex_UsernameBox;
sf::Texture Tex_UsernameBox_P;
sf::Texture Tex_PasswordBox;
sf::Texture Tex_PasswordBox_P;
sf::Texture Tex_Login;
sf::Texture Tex_Login_P;
sf::Texture Tex_NewUser;
sf::Texture Tex_NewUser_P;
sf::Texture Tex_Empty;
sf::Texture Tex_Empty_P;
sf::Texture Tex_bg;
sf::Texture Tex_logo;
sf::Sprite Spr_logo;
sf::Texture beast1;
sf::Texture beast2;
sf::Texture beast3;
sf::Texture ufo;

sf::Texture Tex_ddescendingCChicken;

sf::Texture TexSheild;
sf::Font font;
void load() {
	Tex_SaveTheWorld.loadFromFile("MenuButtons/SaveTheWorld_Before.png");
	Tex_SaveTheWorld_P.loadFromFile("MenuButtons/SaveTheWorld_After.png");
	Tex_HallOfFame.loadFromFile("MenuButtons/HallOfFame_Before.png");
	Tex_HallOfFame_P.loadFromFile("MenuButtons/HallOfFame_After.png");
	Tex_Options.loadFromFile("MenuButtons/Options_Before.png");
	Tex_Options_P.loadFromFile("MenuButtons/Options_After.png");
	Tex_Credits.loadFromFile("MenuButtons/Credits_Before.png");
	Tex_Credits_p.loadFromFile("MenuButtons/Credits_After.png");
	Tex_Quit.loadFromFile("MenuButtons/Quit_Before.png");
	Tex_Quit_P.loadFromFile("MenuButtons/Quit_After.png");
	Tex_NewGame.loadFromFile("MenuButtons/NewGame_before.png");
	Tex_NewGame_P.loadFromFile("MenuButtons/NewGame_After.png");
	Tex_Continue.loadFromFile("MenuButtons/Continue_Before.png");
	Tex_Continue_P.loadFromFile("MenuButtons/Continue_After.png");
	Tex_Back.loadFromFile("MenuButtons/Back_Before.png");
	Tex_Back_P.loadFromFile("MenuButtons/Back_After.png");
	Tex_Create.loadFromFile("MenuButtons/Create_Before.png");
	Tex_Create_P.loadFromFile("MenuButtons/Create_After.png");
	Tex_UsernameBox.loadFromFile("MenuButtons/UserNameBox_Before.png");
	Tex_UsernameBox_P.loadFromFile("MenuButtons/UserNameBox_After.png");
	Tex_PasswordBox.loadFromFile("MenuButtons/PasswordBox_Before.png");
	Tex_PasswordBox_P.loadFromFile("MenuButtons/PasswordBox_After.png");
	Tex_Login.loadFromFile("MenuButtons/Login_Before.png");
	Tex_Login_P.loadFromFile("MenuButtons/Login_After.png");
	Tex_NewUser.loadFromFile("MenuButtons/NewUser_Before.png");
	Tex_NewUser_P.loadFromFile("MenuButtons/NewUser_After.png");
	Tex_Empty.loadFromFile("MenuButtons/Empty_Before.png");
	Tex_Empty_P.loadFromFile("MenuButtons/Empty_After.png");
	Tex_bg.loadFromFile("Resources/bg.jpg");
	Tex_logo.loadFromFile("Resources/logo.png");
	Tex_ddescendingCChicken.loadFromFile("Resources/descending.png");
	font.loadFromFile("myFont.ttf");




	TexSheild.loadFromFile("Resources/shieldGift.png");
	///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////

	level_txt.setFont(font);
	level_txt.setCharacterSize(24);
	lvl_number = level_txt;
	suspenseBuffer.loadFromFile("Resources/suspense.wav");
	suspense.setBuffer(suspenseBuffer);
	///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////
	
	userDataFont.loadFromFile("Resources/myFont.ttf");
	bg.loadFromFile("Resources/bg.jpg");
	playerBanel[0].loadFromFile("Resources/Sprites/GameBackGround/playerTable.png");
	playerBanel[1].loadFromFile("Resources/Sprites/GameBackGround/playerTable2.png");
	bgmuzic.openFromFile("Resources/bgmusic.ogg");

	spaceship.loadFromFile("Resources/space.png");
	playersheild.loadFromFile("Resources/shield.png");

	BigChickenTexRed.loadFromFile("Resources/Sprites/Red/SpriteALL_75_85.png");
	BigChickenTexGreen.loadFromFile("Resources/Sprites/Green/SpriteALL_75_85.png");

	SmallChickenTex.loadFromFile("Resources/Sprites/SmallPink/Small_64_60.png");

	EggTex.loadFromFile("Resources/Sprites/Egg/Sprite_24_27.png");
	rock.loadFromFile("Resources/Sprites/Rock.png");
	ShitTex.loadFromFile("Resources/shit.png");

	//TODO Wait for Alaa
	ChickenPartTex1.loadFromFile("Resources/ChickenPart_50.png");
	ChickenPartTex2.loadFromFile("Resources/sandwich.png");
	ChickenPartTex3.loadFromFile("Resources/chicken.png");


	beast1.loadFromFile("Resources/beast1.png");
	beast2.loadFromFile("Resources/beast2.png");
	beast3.loadFromFile("Resources/eggBeast.png");
	ufo.loadFromFile("Resources/UFO.png");


	Fog.loadFromFile("Resources/Sprites/Fog/Sprite_99_93.png");
	Explosion.loadFromFile("Resources/Sprites/Explosion/Explosion.png");
	RockExplosion.loadFromFile("Resources/Sprites/Explosion/RocketExplosion.png");

	
	g_redbulllet.loadFromFile("Resources/redbullet.png");
	redGift.loadFromFile("Resources/gift.png");

	//Sounds
	bigHits[0].loadFromFile("Resources/Sound/BigHit1.wav");
	bigHits[1].loadFromFile("Resources/Sound/BigHit2.wav");
	bigHits[2].loadFromFile("Resources/Sound/BigHit3.wav");
	SbigHits[0].setBuffer(bigHits[0]);
	SbigHits[1].setBuffer(bigHits[1]);
	SbigHits[2].setBuffer(bigHits[2]);
	

	bigDies[0].loadFromFile("Resources/Sound/BigDie1.wav");
	bigDies[1].loadFromFile("Resources/Sound/BigDie2.wav");
	bigDies[2].loadFromFile("Resources/Sound/BigDie3.wav");
	SbigDies[0].setBuffer(bigDies[0]);
	SbigDies[1].setBuffer(bigDies[1]);
	SbigDies[2].setBuffer(bigDies[2]);

	smallHits[0].loadFromFile("Resources/Sound/SmallHit1.wav");
	smallHits[1].loadFromFile("Resources/Sound/SmallHit2.wav");
	smallHits[2].loadFromFile("Resources/Sound/SmallHit3.wav");
	SsmallHits[0].setBuffer(smallHits[0]);
	SsmallHits[1].setBuffer(smallHits[1]);
	SsmallHits[2].setBuffer(smallHits[2]);

	smallDies[0].loadFromFile("Resources/Sound/SmallDie1.wav");
	smallDies[1].loadFromFile("Resources/Sound/SmallDie2.wav");
	smallDies[2].loadFromFile("Resources/Sound/SmallDie3.wav");
	SsmallDies[0].setBuffer(smallDies[0]);
	SsmallDies[1].setBuffer(smallDies[1]);
	SsmallDies[2].setBuffer(smallDies[2]);

	explosion_buffer.loadFromFile("Resources/Sound/RocketExplosion.wav");
	explosion_sound.setBuffer(explosion_buffer);
	rock_explosion_buffer[0].loadFromFile("Resources/Sound/RockHit1.wav");
	rock_explosion_sound[0].setBuffer(rock_explosion_buffer[0]);
	rock_explosion_buffer[1].loadFromFile("Resources/Sound/RockHit2.wav");
	rock_explosion_sound[1].setBuffer(rock_explosion_buffer[1]);
	rock_explosion_buffer[2].loadFromFile("Resources/Sound/RockHit3.wav");
	rock_explosion_sound[2].setBuffer(rock_explosion_buffer[2]);

	
	bf_gainrocket.loadFromFile("Resources/extrarocket.wav");
	gainRocket.setBuffer(bf_gainrocket);
	

	srand(time(0));
	bgmuzic.play();
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	WIDTH = desktop.right;
	HEIGHT = desktop.bottom;
	newBg.limit = int(HEIGHT);
	newBg.bg1.setTexture(bg);
	newBg.bg2.setTexture(bg);
	newBg.bg1.setScale(float(HEIGHT) / 768.0, float(WIDTH) / 1366.0);
	newBg.bg2.setScale(float(HEIGHT) / 768.0, float(WIDTH) / 1366.0);
	newBg.bg2.setPosition(0, int(HEIGHT));

	gameMenue.setSize(sf::Vector2u(float(WIDTH), float(HEIGHT)));
}
#endif
