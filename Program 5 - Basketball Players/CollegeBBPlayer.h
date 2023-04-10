// Tom Steinman
// CS201-0005
// Program 5

#pragma once
#include "BBPlayer.h"

class BasketBallPlayerCollege : public BasketballPlayer {
private:
	string team;

public:
	BasketBallPlayerCollege();
	BasketBallPlayerCollege(char type, string name, int numGames, float EFG, int TRB,
		int AST, int STL, int BLK, int TOV, int PTS, string team);
	void setTeam(string teamName);
	string getTeam();
	void print();
};