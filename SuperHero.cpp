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
	if (str == "Fire") {
		return PowerType::Fire;
	}
	if (str == "Water") {
		return PowerType::Water;
	}
	if (str == "Earth") {
		return PowerType::Earth;
	}
}

SuperHero::SuperHero(String _name, String _nickName, String _powerType, size_t _powerSize, size_t _price)
	: name(_name), nickname(_nickName), powerType(ToType(_powerType)), powerSize(_powerSize), price(_price) {}

std::ostream& operator<<(std::ostream& os, const SuperHero& obj) {
	os << obj.name << "," << obj.nickname << "," << obj.ToString(obj.powerType) << "," << obj.powerSize << "," << obj.price;
	return os;
}