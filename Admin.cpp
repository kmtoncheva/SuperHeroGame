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
	std::cout << "\n-> Enter name: ";
	std::cin >> name;
	std::cout << "-> Enter SuperHero nickname: ";
	std::cin >> nickname;
	std::cout << "-> Enter SuperHero Power (Fire, Water, Earth): ";
	std::cin >> tempPowerType;
	std::cout << "-> Enter SuperHero power (score): ";
	std::cin >> powerSize;
	std::cout << "-> Enter SuperHero price: ";
	std::cin >> price;
	std::cin.ignore();
	std::cout << "\nCongratulations! You added the super hero! What is your next turn? \n";
	SuperHero hero(name, nickname, tempPowerType, powerSize, price);
	return hero;
}

Player Admin::addPlayer(Vector<Player>& coll) {
	String name, email, userName, pass;
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
		if (userName == coll[i].getUserName()) {
			std::cout << "This username already exist! Enter again: ";
			std::cin >> userName;
			break;
		}
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
			std::cout << "This password is not free! Enter new one: ";
			std::cin >> pass;
			break;
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
		if (userName == coll[i].getUserName()) {
			std::cout << "This username already exist! Enter again: ";
			std::cin >> userName;
			break;
		}
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
			std::cout << "This password is not free! Enter new one: ";
			std::cin >> pass;
			break;
		}
	}
	std::cout << "\nCongratulations! You added the admin! What is your next turn?\n";
	Admin res(name, email, userName, pass);
	return res;
}

void Admin::printChoises() const {
	std::cout << "\n>>Add new admin" << "\n>>Add new player" << "\n>>See all players" << "\n>>See all admins"
		<< "\n>>Add new super hero" << "\n>>Delete player" << "\n>>Leave\n\n";
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