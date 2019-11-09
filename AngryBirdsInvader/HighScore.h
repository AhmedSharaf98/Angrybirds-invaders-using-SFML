#ifndef Highscore_h
#define Highscore_h
#define max_number_of_highScores 10

class HighScores{
private:
	vector <string> names;
	vector <int> scores;
	string filePath;

public:
	HighScores(string);
	void SetName(int i, string n) { names[i] = n; }
	void SetScore(int i, int x) { scores[i] = x; }
	string GetName(int i){ return names[i]; }
	int GetScore(int i){ return scores[i]; }
	void CheckAndInsert(string, int);
	void UpdateInFile();
	void ReadFromFile();
	void PrintToScreen(sf::RenderWindow &, sf::Font);
};


HighScores::HighScores(string filename) {
	filePath = filename;
	ifstream test;
	test.open(filename);
	if (!test.is_open()) {
		ofstream t(filename);
		t.close();
	}
	test.close();
}

void HighScores::CheckAndInsert(string name, int score) {
	if (scores.size() == 0) {
		scores.push_back(score);
		names.push_back(name);
	}
	else if (scores.size() < max_number_of_highScores) {		//not full
		if (score <= scores.back()) {
			scores.push_back(score);
			names.push_back(name);
		}
		else {
			for (int i = 0; i <scores.size(); i++) {
				if (score >= scores[i]) {
					scores.insert(scores.begin() + i, score);
					names.insert(names.begin() + i, name);
					break;
				}
			}
		}
	}
	else {		//full
		if (score >= scores.back()) {
			for (int i = 0; i <scores.size(); i++) {
				if (score > scores[i]) {
					scores.insert(scores.begin() + i, score);
					names.insert(names.begin() + i, name);
					break;
				}
			}
			scores.pop_back();
			names.pop_back();
		}
	}

}

void HighScores::UpdateInFile() {
	ofstream file;
	file.open(filePath.c_str(), std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < scores.size(); i++) {
		if (scores[i] != 0) file << names[i] << 'Ø' << scores[i] << endl;
	}
	file.close();
}

void HighScores::ReadFromFile() {
	ifstream file;
	file.open(filePath.c_str());
	while (!file.eof()) {
		string temp;
		getline(file, temp);
		int index = temp.find('Ø');
		if (atoi(temp.substr(index + 1).c_str()) != 0) {
			names.push_back(temp.substr(0, index));
			scores.push_back(atoi(temp.substr(index + 1).c_str()));
		}
	}
	file.close();
}

void HighScores::PrintToScreen(sf::RenderWindow &window, sf::Font font) {
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(300, 100);
	for (int i = 0; i < names.size(); i++) {
		int n = 40 - names[i].length() - std::to_string(scores[i]).length();
		string s(n, ' ');
		string t = names[i] + s + std::to_string(scores[i]);
		text.setString(t);
		window.draw(text);
		text.move(0, 50);
	}
}

#endif