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
	bool defense = false;
	String sold;
	bool inTheGame = false;
public:
	SuperHero() = default;
	SuperHero(String, String, String, size_t, size_t, bool, String, bool);
	int ComparePowerSize(SuperHero&) const;
	void comparePowerType(SuperHero&);
	String ToString(PowerType) const;
	PowerType ToType(const String&) const;
	friend std::ostream& operator<<(std::ostream&, const SuperHero&);
	const String getName() const;
	const String getNickname() const;
	const PowerType getPowerType() const;
	bool getDefense() const;
	String getSold() const;
	bool getInTheGame() const;
	size_t getPowerSize() const;
	size_t getPrice() const;
	void setSold(String);
	void setInTheGame(bool);
	void setDefense(bool);
	void setPowerSize(size_t);
	void boostPowerSize(size_t);
	String getPowerTypeString() const;
};

