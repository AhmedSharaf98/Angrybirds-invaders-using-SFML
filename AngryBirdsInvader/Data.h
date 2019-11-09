#ifndef Data_h
#define Data_h

class Data{
private:
	vector <string> userNames;
	vector <string> passwords;
	vector <int> scores;
	vector <int> currentLevel;
	vector <int> lives;
	vector <int> rockets;
	vector <int> chickenParts;
	vector <WeaponType> weapon;
	vector <int> weaponPower;
	string filePath;
	string Encrypt(string);
	string Decrypt(string);

public:
	Data(string);
	void SetUserName(int i, string n) { userNames[i] = n; }
	void SetPassword(int i, string x) { passwords[i] = x; }
	void Setscore(int i, int n) { scores[i] = n; }
	void SetcurrentLevel(int i, int n) { currentLevel[i] = n; }
	void SetLives(int i, int x) { lives[i] = x; }
	void SetRockets(int i, int x) { rockets[i] = x; }
	void SetChickenParts(int i, int x) { chickenParts[i] = x; }
	void Setweapon(int i, WeaponType x) { weapon[i] = x; }
	void SetWeaponPower(int i, int x) { weaponPower[i] = x; }
	string GetUsername(int i){ return userNames[i]; }
	string GetPassword(int i){ return passwords[i]; }
	int Getscore(int i){ return scores[i]; }
	int GetCurrentLevel(int i){ return currentLevel[i]; }
	int GetLives(int i){ return lives[i]; }
	int GetRockets(int i){ return rockets[i]; }
	int GetChickenParts(int i){ return chickenParts[i]; }
	WeaponType GetWeapon(int i){ return weapon[i]; }
	int GetWeaponPower(int i){ return weaponPower[i]; }
	void reset(int i);

	bool CheckAndInsert(string, string);
	int CheckUserFound(string, string); // -1 >> not found
	int getNumberOfUsers(){ return userNames.size(); };
	void UpdateInFile();
	void ReadFromFile();
};



Data::Data(string filename) {
	filePath = filename;
	ifstream test;
	test.open(filename);
	if (!test.is_open()) {
		ofstream t(filename);
		t.close();
	}
	test.close();
}

bool Data::CheckAndInsert(string name, string pass) {
	for (int i = 0; i < userNames.size(); i++) {
		if (name == userNames[i]) return false;
	}
	userNames.push_back(name);
	passwords.push_back(pass);
	scores.push_back(0);
	currentLevel.push_back(1);
	lives.push_back(3);
	rockets.push_back(0);
	chickenParts.push_back(0);
	weapon.push_back(WeaponType::red);
	weaponPower.push_back(1);
	return true;
}

void Data::reset(int i) {
	scores[i] = 0;
	currentLevel[i] = 0;
	lives[i] = 3;
	rockets[i] = 0;
	chickenParts[i] = 0;
	weapon[i] = WeaponType::red;
	weaponPower[i] = 1;
	UpdateInFile();
}


int Data::CheckUserFound(string name, string pass) {
	for (int i = 0; i < userNames.size(); i++) {
		if (name == userNames[i] && pass == passwords[i]) return i;
	}
	return -1;
}

void Data::UpdateInFile() {
	ofstream file;
	file.open(filePath.c_str(), std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < passwords.size(); i++) {
		if (userNames[i] != "") file << Encrypt(userNames[i]) << 'Ø' << Encrypt(passwords[i]) << 'Ø' << Encrypt(std::to_string(scores[i])) << 'Ø' << Encrypt(std::to_string(currentLevel[i])) << 'Ø' << Encrypt(std::to_string(lives[i])) << 'Ø' << Encrypt(std::to_string(rockets[i])) << 'Ø' << Encrypt(std::to_string(chickenParts[i])) << 'Ø' << Encrypt(std::to_string(weapon[i])) << 'Ø' << Encrypt(std::to_string(weaponPower[i])) << endl;
	}
	file.close();
}

void Data::ReadFromFile() {
	ifstream file;
	file.open(filePath.c_str());
	while (!file.eof()) {
		string temp;
		getline(file, temp);
		if (temp != "") {
			int index = temp.find('Ø');
			userNames.push_back(Decrypt(temp.substr(0, index)));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			passwords.push_back(Decrypt(temp.substr(0, index)));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			scores.push_back(atoi(Decrypt(temp.substr(0, index)).c_str()));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			currentLevel.push_back(atoi(Decrypt(temp.substr(0, index)).c_str()));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			lives.push_back(atoi(Decrypt(temp.substr(0, index)).c_str()));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			rockets.push_back(atoi(Decrypt(temp.substr(0, index)).c_str()));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			chickenParts.push_back(atoi(Decrypt(temp.substr(0, index)).c_str()));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			weapon.push_back(WeaponType(atoi(Decrypt(temp.substr(0, index)).c_str())));
			temp.erase(0, index + 1);
			index = temp.find('Ø');
			weaponPower.push_back(atoi(Decrypt(temp.substr(0, index)).c_str()));
		}
	}
	file.close();
}



string Data::Encrypt(string x) {
	int shift = 44;
	string encrypted = x;
	for (int i = 0; i < x.length(); i++){
		encrypted[i] = x[i] + shift;
		if (encrypted[i] > 250) encrypted[i] -= 250;
	}
	return encrypted;
}

string Data::Decrypt(string x) {
	int shift = 44;
	string decrypted = x;
	for (int i = 0; i < x.length(); i++){
		decrypted[i] = x[i] - shift;
		if (decrypted[i] < 0) decrypted[i] += 250;
	}
	return decrypted;
}

#endif