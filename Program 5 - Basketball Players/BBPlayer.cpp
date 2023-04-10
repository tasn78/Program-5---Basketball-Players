// Tom Steinman
// CS201-0005
// Program 5

#include "BBPlayer.h"

BasketballPlayer::BasketballPlayer() {
	playerType = '0';
	playerName = "Unknown";
	games = 0;
	efg = 0;
	trb = 0;
	ast = 0;
	stl = 0;
	blk = 0;
	tov = 0;
	pts = 0;
}
BasketballPlayer::BasketballPlayer(char type, string name, int numGames, float EFG,
	int TRB, int AST, int STL, int BLK, int TOV, int PTS)  {
	playerType = type;
	playerName = name;
	games = numGames;
	efg = EFG;
	trb = TRB;
	ast = AST;
	stl = STL;
	blk = BLK;
	tov = TOV;
	pts = PTS;

	float rating = (pts + trb + ast + stl + blk - (pts / efg - pts + tov) / games);
	setEffRating(rating);

	if (efg > 0.7 || rating > 20) {
		setValue(10);
	}
	else if (efg > 0.65 || rating > 15) {
		setValue(9);
	}
	else if (efg > 0.65 || stl / games > 2 && pts / games > 20 && trb / games > 5 && tov / games <= 1) {
		setValue(9);
	}
	else if (efg > 0.60 || rating > 13) {
		setValue(8);
	}
	else if (efg > 0.60 || blk / games > 3 && pts / games > 15 && trb / games > 5) {
		setValue(8);
	}
	else if (efg > 0.60 || pts / games > 15 && trb / games > 5 && tov / games < 2) {
		setValue(8);
	}
	else if (efg > 0.55 || rating > 10) {
		setValue(7);
	}
	else if (efg > 0.55 || pts / games > 15 && trb / games > 5) {
		setValue(7);
	}
	else if (efg > 0.55 || blk / games > 3 && pts / games > 10 && trb / games > 4) {
		setValue(6);
	}
	else if (efg > 0.45 || pts / games > 10 && trb / games > 4) {
		setValue(5);
	}
	else if (efg > 0.40 || pts / games > 5 && trb / games > 3) {
		setValue(3);
	}
	else if (efg > 0.35 || pts / games > 5 && trb / games > 3) {
		setValue(5);
	}
	else {
		setValue(0);
	}
}

void BasketballPlayer::setPlayerType(char type) {
	playerType = type;
}

void BasketballPlayer::setPlayerName(string name) {
	playerName = name;
}

void BasketballPlayer::setGames(int numGames) {
	games = numGames;
}

void BasketballPlayer::setEFG(float EFG) {
	efg = EFG;
}

void BasketballPlayer::setTRB(int TRB) {
	trb = TRB;
}

void BasketballPlayer::setAST(int AST) {
	ast = AST;
}

void BasketballPlayer::setSTL(int STL) {
	stl = STL;
}

void BasketballPlayer::setBLK(int BLK) {
	blk = BLK;
}

void BasketballPlayer::setTOV(int TOV) {
	tov = TOV;
}

void BasketballPlayer::setPoints(int PTS) {
	pts = PTS;
}

void BasketballPlayer::setEffRating(float rating) {
	effRating = rating;

	if (this->getEFG() > 0.7 || rating > 20) {
		setValue(10);
	}
	else if (this->getEFG() > 0.65 || rating > 15) {
		setValue(9);
	}
	else if (this->getEFG() > 0.65 || stl / games > 2 && pts / games > 20 && trb / games > 5 && tov / games <= 1) {
		setValue(9);
	}
	else if (this->getEFG() > 0.60 || rating > 13) {
		setValue(8);
	}
	else if (this->getEFG() > 0.60 || blk / games > 3 && pts / games > 15 && trb / games > 5) {
		setValue(8);
	}
	else if (this->getEFG() > 0.60 || pts / games > 15 && trb / games > 5 && tov / games < 2) {
		setValue(8);
	}
	else if (this->getEFG() > 0.55 || rating > 10) {
		setValue(7);
	}
	else if (this->getEFG() > 0.55 || pts / games > 15 && trb / games > 5) {
		setValue(7);
	}
	else if (this->getEFG() > 0.55 || blk / games > 3 && pts / games > 10 && trb / games > 4) {
		setValue(6);
	}
	else if (this->getEFG() > 0.45 || pts / games > 10 && trb / games > 4) {
		setValue(5);
	}
	else if (this->getEFG() > 0.40 || pts / games > 5 && trb / games > 3) {
		setValue(3);
	}
	else if (this->getEFG() > 0.35 || pts / games > 5 && trb / games > 3) {
		setValue(5);
	}
	else {
		setValue(0);
	}
}

void BasketballPlayer::setValue(int val) {
	value = val;
}

void BasketballPlayer::print() {
	cout << "Implement base print";
}

char BasketballPlayer::getPlayerType() {
	return playerType;
}

string BasketballPlayer::getPlayerName() {
	return playerName;
}

int BasketballPlayer::getGames() {
	return games;
}

float BasketballPlayer::getEFG() {
	return efg;
}

int BasketballPlayer::getTRB() {
	return trb;
}

int BasketballPlayer::getAST() {
	return ast;
}

int BasketballPlayer::getSTL() {
	return stl;
}

int BasketballPlayer::getBLK() {
	return blk;
}

int BasketballPlayer::getTOV() {
	return tov;
}

int BasketballPlayer::getPoints() {
	return pts;
}

float BasketballPlayer::getEffRating() {
	return effRating;
}

int BasketballPlayer::getValue() {
	return value;
}