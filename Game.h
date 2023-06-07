#pragma once
#include "Admin.h"
#include "Player.h"
#include "Vector.hpp"

class Game
{
	void loadAdmins(Vector<Admin>&, const char*);
	void loadPlayers(Vector<Player>&, const char*);
	void loadSuperHeroes(Vector<SuperHero>&, const char*);
	void saveSuperHeroes(Vector<SuperHero>&, const char*);
	void saveAdmins(Vector<Admin>&, const char*);
	void savePlayers(Vector<Player>&, const char*);
	//bool checkPass(String) const;
	Admin& signInAdmin(Vector<Admin>&);
	Player& signInPlayer(Vector<Player>&);
	String setToUserName(const char*) const;
	String setToPass(const char*) const;
	String setToName(const char*) const;
	String setToEmail(const char*) const;
	String setToPassPlayer(const char*) const;
	size_t setToScore(const char*) const;
	size_t setToPrice(const char*) const;

public:
	bool choiseForAdmins(Admin&, Vector<Admin>&, Vector<Player>&, Vector<SuperHero>&);
	bool choiseForPlayers(Player&, Vector<Admin>&, Vector<Player>&, Vector<SuperHero>&);
	bool isEmpty(std::ifstream&) const;
	void run();
	void signIn(Vector<Admin>&, Vector<SuperHero>&, Vector<Player>&);
};

