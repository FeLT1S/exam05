#pragma once

#include "ATarget.hpp"
#include <vector>

class TargetGenerator {
	std::vector<ATarget *> _trgs;

	TargetGenerator(TargetGenerator const & copy) {(void)copy;}
	TargetGenerator &operator=(TargetGenerator const & copy) {(void)copy; return *this;}
public:
	TargetGenerator() {}
	~TargetGenerator() {
		for (std::vector<ATarget *>::iterator it = _trgs.begin(); it != _trgs.end(); ++it)
			delete *it;
	}
	void learnTargetType(ATarget const * trg) {
		for (std::vector<ATarget *>::iterator it = _trgs.begin(); it != _trgs.end(); ++it)
		{
			if (trg->getType() == (*it)->getType())
				return ;
		}
		_trgs.push_back(trg->clone());
	}
	void forgetTargetType(std::string const & spell)
	{
		for (std::vector<ATarget *>::iterator it = _trgs.begin(); it != _trgs.end(); ++it)
		{
			if (spell == (*it)->getType())
			{
				_trgs.erase(it);
				return ;
			}
		}
	}
	ATarget *createTarget(std::string const & spell)
	{
		for (std::vector<ATarget *>::iterator it = _trgs.begin(); it != _trgs.end(); ++it)
		{
			if (spell == (*it)->getType())
				return (*it);
		}
		return NULL;
	}
};