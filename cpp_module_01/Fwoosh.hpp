#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell {
public:
	Fwoosh() : ASpell("Fwoosh" ,"fwooshed") {}
	~Fwoosh() {}
	Fwoosh *clone() {return new Fwoosh();}
};