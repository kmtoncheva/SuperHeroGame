#include "CommandPlayer.h"
#include "LogCommand.h"


Player& CommandPlayer::signInPlayer(Vector<Player>& coll) {
	bool logged = false;
	static int count = 0;
	String _userName;
	String _pass;
	if (count != 0) {
		std::cout << "--> Enter username: ";
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
			std::cout << std::endl << coll[i].getName() << " you have successfully logged in as player! You have only 3 turns in this session! What's first? \n";
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
bool CommandPlayer::choiseForPlayer(Player& player, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	String choise;
	std::cout << std::endl;
	std::cin >> choise;
	if (choise == "See all players" || choise == "see all players") {
		player.printPlayers(plColl);
		return true;
	}
	if (choise == "Sign out" || choise == "sign out") {
		std::cout << "\nGoodbye! See you again!\n\n";
		return false;
	}
	if (choise == "Display market" || choise == "display market") {
		player.displayMarket(heroColl);
		return true;
	}
	if (choise == "Buy new super hero" || choise == "buy new super hero") {
		player.buySuperHero(heroColl);
		return true;
	}
	else {
		std::cout << "Please enter a valid turn! ";
		bool res = choiseForPlayer(player, plColl, heroColl);
		return res;
	}
}

void CommandPlayer::execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	Player& playerLogged = signInPlayer(plColl);
	playerLogged.printChoises();
	size_t index = 0;
	bool toContinue = true;
	for (index = 0; index < 3; index++)
	{
		toContinue = choiseForPlayer(playerLogged, plColl, heroColl);
		if (toContinue == false) {
			break;
		}
	}
	if (toContinue == false) {
		LogCommand temp;
		temp.execute(admColl, plColl, heroColl);
	}
	if (index == 3) {
		std::cout << "\nSorry! You have no more turns! See you soon!\n\n";
		LogCommand commandL;
		commandL.execute(admColl, plColl, heroColl);
	}
}