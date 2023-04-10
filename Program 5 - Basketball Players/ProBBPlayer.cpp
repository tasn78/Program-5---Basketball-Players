#include "ProBBPlayer.h"

BasketBallPlayerPro::BasketBallPlayerPro() : BasketballPlayer() {
	years = 0;
	position = "Unknown";
	contractValue = 0;
}

BasketBallPlayerPro::BasketBallPlayerPro(char type, string name, int numGames, float EFG, int TRB, int AST, int STL,
										int BLK, int TOV, int PTS, int Years, string Position) 
										: BasketballPlayer(type, name, numGames, EFG, TRB, AST, STL, BLK, TOV, PTS) {

	if (Years <= 0) {
		years = 0;
	}
	else {
		years = Years;
	}
	
	position = Position;

	//Contract Value determined by playerValue
	if (this->value == 10) {
		setContractValue(12000000);
	}
	else if (this->value == 9) {
		setContractValue(10000000);
	}
	else if (this->value == 8) {
		setContractValue(7500000);
	}
	else if (this->value == 7) {
		setContractValue(6000000);
	}
	else if (this->value == 5 || this->value == 6) {
		setContractValue(5000000);
	}
	else if (this->value == 3 || this->value == 4) {
		setContractValue(2500000);
	}
	else {
		setContractValue(500000);
	}
}

void BasketBallPlayerPro::setYears(int Years) {
	years = Years;
}

void BasketBallPlayerPro::setPosition(string Position) {
	position = Position;
}

void BasketBallPlayerPro::setContractValue(int ContractVal) {
	contractValue = ContractVal;
}

void BasketBallPlayerPro::print() {
	cout << this->getPlayerName() << " " << this->getValue() << " " << this->getEffRating()
			<< " " << this-> getContractValue() << " " << this->getPosition() << endl;
}

int BasketBallPlayerPro::getYears() {
	return years;
}

string BasketBallPlayerPro::getPosition() {
	return position;
}

int BasketBallPlayerPro::getContractValue() {
	return contractValue;
}