#include "FileHandler.h"
#include <sstream>
#include <fstream>


bool FileHandler::isEmpty(std::ifstream& file) const {
	return (file.peek() == EOF);
}

void FileHandler::uploadFromFileAdmin(Vector<Admin>& coll, const char* name) {
	std::ifstream file(name, std::ios::in);
	if (!file.is_open()) {
		throw std::runtime_error("File cannot be opened");
	}

	while (!file.eof()) {
		char temp[SIZE_BUFFFER];
		file.getline(temp, SIZE_BUFFFER);
		std::stringstream ss(temp);

		char name[STR_MAX];
		char email[STR_MAX];
		char username[PASS];
		char pass[STR_MAX];

		ss.getline(name, STR_MAX, DELIMITER);
		ss.getline(email, STR_MAX, DELIMITER);
		ss.getline(username, PASS, DELIMITER);
		ss.getline(pass, PASS);

		String _name(name);
		String _email(email);
		String _username(username);
		String _pass(pass);

		Admin adminToSave(_name, _email, _username, _pass);
		coll.push_back(adminToSave);
	}
	file.close();
}

void FileHandler::saveToFileAdmin(Vector<Admin>& coll, const char* name) {
	std::ofstream file(name, std::ios::out);
	if (!file.is_open()) {
		throw std::runtime_error("File cannot be opened");
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (i == coll.size() - 1) {
			file << coll[i];
			break;
		}
		file << coll[i] << std::endl;
	}
	file.close();
}

void FileHandler::uploadFromFilePlayer(Vector<Player>& coll, const char* name) {
	std::ifstream file(name, std::ios::in);
	if (!file.is_open()) {
		throw std::runtime_error("File cannot be opened");
	}
	if (isEmpty(file)) {
		return;
	}
	while (!file.eof()) {
		char temp[SIZE_BUFFFER];
		file.getline(temp, SIZE_BUFFFER);
		std::stringstream ss(temp);

		char name[STR_MAX];
		char email[STR_MAX];
		char username[PASS];
		char pass[STR_MAX];
		char money[DIGITS_MAX];

		ss.getline(name, STR_MAX, DELIMITER);
		ss.getline(email, STR_MAX, DELIMITER);
		ss.getline(username, PASS, DELIMITER);
		ss.getline(pass, PASS, DELIMITER);
		ss.getline(money, DIGITS_MAX);

		String _name(name);
		String _email(email);
		String _username(username);
		String _pass(pass);
		size_t _money = 0;
		sscanf_s(money, "%zu", &_money);
		Player playerToSave(_name, _email, _username, _pass, _money);
		coll.push_back(playerToSave);
	}
	file.close();
}

void FileHandler::saveToFilePlayer(Vector<Player>& coll, const char* name) {
	std::ofstream file(name, std::ios::out);
	if (!file.is_open()) {
		throw std::runtime_error("File cannot be opened!");
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (i == coll.size() - 1) {
			file << coll[i];
			break;
		}
		file << coll[i] << std::endl;
	}
	file.close();
}

void FileHandler::uploadFromFileSuperHero(Vector<SuperHero>& coll, const char* name) {
	std::ifstream file(name, std::ios::in);
	if (!file.is_open()) {
		throw std::runtime_error("File cannot be opened");
	}
	if (isEmpty(file)) {
		return;
	}
	while (!file.eof()) {
		char temp[SIZE_BUFFFER];
		file.getline(temp, SIZE_BUFFFER);
		std::stringstream ss(temp);

		char name[STR_MAX];
		char nickname[STR_MAX];
		char powerType[DIGITS_MAX];
		char powerScore[DIGITS_MAX];
		char price[DIGITS_MAX];
		char attack[BOOLEAN_MAX];
		char sold[STR_MAX];
		char inTheGame[BOOLEAN_MAX];

		ss.getline(name, STR_MAX, DELIMITER);
		ss.getline(nickname, STR_MAX, DELIMITER);
		ss.getline(powerType, DIGITS_MAX, DELIMITER);
		ss.getline(powerScore, DIGITS_MAX, DELIMITER);
		ss.getline(price, DIGITS_MAX, DELIMITER);
		ss.getline(attack, BOOLEAN_MAX, DELIMITER);
		ss.getline(sold, STR_MAX, DELIMITER);
		ss.getline(inTheGame, BOOLEAN_MAX);

		String _name(name);
		String _nickname(nickname);
		String _powerType(powerType);
		size_t _powerScore = 0;
		String inTheGameTemp(inTheGame);
		String attackTemp(attack);

		sscanf_s(powerScore, "%zu", &_powerScore);
		size_t _price = 0;
		sscanf_s(price, "%zu", &_price);
		bool _attack = false;
		if (attackTemp == "0") {
			_attack = false;
		}
		if (attackTemp == "1") {
			_attack = true;
		}
		String _sold(sold);
		bool _inTheGame = false;
		if (inTheGameTemp == "0") {
			_inTheGame = false;
		}
		if (inTheGameTemp == "1") {
			_inTheGame = true;
		}

		SuperHero heroToSave(_name, _nickname, _powerType, _powerScore, _price, _attack, _sold, _inTheGame);
		coll.push_back(heroToSave);
	}
	file.close();
}
void FileHandler::saveToFileSuperHero(Vector<SuperHero>& coll, const char* name) {
	std::ofstream file(name, std::ios::out);
	if (!file.is_open()) {
		throw std::runtime_error("File cannot be opened!");
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (i == coll.size() - 1) {
			if (coll[i].getNickname() == "error" || coll[i].getNickname() == "already saved") {
				continue;
			}
			file << coll[i];
			break;
		}
		if (coll[i].getNickname() == "error" || coll[i].getNickname() == "already saved") {
			continue;
		}
		file << coll[i] << std::endl;
	}
	file.close();
}

void FileHandler::uploadSuperHeroesCollection(Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	for (size_t i = 0; i < heroColl.size(); i++)
	{
		if ((heroColl[i].getSold() != "0") && (heroColl[i].getInTheGame() == true)) {
			for (size_t j = 0; j < plColl.size(); j++)
			{
				if (heroColl[i].getSold() == plColl[j].getPass()) {
					plColl[j].myHeroes.push_back(heroColl[i]);
				}
			}
		}
	}
}

void FileHandler::uploadFromFile(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl, const char* admName, const char* plName, const char* heroName) {
	uploadFromFileAdmin(admColl, admName);
	uploadFromFilePlayer(plColl, plName);
	uploadFromFileSuperHero(heroColl, heroName);
	uploadSuperHeroesCollection(plColl, heroColl);
}
void FileHandler::saveToFile(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl, const char* admName, const char* plName, const char* heroName) {
	saveToFileAdmin(admColl, admName);
	saveToFilePlayer(plColl, plName);
	saveToFileSuperHero(heroColl, heroName);
}