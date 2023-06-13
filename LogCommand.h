#pragma once
#include "Command.h"

class LogCommand final : public Command
{
	static size_t counter;
public:
	LogCommand();
	void execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) override;
};

