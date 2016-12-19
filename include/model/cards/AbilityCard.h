#ifndef ABILITY_CARD_H
#define ABILITY_CARD_H

#include <string>
#include <iostream>
#include <memory>
#include "model/cards/Card.h"
#include "model/cards/AnimalCard.h"
#include "model/cards/abilities/Ability.h"
#include "functions.h"
using namespace std;

class AbilityCard : public Card {
protected:
	Ability::AbilityType ability;
	bool duplicated;
	bool passive;
	AnimalCard* owner;
public:
	AbilityCard(Ability::AbilityType, bool duplicated, bool passive);

	Ability::AbilityType getAbility();	

	string getDescription();
	AbilityCard* getAbilityCard();

	virtual ostream& write(ostream&) = 0;
	virtual istream& read(istream&) = 0;

	bool isDuplicated();
	bool isPassive();
	
	void setOwner(AnimalCard* owner);

	virtual string getStatus() = 0;
	virtual void use() = 0;
	static shared_ptr<AbilityCard> readFromFile(istream&);
};

#endif