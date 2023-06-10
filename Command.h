#pragma once
#include "Admin.h"
#include "Player.h"

class Command
{
public:
	virtual void execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) = 0;
	~Command() = default;
};

