#include "ASpell.hpp"
#include "ATarget.hpp"

void ASpell::launch(ATarget const & trg) const {
	trg.getHitBySpell((*this));
}

void ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}