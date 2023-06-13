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
	size_t powerSize = 0;
	size_t price = 0;
	size_t soldCount = 0;

	for (size_t i = 0; i < coll.size(); i++)
	{
		if ((coll[i].getInTheGame() == false) && (coll[i].getSold() != "0")) {
			soldCount++;
		}
	}

	if (soldCount != 0) {
		std::cout << "Already saved heroes you can choose from: \n\n";

		for (size_t i = 0; i < coll.size(); i++)
		{
			if ((coll[i].getInTheGame() == false) && (coll[i].getSold() != "0")) {
				std::cout << " - Name:" << coll[i].getName() << ", Nickname: " << coll[i].getNickname() << ", Type: " << coll[i].ToString(coll[i].getPowerType()) << ", Power: "
					<< coll[i].getPowerSize() << ", Price: " << coll[i].getPrice() << "$" << std::endl;
			}
		}
		std::cout << std::endl;
		String ans;
		std::cout << "Do you want to add some of them? (yes/no) ";
		std::cin >> ans;
		if (ans == "yes") {
			String tempNickname;
			bool checkNickname = false;
			std::cout << "Enter the nickname of the super hero you want to add again: ";
			std::cin >> tempNickname;
			for (size_t i = 0; i < coll.size(); i++)
			{
				if (tempNickname == coll[i].getNickname()) {
					coll[i].setSold("0");
					coll[i].setInTheGame(true);
					std::cout << "Congratulations! You added " << coll[i].getName() << " again in the game!\n";
					checkNickname = true;
					SuperHero saved("already saved", "already saved", "already saved", powerSize, price, false, "0", false);
					return saved;
				}
			}
			if (!checkNickname) {
				std::cout << "Sorry, wrong nickname! Try again later!\n";
				SuperHero error("error", "error", "error", powerSize, price, false, "0", false);
				return error;
			}
		}
		if (ans == "no") {
			std::cout << "Then add new super hero!\n";
		}
		else {
			std::cout << "Take this answer for 'no'. Then add new super hero!\n";
		}
	}
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
		std::cout << "Your password is not safe enough! (at least 1 uppecase, 1 lowercase and 1 digit) Enter new password: ";
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
		std::cout << i + 1 << ".  Name:" << admColl[i].getName() << ", Email: " << admColl[i].getEmail() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "What is your next turn?\n";
}

void Admin::printPlayers(Vector<Player>& coll) const {
	if (coll.size() == 0) {
		std::cout << "There are no players!\n";
		return;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < coll.size(); i++)
	{
		std::cout << i + 1 << ". Name: " << coll[i].getName() << ", Email: " << coll[i].getEmail() << ", Username: "
			<< coll[i].getUserName() << ", Password: " << coll[i].getPass() << ", Balance: " << coll[i].getMoney() << "$"
			<< ", Super Heroes: ";
		if (coll[i].myHeroes.size() == 0)
			std::cout << "\n  - no heroes";
		for (size_t j = 0; j < coll[i].myHeroes.size(); j++)
		{
			if (j == coll[i].myHeroes.size() - 1) {
				std::cout << std::endl  << "  - " << coll[i].myHeroes[j].getNickname() << " / " << coll[i].myHeroes[j].getPowerTypeString() << " / Score:" <<
					coll[i].myHeroes[j].getPowerSize();
			}
			else {
				std::cout << std::endl << "  - " << coll[i].myHeroes[j].getNickname() << " / " << coll[i].myHeroes[j].getPowerTypeString() << " / Score:" <<
					coll[i].myHeroes[j].getPowerSize();
			}
		}
		std::cout << std::endl;
	}
}

void Admin::deleteAccount(Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	if (plColl.size() == 0) {
		std::cout << "There are no players in the game! Please, enter another turn!\n\n";
		return;
	}
	String userName;
	String myPass;
	size_t index = 0;
	size_t count = 0;
	bool found = false;
	std::cout << "\nEnter the username of the player you want to delete: ";
	std::cin >> userName;
	for (size_t i = 0; i < plColl.size(); i++)
	{
		if (userName == plColl[i].getUserName()) {
			found = true;
			index = i;
			break;
		}
	}
	while (!found) {
		std::cout << "Sorry, we could't find player with this username! Try again:";
		std::cin >> userName;
		for (size_t i = 0; i < plColl.size(); i++)
		{
			if (userName == plColl[i].getUserName()) {
				index = i;
				found = true;
				break;
			}
		}
	}
	std::cout << "Confirm with your password: ";
	std::cin >> myPass;
	while (myPass != this->getPass()) {
		std::cout << "Wrong password! Try again : ";
		std::cin >> myPass;
	}
	if (plColl[index].haveHeroes()) {
		for (size_t i = 0; i < heroColl.size(); i++)
		{
			if (heroColl[i].getSold() == plColl[index].getPass()) {
				heroColl[i].setSold("0");
				heroColl[i].setInTheGame(false);
				heroColl[i].setDefense(false);
			}
		}
	}
	std::cout << "You deleted " << plColl[index].getName() << " successfully!\n";
	plColl.erase(index);
}