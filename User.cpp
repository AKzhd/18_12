#include "User.hpp"

User::User(){}
User::User(const std::string& name, const std::string& login, const std::string& pass) : _name(name), _login(login), _pass(pass) {}

void User::setName(const std::string& name)
{ 
	_name = name;
}
const std::string& User::getName() const
{
	return _name;
}

const std::string& User::getLogin() const
{
	return _login;
}

void User::setPass(const std::string& pass)
{
	_pass = pass;
}
const std::string& User::getPass() const
{
	return _pass;
}



std::fstream& User::operator >>(std::fstream& is)
{
	is >> _name;
	is >> _login;
	is >> _pass;
   	return is;
}
std::ostream& User::operator <<(std::ostream& os)
{
	os << _name;
	os << ' ';
	os << _login;
	os << ' ';
	os << _pass;
    os << ' ';
	os << std::endl;
	return os;
}

User::~User(){}