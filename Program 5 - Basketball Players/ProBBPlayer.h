// Tom Steinman
// CS201-0005
// Program 5

#pragma once
#include "BBPlayer.h"

class BasketBallPlayerPro : public BasketballPlayer {
private:
	int years;
	string position;
	int contractValue;

public:
	BasketBallPlayerPro();
	BasketBallPlayerPro(char type, string name, int numGames, float EFG, int TRB,
						int AST, int STL, int BLK, int TOV, int PTS, int Years, string Position);
	void setYears(int years);
	void setPosition(string position);
	void setContractValue(int ContractValue);
	void print();
	int getYears();
	string getPosition();
	int getContractValue();
};