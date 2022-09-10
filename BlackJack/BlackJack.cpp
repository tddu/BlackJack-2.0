#include <iostream>
#include <string>
#include <iomanip>
#pragma once
using namespace std;
void printMenu () {
	cout << "1. Get another card" << endl;
	cout << "2. Hold hand" << endl;
	cout << "3. Print statistics" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
	cout << "Choose an option: ";
	cout << endl;
}
// This function constantly checks to see if the player goes over 21
int checkWin(int userHand) {
	int winState = 3;
	if (userHand == 21) {
		winState = 1;
	}
	else if (userHand > 21) {
		winState = 2;
	}
	return winState;
}
// This function checks if the player wins when they stand.
int checkStand(int userHand, int dealerHand) {
	int winState = 1;

	if (dealerHand > 21) {
		winState = 1;
	}
	else if (dealerHand == userHand) {
		winState = 2;
	}
	else if (userHand > dealerHand) {
		winState = 3;
	}
	else if (dealerHand > userHand) {
		winState = 4;
	}
	return winState;
}
//Print menu function
int main()
{
 int userInput = 1;
 int userHand = 0;
 int cardPulled = 0;
 int userWins = 0;
 int dealerWins = 0;
 int userTies = 0;
 int totalGames = 0;
 double winPercent = 0.0;
 bool playing = true;
 int gameCounter = 0;
 while (userInput != 4) {
	 gameCounter += 1;
	 cout << "START GAME #" << gameCounter << endl;
	 cout << endl;
	 userHand = 0;
	 userInput = 1;
	 playing = true;
	 while (playing == true) {
		 if (checkWin(userHand) == 1) {
			 cout << "BLACKJACK! You win!" << endl;
			 userWins += 1;
			 playing = false;
		 }
		 else if (checkWin(userHand) == 2) {
			 cout << "You exceeded 21! You lose." << endl;
			 dealerWins += 1;
			 playing = false;
		 }
		 if (userInput == 1) {
			 cardPulled = rand() % 13 + 1;
			 userHand += cardPulled;
			 if (cardPulled == 1) {
				 cout << "Your card is an ACE!" << endl;
				 cout << "Your hand is: " << userHand << endl;
				 cout << endl;
			 }
			 else if (cardPulled == 11) {
				 userHand -= 1;
				 cout << "Your card is a JACK!" << endl;
				 cout << "Your hand is: " << userHand << endl;
				 cout << endl;
			 }
			 else if (cardPulled == 12) {
				 userHand -= 2;
				 cout << "Your card is a QUEEN!" << endl;
				 cout << "Your hand is: " << userHand << endl;
				 cout << endl;
			 }
			 else if (cardPulled == 13) {
				 cout << "Your card is a KING!" << endl;
				 cout << "Your hand is: " << userHand << endl;
				 cout << endl;
				 userHand -= 3;
			 }
			 else {
				 cout << "Your card is a " << cardPulled << "!" << endl;
				 cout << "Your hand is: " << userHand << endl;
				 cout << endl;
			 }
		 }
		 else if (userInput == 2) {
			 int dealerHand = rand() % 11 + 16;
			 cout << "Dealer's hand: " << dealerHand << endl;
			 cout << "Your hand is: " << userHand << endl;
			 cout << endl;
			 if (checkStand(userHand,dealerHand) == 1) {
				 cout << "Dealer Bust! You win!";
				 cout << endl;
				 userWins += 1;
			 }
			 else if (checkStand(userHand,dealerHand) == 2) {
				 cout << "It's a tie! No one wins!" << endl;
				 cout << endl;
				 userTies += 1;
			 }
			 else if (checkStand(userHand,dealerHand) == 3) {
				 cout << "You win!" << endl;
				 cout << endl;
				 userWins += 1;
			 }
			 else if (checkStand(userHand,dealerHand) == 4) {
				 cout << "Dealer wins!" << endl;
				 cout << endl;
				 dealerWins += 1;
			 }
			 playing = false;
		 }
		 else if (userInput == 3) {
			 if (totalGames == 0) {
				 cout << "Number of Player wins: " << userWins << endl;
				 cout << "Number of Dealer wins: " << dealerWins << endl;
				 cout << "Number of tie games: " << userTies << endl;
				 cout << "Total # of games played is: " << totalGames << endl;
				 cout << "Percentage of Player wins: 0.0%" << endl;
				 cout << endl;
			 }
			 else {
				 winPercent = ((userWins * 1.0) / (totalGames * 1.0) * 100);
				 cout << "Number of Player wins: " << userWins << endl;
				 cout << "Number of Dealer wins: " << dealerWins << endl;
				 cout << "Number of tie games: " << userTies << endl;
				 cout << "Total # of games played is: " << totalGames << endl;
				 cout << "Percentage of Player wins: " << setprecision(1) << winPercent << "%" << endl;
				 cout << endl;
			 } 
		 }
		 else if (userInput == 4) {
			 playing = false;
		 }
		 else {
			 cout << "Invalid input!" << endl;
			 cout << "Please enter an interger value between 1 and 4." << endl;
			 cout << endl;
		 }
		 if (checkWin(userHand) == 1) {
			 cout << "BLACKJACK! You win!" << endl;
			 userWins += 1;
			 playing = false;
		 }
		 else if (checkWin(userHand) == 2) {
			 cout << "You exceeded 21! You lose." << endl;
			 dealerWins += 1;
			 playing = false;
		 }
		 if (playing == true) {
			 printMenu();
			 cin >> userInput;
		 }
		 else {
			 totalGames += 1;
		 }
	 }
 }
}