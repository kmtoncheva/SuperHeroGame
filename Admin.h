#pragma once
#include "User.h"
#include "Player.h"
#include "SuperHero.h"
#include "Vector.hpp"

class Admin : public User
{
	bool checkPass(String) const;
public:
	Admin();
	Admin(String, String, String, String);
	void printChoises() const override;
	void printAdmins(Vector<Admin>&) const;
	void printPlayers(Vector<Player>&) const;
	Player addPlayer(Vector<Player>& coll);
	Admin addAdmin(Vector<Admin>&);
	SuperHero addSuperHero(Vector<SuperHero>&);
	friend std::ostream& operator<<(std::ostream&, const Admin&);
};

