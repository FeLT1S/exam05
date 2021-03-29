#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;
public:
	ASpell() : _name(NULL), _effects(NULL) {}
	ASpell(ASpell const & copy) : _name(copy._name), _effects(copy._effects) {}
	ASpell &operator=(ASpell const & copy) {
		_name = copy._name;
		_effects = copy._effects;
		return *this;
	}
	virtual ~ASpell() {}
	
	ASpell(std::string const & name, std::string const & effects) : _name(name), _effects(effects) {}

	std::string getName() const {return _name;}
	std::string getEffects() const {return _effects;}
	virtual ASpell *clone() const = 0;

	void launch(ATarget const & trg) const;
};

