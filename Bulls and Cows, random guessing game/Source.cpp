/*
	Marcos Garnica
	CS 318
	P02
	gives you a random number you have to guess what it is 
	its like wordle number of bulls is the number that you got right with the correct position
	cows is the right number wrong position
*/



#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>



using namespace std;




vector<int> generateAnswer(int maxDigits) { //generates the random answer for each game
	srand(time(0));
	vector <int> number{ 0,1,2,3,4,5,6,7,8,9 };
	random_shuffle(number.begin(), number.end()); //shuffles through numbers in the vector
	number.resize(maxDigits); //once it shuffles through it cuts down the size to max digits this case 4

	return number;

}
bool isUnique(const vector<int>& v) { //this one check to make sure that the numbers dont repeat

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				return false; //false if the number appears more than once
			}
		}
	}
	return true;
}
bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789") == string::npos; //takes the string, and check if its one of those numbers, 
}

void getValidGuess(int maxDigits, vector<int>& guessVec) { //outputs saying errors if its not in the max number, if it doesnt have only numbers, and if it isnt unique
	string guess;
	for (int i = 0; i < maxDigits; i++) {
		guess.push_back(guessVec.at(i) + '0'); //pushes the numbers from the vector into a string
		//the +'0' is to make the number from the vector into a char so that hasOnlyDigits work
		
	}

	if (guessVec.size() != maxDigits) {
		cout << "      Error: Guess must be " << maxDigits << " digits -- try again!" << endl;
		cout << endl;
		return;
	}
	else if (hasOnlyDigits(guess) == false) {
		cout << "      Error: Guess can only contain digits -- try again!" << endl;
		cout << endl;
		return;
	}
	else if (isUnique(guessVec) == false) {
		cout << "      Error: Digits can not be repeated -- try again!" << endl;
		cout << endl;
		return;
	}


}




void getGuesses(vector<int>& answerVec, int maxDigits) {
	int Bulls = 0; //number correct postion
	int Cows = 0; //correct number wrong position
	vector<int> guessVector;
	string userGuess;
	int numGuesses = 0;


	

	while (Bulls != maxDigits) {
		Bulls = 0;
		Cows = 0;
		userGuess.clear(); //clears the string each time
		cout << "  Enter Guess: ";
		cin >> userGuess;
		guessVector.clear(); //clears the vector before
		for (int i = 0; i < userGuess.size(); i++) {
			int convertNUM;
			convertNUM = userGuess.at(i) - '0'; //makes the char from the string into an int for the vector
			guessVector.push_back(convertNUM);
		}

		getValidGuess(maxDigits, guessVector); //goes to getValidGuesses to output errors if there are any
		

		if ((guessVector.size() == maxDigits) && (isUnique(guessVector) == true) && (hasOnlyDigits(userGuess) == true)) { //makes sure that the output happens only if there are no errors
			numGuesses++;
			for (int i = 0; i < maxDigits; i++) {
				


				if (guessVector.at(i) == answerVec.at(i)) {
					Bulls++;

				}
				else {
					for (int j = 0; j < maxDigits; j++) {
						if (guessVector.at(i) == answerVec.at(j)) {
							Cows++;

						}
					}
				}
			}
			cout << "      Guess #" << numGuesses << ": Bulls " << Bulls << " Cows " << Cows << endl;
			cout << endl;
		}
	}

	cout << "  *** YOU WIN! ***" << endl << endl;

	
}





int main() {
	string guessNum;
	//string userGuess;
	vector <int> answer;
	vector <int> uservec;
	bool allDigits = false;
	char Playagain;
	

	const int MaxDigit = 4;


	

	cout << "*** P02 Bulls and Cows ***" << endl;
	cout << endl;
	do {
		answer = generateAnswer(MaxDigit); //makes the random number, has to be in the do loop in order to make new ones each time its played
		cout << "************* New Game *************" << endl;
		cout << endl;
		cout << "Number to Guess: ";
		for (int i = 0; i < MaxDigit; i++) {

			cout << answer.at(i);

		}




		cout << endl;
		cout << endl;

		cout << "  Guesses entered must be digits 0-9, 4 digits long, no repetition." << endl;
		cout << endl;
		//cout << endl;
		

		getGuesses(answer, MaxDigit);






		cout << "Enter Y to play again (anything else to end): ";
		cin >> Playagain;
		cout << endl;

	} while (Playagain == 'Y' || Playagain == 'y');
}