#pragma once
#include "String.h"

enum class PowerType {
	Fire,
	Water, 
	Earth
};

class SuperHero
{
	String name;
	String nickname;
	PowerType powerType;
	size_t powerSize = 0;
	size_t price = 0;
	bool attack = false;

public:
	SuperHero() = default;
	SuperHero(String, String, String, size_t, size_t);
	String ToString(PowerType) const;
	PowerType ToType(const String&) const;
	friend std::ostream& operator<<(std::ostream&, const SuperHero&);
};

