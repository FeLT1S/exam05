#pragma once
#include "Warlock.hpp"

class SpellBook {
	std::vector<ASpell *> _spells;

	SpellBook(SpellBook const & copy) {(void)copy;}
	SpellBook &operator=(SpellBook const & copy) {(void)copy; return *this;}
public:
	SpellBook() {}
	~SpellBook() {
		for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
			delete *it;
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
	ASpell *createSpell(std::string const & spell)
	{
		for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		{
			if (spell == (*it)->getName())
				return (*it);
		}
		return NULL;
	}
};