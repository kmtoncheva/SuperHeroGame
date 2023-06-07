#include "Game.h"
#include "SuperHero.h"
#include <iostream>
#include <fstream>


bool Game::isEmpty(std::ifstream& file) const {
	return (file.peek() == EOF);
}

String Game::setToName(const char* _buffer) const {
	size_t index = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			index = i;
			break;
		}
	}
	char temp[100];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = _buffer[i];
	}
	temp[index] = '\0';
	return temp;
}
String Game::setToEmail(const char* _buffer) const {
	size_t commaCount = 0;
	size_t firstIindex = 0;
	size_t secondIndex = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			++commaCount;
		}
		if (_buffer[i] == ',' && commaCount == 1) {
			firstIindex = i;
		}
		if (_buffer[i] == ',' && commaCount == 2) {
			secondIndex = i;
		}
	}
	char temp[100];
	size_t pos = 0;
	for (size_t i = firstIindex + 1; i < secondIndex; i++)
	{
		temp[pos++] = _buffer[i];
	}
	temp[pos] = '\0';
	return temp;
}
String Game::setToUserName(const char* _buffer) const {
	size_t commaCount = 0;
	size_t firstIindex = 0;
	size_t secondIndex = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			++commaCount;
		}
		if (_buffer[i] == ',' && commaCount == 2) {
			firstIindex = i;
		}
		if (_buffer[i] == ',' && commaCount == 3) {
			secondIndex = i;
		}
	}
	char temp[100];
	size_t pos = 0;
	for (size_t i = firstIindex + 1; i < secondIndex; i++)
	{
		temp[pos++] = _buffer[i];
	}
	temp[pos] = '\0';
	return temp;
}
size_t Game::setToScore(const char* _buffer) const{
	size_t commaCount = 0;
	size_t firstIndex = 0;
	size_t secondIndex = 0;
	size_t res = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			++commaCount;
		}
		if (_buffer[i] == ',' && commaCount == 3) {
			firstIndex = i;
		}
		if (_buffer[i] == ',' && commaCount == 4) {
			secondIndex = i;
		}
	}
	char temp[6];
	size_t pos = 0;
	for (size_t i = firstIndex + 1; i < secondIndex; i++)
	{
		temp[pos++] = _buffer[i];
	}
	temp[pos] = '\0'; 
	sscanf_s(temp, "%zu", &res);
	return res;
}
String Game::setToPassPlayer(const char* _buffer) const {
	size_t commaCount = 0;
	size_t firstIndex = 0;
	size_t secondIndex = 0;
	size_t res = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			++commaCount;
		}
		if (_buffer[i] == ',' && commaCount == 3) {
			firstIndex = i;
		}
		if (_buffer[i] == ',' && commaCount == 4) {
			secondIndex = i;
		}
	}
	char temp[100];
	size_t pos = 0;
	for (size_t i = firstIndex + 1; i < secondIndex; i++)
	{
		temp[pos++] = _buffer[i];
	}
	temp[pos] = '\0';
	return temp;
}
String Game::setToPass(const char* _buffer) const {
	size_t commaCount = 0;
	size_t index = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			++commaCount;
		}
		if (_buffer[i] == ',' && commaCount == 3) {
			index = i;
		}
	}
	char tempPass[17];
	size_t pos = 0;
	for (size_t i = index + 1; i < strlen(_buffer) + 1; i++)
	{
		tempPass[pos++] = _buffer[i];
	}
	tempPass[pos] = '\0';
	return tempPass;
}
size_t Game::setToPrice(const char* _buffer) const {
	size_t commaCount = 0;
	size_t index = 0;
	size_t res = 0;
	for (size_t i = 0; i < strlen(_buffer) + 1; i++)
	{
		if (_buffer[i] == ',') {
			++commaCount;
		}
		if (_buffer[i] == ',' && commaCount == 4) {
			index = i;
		}
	}
	char temp[6];
	size_t pos = 0;
	for (size_t i = index + 1; i < strlen(_buffer) + 1; i++)
	{
		temp[pos++] = _buffer[i];
	}
	temp[pos] = '\0';
	sscanf_s(temp, "%zu", &res);
	return res;
}

void Game::loadAdmins(Vector<Admin>& adm, const char* fileName) {
	std::ifstream file(fileName, std::ios::in);
	if (!file.is_open()) {
		throw std::invalid_argument("File cannot be opened!");
	}
	char buffer[300];
	String nameAdmin;
	String emailAdmin;
	String UserName;
	String Pass;
	while (!file.eof()) {
		file.getline(buffer, 300);
		nameAdmin = setToName(buffer);
		emailAdmin = setToEmail(buffer);
		UserName = setToUserName(buffer);
		Pass = setToPass(buffer);
		Admin adminSaved(nameAdmin, emailAdmin, UserName, Pass);
		adm.push_back(adminSaved);
		//std::cin.ignore();
	}
	file.close();
}

void Game::loadSuperHeroes(Vector<SuperHero>& coll, const char* fileName) {
	std::ifstream file(fileName, std::ios::in);
	if (!file.is_open()) {
		throw std::invalid_argument("File cannot be opened!");
	}
	if (isEmpty(file)) {
		return;
	}
	char buffer[300];
	String name;
	String nickName;
	String power;
	size_t powerScore = 0;
	size_t price = 0;
	while (!file.eof()) {

		file.getline(buffer, 300);
		name = setToName(buffer);
		nickName = setToEmail(buffer);
		power = setToUserName(buffer);
		powerScore = setToScore(buffer);
		price = setToPrice(buffer);
		SuperHero heroSaved(name, nickName,power, powerScore,price);
		coll.push_back(heroSaved);
	}
	file.close();
}
void Game::loadPlayers(Vector<Player>& coll, const char* fileName) {
	std::ifstream file(fileName, std::ios::in);
	if (!file.is_open()) {
		throw std::invalid_argument("File cannot be opened!");
	}
	if (isEmpty(file)) {
		return;
	}
	char buffer[300];
	String name;
	String email;
	String username;
	String pass;
	size_t money = 0;
	while (!file.eof()) {

		file.getline(buffer, 300);
		name = setToName(buffer);
		email = setToEmail(buffer);
		username = setToUserName(buffer);
		pass = setToPassPlayer(buffer);
		money = setToPrice(buffer);
		Player playerSaved(name, email, username, pass, money);
		coll.push_back(playerSaved);
	}
	file.close();
}


void Game::saveSuperHeroes(Vector<SuperHero>& coll, const char* fileName) {
	std::ofstream file(fileName, std::ios::out);
	if (!file.is_open()) {
		throw std::invalid_argument("File cannot be opened!");
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
void Game::saveAdmins(Vector<Admin>& coll, const char* fileName) {
	std::ofstream file(fileName, std::ios::out);
	if (!file.is_open()) {
		throw std::invalid_argument("File cannot be opened!");
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
void Game::savePlayers(Vector<Player>& coll, const char* fileName) {
	std::ofstream file(fileName, std::ios::out);
	if (!file.is_open()) {
		throw std::invalid_argument("File cannot be opened!");
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

Admin& Game::signInAdmin(Vector<Admin>& admColl) {
	bool logged = false;
	static int count = 0;
	String _userName;
	String _pass;
	if (count != 0) {
		std::cout << "--> Enter username: ";
		//std::cin.ignore();
		std::cin >> _userName;
		std::cout << "--> Enter password: ";
		std::cin >> _pass;
	}
	if(count == 0){
		std::cout << "--> Enter username: ";
		std::cin.ignore();
		std::cin >> _userName;
		std::cout << "--> Enter password: ";
		std::cin >> _pass;
	}
	for (size_t i = 0; i < admColl.size(); i++)
	{
		if (admColl[i].getUserName() == _userName && admColl[i].getPass() == _pass) {
			logged = true;
			std::cout << std::endl << admColl[i].getName() << " you have successfully logged in as administrator!\n\n";
			return admColl[i];
		}
	}
	if (!logged) {
		count++;
		std::cout << "Wrong username or password! Please try again!\n";
		Admin& res = signInAdmin(admColl);
		return res;
	}
}
Player& Game::signInPlayer(Vector<Player>& coll) {
	bool logged = false;
	static int count = 0;
	String _userName;
	String _pass;
	if (count != 0) {
		std::cout << "--> Enter username: ";
		//std::cin.ignore();
		std::cin >> _userName;
		std::cout << "--> Enter password: ";
		std::cin >> _pass;
	}
	if (count == 0) {
		std::cout << "--> Enter username: ";
		std::cin.ignore();
		std::cin >> _userName;
		std::cout << "--> Enter password: ";
		std::cin >> _pass;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (coll[i].getUserName() == _userName && coll[i].getPass() == _pass) {
			logged = true;
			std::cout << std::endl << coll[i].getName() << " you have successfully logged in as player!\n\n";
			return coll[i];
		}
	}
	if (!logged) {
		count++;
		std::cout << "Wrong username or password! Please try again!\n";
		Player& res = signInPlayer(coll);
		return res;
	}
}

void Game::signIn(Vector<Admin>& admColl, Vector<SuperHero>& heroColl, Vector<Player>& plColl) {
	char chosen = 0;
	std::cout << "\n--> Press 1 to sign in as an administrator" << std::endl;
	std::cout << "--> Press 2 to sign in as a player" << std::endl;
	std::cout << "--> Press Q to quit" << std::endl;
	std::cin >> chosen;
	if (chosen == '1') {
		Admin adminLogged = signInAdmin(admColl);
		if (heroColl.size() == 0) {
			std::cout << "--> You should add at least 3 new Super Heroes!\n";
			for (size_t i = 0; i < 3; i++)
			{
				SuperHero hero = adminLogged.addSuperHero(heroColl);
				heroColl.push_back(hero);
			}
		}
		adminLogged.printChoises();
		bool toContinue = true;
		while (toContinue) {
			toContinue = choiseForAdmins(adminLogged, admColl, plColl, heroColl);
		}
		signIn(admColl, heroColl, plColl);
		return;
	}
	if (chosen == '2') {
		Player playerLogged = signInPlayer(plColl);
		playerLogged.printChoises();
		///
		size_t index = 0;
		bool toContinue = true;
		for (index = 0; index < 3; index++)
		{
			toContinue = choiseForPlayers(playerLogged, admColl, plColl, heroColl);
			if (toContinue == false) {
				break;
			}
		}
		if (index == 3) {
			std::cout << "You have no more turns! See you soon!\n";
		}
	}
	if (chosen == 'Q' || chosen == 'q') {
		system("CLS");
		std::cout << "See you soon!\n";
		return;
	}
	else {
		throw std::invalid_argument("Invalid argument!");
	}
}


bool Game::choiseForAdmins(Admin& adm, Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	String choise;
	std::cin >> choise;
	if (choise == "Add new admin") {
		Admin res = adm.addAdmin(admColl);
		admColl.push_back(res);
		return true;
	}
	if (choise == "Add new player") {
		Player res = adm.addPlayer(plColl);
		plColl.push_back(res);
	}

	if (choise == "Leave") {
		std::cout << "\nGoodbye! See you again!\n";
		return false;
	}
	if (choise == "Add new super hero") {
		SuperHero res = adm.addSuperHero(heroColl);
		heroColl.push_back(res);
		return true;
	}
	else {
		throw std::invalid_argument("Invalid input");
	}
}
bool Game::choiseForPlayers(Player& player, Vector<Admin>& adColl, Vector<Player>& plColl, Vector<SuperHero>& supColl) {
	String choise;
	std::cin >> choise;
	if (choise == "See all players") {
		//player.printPlayers();
		return true;
	}
}

void Game::run() {
	static Vector<Admin> adminsCollection;
	static Vector<Player> playersCollection;
	static Vector<SuperHero> heroesCollection;
	loadAdmins(adminsCollection, "AdminCollection.txt");
	loadPlayers(playersCollection, "PlayersCollection.txt");
	loadSuperHeroes(heroesCollection, "SuperHeroesCollection.txt");
	std::cout << "Welcome to SuperHeroes Game!" << std::endl;
	signIn(adminsCollection, heroesCollection, playersCollection);
	saveSuperHeroes(heroesCollection, "SuperHeroesCollection.txt");
	saveAdmins(adminsCollection, "AdminCollection.txt");
	savePlayers(playersCollection, "PlayersCollection.txt");
}



































//bool Game::checkPass(String _pass) const{
//	bool Upper, Lower, Num = false;
//	for (size_t i = 0; i < _pass.length() + 1; i++)
//	{
//		if (_pass[i] >= 'A' && _pass[i] <= 'Z') {
//			Upper = true;
//		}
//		if (_pass[i] >= 'a' && _pass[i] <= 'z') {
//			Lower = true;
//		}
//		if (_pass[i] >= '0' && _pass[i] <= '9') {
//			Num = true;
//		}
//	}
//	return (Upper && Lower && Num);
//}



//Player Game::signInPlayer() {
//	bool logged = false;
//	String _userName;
//	String _pass;
//	String _userNameFile;
//	String _passFile;
//
//	std::cout << "--> Enter username: ";
//	std::cin.ignore();
//	std::cin >> _userName;
//	std::cout << "--> Enter password: ";
//	std::cin >> _pass;
//
//	std::ifstream file("PlayersCollection.txt", std::ios::in);
//	if (!file.is_open())
//	{
//		throw std::invalid_argument("The file can not be opened!");
//	}
//	char buffer[300];
//	while (!file.eof()) {
//		file.getline(buffer, 300);
//		String tempUserName(setToUserName(buffer));
//		String tempPass(setToPass(buffer));
//		if (tempUserName == _userName && tempPass == _pass) {
//			logged = true;
//			std::cout << std::endl << _userName << " you have successfully logged in as administrator!\n\n";
//			String nameAdmin(setToName(buffer));
//			//std::cout << nameAdmin;
//			String emailAdmin(setToEmail(buffer));
//			//std::cout << emailAdmin;
//			Player adminLogged(nameAdmin, emailAdmin, tempUserName, tempPass);
//			//std::cout << adminLogged;
//			return adminLogged;
//			//break;
//		}
//	}
//	if (!logged) {
//		std::cout << "Wrong password or username! Try again!\n" << std::endl;
//		signInAdmin();
//	}
//	file.close();
//}