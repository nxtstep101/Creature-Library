#ifndef CREATURES_H
#define CREATURES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Cost {
	double careHours, costPerHour, foodCost, materialsCost;
};

struct Creatures {
	string creatureName, creatureDescription, creatureLocation;
	double avgLength, avgHeight;
	bool creatureThreat;
	Cost creatureCost;
};

int enterCreatures(int, Creatures[]);
void printCreatures(int, Creatures[]);
void printStatistics(int, Creatures[]);
void saveCreatureToFile(int, Creatures[]);
float convertToFloat(string);

#endif
