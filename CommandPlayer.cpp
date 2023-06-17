#include "CommandPlayer.h"
#include "Constants.h"
#include "LogCommand.h"

size_t CommandPlayer::counter = 0;

Player& CommandPlayer::signInPlayer(Vector<Player>& coll) {
	if (coll.size() == 0) {
		throw std::invalid_argument("There are no players!");
	}
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
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (coll[i].getUserName() == _userName && coll[i].getPass() == _pass) {
			logged = true;
			wrongTry = -1;
			std::cout << std::endl << coll[i].getName() << " you have successfully logged in as player! You have only 3 turns in this session! What's first? \n";
			return coll[i];
		}
	}
	if (!logged) {
		count++;
		std::cout << "Wrong username or password! Please try again!\n";
		wrongTry++;
		Player& res = signInPlayer(coll);
		return res;
	}
}
char CommandPlayer::choiseForPlayer(Player& player, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {

	String choise;
	std::cout << std::endl << "->";
	std::cin >> choise;

	if (choise == "See all players" || choise == "see all players") {
		player.printPlayers(plColl);
		return 'i'; // it is returning info, not an action
	}
	if (choise == "Sign out" || choise == "sign out") {
		player.setLogged(false);
		std::cout << "\nGoodbye! See you again!\n\n";
		return 'q'; // quit
	}
	if (choise == "Display market" || choise == "display market") {
		player.displayMarket(heroColl);
		return 'i';
	}
	if (choise == "See rank" || choise == "see rank") {
		player.seeRank(plColl);
		return 'i';
	}
	if (choise == "Buy new super hero" || choise == "buy new super hero") {
		player.buySuperHero(heroColl);
		return 'a'; // action
	}
	if (choise == "Delete my account" || choise == "delete my account") {
		player.deleteMyself(plColl, heroColl);
		return 'q';
	}
	if (choise == "Show balance" || choise == "show balance") {
		player.showBalance();
		return 'i';
	}
	if (choise == "Set Super Hero to defense" || choise == "set super hero to defense") {
		player.setMode(heroColl, true); //defense mode - true, attack mode - false (by default)
		return 'a';
	}
	if (choise == "Set Super Hero to attack" || choise == "set super hero to attack") {
		player.setMode(heroColl, false); //defense mode - true, attack mode - false (by default)
		return 'a';
	}
	if (choise == "Boost my super hero" || choise == "boost my super hero") {
		player.boostSuperHero(heroColl);
		return 'a';
	}
	if (choise == "Attack player" || choise == "attack player") {
		player.attackPlayer(plColl, heroColl);
		return 'a';
	}
	else {
		std::cout << "Please enter a valid turn! ";
		char res = choiseForPlayer(player, plColl, heroColl);
		return res;
	}
}

void CommandPlayer::execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	Player* playerLoggedPtr = nullptr;
	try {
		playerLoggedPtr = &signInPlayer(plColl);
	}
	catch (std::invalid_argument& exc) {
		std::cout << std::endl << exc.what() << std::endl;
		return;
	}
	Player& playerLogged = *playerLoggedPtr;

	// money for a period of time (if all players has logged)
	if (playerLogged.getLogged() == true) {
		counter = 0;
	}
	if (playerLogged.getLogged() == false) {
		counter++;
		playerLogged.setLogged(true);
	}
	if (counter == plColl.size()) {
		for (size_t i = 0; i < plColl.size(); i++)
		{
			plColl[i].addMoney(2*MONEY);
			plColl[i].setLogged(false);
		}
		counter = 0;
	}

	playerLogged.printChoises();
	size_t counter = 0;
	char toContinue = 'i'; // i - info / a - action / q - quit
	while (toContinue == 'i' || toContinue == 'a') {
		if (counter == 3) {
			std::cout << "\nSorry! You have no more turns! See you soon!\n\n";
			LogCommand commandL;
			commandL.execute(admColl, plColl, heroColl);
			return;
		}
		toContinue = choiseForPlayer(playerLogged, plColl, heroColl);
		if (toContinue == 'a') {
			counter++;
		}
	}
		LogCommand temp;
		temp.execute(admColl, plColl, heroColl);
}