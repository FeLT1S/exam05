#pragma once
#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Warlock {
	std::string _name;
	std::string _title;
	std::vector<ASpell *> _spells;
	Warlock();
	Warlock(Warlock const & copy) {(void)copy;}
	Warlock &operator=(Warlock const & copy) {(void)copy; return *this;}
public:
	Warlock(std::string const & name, std::string const & title) : _name(name), _title(title) {
		std::cout << _name << ": This looks like another boring day." << std::endl;
	}

	~Warlock() {
		std::cout << _name << ": My job here is done!" << std::endl;
		for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
			delete *it;
	}

	std::string getName() const {return _name;}
	std::string getTitle() const {return _title;}

	void setTitle(std::string const & title) { _title = title;}

	void introduce() const {
		std::cout << _name << ": I am " << _name <<", " << _title << "!" << std::endl;
	}

	void learnSpell(ASpell const * spell) {
		for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		{
			if (spell->getName() == (*it)->getName())
				return ;
		}
		_spells.push_back(spell->clone());
	}
	void forgetSpell(std::string const & spell)
	{
		for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		{
			if (spell == (*it)->getName())
			{
				_spells.erase(it);
				return ;
			}
		}
	}
	void launchSpell(std::string const & spell, ATarget const & trg)
	{
		for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		{
			if (spell == (*it)->getName())
				(*it)->launch(trg);
		}
	}
};