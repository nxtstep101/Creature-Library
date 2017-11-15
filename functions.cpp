#include "creatures.h"

using namespace std;

int enterCreatures(int numCreatures, Creatures creaturesArray[]) {
	if (numCreatures != 100) {
		int userChoice = 0;
		string userFile = "";
		string tempString = "";
		string tempData = "";
		
		cout << "What do you want to do?" << endl;
		cout << "\t1. Load my creatures from a file" << endl;
		cout << "\t2. Enter one creature manually." << endl;
		cout << "\tChoose either 1 or 2" << endl;

		do {
			cout << "CHOICE: ";
			cin >> userChoice;
			if (userChoice == 1) {
				cout << "What is the name of the file with your list of creatures?" << endl;
				cout << "FILENAME: ";
				cin >> userFile;
				cin.ignore();
				
				ifstream uFile;
				uFile.open(userFile.c_str());
				
				if (!uFile.is_open()) {
					cout << endl << userFile << " does not exist or is corrupt. Can't load creatures." << endl << endl;
				}
				
				else {
					getline(uFile, tempString, '#');
					while (!uFile.eof()) {
						creaturesArray[numCreatures].creatureName = tempString;
						getline(uFile, creaturesArray[numCreatures].creatureDescription, '#');
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].avgLength = convertToFloat(tempData);
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].avgHeight = convertToFloat(tempData);
						getline(uFile, creaturesArray[numCreatures].creatureLocation, '#');
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].creatureThreat = convertToFloat(tempData);
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].creatureCost.careHours = convertToFloat(tempData);
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].creatureCost.costPerHour = convertToFloat(tempData);
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].creatureCost.foodCost = convertToFloat(tempData);
						getline(uFile, tempData, '#');
						creaturesArray[numCreatures].creatureCost.materialsCost = convertToFloat(tempData);
						numCreatures++;
						getline(uFile, tempString, '#');
					}
					uFile.close();
				}	
				cout << endl << numCreatures << " creatures from " << userFile << " have been added to the database." << endl << endl;
				
				return numCreatures;
			}

			else if (userChoice == 2) {
				cin.ignore();
				cout << "Name: ";
				getline(cin, creaturesArray[numCreatures].creatureName);
				cout << endl << "Description: ";
				getline(cin, creaturesArray[numCreatures].creatureDescription);
				cout << endl << "Avg Length (ft): ";
				cin >> creaturesArray[numCreatures].avgLength;
				cin.ignore();
				cout << endl << "Avg Height (ft): ";
				cin >> creaturesArray[numCreatures].avgHeight;
				cin.ignore();
				cout << endl << "Location: ";
				getline(cin, creaturesArray[numCreatures].creatureLocation);
				cout << endl << "Is the creature dangerous? (y or n): ";
				
				char tempChar;
				while (tempChar != 'y' && tempChar != 'n') {
					cin >> tempChar;
					
					if (tempChar == 'y') {
						creaturesArray[numCreatures].creatureThreat = true;
					}
					
					else if (tempChar == 'n') {
						creaturesArray[numCreatures].creatureThreat = false;
					}
					
					else {
						cout << "Please enter either 'y' or 'n'." << endl;
					}
				}
				cout << endl << "How many hours do you spend caring for the " << creaturesArray[numCreatures].creatureName << "? ";
				cin >> creaturesArray[numCreatures].creatureCost.careHours;
				cout << endl << "What is the cost per hour for caring for " << creaturesArray[numCreatures].creatureName << "? ";
				cin >> creaturesArray[numCreatures].creatureCost.costPerHour;
				cout << endl << "How much money do you spend on " << creaturesArray[numCreatures].creatureName << "? ";
				cin >> creaturesArray[numCreatures].creatureCost.foodCost;
				cout << endl << "How much money do you spend on grooming and medical supplies for the " << creaturesArray[numCreatures].creatureName << "? ";
				cin >> creaturesArray[numCreatures].creatureCost.materialsCost;
				cout << endl << "The " << creaturesArray[numCreatures].creatureName << " was added!" << endl;
				cin.ignore();
				numCreatures++;
						
				return numCreatures;
			}
		
			else {
				cout << "Please enter either 1 or 2" << endl;
			}
			
		} while (userChoice != 1 || userChoice != 2);
	}
	
	else {
		cout << "Sorry! Your zoo is at full capacity, not able to add additional creatures at this time." << endl;
	}
}

void printCreatures(int numCreatures, Creatures creaturesArray[]) {
	if (numCreatures == 0) {
		cout << "There are no creatures in your zoo!" << endl << endl;
		return;
	}
	
	else {
		for(int k = 0; k < numCreatures; k++) {
			string threatString;
			if (creaturesArray[k].creatureThreat == true) {
				threatString = "Yes";
			}
			
			else {
				threatString = "No";
			}
	
			cout << "CREATURE " << (k+1) << ":" << endl;
			cout << setw(10) << left << "Name:" << setw(10) << left << creaturesArray[k].creatureName << endl;
			cout << setw(10) << left << "Description:" << setw(10) << left << endl << creaturesArray[k].creatureDescription << endl << endl;
			cout << setw(50) << left << "Length:" << creaturesArray[k].avgLength << " feet" << endl;
			cout << setw(50) << left << "Height:" << creaturesArray[k].avgHeight << " feet" << endl;			
			cout << setw(50) << left << "Location:" <<  creaturesArray[k].creatureLocation << endl;
			cout << setw(50) << left << "Dangerous?" <<  threatString << endl;
			cout << setw(50) << left << "Number of hours to care for the creature:" << creaturesArray[k].creatureCost.careHours << endl;
			cout << setw(50) << left << "Cost per hour of taking care of creature:" << "$" << creaturesArray[k].creatureCost.costPerHour << endl;
			cout << setw(50) << left << "Cost to feed creature:" << "$" << creaturesArray[k].creatureCost.foodCost << endl;
			cout << setw(50) << left << "Grooming and Supplies cost:" << "$" << creaturesArray[k].creatureCost.materialsCost << endl;
			cout << "--------------------------------------------------" << endl << endl;
		}
	}
}

void printStatistics(int numCreatures, Creatures creaturesArray[]) {
	double totalCost = 0.0;
	cout << "Cost of each creature for one week:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "CREATURE" << setw(36) << "COST" << endl;
	
	for (int g = 0; g < numCreatures; g++) {
		cout << setw(20) << left << creaturesArray[g].creatureName << setw(20) << left << "$";
		cout << setw(20) << left << (creaturesArray[g].creatureCost.careHours * creaturesArray[g].creatureCost.costPerHour) + creaturesArray[g].creatureCost.foodCost + creaturesArray[g].creatureCost.materialsCost;
		cout << endl;
	}
	
	for (int j = 0; j < numCreatures; j++) {
		totalCost += (creaturesArray[j].creatureCost.careHours * creaturesArray[j].creatureCost.costPerHour) + creaturesArray[j].creatureCost.foodCost + creaturesArray[j].creatureCost.materialsCost;
	}
	
	cout << endl << setw(20) << left << "Total Cost:" << setw(20) << left << "$" << setw(20) << left << totalCost << endl;
	cout << "--------------------------------------------------" << endl;
}

void saveCreatureToFile(int numCreatures, Creatures creaturesArray[]) {
	string userFilename = "";
	
	cout << "What would you like to name the file?" << endl;
	cout << "FILENAME: ";
	cin >> userFilename;
	
	ofstream oFile;
	oFile.open(userFilename.c_str());
	
	for (int i = 0; i < numCreatures; i++) {
		oFile << creaturesArray[i].creatureName << "#";
		oFile << creaturesArray[i].creatureDescription << "#";
		oFile << creaturesArray[i].avgLength << "#";
		oFile << creaturesArray[i].avgHeight << "#";
		oFile << creaturesArray[i].creatureLocation << "#";
		oFile << creaturesArray[i].creatureThreat << "#";
		oFile << creaturesArray[i].creatureCost.careHours << "#";
		oFile << creaturesArray[i].creatureCost.costPerHour << "#";
		oFile << creaturesArray[i].creatureCost.foodCost << "#";
		oFile << creaturesArray[i].creatureCost.materialsCost << "#";
	}
	
	oFile.close();
	
	cout << "Your creatures were succesfully saved to the " << userFilename << " text file." << endl << endl;
}

float convertToFloat(string s) {
	istringstream mystring(s);
	float myFloat;
	if (!(mystring >> myFloat))
		myFloat = 0;
	return myFloat;
}
