#include "Game.h"
#include "SuperHero.h"
#include "FileHandler.h"
#include "LogCommand.h"


void Game::run() {
	Vector<Admin> adminsCollection;
	Vector<Player> playersCollection;
	Vector<SuperHero> heroesCollection;
	FileHandler file;
	file.uploadFromFile(adminsCollection, playersCollection, heroesCollection, "AdminCollection.txt", "PlayersCollection.txt", "SuperHeroesCollection.txt");
	LogCommand command;
	command.execute(adminsCollection, playersCollection, heroesCollection);
	file.saveToFile(adminsCollection, playersCollection, heroesCollection, "AdminCollection.txt", "PlayersCollection.txt", "SuperHeroesCollection.txt");
}

