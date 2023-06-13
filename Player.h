#pragma once
#include "User.h"
#include "SuperHero.h"
#include "Vector.hpp"

class Player : public User
{
private:
	bool logged = false;
	size_t money;
	size_t Abs(int);
	void fight(Vector<Player>&, Vector<SuperHero>&, size_t, size_t, size_t, size_t,size_t);
public:
	Vector<SuperHero> myHeroes;
	Player();
	Player(String, String, String, String, size_t);

	void printChoises() const override;
	bool haveHeroes() const;
	void addMoney(size_t);
	void removeMoney(size_t);
	void seeRank(Vector<Player>) const;
	void displayMarket(Vector<SuperHero>&) const;
	void buySuperHero(Vector <SuperHero>&);
	void deleteMyself(Vector<Player>&, Vector<SuperHero>&);
	size_t getMoney() const;
	bool getLogged() const;
	void setLogged(bool);
	void setMoney(size_t);
	void printPlayers(Vector<Player>&) const;
	void showBalance() const;
	void setMode(Vector<SuperHero>&, bool);
	void attackPlayer(Vector<Player>&, Vector<SuperHero>&);
	void boostSuperHero(Vector<SuperHero>&);
	friend std::ostream& operator<<(std::ostream&, const Player&);
};

