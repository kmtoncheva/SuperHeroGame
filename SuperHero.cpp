#include "SuperHero.h"

String SuperHero::ToString(PowerType type) const{
	switch (type)
	{
	case PowerType::Fire:
		return "Fire"; break;
	case PowerType::Water:
		return "Water"; break;
	case PowerType::Earth:
		return "Earth"; break;
	default:
		break;
	}
}

PowerType SuperHero::ToType(const String& str) const{
	if (str == "Fire" || str == "fire") {
		return PowerType::Fire;
	}
	if (str == "Water" || str == "water") {
		return PowerType::Water;
	}
	if (str == "Earth" || str == "earth") {
		return PowerType::Earth;
	}
}

SuperHero::SuperHero(String _name, String _nickName, String _powerType, size_t _powerSize, size_t _price, bool _defense, String _sold, bool _inTheGame)
	: name(_name), nickname(_nickName), powerType(ToType(_powerType)), powerSize(_powerSize), price(_price), defense(_defense), sold(_sold), inTheGame(_inTheGame) {}

std::ostream& operator<<(std::ostream& os, const SuperHero& obj) {
	os << obj.name << "," << obj.nickname << "," << obj.ToString(obj.powerType) << "," << obj.powerSize << "," << obj.price
		<< "," << obj.defense << "," << obj.sold << "," << obj.inTheGame;
	return os;
}

int SuperHero:: ComparePowerSize(SuperHero& other) const{
	if (this->getPowerSize() > other.getPowerSize()) {
		return 1;
	}
	if (this->getPowerSize() == other.getPowerSize()) {
		return 0;
	}
	if (this->getPowerSize() < other.getPowerSize()) {
		return -1;
	}
}

void SuperHero::ComparePowerType(SuperHero& other) {
	size_t temp = 0;
	switch (powerType)
	{
	case PowerType::Fire:
		if (other.powerType == PowerType::Water) {
			temp = 2 * (other.getPowerSize());
			other.setPowerSize(temp);
			return;
		}
		if (other.powerType == PowerType::Earth) {
			temp = 2 * (this->getPowerSize());
			this->setPowerSize(temp);
			return;
		}
		break;
	case PowerType::Water:
		if (other.powerType == PowerType::Earth) {
			temp = 2 * other.getPowerSize();
			other.setPowerSize(temp);
			return;
		}
		if (other.powerType == PowerType::Fire) {
			temp = 2 * (this->getPowerSize());
			this->setPowerSize(temp);
			return;
		}
		break;
	case PowerType::Earth:
		if (other.powerType == PowerType::Fire) {
			temp = 2 * other.getPowerSize();
			other.setPowerSize(temp);
			return;
		}
		if (other.powerType == PowerType::Water) {
			temp = 2 * (this->getPowerSize());
			this->setPowerSize(temp);
			return;
		}
		break;
	default:
		break;
	}
}

const String SuperHero::getName() const {
	return name;
}
const String SuperHero::getNickname() const {
	return nickname;
}
const PowerType SuperHero::getPowerType() const {
	return powerType;
}
bool SuperHero::getDefense() const{
	return defense;
}
String SuperHero::getSold() const{
	return sold;
}
bool SuperHero::getInTheGame() const{
	return inTheGame;
}
size_t SuperHero::getPowerSize() const {
	return powerSize;
}
size_t SuperHero::getPrice() const {
	return price;
}
void SuperHero::setSold(String _sold) {
	sold = _sold;
}
void SuperHero::setInTheGame(bool _inTheGame) {
	inTheGame = _inTheGame;
}
void SuperHero::setDefense(bool _defense) {
	defense = _defense;
}
String SuperHero::getPowerTypeString() const {
	return ToString(powerType);
}
void SuperHero::setPowerSize(size_t ps) {
	powerSize = ps;
}
void SuperHero::boostPowerSize(size_t add) {
	powerSize += add;
}