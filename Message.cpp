#include "Message.hpp"


Message::Message(){};
Message::Message(const std::string& text, const std::string& sender, const std::string& receiver) : _text(text), _sender(sender), _receiver(receiver) {};

const std::string& Message::getText() const
{
	return _text;
}
const std::string& Message::getSender() const
{
	return _sender;
}
const std::string& Message::getReceiver() const
{
	return _receiver;
}


std::fstream& Message::operator >>(std::fstream& is)
{
	is >> _text;
	is >> _sender;
	is >> _receiver;
	return is;
}
std::ostream& Message::operator <<(std::ostream& os)
{
	os << _text;
	os << ' ';
	os << _sender;
	os << ' ';
	os << _receiver;
	os << std::endl;
	return os;
}
Message::~Message(){}