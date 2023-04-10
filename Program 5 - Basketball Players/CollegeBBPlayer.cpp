#include "CollegeBBPlayer.h"

BasketBallPlayerCollege::BasketBallPlayerCollege() : BasketballPlayer() {
	team = "Unknown";
}
BasketBallPlayerCollege::BasketBallPlayerCollege(char type, string name, int numGames, float EFG, int TRB,
	int AST, int STL, int BLK, int TOV, int PTS, string teamName) :
	BasketballPlayer(type, name, numGames, EFG, TRB, AST, STL, BLK, TOV, PTS) {
	team = teamName;
}

void BasketBallPlayerCollege::setTeam(string teamName) {
	team = teamName;
}

string BasketBallPlayerCollege::getTeam() {
	return team;
}

void BasketBallPlayerCollege::print() {
	cout << this->getPlayerName() << " " << this->getValue() << " " << this->getValue() << endl;
}