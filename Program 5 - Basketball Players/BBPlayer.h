// Tom Steinman
// CS201-0005
// Program 5

#pragma once
#include <string>
#include <iostream>
using namespace std;

class BasketballPlayer {
protected:
    char playerType;   //pro or college
    string playerName; //player name
    int games;   //total games played
    float efg;   //effective field goal
    int trb;     //total rebounds
    int ast;     //total assists
    int stl;     //total steals
    int blk;     //total blocks
    int tov;     //total turn overs
    int pts;     //total points
    float effRating;  //calculated based on equation provided
    int value;  //calculated based on table provided in requirements

public:
    BasketballPlayer();
    BasketballPlayer(char playerType, string playerName, int games, float efg,
                     int trb, int ast, int stl, int blk, int tov, int pts);
    void setPlayerType(char);
    void setPlayerName(string);
    void setGames(int);
    void setEFG(float);
    void setTRB(int);
    void setAST(int);
    void setSTL(int);
    void setBLK(int);
    void setTOV(int);
    void setPoints(int);
    void setEffRating(float);
    void setValue(int);
    void print();
    char getPlayerType();
    string getPlayerName();
    int getGames();
    float getEFG();
    int getTRB();
    int getAST();
    int getSTL();
    int getBLK();
    int getTOV();
    int getPoints();
    float getEffRating();
    int getValue();
};

