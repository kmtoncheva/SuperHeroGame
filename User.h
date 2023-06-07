#pragma once
#include "String.h"
#include "Vector.hpp"
class User
{
protected:
	//size_t ID;
	String name;
	String userName;
	String password;
	String email;
public:
	String getName() const;
	String getUserName() const;
	String getPass() const;
	String getEmail() const;
	User();
	User(String, String, String, String);
	virtual void printChoises() const = 0;
	//virtual void printPlayers(Vector<Player>&) const = 0; vector<user>???
	//virtual void deletePlayer() = 0;
	//virtual User& peekPlayer() const = 0;
};

