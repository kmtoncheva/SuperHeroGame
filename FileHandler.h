#pragma once
#include "Vector.hpp"
#include "Admin.h"
#include "Player.h"
#include "SuperHero.h"
#include "Constants.h"


class FileHandler
{
	void uploadFromFileAdmin(Vector<Admin>&, const char*);
	void saveToFileAdmin(Vector<Admin>&, const char*);
	void uploadFromFilePlayer(Vector<Player>&, const char*);
	void saveToFilePlayer(Vector<Player>&, const char*);
	void uploadFromFileSuperHero(Vector<SuperHero>&, const char*);
	void saveToFileSuperHero(Vector<SuperHero>&, const char*);
	void uploadSuperHeroesCollection(Vector<Player>&, Vector<SuperHero>&);
	bool isEmpty(std::ifstream&) const;

public:
	FileHandler() = default;
	void uploadFromFile(Vector<Admin>&, Vector<Player>&, Vector<SuperHero>&, const char*, const char*, const char*);
	void saveToFile(Vector<Admin>&, Vector<Player>&, Vector<SuperHero>&, const char*, const char*, const char*);
};

