#pragma once
#ifndef _MENU_
#define _MENU_

enum WeaponType { red, green, yellow, all };

class Menu
{
public:
	Menu(float, float, int);
	~Menu();

	std::vector <sf::Texture> unpressed;
	std::vector <sf::Texture> pressed;
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void AddMenuItem(int, sf::Texture, sf::Texture);
	int GetPressedItem() { return selectedItemIndex; }
	void SetSelectedItem(int);
	int GetNumberOFItems() { return numberOfItems; };
	sf::Sprite GetSprite(int i) { return menu[i]; };
	void SetPressed(int i) { menu[i].setTexture(pressed[i]); };
	void SetUnPressed(int i) { menu[i].setTexture(unpressed[i]); };
	void ShiftMenu(int , int );
	sf::Vector2f GetItemPosition(int i) { return menu[i].getPosition(); };

private:
	float width, height;
	int selectedItemIndex;
	int numberOfItems;

	std::vector <sf::Sprite> menu;

};


Menu::Menu(float w, float h, int n)
{
	width = w;
	height = h;
	numberOfItems = n;
	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::AddMenuItem(int i, sf::Texture before, sf::Texture after) {
	sf::Sprite x;
	x.setOrigin(before.getSize().x / 2, before.getSize().y / 2);
	x.setPosition(sf::Vector2f(width / 2, height / (numberOfItems + 1) * (i + 1)));
	x.setScale(0.5, 0.48);
	x.setTexture(before);
	menu.push_back(x);
	unpressed.push_back(before);
	pressed.push_back(after);
}


void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < numberOfItems; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setTexture(unpressed[selectedItemIndex]);
		selectedItemIndex--;
		menu[selectedItemIndex].setTexture(pressed[selectedItemIndex]);
	}
	else {
		menu[selectedItemIndex].setTexture(unpressed[selectedItemIndex]);
		selectedItemIndex = numberOfItems - 1;
		menu[selectedItemIndex].setTexture(pressed[selectedItemIndex]);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < numberOfItems)
	{
		menu[selectedItemIndex].setTexture(unpressed[selectedItemIndex]);
		selectedItemIndex++;
		menu[selectedItemIndex].setTexture(pressed[selectedItemIndex]);
	}
	else {
		menu[selectedItemIndex].setTexture(unpressed[selectedItemIndex]);
		selectedItemIndex = 0;
		menu[selectedItemIndex].setTexture(pressed[selectedItemIndex]);
	}
}

void Menu::SetSelectedItem(int i) {
	menu[selectedItemIndex].setTexture(unpressed[selectedItemIndex]);
	selectedItemIndex = i;
	menu[selectedItemIndex].setTexture(pressed[selectedItemIndex]);
}

void Menu::ShiftMenu(int x, int y) {
	for (int i = 0; i < numberOfItems; i++) {
		menu[i].move(x, y);
	}
}

#endif