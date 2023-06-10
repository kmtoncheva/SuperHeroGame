#include "Game.h"
#include "SuperHero.h"
#include "FileHandler.h"
#include "LogCommand.h"


void Game::run() {
	static Vector<Admin> adminsCollection;
	static Vector<Player> playersCollection;
	static Vector<SuperHero> heroesCollection;
	FileHandler file;
	file.uploadFromFile(adminsCollection, playersCollection, heroesCollection, "AdminCollection.txt", "PlayersCollection.txt", "SuperHeroesCollection.txt");
	LogCommand command;
	command.execute(adminsCollection, playersCollection, heroesCollection);
	file.saveToFile(adminsCollection, playersCollection, heroesCollection, "AdminCollection.txt", "PlayersCollection.txt", "SuperHeroesCollection.txt");
}

