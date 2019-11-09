#ifndef ChickenHeader_h
#define ChickenHeader_h

class Chicken {
protected:
	Position position;
	Sprite sprite;
	int currentStrength;
	Position size;
	int currentSprite;
public:
	void move(int x, int y);
	void setPosition(int x, int y);
	Position getPosition();
	void drawSprite();
	void die();
	Sprite getSprite();
	bool damage(int x);
	void setStartingFrame(int);
	
};

//////////////////////////////////
void Chicken::setStartingFrame(int x) {
	currentSprite = x;
}

void Chicken::move(int x, int y){
	position.x += x;
	position.y += y;
	sprite.move(Vector2f(x, y));
}

bool Chicken::damage(int x) {
	currentStrength -= x;
	if (currentStrength <= 0)
		return true;
	return false;
}

void Chicken::setPosition(int x, int y){
	position.x = x;
	position.y = y;
	sprite.setPosition(Vector2f(position.x, position.y));
}
Position Chicken::getPosition(){
	return position;
}

void Chicken::drawSprite(){
	gameMenue.draw(sprite);
}

Sprite Chicken::getSprite(){
	return sprite;
}

void Chicken::die(){

	Fogs temp;
	temp.sprite.setTexture(Fog);
	temp.sprite.setOrigin(50 , 46);
	temp.sprite.setTextureRect(IntRect(0, 0, 99, 93));
	temp.sprite.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y));
	fog.push_back(temp);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SmallChicken :public Chicken {

public:
	void animate(int);
	SmallChicken();
	SmallChicken(int x, int y);
	void hit();
};

void SmallChicken::animate(int probability) {
	sprite.rotate(rand() % 11 - (5 + sprite.getRotation()));
	if (!probability) return;
	currentSprite++;
	if (currentSprite >= 6) currentSprite = 0;
	sprite.setTextureRect(sf::IntRect(currentSprite * 64, 0, 64, 60));
}

//////////////////////////////////

SmallChicken::SmallChicken(){
	setStartingFrame(rand() % 6);
	sprite.setTexture(SmallChickenTex);
	currentStrength = 5;
	sprite.setOrigin(75 / 2, 85 / 2);
	sprite.setTextureRect(sf::IntRect(currentSprite * 64, 0, 64, 60));
}

SmallChicken::SmallChicken(int x, int y){
	
	setStartingFrame(rand() % 6);
	sprite.setTexture(SmallChickenTex);
	currentStrength = 5;
	position.x = x;
	position.y = y;
	sprite.setOrigin(75 / 2, 85 / 2);
	sprite.setTextureRect(sf::IntRect(currentSprite * 64, 0, 64, 60));
	sprite.setPosition(position.x, position.y);
}

void SmallChicken::hit(){
	SsmallHits[rand() % 3].play();
	sprite.setTextureRect(sf::IntRect(6 * 64, 0, 64, 60));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class BigChicken :public Chicken {
	//ChickenPart part;
public:
	void animate(int);
	BigChicken(ChickenType);
	BigChicken(int x, int y, ChickenType);
	void hit();
	//void throwEgg();
	//void throwChickenLeg();

};


void BigChicken::animate(int probability) {
	sprite.rotate(rand() % 11 - (5 + sprite.getRotation()));
	if (!probability) return;
	currentSprite++;
	if (currentSprite >= 5) currentSprite = 0;
	sprite.setTextureRect(sf::IntRect(currentSprite * 75, 0, 75, 85));
}
////////////////////////////
BigChicken::BigChicken(ChickenType t){
	setStartingFrame(rand() % 5);
	switch (t)
	{
	case bigRed:
		sprite.setTexture(BigChickenTexRed);
		break;
	case bigGreen:
		sprite.setTexture(BigChickenTexGreen);
		break;
	}//////
	currentStrength = 10;
	sprite.setOrigin(75 / 2, 85 / 2);
	sprite.setTextureRect(sf::IntRect(currentSprite * 75, 0, 75, 85));
	//ChickenPart tmp(position.x, position.y);
	//part = tmp;
}

BigChicken::BigChicken(int x, int y, ChickenType t){

	setStartingFrame(rand() % 5);
	switch (t)
	{
	case bigRed:
		sprite.setTexture(BigChickenTexRed);
		break;
	case bigGreen:
		sprite.setTexture(BigChickenTexGreen);
		break;
	}
	sprite.setColor(Color(0, 0, 0, 50));
	currentStrength = 10;
	position.x = x;
	position.y = y;
	sprite.setPosition(position.x, position.y);
	sprite.setTextureRect(sf::IntRect(currentSprite * 75, 0, 75, 85));
	sprite.setOrigin(75 / 2, 85 / 2);
	//ChickenPart tmp(position.x, position.y);
	//part = tmp;
}

void BigChicken::hit() {
	SbigHits[rand() % 3].play();
	sprite.setTextureRect(sf::IntRect(5 * 75, 0, 75, 85));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class beast : public Chicken {			//UPDATE//UPDATE//UPDATE
public:
	int beastNumber;
	beast(int, int, Texture&, int);
	void settexture(Texture);
	void drawSprite();
	bool hit(int);
	void returnn();
	int getBeastNumber() { return beastNumber; };
};

beast::beast(int x, int y, Texture &tex, int n) {
	beastNumber = n;
	currentSprite = 0;																		//UPDATE
	position.x = x;																			//UPDATE
	position.y = y;																			//UPDATE								//UPDATE
	sprite.setPosition(Vector2f(x, y));
	currentStrength = 100;

	if (beastNumber == 1) {
		sprite.setScale(3, 3);
		sprite.setTextureRect(IntRect(0, 0, 330, 321));
	}
	else if (beastNumber == 2) {
		sprite.setScale(0.3, 0.3);
	}
	else if(beastNumber == 3 ){
		sprite.setScale(3, 3);
		sprite.setTextureRect(IntRect(0, 0, 330, 321));
	}
	sprite.setTexture(tex);
	//UPDATE
	sprite.setScale(0.5, 0.5);
	
}
void beast::settexture(Texture tex) {
	sprite.setTexture(tex);
}

bool beast::hit(int x) {
	currentStrength -= x;
	if(beastNumber == 1)
		sprite.setTextureRect(IntRect(330, 0, 330, 321));
	SbigHits[rand() % 3].play();
	if (currentStrength > 0) return false;
	return true;
}


void beast::returnn() {
	if (beastNumber == 1)
		sprite.setTextureRect(IntRect(0, 0, 330, 321));
}

//UPDATE

void beast::drawSprite() {
	gameMenue.draw(sprite);
}



///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

class ChickenPart {
	Position position;
	ChickenLegType type;
	Sprite sprite;
	float Xfactor;

	int stepNumber;
	int jumps;
	std::chrono::duration<double> delay;
	std::chrono::time_point<std::chrono::system_clock> created;
public:
	float Yfactor;
	ChickenPart(int x, int y);
	void move(int x, int y);

	void setPosition(int x, int y);
	Position getPosition();

	//void setTexture(Texture texture);
	//Texture getTexture();

	void drawSprite();
	void go();
	void reverseX();
	void reverseY();
	void incrementJumps();
	int getJumps();
	Sprite getSprite() {
		return sprite;
	}
	ChickenLegType getType() {
		return type;
	}
};

//////////////////////////////////

ChickenPart::ChickenPart(int x, int y){		//type is created ranomly
	position.x = x;
	position.y = y;
	int temp = rand() % 10;
	created = std::chrono::system_clock::now();
	stepNumber = 1;
	Xfactor = rand() % 11 - 5;
	Yfactor = 1;
	jumps = 0;
	delay = std::chrono::milliseconds(10);

	//randomize L type
	if (temp < 7) {
		type = leg;
		sprite.setScale(.5, .5);
		sprite.setTexture(ChickenPartTex1);
	}
	else if (temp == 7 || temp == 8) {
		type = sandwich;
		sprite.setScale(.5, .5);
		sprite.setTexture(ChickenPartTex2);
	}
	else {
		type = chicken;
		sprite.setScale(.75, .75);
		sprite.setTexture(ChickenPartTex3);
	}
	sprite.setPosition(Vector2f(x, y));
}

void ChickenPart::drawSprite(){
	gameMenue.draw(sprite);
}

void ChickenPart::move(int x, int y){
	position.x += x;
	position.y += y;
	sprite.move(x, y);
}

void ChickenPart::setPosition(int x, int y){
	position.x = x;
	position.y = y;
}
Position ChickenPart::getPosition(){
	return position;
}

void ChickenPart::go(){
	if (std::chrono::system_clock::now() > created + stepNumber * delay){
		stepNumber++;
		Yfactor++;
		move(Xfactor, Yfactor/8);
	}
}

void ChickenPart::reverseX(){
	if (Xfactor >= 0) move(-1, 0);
	else move(1, 0);
	Xfactor = (int) (Xfactor * -0.7);
}

void ChickenPart::reverseY(){
	move(0, -1);
	Yfactor = (int) (Yfactor * -0.7);
}

void ChickenPart::incrementJumps(){
	jumps++;
}

int ChickenPart::getJumps(){
	return jumps;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Egg {
	Position position;
	Sprite sprite;
	EggType type;
	int stepNumber;
	std::chrono::duration<double> delay;
	std::chrono::time_point<std::chrono::system_clock> created;
	int currentSprite;
public:
	EggType getType() {
		return type;
	}
	Egg(int x, int y, EggType type);
	void move(int x, int y);
	void setPosition(int x, int y);
	Position getPosition();
	void drawSprite();
	void go();
	Sprite getSprite();
	void die();
	void animate();
};

//////////////////////////////////

void Egg::animate() {
	if (type == EggType::shit) return;
	currentSprite++;
	if (currentSprite >= 8) currentSprite = 0;
	sprite.setTextureRect(sf::IntRect(currentSprite * 24, 0, 24, 27));
}

Egg::Egg(int x, int y, EggType type){
	currentSprite = 0;
	position.x = x;
	position.y = y;
	if (type == EggType::Eggg) {
		sprite.setTexture(EggTex);
		sprite.setTextureRect(sf::IntRect(0 * 24, 0, 24, 27));
	}
	else sprite.setTexture(ShitTex);
	sprite.setPosition(Vector2f(x, y));
	created = std::chrono::system_clock::now();
	stepNumber = 1;
	delay = std::chrono::milliseconds(10);		
}
void Egg::die() {
	//Change Texture to brocken Egg
}
void Egg::drawSprite(){
	gameMenue.draw(sprite);
}

void Egg::move(int x, int y){
	position.x += x;
	position.y += y;
	sprite.move(x, y);
}

void Egg::setPosition(int x, int y){
	position.x = x;
	position.y = y;
}
Position Egg::getPosition(){
	return position;
}

void Egg::go(){
	if (std::chrono::system_clock::now() > created + stepNumber * delay){
		stepNumber++;
		move(0, 1);	//////////////////////////////////// was sprite.move
	}
}

Sprite Egg::getSprite(){
	return sprite;
}


class DescendingChicken :public Chicken {													
private:																					
	int stepNumber;																			
	std::chrono::duration<double> delay;													
	std::chrono::time_point<std::chrono::system_clock> created;								
public:																																							//UPDATE
	DescendingChicken(int x, int y);														
	void go();																																										
	void hit();
	void returnn();
};	

void DescendingChicken::returnn() {
	sprite.setTextureRect(IntRect(0, 0, 132, 310));
}

void DescendingChicken::hit() {
	SsmallHits[rand() % 3].play();
	sprite.setTextureRect(sf::IntRect(132, 0, 132, 310));
}

DescendingChicken::DescendingChicken(int x, int y) {										
	currentSprite = 0;																		
	position.x = x;																			
	position.y = y;																			
	currentStrength = 4;
	sprite.setScale(.5, .5);
	sprite.setTexture(Tex_ddescendingCChicken);//to be changed								
	sprite.setPosition(Vector2f(x, y));														
	created = std::chrono::system_clock::now();												
	stepNumber = 1;																			
	delay = std::chrono::milliseconds(10);													
}																							
																							
void DescendingChicken::go() {																
	if (std::chrono::system_clock::now() > created + stepNumber * delay) {					
		stepNumber++;																		
		move(0, stepNumber % 2);	////////////////////////////////// was sprite.move		
	}																						
}																							


vector <SmallChicken> smallChickens;
vector <BigChicken> bigChickens;
vector <ChickenPart> parts;
vector <Egg> Eggs;
vector <DescendingChicken> descendingChickens;
vector <beast> beasts;									//UPDATE2

#endif // ChickenHeader_h