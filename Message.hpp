#pragma once
#include <string>
#include <fstream>


class Message{
    private:
        std::string _text;
        std::string _sender;
        std::string _receiver;
    public:
        Message();
        Message(const std::string& text, const std::string& sender, const std::string& receiver);
        const std::string& getText() const;
        const std::string& getSender() const;
        const std::string& getReceiver() const;

		std::fstream& operator >>(std::fstream& is);
	    std::ostream& operator <<(std::ostream& os);
        ~Message();
};