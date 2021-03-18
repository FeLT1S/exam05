#pragma once
#include <iostream>

class Warlock {
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(Warlock const & copy) {(void)copy;}
	Warlock &operator=(Warlock const & copy) {(void)copy; return *this;}
public:
	Warlock(std::string const & name, std::string const & title) : _name(name), _title(title) {
		std::cout << _name << ": This looks like another boring day." << std::endl;
	}

	~Warlock() {
		std::cout << _name << ": My job here is done!" << std::endl;
	}

	std::string getName() const {return _name;}
	std::string getTitle() const {return _title;}

	void setTitle(std::string const & title) { _title = title;}

	void introduce() const {
		std::cout << _name << ": I am" << _name <<", " << _title << "!" << std::endl;
	}
};