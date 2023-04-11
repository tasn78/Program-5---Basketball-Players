
#include "functions.h"
#include "BBPlayer.h"
#include "ProBBPlayer.h"
#include "CollegeBBPlayer.h"


bool isdigit(string str) {
    return str.find_first_not_of("0123456789.") == string::npos;
}
bool digitCheck(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void getNCAAData(vector<BasketballPlayer*>& teamList) {

    //open file & check it is open
    ifstream inFile;
    inFile.open("playerStatsNCAA.csv");
    if (!inFile.is_open()) {
        cout << "Unable to open NCAA file\n";
        return;
    }
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    string tempRec, tempField;
    vector<string> row;
    getline(inFile, tempRec);       // reads entire row  

    while (inFile.good()) {
        stringstream inSS(tempRec);   // Copies tempRec into StringStream
        row.clear();                  // Clears row vector
        while (getline(inSS, tempField, ',')) {  //(input, output, separator) 
            row.push_back(tempField);
        }

        //BasketBallPlayerCollege* tempPlayer = new BasketBallPlayerCollege('C', row[0], stoi(row[1]), stof(row[2]),
        //    stoi(row[3]), stoi(row[4]), stoi(row[5]), stoi(row[6]), stoi(row[7]), stoi(row[8]), row[9]);
        
        BasketBallPlayerCollege* tempPlayer = new BasketBallPlayerCollege;
        tempPlayer->setPlayerType('C');     // C for college / NCAA

        /*
          // check each value in input for valid values
        if (digitCheck(row[1]))
            tempPlayer->setGames(stoi(row[1]));
        else {
            cout << "Error in record: " << tempPlayer->getPlayerName() << endl;
            getline(inFile, tempRec);
            continue;
        }
        if (isdigit(row[2]))
            tempPlayer->setEFG(stof(row[2]));
        else {
            cout << "Error in record: " << tempPlayer->getPlayerName() << endl;
            getline(inFile, tempRec);
            continue;
        }
        if (digitCheck(row[3]))
            tempPlayer->setAST(stoi(row[3]));
        else {
            cout << "Error in record: " << tempPlayer->getPlayerName() << endl;
            getline(inFile, tempRec);
            continue;
        }
        */
          // or use try/catch
        try {
         
            tempPlayer->setPlayerName(row[0]);
            tempPlayer->setTeam(row[9]);
            tempPlayer->setGames(stoi(row[1]));
            tempPlayer->setEFG(stof(row[2]));
            tempPlayer->setTRB(stoi(row[3]));
            tempPlayer->setAST(stoi(row[4]));
            tempPlayer->setSTL(stoi(row[5]));
            tempPlayer->setBLK(stoi(row[6]));
            tempPlayer->setTOV(stoi(row[7]));
            tempPlayer->setPoints(stoi(row[8]));

            teamList.push_back(tempPlayer);

            if (tempPlayer->getGames() >= 1) {
                float rating = ((tempPlayer->getPoints() + tempPlayer->getTRB() + tempPlayer->getAST() + tempPlayer->getSTL() +
                                 tempPlayer->getBLK() - ((tempPlayer->getPoints() / tempPlayer->getEFG()) - tempPlayer->getPoints() +
                                 tempPlayer->getTOV())) / tempPlayer->getGames());
                    tempPlayer->setEffRating(rating);
            }

            else
                throw runtime_error("Game count too low");
            getline(inFile, tempRec);
            continue;
        }
        catch (runtime_error e) {
            cout << "error for NCAA Player: " << row[0]
                << ":" << e.what() << endl;
            getline(inFile, tempRec);
            continue;
        }
        catch (invalid_argument e) {
            cout << "error for NCAA Player: " << row[0]
                << ":" << e.what() << endl;
            getline(inFile, tempRec);
            continue;
        }

        catch (...) {  //Catches any type of error - (...)
            cout << "Error for NCAA Player: " << row[0] << endl;
            getline(inFile, tempRec);
            continue;
        }

        teamList.push_back(tempPlayer);
        getline(inFile, tempRec);
    }

    inFile.close();
}


void getNBAData(vector<BasketballPlayer*>& teamList) {

    //open file & check it is open
    ifstream inFile;
    inFile.open("playerStatsPRO.csv");
    if (!inFile.is_open()) {
        cout << "Unable to open NBA file\n";
        return;
    }
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    string tempRec, tempField;
    vector<string> row;
    getline(inFile, tempRec);       // reads entire row  

    while (inFile.good()) {
        stringstream inSS(tempRec);   // Copies tempRec into StringStream
        row.clear();                  // Clears row vector
        while (getline(inSS, tempField, ',')) {  //(input, output, separator) 
            row.push_back(tempField);
        }

        BasketBallPlayerPro* tempPlayer = new BasketBallPlayerPro;
        tempPlayer->setPlayerType('P');     // P for Pro / NBA

        try {

            tempPlayer->setPlayerName(row[0]);
            tempPlayer->setGames(stoi(row[1]));
            tempPlayer->setEFG(stof(row[2]));
            tempPlayer->setTRB(stoi(row[3]));
            tempPlayer->setAST(stoi(row[4]));
            tempPlayer->setSTL(stoi(row[5]));
            tempPlayer->setBLK(stoi(row[6]));
            tempPlayer->setTOV(stoi(row[7]));
            tempPlayer->setPoints(stoi(row[8]));
            tempPlayer->setYears(stoi(row[10]));
            tempPlayer->setPosition(row[11]);

            teamList.push_back(tempPlayer);

            if (tempPlayer->getGames() > 5) {
                float rating = ((tempPlayer->getPoints() + tempPlayer->getTRB() + tempPlayer->getAST() + tempPlayer->getSTL() +
                    tempPlayer->getBLK() - ((tempPlayer->getPoints() / tempPlayer->getEFG()) - tempPlayer->getPoints() +
                        tempPlayer->getTOV())) / tempPlayer->getGames());
                tempPlayer->setEffRating(rating);
            }

            else
                throw runtime_error("Game count too low");
            getline(inFile, tempRec);
            continue;
        }
        catch (runtime_error e) {
            cout << "error for NBA Player: " << row[0]
                << ":" << e.what() << endl;
            getline(inFile, tempRec);
            continue;
        }
        catch (invalid_argument e) {
            cout << "error for NBA Player: " << row[0]
                << ":" << e.what() << endl;
            getline(inFile, tempRec);
            continue;
        }

        catch (...) {  //Catches any type of error - (...)
            cout << "Error for NBA Player: " << row[0] << endl;
            getline(inFile, tempRec);
            continue;
        }

    }

    inFile.close();
}




void printTeam(ofstream& outFile, vector<BasketballPlayer*> const& teamList) {
    for (int i = 0; i < teamList.size(); i++) {
        outFile << setw(20) << teamList[i]->getPlayerName() << setw(8) << teamList[i]->getValue() << setw(14) << fixed << setprecision(2) <<
            teamList[i]->getEffRating() << setw(10) << fixed << setprecision(2) << teamList[i]->getEFG() << endl;
    }
}
    /*    for (auto i : teamList) {
            cout << setw(20) << i->getPlayerName() << setw(8) << i->getValue() << setw(14) << fixed << setprecision(2) <<
                i->getEffRating() << setw(8) << i->getEFG() << endl;
        }
    }
}
*/