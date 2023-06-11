#include "CommandPlayer.h"
#include "LogCommand.h"


Player& CommandPlayer::signInPlayer(Vector<Player>& coll) {
	if (coll.size() == 0) {
		throw std::invalid_argument("There are no players!");
	}
	bool logged = false;
	static int count = 0;
	if (count == 3) {
		throw std::invalid_argument("Sorry, you do not have more attempts!");
	}
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
char CommandPlayer::choiseForPlayer(Player& player, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	String choise;
	std::cout << std::endl << "->";
	std::cin >> choise;
	if (choise == "See all players" || choise == "see all players") {
		player.printPlayers(plColl);
		return 'i'; // it is returning info, not an action
	}
	if (choise == "Sign out" || choise == "sign out") {
		std::cout << "\nGoodbye! See you again!\n\n";
		return 'q'; // quit
	}
	if (choise == "Display market" || choise == "display market") {
		player.displayMarket(heroColl);
		return 'i'; 
	}
	if (choise == "Buy new super hero" || choise == "buy new super hero") {
		player.buySuperHero(heroColl);
		return 'a';
	}
	if (choise == "Delete my account" || choise == "delete my account") {
		player.deleteMyself(plColl, heroColl);
		return 'q';
	}
	if (choise == "Show balance" || choise == "show balance") {
		player.showBalance();
		return 'i';
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