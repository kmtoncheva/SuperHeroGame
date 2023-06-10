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
	String getName() const;
	String getUserName() const;
	String getPass() const;
	String getEmail() const;
	User();
	User(String, String, String, String);
	virtual void printChoises() const = 0;
	virtual ~User() = default;
};

