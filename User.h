#pragma once
#include "String.h"
#include "Vector.hpp"

class User
{
protected:
	String name;
	String userName;
	String password;
	String email;
public:
	User();
	User(String, String, String, String);
	String getName() const;
	String getUserName() const;
	String getPass() const;
	String getEmail() const;
	virtual void printChoises() const = 0;
	virtual ~User() = default;
};

