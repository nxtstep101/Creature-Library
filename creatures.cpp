#include "creatures.h"

using namespace std;

int main() {
	
	const int ARRAY_SIZE = 100;
	int menuInput = 0;
	Creatures creaturesArray[ARRAY_SIZE];
	int numCreatures = 0;
	char saveCreature;
	
	// main menu
	do {
		cout << "What would you like to do?" << endl;
		cout << "\t1. Enter new magical creatures or load from file." << endl;
		cout << "\t2. Print all creatures." << endl;
		cout << "\t3. Print statistics on creature cost." << endl;
		cout << "\t4. End program." << endl;
		cout << "\tEnter 1, 2, 3, or 4." << endl;
		cout << "CHOICE:";
		cin >> menuInput;
		cout << endl;
		
		if (menuInput > 4 || menuInput < 1) {
			cout << "Please enter a number 1-4." << endl << endl;
		}
		
		switch (menuInput) {
			case 1: numCreatures = enterCreatures(numCreatures, creaturesArray);
				break;
			case 2: printCreatures(numCreatures, creaturesArray);
				break;
			case 3: printStatistics(numCreatures, creaturesArray);
				break;
			case 4: cout << "Would you like to save your creatures to a file? (y or n)" << endl;
					while (saveCreature != 'y', 'n') {
						cin >> saveCreature;
						
						if (tolower(saveCreature) == 'y') {
							saveCreatureToFile(numCreatures, creaturesArray);
							cout << "Goodbye!" << endl;
							break;
						}
						
						else {
							cout << endl << "Goodbye!" << endl;
							break;
						}
					}
		}
	} while (menuInput != 4);
	
}
