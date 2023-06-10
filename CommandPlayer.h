#pragma once
#include "Command.h"
#include "Player.h"

class CommandPlayer final: public Command
{
	Player& signInPlayer(Vector<Player>&);
	bool choiseForPlayer(Player& pl, Vector<Player>& plColl, Vector<SuperHero>& heroColl);
public:
	void execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) override;
};

