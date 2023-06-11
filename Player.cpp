#include "Player.h"
#include "LogCommand.h"

Player::Player() : User() {}
Player::Player(String _name, String _email, String _user, String _pass, size_t _money) : User(_name, _email, _user, _pass) 
{
	money = _money;
}
void Player::printChoises() const {
	std::cout << "\n>>Show balance" << "\n>>See all players" << "\n>>See rank" << "\n>>Display market" << "\n>>Buy new Super Hero"
		<< "\n>>Attack player" << "\n>>Set Super Hero position\n" << ">>Delete my account" << "\n>>Sign out\n";
}

size_t Player::getMoney() const{
	return money;
}
void Player::setMoney(size_t _money) {
	money = _money;
}
std::ostream& operator<<(std::ostream& os, const Player& obj) {
	os << obj.name << "," << obj.email << "," << obj.userName << "," << obj.password << "," << obj.money;
	return os;
}

void Player::displayMarket(Vector<SuperHero>& coll) const {
	std::cout << std::endl;
	size_t counter = 0;
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (coll[i].getSold() == "0") {
			counter++;
		}
	}
	if (counter == 0) {
		std::cout << "Sorry! There are no Super Heroes available!\n";
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (coll[i].getSold() == "0") {
			std::cout << " - Name:" << coll[i].getName() << ", Nickname: " << coll[i].getNickname() << ", Type: " << coll[i].ToString(coll[i].getPowerType()) << ", Power: "
				<< coll[i].getPowerSize() << ", Price: " << coll[i].getPrice() << "$" << std::endl;
		}
	}
	std::cout << std::endl << "What is your next turn? " << std::endl;
}

void Player::buySuperHero(Vector <SuperHero>& coll) {
	size_t counter = 0;
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (coll[i].getSold() == "0") {
			counter++;
		}
	}
	if (counter == 0) {
		std::cout << "Sorry! There are no Super Heroes available!\n";
		return;
	}
	String nick;
	std::cout << "\nEnter the nickname of the Super Hero you want to buy: ";
	std::cin >> nick;
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (coll[i].getNickname() == nick && coll[i].getSold() == "0") {
			if (money >= coll[i].getPrice()) {
				size_t temp = money - coll[i].getPrice();
				setMoney(temp);
				coll[i].setSold(this->getPass());
				coll[i].setInTheGame(1);
				this->myHeroes.push_back(coll[i]);
				std::cout << "Congratulation! " << coll[i].getName() << " is your new Super Hero! What is your next turn?";
				return;
			}
			else {
				std::cout << "\nNot enough balance!";
				return;
			}
			break;
		}
	}
	std::cout << "Unavailable Super Hero!\n";
}
void Player::printPlayers(Vector<Player>& coll) const {
	std::cout << std::endl;
	for (size_t i = 0; i < coll.size(); i++)
	{
		std::cout << " - Name : " << coll[i].getUserName() << ", Money: " << coll[i].getMoney() << "$" << ", Super Heroes: ";
		if (coll[i].myHeroes.size() == 0)
			std::cout << "no heroes";
		for (size_t j = 0; j < coll[i].myHeroes.size(); j++)
		{
			if (j == coll[i].myHeroes.size() - 1) {
				std::cout << coll[i].myHeroes[j].getNickname();
			}
			else {
				std::cout << coll[i].myHeroes[j].getNickname() << ", ";
			}
		}
		std::cout << std::endl;
	}
}
bool Player::haveHeroes() const {
	return (myHeroes.size() != 0);
}
void Player::deleteMyself(Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	size_t index = 0;
	for (size_t i = 0; i < plColl.size(); i++)
	{
		if (this->getPass() == plColl[i].getPass()) {
			index = i;
			break;
		}
	}
	if (haveHeroes()) {
		for (size_t i = 0; i < heroColl.size(); i++)
		{
			if (heroColl[i].getSold() == this->getPass()) {
				heroColl[i].setSold("0");
				heroColl[i].setInTheGame(false);
				heroColl[i].setAttack(false);
			}
		}
	}
	plColl.erase(index);
	std::cout << "Your account has been deleted!\n\n";
}
void Player::showBalance() const {
	std::cout << std::endl << this->getMoney() << " $\n";
}