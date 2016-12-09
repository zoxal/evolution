#include "model/cards/abilities/Fat.h"
#include "model/cards/abilities/Ability.h"
#include "model/cards/AbilityCard.h"
#include "exceptions/Exception.h"
#include "functions.h"
#include <iostream>
#include <string>
using namespace std;

Fat::Fat() : AbilityCard(Ability::FAT) {};

bool Fat::hasReserve() {
	return reserve;
}

void Fat::useReserve() {
	reserve = false;
}

void Fat::fillReserve() {
	if (reserve) {
		throw Exception("Cannot fill full reserve for Fat ability");
	}
	reserve = true;
}

string Fat::getStatus() {
	string status = abilityToString(ability);
	status += "(";
	status += (reserve)? "full" : "empty";
	status += "(";
	return status;
}

ostream& Fat::write(ostream& stream)  {
	stream << abilityToString(ability) << endl;
	return stream;
}
istream& Fat::read(istream& stream) {
	cout << "Reading from stream: " << abilityToString(ability) << endl;
	return stream;
}