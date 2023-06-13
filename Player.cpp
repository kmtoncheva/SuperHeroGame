#include "Player.h"
#include "LogCommand.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

size_t Player::Abs(int num) {
	if (num < 0) {
		return (-num);
	}
	return num;
}

void Player::seeRank(Vector<Player> coll) const{
	int maxIndex = 0;
	for (size_t i = 0; i < coll.size() - 1; i++)
	{
		maxIndex = i;
		for (size_t j = i + 1; j < coll.size(); j++)
		{
			if (coll[j].getMoney() > coll[maxIndex].getMoney()) {
				maxIndex = j;
			}
		}
		if (maxIndex != i) {
			std::swap(coll[i], coll[maxIndex]);
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < coll.size(); i++)
	{
		std::cout << i + 1 << ". " << coll[i].getName() << std::endl;
	}
}

Player::Player() : User() {}
Player::Player(String _name, String _email, String _user, String _pass, size_t _money) : User(_name, _email, _user, _pass) 
{
	money = _money;
}

void Player::printChoises() const {
	std::cout << "\n>>Show balance" << "\n>>See all players" << "\n>>See rank" << "\n>>Display market" << "\n>>Buy new Super Hero"
		<< "\n>>Attack player" << "\n>>Set Super Hero to defense / Set Super hero to attack\n" << ">>Boost my super hero\n" << ">>Delete my account" << "\n>>Sign out\n";
}

size_t Player::getMoney() const{
	return money;
}
void Player::setMoney(size_t _money) {
	money = _money;
}
void Player::addMoney(size_t _add) {
	size_t res = this->getMoney() + _add;
	setMoney(res);
}
void Player::removeMoney(size_t _remove) {
	if (_remove >= this->getMoney()) {
		setMoney(0);
		return;
	}
	size_t res = this->getMoney() - _remove;
	setMoney(res);
}
bool Player::getLogged() const {
	return logged;
}
void Player::setLogged(bool newLog) {
	logged = newLog;
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
		if (coll[i].getSold() == "0" && coll[i].getNickname() != "error" && coll[i].getNickname() != "already saved") {
			std::cout <<"-  Name:" << coll[i].getName() << ", Nickname: " << coll[i].getNickname() << ", Type: " << coll[i].ToString(coll[i].getPowerType()) << ", Power: "
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
		std::cout << i + 1 << ". Name : " << coll[i].getUserName() << ", Money: " << coll[i].getMoney() << "$" << ", Super Heroes: ";
		if (coll[i].myHeroes.size() == 0)
			std::cout << "\n  - no heroes";
		for (size_t j = 0; j < coll[i].myHeroes.size(); j++)
		{
			if (j == coll[i].myHeroes.size() - 1) {
				std::cout << std::endl <<  "  - " << coll[i].myHeroes[j].getNickname();
			}
			else {
				std::cout << std::endl << "  - " << coll[i].myHeroes[j].getNickname();
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
				heroColl[i].setDefense(false);
			}
		}
	}
	plColl.erase(index);
	std::cout << "Your account has been deleted!\n\n";
}

void Player::showBalance() const {
	std::cout << std::endl << this->getMoney() << "$\n";
}

void Player::setMode(Vector<SuperHero>& coll, bool mode) {
	if (this->myHeroes.size() == 0) {
		std::cout << "You don't have super heroes!";
		return;
	}
	String nickname;
	bool found = false;
	std::cout << "Enter the nickname of the Super Hero you want to change mode: ";
	std::cin >> nickname;
	for (size_t i = 0; i < this->myHeroes.size(); i++)
	{
		if (nickname == this->myHeroes[i].getNickname()) {
			found = true;
			this->myHeroes[i].setDefense(mode);
			for (size_t i = 0; i < coll.size(); i++)
			{
				if (nickname == coll[i].getNickname()) {
					coll[i].setDefense(mode);
					if (mode) {
						std::cout << coll[i].getNickname() << " set to defense mode successfully!\n";
					}
					else {
						std::cout << coll[i].getNickname() << " set to attack mode successfully!\n";
					}
					break;
				}
			}
			break;
		}
	}
	if (!found) {
		std::cout << "No Super Heroes with this name! Please try again later!\n";
		return;
	}
}

void Player::fight(Vector<Player>& plColl, Vector<SuperHero>& heroColl,size_t indexOfMyHeroToAttackWithFromMyColl, size_t indexOfMyHeroToAttackWithFromMainColl, size_t indexOfPlayerToAttack, size_t indexOfHeroToFightWithFromOtherCollection, size_t indexOfHeroToFightWithFromMainCollection) {
	if (plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection].getDefense() == true) {

		this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].comparePowerType(plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection]);
		int temp = this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].ComparePowerSize(plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection]);

		size_t powerSizeDiff = Abs(this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].getPowerSize() - plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection].getPowerSize());
		if (temp == 1) {
			this->addMoney(MONEY);
			plColl[indexOfPlayerToAttack].myHeroes.erase(indexOfHeroToFightWithFromOtherCollection); // remove from myHero collection
			heroColl[indexOfHeroToFightWithFromMainCollection].setDefense(false);
			heroColl[indexOfHeroToFightWithFromMainCollection].setInTheGame(false); // now can be added again from admin in main hero collection

			std::cout << "You won 100$ and " << plColl[indexOfPlayerToAttack].getName() << " lost their super hero!\n";
			return;
		}
		if (temp == -1) {
			this->removeMoney(2 * powerSizeDiff);
			this->myHeroes.erase(indexOfMyHeroToAttackWithFromMyColl);
			heroColl[indexOfMyHeroToAttackWithFromMainColl].setDefense(false);
			heroColl[indexOfMyHeroToAttackWithFromMainColl].setInTheGame(false);

			std::cout << "You lost " << (2 * powerSizeDiff) << "$ and your player!\n";
			return;
		}
		if (temp == 0) {
			this->removeMoney(MONEY);
			std::cout << "You lost 100$\n";
			return;
		}
	}
	this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].comparePowerType(plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection]);
	size_t tempRes = this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].ComparePowerSize(plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection]);
	size_t powerSizeDiff = Abs(this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].getPowerSize() - plColl[indexOfPlayerToAttack].myHeroes[indexOfHeroToFightWithFromOtherCollection].getPowerSize());
	if (tempRes == -1) {
		this->removeMoney(2 * powerSizeDiff);
		plColl[indexOfPlayerToAttack].addMoney(MONEY);
		this->myHeroes.erase(indexOfMyHeroToAttackWithFromMyColl);
		heroColl[indexOfMyHeroToAttackWithFromMainColl].setDefense(false);
		heroColl[indexOfMyHeroToAttackWithFromMainColl].setInTheGame(false);
		if (this->getMoney() == 0) {
			std::cout << "You lost all your money and your player!\n";
			return;
		}
		std::cout << "You lost " << (2 * powerSizeDiff) << "$ and your player!\n";
		return;
	}
	if (tempRes == 0) {
		this->removeMoney(50);
		std::cout << "Equal fight! You lost 50$!\n";
		return;
	}
	if (tempRes == 1) {
		this->addMoney(powerSizeDiff);
		plColl[indexOfPlayerToAttack].removeMoney(powerSizeDiff);
		plColl[indexOfPlayerToAttack].myHeroes.erase(indexOfHeroToFightWithFromOtherCollection);
		heroColl[indexOfHeroToFightWithFromMainCollection].setDefense(false);
		heroColl[indexOfHeroToFightWithFromMainCollection].setInTheGame(false);
		std::cout << "You won " << powerSizeDiff << "$ and " << plColl[indexOfPlayerToAttack].getName() << " lost their super hero!\n";
		return;
	}
}

void Player::attackPlayer(Vector<Player>& plColl, Vector<SuperHero>& heroColl) {
	if (this->myHeroes.size() == 0) {
		std::cout << "You don't have super heroes to attack with! Please, first buy one!\n";
		return;
	}
	if (plColl.size() == 1) {
		std::cout << "There are no other players in the game!\n";
		return;
	}
	String mySuperHeroNickname;
	bool found = false;
	size_t indexOfMyHeroToAttackWithFromMyColl = 0;
	std::cout << "Enter the nickname of your super hero you want to attack with: ";
	std::cin >> mySuperHeroNickname; // nickname of my super hero (attacker)
	for (size_t i = 0; i < this->myHeroes.size(); i++)
	{
		if (mySuperHeroNickname == this->myHeroes[i].getNickname()) {
			found = true;
			indexOfMyHeroToAttackWithFromMyColl = i;
			break;
		}
	}
	if (!found) {
		std::cout << "No super hero with this nickname found! Please, try again later!\n";
		return;
	}
	size_t indexOfMyHeroToAttackWithFromMainColl = 0;
	for (size_t i = 0; i < heroColl.size(); i++)
	{
		if (mySuperHeroNickname == heroColl[i].getNickname()) {
			indexOfMyHeroToAttackWithFromMainColl = i;
			break;
		}
	}
	String _username;
	found = false;
	size_t indexOfPlayerToAttack = 0;
	std::cout << "Enter username of the player you want to attack: ";
	std::cin >> _username;
	for (size_t i = 0; i < plColl.size(); i++)
	{
		if (_username == plColl[i].getUserName()) {
			found = true;
			indexOfPlayerToAttack = i; // index in plColl of the attacked player
			break;
		}
	}
	if (!found) {
		std::cout << "No players with such username! Please, try again later!\n";
		return;
	}
	if (plColl[indexOfPlayerToAttack].myHeroes.size() == 0) {
		std::cout << "This player does not have super heroes! You win 100$\n";
		this->addMoney(MONEY);
		plColl[indexOfPlayerToAttack].removeMoney(this->myHeroes[indexOfMyHeroToAttackWithFromMyColl].getPowerSize());
		return;
	}
	String superHeroToFightWith;
	found = false;
	size_t indexOfHeroToFightWithFromOtherCollection = 0;
	std::cout << "Enter the nickname of the super hero you want to fight with:(R for random)\n";
	for (size_t i = 0; i < plColl[indexOfPlayerToAttack].myHeroes.size(); i++)
	{
		std::cout << "> " << plColl[indexOfPlayerToAttack].myHeroes[i].getNickname() << std::endl;
	}
	std::cout << std::endl;
	std::cin >> superHeroToFightWith;
	if (superHeroToFightWith == "R" || superHeroToFightWith == "r") {

		//pick random
		std::srand(static_cast<size_t>(std::time(nullptr))); //seed the random number generator
		size_t randomIndexOtherColl = std::rand() % plColl[indexOfPlayerToAttack].myHeroes.size();
		std::cout << "You will be fighting with: " << plColl[indexOfPlayerToAttack].myHeroes[randomIndexOtherColl].getNickname() << std::endl << std::endl;
		size_t randomIndexMainColl = 0;
		for (size_t i = 0; i < heroColl.size(); i++)
		{
			if (plColl[indexOfPlayerToAttack].myHeroes[randomIndexOtherColl].getNickname() == heroColl[i].getNickname()) {
				randomIndexMainColl = i;
				break;
			}
		}
		fight(plColl, heroColl, indexOfMyHeroToAttackWithFromMyColl, indexOfMyHeroToAttackWithFromMainColl, indexOfPlayerToAttack, randomIndexOtherColl, randomIndexMainColl);
		return;
	}
	else {
		for (size_t i = 0; i < plColl[indexOfPlayerToAttack].myHeroes.size(); i++)
		{
			if (superHeroToFightWith == plColl[indexOfPlayerToAttack].myHeroes[i].getNickname()) {
				found = true;
				indexOfHeroToFightWithFromOtherCollection = i;
				break;
			}
		}
		if (!found) {
			std::cout << "Wrong username! Try again later!\n";
			return;
		}
		size_t indexOfHeroToFightWithFromMainCollection = 0;
		for (size_t i = 0; i < heroColl.size(); i++)
		{
			if (heroColl[i].getNickname() == superHeroToFightWith) {
				indexOfHeroToFightWithFromMainCollection = i;
				break;
			}
		}
		fight(plColl, heroColl, indexOfMyHeroToAttackWithFromMyColl, indexOfMyHeroToAttackWithFromMainColl, indexOfPlayerToAttack, indexOfHeroToFightWithFromOtherCollection, indexOfHeroToFightWithFromMainCollection);	
	}
}

void Player::boostSuperHero(Vector<SuperHero>& coll) {
	if (this->getMoney() < 100) {
		std::cout << "Not enough balance!\n";
		return;
	}
	String nicknameSuperHero;
	size_t indexMyColl = 0;
	size_t indexMainColl = 0;
	bool found = false;
	std::cout << "Enter the nickname of the super hero you want to boost: ";
	std::cin >> nicknameSuperHero;
	for (size_t i = 0; i < this->myHeroes.size(); i++)
	{
		if (nicknameSuperHero == this->myHeroes[i].getNickname()) {
			indexMyColl = i;
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "This hero does not exist in your collection! Please, try again later!\n";
		return;
	}
	for (size_t i = 0; i < coll.size(); i++)
	{
		if (nicknameSuperHero == coll[i].getNickname()) {
			indexMainColl = i;
			break;
		}
	}
	size_t moneyToBoost = 0;
	std::cout << "Enter how much money to boost with (your balance: " << this->getMoney() << "$)\n >>300$ - 100 points\n" << " >>400$ - 150 points\n" " >>500$ - 200 points\n";
	std::cin >> moneyToBoost;
	if (moneyToBoost > this->getMoney()) {
		std::cout << "Error! Please, try again later!\n";
		std::cin.ignore();
		return;
	}
	switch (moneyToBoost)
	{
	case 300:
		this->removeMoney(300);
		this->myHeroes[indexMyColl].boostPowerSize(100);
		coll[indexMainColl].boostPowerSize(100);
		std::cout << "Congratulations! You boosted your super hero!\n";
		std::cin.ignore();
		return;
	case 400:
		this->removeMoney(400);
		this->myHeroes[indexMyColl].boostPowerSize(150);
		coll[indexMainColl].boostPowerSize(150);
		std::cout << "Congratulations! You boosted your super hero!\n";
		std::cin.ignore();
		return;
	case 500:
		this->removeMoney(500);
		this->myHeroes[indexMyColl].boostPowerSize(200);
		coll[indexMainColl].boostPowerSize(200);
		std::cout << "Congratulations! You boosted your super hero!\n";
		std::cin.ignore();
		return;
	default:
		std::cout << "Error! Please, try again later!\n";
		std::cin.ignore();
		return;
	}
}
