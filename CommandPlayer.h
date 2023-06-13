#pragma once
#include "Command.h"
#include "Player.h"

class CommandPlayer final: public Command
{
private:
	static size_t counter;
	Player& signInPlayer(Vector<Player>&);
	char choiseForPlayer(Player& pl, Vector<Player>& plColl, Vector<SuperHero>& heroColl);
public:
	void execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) override;
};

