#pragma once
#include "User.h"
#include "SuperHero.h"
#include "Vector.hpp"

class Player : public User
{
	size_t money = 1000;
	Vector<SuperHero> myHeroes;
public:
	Player();
	Player(String, String, String, String, size_t money);
	void printChoises() const override;
	//void printPlayers(Vector<Player>&) const override;
	friend std::ostream& operator<<(std::ostream&, const Player&);
};

