// Tom Steinman
// CS201-0005
// Program 5
#include "BBPlayer.h"
#include "CollegeBBPlayer.h"
#include "ProBBPlayer.h"
#include "Functions.h"

vector<BasketballPlayer*> teamList;

int main() {
	ofstream outFile;
	outFile.open("PlayerData.txt");
	if (!outFile.is_open()) {
		cout << "Unable to open output file\n";
		return -1;
	}
	getNCAAData(teamList);
	getNBAData(teamList);
	
	printTeam(outFile, teamList);

	cout << teamList.size() << endl;

	outFile.close();

}