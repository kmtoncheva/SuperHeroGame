#include "CommandAdmin.h"
#include "LogCommand.h"

Admin& CommandAdmin::signInAdmin(Vector<Admin>& admColl) {

	bool logged = false;
	static int count = 0;
	static int wrongTry = 0;

	if (wrongTry == 3) {
		throw std::invalid_argument("Sorry, you do not have more attempts!");
	}

	String _userName;
	String _pass;

	if (wrongTry == -1) {
		std::cout << "--> Enter username: ";
		std::cin.ignore();
		std::cin >> _userName;
		std::cout << "--> Enter password: ";
		std::cin >> _pass;
	}
	if (count != 0 && wrongTry != -1) {
		std::cout << "--> Enter username: ";
		std::cin >> _userName;
		std::cout << "--> Enter password: ";
		std::cin >> _pass;
	}
	if (count == 0 && wrongTry != -1) {
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
			wrongTry = -1;
			std::cout << std::endl << admColl[i].getName() << " you have successfully logged in as administrator!\n";
			return admColl[i];
		}
	}
	if (!logged) {
		count++;
		wrongTry++;
		std::cout << "Wrong username or password! Please try again!\n";
		Admin& res = signInAdmin(admColl);
		return res;
	}
}

bool CommandAdmin::choiseForAdmins(Admin& adm, Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {

	String choise;
	std::cout << std::endl;
	std::cout << "->";
	std::cin >> choise;

	if (choise == "Add new admin" || choise == "add new admin") {
		Admin res = adm.addAdmin(admColl);
		admColl.push_back(res);
		return true;
	}
	if (choise == "Add new player" || choise == "add new player") {
		Player res = adm.addPlayer(plColl);
		plColl.push_back(res);
		return true;
	}
	if (choise == "Sign out" || choise == "sign out") {
		std::cout << "\nGoodbye! See you again!\n\n";
		return false;
	}
	if (choise == "Add new super hero" || choise == "add new super hero") {
		SuperHero res = adm.addSuperHero(heroColl);
		if (res.getNickname() == "error" && res.getName() == "error") {
			return true;
		}
		if (res.getName() == "already saved" || res.getNickname() == "already saved") {
			return true;
		}
		heroColl.push_back(res);
		return true;
	}
	if (choise == "See all admins" || choise == "see all admins") {
		adm.printAdmins(admColl);
		return true;
	}
	if (choise == "See all players" || choise == "see all players") {
		adm.printPlayers(plColl);
		return true;
	}
	if (choise == "Delete player" || choise == "delete player") {
		adm.deleteAccount(plColl, heroColl);
		return true;
	}
	else {
		std::cout << "Please enter a valid turn! : ";
		bool res = choiseForAdmins(adm, admColl, plColl, heroColl);
		return res;
	}
}

void CommandAdmin::execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	Admin* adminLoggedPtr = nullptr;
	try {
		adminLoggedPtr = &signInAdmin(admColl);
	}
	catch (std::invalid_argument& exc) {
		std::cout << std::endl << exc.what() << std::endl;
		return;
	}
	Admin& adminLogged = *adminLoggedPtr;
	size_t counter = 0;
	for (size_t i = 0; i < heroColl.size(); i++)
	{
		if (heroColl[i].getSold() == "0") {
			counter++;
		}
	}
	if (counter == 0) {
		std::cout << "\n--> Welcome! You should add at least 3 new Super Heroes!\n\n";
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
	LogCommand log;
	log.execute(admColl, plColl, heroColl);
	return;
}