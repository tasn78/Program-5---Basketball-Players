#pragma once
#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "BBPlayer.h"


using namespace std;

void getNCAAData(vector<BasketballPlayer*>& teamList);
void getNBAData(vector<BasketballPlayer*>& teamList);

void printTeam(ofstream& outFile, vector<BasketballPlayer*> const& teamList);

