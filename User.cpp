#include "User.h"


User::User() {
	name = "\0";
	email = "\0";
	userName = "\0";
	password = "\0";
}
User::User(String _name, String _email, String _user, String _pass) {
	name = _name;
	email = _email;
	userName = _user;
	password = _pass;
}

String User::getName() const {
	return name;
}
String User::getUserName() const
{
	return userName;
}
String User::getPass() const {
	return password;
}
String User::getEmail() const {
	return email;
}