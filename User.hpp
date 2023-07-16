#pragma once
#include <string>
#include <fstream>


class User {
    private:
        std::string _name;
        std::string _login;
        std::string _pass;
    public:
        User(); 
        User(const std::string& name, const std::string& login, const std::string& pass);
        void setName(const std::string& name);
        const std::string& getName() const;
        const std::string& getLogin() const;
        void setPass(const std::string& pass);
        const std::string& getPass() const;

        std::fstream& operator >>(std::fstream& is);
	    std::ostream& operator <<(std::ostream& os);

        ~User();
};
