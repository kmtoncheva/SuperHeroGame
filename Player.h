#pragma once
#include "User.h"
#include "SuperHero.h"
#include "Vector.hpp"

class Player : public User
{
	size_t money;
public:
	Vector<SuperHero> myHeroes;
	Player();
	Player(String, String, String, String, size_t);
	void printChoises() const override;
	void displayMarket(Vector<SuperHero>&) const;
	void buySuperHero(Vector <SuperHero>&);
	size_t getMoney() const;
	void setMoney(size_t);
	void printPlayers(Vector<Player>&) const;
	friend std::ostream& operator<<(std::ostream&, const Player&);
};

