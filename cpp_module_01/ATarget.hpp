#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string _type;
public:
	ATarget() : _type(NULL) {}
	ATarget(ATarget const & copy) : _type(copy._type) {}
	ATarget &operator=(ATarget const & copy) {
		_type = copy._type;
		return *this;
	}
	virtual ~ATarget() {}
	
	ATarget(std::string const & type) : _type(type) {}

	std::string getType() const {return _type;}
	virtual ATarget *clone() const  = 0;

	void getHitBySpell(ASpell const & spell) const;
};