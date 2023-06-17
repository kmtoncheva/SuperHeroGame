#include "LogCommand.h"
#include "CommandAdmin.h"
#include "CommandPlayer.h"

size_t LogCommand::counter = 0;

LogCommand::LogCommand() {
	if (counter == 0) {
		std::cout << "---> Welcome to Super Heroes Game! <---\n" << std::endl;
	}
	counter++;
}

void LogCommand::execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	char chosen = 0;
	std::cout << "--> Press 1 to sign in as an administrator" << std::endl;
	if (plColl.size() != 0) {
		std::cout << "--> Press 2 to sign in as a player" << std::endl;
	}
	std::cout << "--> Press Q to quit" << std::endl;
	std::cin >> chosen;
	if (chosen == '1') {
		CommandAdmin commmandA;
		commmandA.execute(admColl, plColl, heroColl);
	}
	if (chosen == '2') {
		CommandPlayer commandP;
		commandP.execute(admColl, plColl, heroColl);
	}
	if (chosen == 'Q' || chosen == 'q')
	{
		system("CLS");
		std::cout << "See you soon!\n";
		return;
	}
	else if (chosen != '1' && chosen != '1' && chosen != '2') {
		std::cout << "Please enter a valid turn! : \n";
		execute(admColl, plColl, heroColl);
	}
}