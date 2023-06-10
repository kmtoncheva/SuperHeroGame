#pragma once
#include "Command.h"
class CommandAdmin final : public Command
{
	Admin& signInAdmin(Vector<Admin>&);
	bool choiseForAdmins(Admin& adm, Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl);
public:
	void execute(Vector<Admin>& admColl, Vector<Player>& plColl, Vector<SuperHero>& heroColl) override;
};

