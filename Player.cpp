#include "Player.h"
Player::Player() : User() {}
Player::Player(String _name, String _email, String _user, String _pass, size_t _money) : User(_name, _email, _user, _pass) 
{
	money = _money;
}
void Player::printChoises() const {
	std::cout << "\n>>See all players" << "\n>>See rank" << "\n>>Display market" << "\n>>Buy new Super Hero"
		<< "\n>>Attack player" << "\n>>Set Super Hero position\n" << "\n>>Delete profile" << "\n>>Leave game\n";
}


std::ostream& operator<<(std::ostream& os, const Player& obj) {
	os << obj.name << "," << obj.email << "," << obj.userName << "," << obj.password << "," << obj.money;
	return os;
}