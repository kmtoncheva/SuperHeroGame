#include "Admin.h"

Admin::Admin() : User() {}
Admin::Admin(String _name, String _email, String _user, String _pass) 
	: User(_name, _email, _user, _pass) {}

std::ostream& operator<<(std::ostream& os, const Admin& obj) {
	os << obj.name << "," << obj.email << "," << obj.userName << "," << obj.password;
	return os;
}

SuperHero Admin::addSuperHero(Vector<SuperHero>& coll) {

	String name;
	String nickname;
	String tempPowerType;
	PowerType powerType;
	size_t powerSize, price = 0;
	std::cout << "-> Enter name: ";
	std::cin >> name;
	if (name == "") {
		std::cout << "Please enter a valid name : ";
		std::cin >> name;
	}
	std::cout << "-> Enter SuperHero nickname: ";
	std::cin >> nickname;
	if (nickname == "") {
		std::cout << "Please enter a valid nickname : ";
		std::cin >> nickname;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (nickname == coll[i].getNickname()) {
			std::cout << "This nickname is already used! Please, enter different one: ";
			std::cin >> nickname;
		}
	}
	std::cout << "-> Enter SuperHero Power (Fire, Water, Earth): ";
	std::cin >> tempPowerType;
	if ((tempPowerType != "Fire") && (tempPowerType != "fire") && (tempPowerType != "Water") && (tempPowerType != "water") && (tempPowerType != "Earth") && (tempPowerType != "earth")) {
		std::cout << "Please enter one of the Powers above! : ";
		std::cin >> tempPowerType;
	}
	std::cout << "-> Enter SuperHero power (score): ";
	std::cin >> powerSize;
	std::cout << "-> Enter SuperHero price: ";
	std::cin >> price;
	std::cin.ignore();
	std::cout << "\nCongratulations! You added the super hero! What is your next turn? \n";
	SuperHero hero(name, nickname, tempPowerType, powerSize, price, false, "0", false);
	return hero;
}

Player Admin::addPlayer(Vector<Player>& coll) {
	String name, email, userName, pass;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter email: ";
	std::cin >> email;
	std::cout << "Enter username: ";
	std::cin >> userName;
	if (userName.length() > 16) {
		std::cout << "This username is too long! It should be up to 16  characters! Enter new username: ";
		std::cin >> userName;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (userName == coll[i].getUserName() || userName.length() > 16) {
			std::cout << "This username is already used or it is too long! Please, enter different one: ";
			std::cin >> userName;
		}
	}
	if (userName.length() > 16) {
		std::cout << "This username is too long! It should be up to 16  characters! Enter new username: ";
		std::cin >> userName;
	}
	std::cout << "Enter password: ";
	std::cin >> pass;
	while (!checkPass(pass)) {
		std::cout << "Your password should include at least 1 uppecase, 1 lowercase and 1 digit! Enter new password: ";
		std::cin >> pass;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		while (pass == coll[i].getPass() || !checkPass(pass)) {
			std::cout << "This password is not free or it is not save! Please, enter new one: ";
			std::cin >> pass;
		}
	}
	std::cout << "\nCongratulations! You added the player! What is your next turn? \n";
	Player pl(name, email, userName, pass, 1000);
	return pl;
}


Admin Admin::addAdmin(Vector<Admin>& coll) {
	String name;
	String email;
	String userName;
	String pass;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter email: ";
	std::cin >> email;
	std::cout << "Enter userName: ";
	std::cin >> userName;
	if (userName.length() > 16) {
		std::cout << "This username is too long! It should be up to 16  characters! Enter new username: ";
		std::cin >> userName;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (userName == coll[i].getUserName() || userName.length() > 16) {
			std::cout << "This username is already used or it is too long! Please, enter different one: ";
			std::cin >> userName;
		}
	}
	if (userName.length() > 16) {
		std::cout << "This username is too long! It should be up to 16  characters! Enter new username: ";
		std::cin >> userName;
	}
	std::cout << "Enter password: ";
	std::cin >> pass;
	while (!checkPass(pass)) {
		std::cout << "Your password should include at least 1 uppecase, 1 lowercase and 1 digit! Enter new password: ";
		std::cin >> pass;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		while (pass == coll[i].getPass() || !checkPass(pass)) {
			std::cout << "This password is not free or it is not save! Please, enter new one: ";
			std::cin >> pass;
		}
	}
	std::cout << "\nCongratulations! You added the admin! What is your next turn?\n";
	Admin res(name, email, userName, pass);
	return res;
}

void Admin::printChoises() const {
	std::cout << "\n>>Add new admin" << "\n>>Add new player" << "\n>>See all players" << "\n>>See all admins"
		<< "\n>>Add new super hero" << "\n>>Delete player" << "\n>>Sign out\n\n";
}



bool Admin::checkPass(String _pass) const{
	bool Upper = false;
	bool Lower = false;
	bool Num = false;
	for (size_t i = 0; i < _pass.length() + 1; i++)
	{
	if (_pass[i] >= 'A' && _pass[i] <= 'Z') {
			Upper = true;
		}
		if (_pass[i] >= 'a' && _pass[i] <= 'z') {
			Lower = true;
		}
		if (_pass[i] >= '0' && _pass[i] <= '9') {
			Num = true;
		}
	}
	return (Upper && Lower && Num);
}

void Admin::printAdmins(Vector<Admin>& admColl) const {
	std::cout << std::endl;
	for (size_t i = 0; i < admColl.size(); i++)
	{
		std::cout << " - " << admColl[i].getName() << ", " << admColl[i].getEmail() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "What is your next turn?\n";
}

void Admin::printPlayers(Vector<Player>& coll) const {
	std::cout << std::endl;
	for (size_t i = 0; i < coll.size(); i++)
	{
		std::cout << " - Name: " << coll[i].getName() << ", email: " << coll[i].getEmail() << ", username: "
			<< coll[i].getUserName() << ", password: " << coll[i].getPass() << ", balance: " << coll[i].getMoney()
			<< ", heroes: ";
		if (coll[i].myHeroes.size() == 0)
			std::cout << "No heroes";
		for (size_t j = 0; j < coll[i].myHeroes.size(); j++)
		{
			if (j == coll[i].myHeroes.size() - 1) {
				std::cout << coll[i].myHeroes[j].getNickname() << "/" << coll[i].myHeroes[j].getPowerTypeString() << "/score:" <<
					coll[i].myHeroes[j].getPowerSize();
			}
			else {
				std::cout << coll[i].myHeroes[j].getNickname() << "/" << coll[i].myHeroes[j].getPowerTypeString() << "/score:" <<
					coll[i].myHeroes[j].getPowerSize() << ", ";
			}
		}
		std::cout << std::endl;
	}
}
