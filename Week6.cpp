// Week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



/*
Name: Raymond Bawal III
Date: November 22 , 2025
Section: ITCS 2530 C++
BasicInputAssignment.cpp

A program that does the following:
USER INPUT
Create a friendly introduction banner to welcome the user to your program.
Prompt the user for at least three inputs of mixed types (e.g., string name with spaces, int count, double price/time) related to your assigned hobby or interest (as indicated in List of Student "Hobby or Interest".
Your code should handle invalid input (refer to the concepts in chapter 3).
Compute at least one derived value tied to the hobby (e.g., average lap time, total cost, win/loss ratio).
FORMATTED
Present a pretty summary table using setw and alignment. For any floating-point result, use a sensible precision.
Save the pretty formatted report to a file named report.txt.

SELECTION STATEMENTS
A menu implemented with switch (e.g., 1=Add session, 2=View weekly report, 3=Recommend level).
At least two if/else blocks using compound Boolean conditions (e.g., if (hours >= 5 && budget <= 20) ...).
Note: Since this is the crux of the chapter, the above code should be explained thoroughly in your demonstration video.
REPETITION
Include at least three of the following:
One for loop that runs a fixed number of times.
One while loop that continues based on a condition (e.g., user input or data validation).
One do-while loop that repeats until the user decides to quit.
** Copied from assignment instructions above for reference. **
New:  Console Color
Change the color of the text that is printed in console by your program. You don't have to go crazy with it, just make it look pretty.
Here is an example for WindowsLinks to an external site. programs.
Here is an example for Mac OSLinks to an external site. programs.
Use AI to help you with this.
User-Defined Functions
New - Create an enum that represents something meaningful for your hobby.
Examples:
Difficulty level (Easy, Intermediate, Hard)
Event types (Practice, Competition, FreePlay)
Skill rating (Beginner, Amateur, Pro)
New - Arrays

Use functions to:
Display the banner
Collect and validate input
Perform calculations
Display the menu
Save the report
Change console color
Keep functions simple and focused on one task.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "windows.h"

using namespace std;

void setConsoleColor(HANDLE headerColor, int colorCode); // helper was coded individually in main

enum GameTier { LOW_TIER, GOOD_TIER, SUPER_TIER };
enum DifficultyLevels { EASY, NORMAL, HARD };
//Struct to hold user info
struct UserInfo {
    string videoGame;
    string favoriteCharacter;
    string gamingPlatform;
    int age;
};

void titleBanner(HANDLE headerColor, const string& programName);
void userInfo(HANDLE headerColor, UserInfo& user,
    const int& minAge, const int& maxAge, const int& childAge, int& ageDifference);
void theCreatorsNastalgia(HANDLE headerColor, const int& childAge, string& videoGame, string& favoriteCharacter);
void valueOfGame(HANDLE headerColor, int& hoursPlayed, double& gamePrice, double& gameValue,
    string& videoGame, const double& minGamePrice, const int& minHoursPlayed);

void gameWorth(HANDLE headerColor, double gamePrice, double gameValue, int hoursPlayed, int maxHours,
    int midHours, double superValue, double midPrice, int maxPrice, string& valueTier,
    const string& videoGame, GameTier& tier);

void ratings_Recomendation(HANDLE headerColor, int hoursPlayed, int maxHours, double gameValue, double lowValue, double gamePrice,
    double goodValue, double superValue, double justBelowMax, string& recommendation,
    const string& videoGame, int& story, int& gameplay, int& graphics, int& nastalgia,
    int& replay, int& ratingSum, double& avgRating, GameTier& tier);

void difficultyDescription(HANDLE headerColor, DifficultyLevels& difficulty);

/*void summary_Report(HANDLE headerColor, const string& videoGame, const string& favoriteCharacter,
    const string& gamingPlatform, int age, double gamePrice, int hoursPlayed, double gameValue,
    double avgRating, const string& recommendation, const string& valueTier, DifficultyLevels difficulty);*/
void summary_Report(HANDLE headerColor, const UserInfo& user,
    double gamePrice, int hoursPlayed, double gameValue,
    double avgRating, const string& recommendation,
    const string& valueTier, DifficultyLevels difficulty);

bool endingMenu(HANDLE headerColor, int& menuChoice, const string& videoGame, double gamePrice, double gameValue,
    const string& favoriteCharacter, int age, const string& gamingPlatform, int hoursPlayed,
    double avgRating, const string& recommendation, const string& valueTier, DifficultyLevels difficulty);


// main
int main() {
    bool runAgain = true;

    do {
        HANDLE headerColor = GetStdHandle(STD_OUTPUT_HANDLE);
        // Variables
        string videoGame;
        string gamingPlatform;
        string favoriteCharacter;
        int age;
        const string programName = "Fun with Video Games and the First Steps of My Journey in UX Design";
        const int childAge = 7;
        int ageDifference;
        double gamePrice;
        int hoursPlayed;
        double gameValue;
        const int minAge = 0;
        const int maxAge = 110;

        const double minGamePrice = 0.0;
        const int minHoursPlayed = 0;
        const double superValue = 1.00;
        const int maxPrice = 70;
        const double midPrice = 2.00;
        const int maxHours = 40;
        const int midHours = 20;
        const double lowValue = 1.00;
        const double goodValue = 50.00;
        const double justBelowMax = 60.00;

        int story, gameplay, graphics, nastalgia, replay;
        string recommendation;
        string valueTier;
        int ratingSum = 0;
        double avgRating = 0.0;
       
        int menuChoice;

        GameTier tier;                 // enum variable for value tier
        DifficultyLevels difficulty;   // enum variable for difficulty

        // Program Execution through functions

        titleBanner(headerColor, programName);
		
		//OLD BELOW functions call no longer needed withn struct
        //userInfo(headerColor, videoGame, favoriteCharacter, gamingPlatform,
            //age, minAge, maxAge, childAge, ageDifference);
		UserInfo user; // create UserInfo struct instance
		

	

		userInfo(headerColor, user, minAge, maxAge, childAge, ageDifference);
        //Sync struct fileds in old varibles
        videoGame = user.videoGame;
        favoriteCharacter = user.favoriteCharacter;
        gamingPlatform = user.gamingPlatform;
        age = user.age;


        theCreatorsNastalgia(headerColor, childAge, videoGame, favoriteCharacter);

        valueOfGame(headerColor, hoursPlayed, gamePrice, gameValue, videoGame,
            minGamePrice, minHoursPlayed);

        gameWorth(headerColor, gamePrice, gameValue, hoursPlayed, maxHours, midHours,
            superValue, midPrice, maxPrice, valueTier, videoGame, tier);

        ratings_Recomendation(headerColor, hoursPlayed, maxHours, gameValue, lowValue, gamePrice, goodValue,
            superValue, justBelowMax, recommendation, videoGame,
            story, gameplay, graphics, nastalgia, replay,
            ratingSum, avgRating, tier);

        // NEW: ask for difficulty and store in difficulty enum
        difficultyDescription(headerColor, difficulty);
        // added for the struct
        summary_Report(headerColor, user,gamePrice, hoursPlayed, gameValue, avgRating,
            recommendation, valueTier, difficulty);
		// ran into errors here so I had to pass user.age instead of age due to added structs.
        runAgain = endingMenu(headerColor, menuChoice, videoGame, gamePrice, gameValue,
            favoriteCharacter, user.age, gamingPlatform, hoursPlayed,
            avgRating, recommendation, valueTier, difficulty);

    } while (runAgain);

    cout << "Thanks for trying my program sincerely Raymond. Goodbye\n";
    return 0;
}



//added funtions below
void setConsoleColor(HANDLE headerColor, int colorCode) // helper was coded individually in main
{
    SetConsoleTextAttribute(headerColor, colorCode);
}

void titleBanner(HANDLE headerColor, const string& programName) {
    setConsoleColor(headerColor, 11);// changed to setConsoleColor helper function
    cout << string(90, '*') << endl;
    cout << "*" << setw(89) << "*" << endl;
    cout << "*" << setw(89) << "*" << endl;
    cout << "*" << setw(89) << "*" << endl;
    cout << "*" << string(9, ' ') << setw(10) << programName << setw(13) << "*" << endl;
    cout << "*" << setw(89) << "*" << endl;
    cout << "*" << setw(89) << "*" << endl;
    cout << "*" << setw(89) << "*" << endl;
    cout << string(90, '*') << endl;

    system("pause");
    system("cls");
}
/* modified userInfo function to use UserInfo struct
void userInfo(HANDLE headerColor, string& videoGame, string& favoriteCharacter, string& gamingPlatform,
    int& age, const int& minAge, const int& maxAge, const int& childAge, int& ageDifference)*/
void userInfo(HANDLE headerColor, UserInfo& user,
    const int& minAge, const int& maxAge, const int& childAge, int& ageDifference) {
    setConsoleColor(headerColor, 11);// changed to setConsoleColor helper function
	// added . operator to access struct members
    cout << "\nEnter the name of your favorite video game.\n";
    getline(cin, user.videoGame);

    cout << "\nEnter the name of your favorite character.\n";
    getline(cin, user.favoriteCharacter);

    cout << "\nEnter the gaming platform you used to play your favorite game on.\n";
    getline(cin, user.gamingPlatform);

    cout << "\nEnter your age in years in a whole number.\n";
    while (!(cin >> user.age) || user.age <= minAge || user.age >= maxAge) {
        cout << "Age must be a positive whole number between 1 and 109. Please try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "\nThank you for providing your age as " << user.age << " years old.\n" << endl;
    cout << "\nYou were " << user.age << " Years old and loved to play the game " << user.videoGame
        << " on the game system. " << user.gamingPlatform << endl;

    ageDifference = user.age - childAge;
    cout << "\nYour favorite character from that game is " << user.favoriteCharacter << endl;

    if (ageDifference >= 0) {
        cout << "You are " << ageDifference
            << " years older than I was when I started playing my favorite game! \n" << endl;
    }
    else {
        cout << "\nYou were younger than I was when I started playing my favorite game! \n" << endl;
    }

    system("pause");
    system("cls");
}

void theCreatorsNastalgia(HANDLE headerColor, const int& childAge, string& videoGame, string& favoriteCharacter) {
    setConsoleColor(headerColor, 4);
    cout << "My name is Raymond and my favorite game of all time is Pokemon Red, more for the nostalgia factor.\n"
        << "My favorite character was Charizard, but I loved Gyarados as well.\n"
        << "I used to play it on my Gameboy Color when I was the age of " << childAge << " years old!\n"
        << "I remember one of the first times using dial-up internet to find this cheat!\n"
        << "There was the rare candy cheat where you could level up your Pokemon instantly!\n"
        << "To get the rare candies you would have to encounter the glitch Pokemon Missingno.\n"
        << "Which would appear on the right side of the screen when you surfed along the shore of Cinnabar Island.\n"
        << "It would duplicate the item in the 6th slot of your inventory!\n"
        << "What fun times it was!\n" << endl;
    cout << "Thank you for sharing your favorite game " << videoGame
        << " and character " << favoriteCharacter << " with me!\n" << endl;
    cout << "Now time to analyze your game data!\n" << endl;
    for (int i = 3; i > 0; --i) {
        cout << "Starting analysis in " << i << "...\n";
    }
    system("pause");
    system("cls");
}

void valueOfGame(HANDLE headerColor, int& hoursPlayed, double& gamePrice, double& gameValue,
    string& videoGame, const double& minGamePrice, const int& minHoursPlayed) {
    setConsoleColor(headerColor, 11);
    cout << "Now lets see if that game was worth buying!\n" << endl;

    cout << "Enter the price you paid for the game in dollars and cents (example 59.99).\n";
    while (!(cin >> gamePrice) || gamePrice < minGamePrice) {
        cout << "Invalid input for price. Please enter a number like 59.99 or 20.00: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter the number of hours you think you played the game in a whole integer.\n";
    while (!(cin >> hoursPlayed) || hoursPlayed <= minHoursPlayed) {
        cout << "Invalid input for hours played. Please enter a whole number greater than 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << fixed << setprecision(2);
    cout << "\nYou paid $" << gamePrice << " for " << videoGame
        << " and have played it for " << hoursPlayed << " hours.\n";

    gameValue = gamePrice / hoursPlayed;
    cout << "\nThat means you have paid $" << gameValue << " per hour of gameplay!\n"
        << "\nWhen you think about it that is not a bad value for a game!\n" << endl;
    setConsoleColor(headerColor, 4);
    cout << "\nI sure think that Pokemon Red was worth every penny and hour I put into it back in the day!\n" << endl;
    cout << "UX design is all about user experience and making things enjoyable and fun for the user!\n"
        << "Just like how video games are designed to be fun and engaging for the player!\n"
        << "I would consider the title box of this program to be a miniscule example of UX design!\n"
        << "Lets go deeper into UX design and data to see a summary of some of the cool stuff we learned about each other's gaming preferences!\n" << endl;

    system("pause");
    system("cls");
}

void gameWorth(HANDLE headerColor, double gamePrice, double gameValue, int hoursPlayed, int maxHours,
    int midHours, double superValue, double midPrice, int maxPrice, string& valueTier,
    const string& videoGame, GameTier& tier) {
    SetConsoleTextAttribute(headerColor, 11);
    cout << "Now lets see if that game was worth buying!\n" << endl;
    cout << string(90, '*') << endl;
    cout << "*" << setw(50) << "Game Tier Evaluation" << setw(39) << "*" << endl;
    cout << string(90, '*') << endl;

    if (hoursPlayed >= maxHours && gameValue <= superValue && gamePrice <= maxPrice) {
        tier = SUPER_TIER;// set enum variable
        valueTier = "Super Tier";
        cout << "After analyzing your game data, " << videoGame
            << " was a Super Tier game and a phenomenal value!\n";
    }
    else if (hoursPlayed >= midHours && gameValue <= midPrice && gamePrice <= maxPrice) {
        tier = GOOD_TIER;// set enum variable
        valueTier = "Good Tier";
        cout << "After analyzing your game data, " << videoGame
            << " was not the best value but money does not judge everything.\n";
    }
    else {
        tier = LOW_TIER;// set enum variable
        valueTier = "Low Tier";
        cout << "After analyzing your game data, " << videoGame
            << " is not a great value, but if it is your favorite game that’s what matters.\n";
    }

    system("pause");
    system("cls");
}

void ratings_Recomendation(HANDLE headerColor, int hoursPlayed, int maxHours, double gameValue, double lowValue, double gamePrice,
    double goodValue, double superValue, double justBelowMax, string& recommendation,
    const string& videoGame, int& story, int& gameplay, int& graphics, int& nastalgia,
    int& replay, int& ratingSum, double& avgRating, GameTier& tier) {

    SetConsoleTextAttribute(headerColor, 11);

    if ((hoursPlayed >= maxHours && gameValue <= lowValue) || (gamePrice <= goodValue && hoursPlayed >= 25)) {
        recommendation = "I would highly recommend this game to a friend!";
    }
    else if ((hoursPlayed >= 15 && gameValue <= superValue) || (gamePrice <= justBelowMax && hoursPlayed >= 10)) {
        recommendation = "I would recommend this game to a friend.";
    }
    else {
        recommendation = "I would not recommend this game to a friend.";
    }

    switch (tier) {
    case SUPER_TIER:
        cout << "Tier advice: This game is top-tier value. Definitely keep playing!\n";
        break;
    case GOOD_TIER:
        cout << "Tier advice: Good value overall. Worth your time.\n";
        break;
    case LOW_TIER:
        cout << "Tier advice: Not great value, but favorites aren’t always logical.\n";
        break;
    }

    cout << "\nYour favorite game " << videoGame
        << " was it the value you thought? $" << gameValue << " per Hour" << endl;

    cout << "I have asked many questions but UX design is all about understanding the user!\n";
    cout << "Lets rate your game's overall experience from 1 to 5!\n";

    const int numberOfRatings = 5;
    string ratingNames[numberOfRatings] = { "Story", "Gameplay", "Graphics", "Nostalgia", "Replayability" };
    int ratingValues[numberOfRatings];

    for (int i = 0; i < numberOfRatings; ++i) {
        cout << ratingNames[i] << " rating 1 - 5\n";
        while (!(cin >> ratingValues[i]) || ratingValues[i] < 1 || ratingValues[i] > 5) {
            cout << "Invalid input must be between 1 and 5. Please try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    story = ratingValues[0];
    gameplay = ratingValues[1];
    graphics = ratingValues[2];
    nastalgia = ratingValues[3];
    replay = ratingValues[4];

    ratingSum = 0;
    for (int i = 0; i < numberOfRatings; ++i) {
        ratingSum += ratingValues[i];
    }
    avgRating = static_cast<double>(ratingSum) / numberOfRatings;

    cout << fixed << setprecision(2);
    cout << "\nYour average rating for " << videoGame << " is: " << avgRating << " out of 5.\n\n";
}

// NEW : function to get difficulty description
void difficultyDescription(HANDLE headerColor, DifficultyLevels& difficulty)
{
    setConsoleColor(headerColor, 4);

    cout << "Now that we rated the game, I hope you had fun doing it!\n";
    cout << "I want to know how difficult you found the game to be!\n\n";

    int choice;
    cout << "If you found it easy type 0, normal type 1, hard type 2: ";
    cin >> choice;

    switch (choice) {
    case 0:
        difficulty = EASY;
        cout << "You found the game easy! That's great for a relaxing experience.\n";
        break;
    case 1:
        difficulty = NORMAL;
        cout << "You found the game normal! A balanced challenge is always fun.\n";
        break;
    case 2:
        difficulty = HARD;
        cout << "You found the game hard! Tough games can be very rewarding.\n";
        break;
    default:
        difficulty = EASY; // default choice
        cout << "Invalid choice. We'll record it as EASY by default.\n";
        break;
    }

    system("pause");
    system("cls");
}
// added UserInfo struct to parameters
/*void summary_Report(HANDLE headerColor, const string& videoGame, const string& favoriteCharacter,
    const string& gamingPlatform, int age, double gamePrice, int hoursPlayed, double gameValue,
    double avgRating, const string& recommendation, const string& valueTier, DifficultyLevels difficulty)*/
void summary_Report(HANDLE headerColor, const UserInfo& user,
    double gamePrice, int hoursPlayed, double gameValue,
    double avgRating, const string& recommendation,
    const string& valueTier, DifficultyLevels difficulty) {

    setConsoleColor(headerColor, 11);

    // Convert difficulty enum to text
    string diffText;
    switch (difficulty) {
    case EASY:   diffText = "Easy";   break;
    case NORMAL: diffText = "Normal"; break;
    case HARD:   diffText = "Hard";   break;
    }

    cout << string(90, '*') << endl;
    cout << "*" << setw(50) << "Summary of Your Gaming Preferences" << setw(39) << "*" << endl;
    cout << string(90, '*') << endl;

    cout << left << setw(30) << "Data Collected " << setw(40) << "Your Input" << endl;
    cout << string(90, '-') << endl;
	//updated to use struct members up to Your Age
    cout << left << setw(30) << "Favorite Game: " << setw(40) << user.videoGame << endl;
    cout << left << setw(30) << "Favorite Character: " << setw(40) << user.favoriteCharacter << endl;
    cout << left << setw(30) << "Gaming Platform: " << setw(40) << user.gamingPlatform << endl;
    cout << left << setw(30) << "Your Age: " << setw(40) << user.age << endl;
    cout << left << setw(30) << "Game Price: " << "$" << setw(39) << gamePrice << endl;
    cout << left << setw(30) << "Hours Played: " << setw(40) << hoursPlayed << endl;
    cout << left << setw(30) << "Value per Hour Played: " << "$" << setw(39) << gameValue << endl;
    cout << left << setw(30) << "Average Rating (1-5): " << setw(40) << avgRating << endl;
    cout << left << setw(30) << "Recommendation: " << setw(40) << recommendation << endl;
    cout << left << setw(30) << "Value Tier: " << setw(40) << valueTier << endl;
    cout << left << setw(30) << "Difficulty: " << setw(40) << diffText << endl;
    cout << string(90, '-') << endl;

    /*ofstream report("report.txt");
    if (report) {
        report << left << setw(30) << "Favorite Game: " << setw(40) << videoGame << endl;
        report << left << setw(30) << "Favorite Character: " << setw(40) << favoriteCharacter << endl;
        report << left << setw(30) << "Gaming Platform: " << setw(40) << gamingPlatform << endl;
        report << left << setw(30) << "Your Age: " << setw(40) << age << endl;
        report << left << setw(30) << "Game Price: " << "$" << setw(39) << gamePrice << endl;
        report << left << setw(30) << "Hours Played: " << setw(40) << hoursPlayed << endl;
        report << left << setw(30) << "Value per Hour Played: " << "$" << setw(39) << gameValue << endl;
        report << left << setw(30) << "Average Rating (1-5): " << setw(40) << avgRating << endl;
        report << left << setw(30) << "Recommendation: " << setw(40) << recommendation << endl;
        report << left << setw(30) << "Value Tier: " << setw(40) << valueTier << endl;
        report << left << setw(30) << "Difficulty: " << setw(40) << diffText << endl;
        report << string(90, '-') << endl;
        report.close();
        cout << "A summary report has been saved to report.txt\n" << endl;
    }*/
	// Swapped to use struct members
    ofstream report("report.txt");
    if (report) {
        report << left << setw(30) << "Favorite Game: " << setw(40) << user.videoGame << endl;
        report << left << setw(30) << "Favorite Character: " << setw(40) << user.favoriteCharacter << endl;
        report << left << setw(30) << "Gaming Platform: " << setw(40) << user.gamingPlatform << endl;
        report << left << setw(30) << "Your Age: " << setw(40) << user.age << endl;
        report << left << setw(30) << "Game Price: " << "$" << setw(39) << gamePrice << endl;
        report << left << setw(30) << "Hours Played: " << setw(40) << hoursPlayed << endl;
        report << left << setw(30) << "Value per Hour Played: " << "$" << setw(39) << gameValue << endl;
        report << left << setw(30) << "Average Rating (1-5): " << setw(40) << avgRating << endl;
        report << left << setw(30) << "Recommendation: " << setw(40) << recommendation << endl;
        report << left << setw(30) << "Value Tier: " << setw(40) << valueTier << endl;
        report << left << setw(30) << "Difficulty: " << setw(40) << diffText << endl;
        report << string(90, '-') << endl;
        report.close();
        cout << "A summary report has been saved to report.txt\n" << endl;
    }
    else {
        cout << "Could not open report.txt for writing.\n";
    }

    system("pause");
    system("cls");
}

bool endingMenu(HANDLE headerColor, int& menuChoice, const string& videoGame, double gamePrice, double gameValue,
    const string& favoriteCharacter, int age, const string& gamingPlatform, int hoursPlayed,
    double avgRating, const string& recommendation, const string& valueTier, DifficultyLevels difficulty) {

    setConsoleColor(headerColor, 11);
    cout << string(52, '*') << endl;
    cout << "*" << setw(50) << "Selection Menu" << "*" << endl;
    cout << string(52, '*') << endl;

    cout << "1.) See Value Assumption again\n";
    cout << "2.) See Summary Table Again \n";
    cout << "3.) Exit Program \n";
    cout << "Please enter option (1-3): ";

    while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 3) {
        cout << "Invalid input must be 1-3. Please try again: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    enum MenuOptions { ValueAssumptions = 1, SummaryTable = 2, ExitProgram = 3 };

    // Convert difficulty enum to text for the re-summary
    string diffText;
    switch (difficulty) {
    case EASY:   diffText = "Easy";   break;
    case NORMAL: diffText = "Normal"; break;
    case HARD:   diffText = "Hard";   break;
    }

    switch (menuChoice) {
    case ValueAssumptions:
        cout << "\nValue Assumption: price $" << gamePrice
            << "   value estimate is $" << gameValue << " per hour!\n";
        cout << "I hope you were still happy with the value of the game \n" << videoGame << "\n\n";
        break;

    case SummaryTable:
        cout << "\n--- Summary Again! ---\n";
        cout << left << setw(30) << "Favorite Game: " << setw(40) << videoGame << endl;
        cout << left << setw(30) << "Favorite Character: " << setw(40) << favoriteCharacter << endl;
        cout << left << setw(30) << "Gaming Platform: " << setw(40) << gamingPlatform << endl;
        cout << left << setw(30) << "Your Age: " << setw(40) << age << endl;
        cout << left << setw(30) << "Game Price: " << "$" << setw(39) << gamePrice << endl;
        cout << left << setw(30) << "Hours Played: " << setw(40) << hoursPlayed << endl;
        cout << left << setw(30) << "Value per Hour Played: " << "$" << setw(39) << gameValue << endl;
        cout << left << setw(30) << "Average Rating (1-5): " << setw(40) << avgRating << endl;
        cout << left << setw(30) << "Recommendation: " << setw(40) << recommendation << endl;
        cout << left << setw(30) << "Value Tier: " << setw(40) << valueTier << endl;
        cout << left << setw(30) << "Difficulty: " << setw(40) << diffText << endl;
        cout << string(90, '-') << endl << endl;
        break;

    case ExitProgram:
        cout << "\nThanks for trying my program. ";
        break;
    }

    char userChoice;
    cout << endl;
    cout << "Do you want to run the program again y/n: ";
    cin >> userChoice;
    userChoice = static_cast<char>(tolower(static_cast<unsigned char>(userChoice)));
    // Clear the leftover newline after the y/n input
    cin.ignore(10000, '\n');  
    cout << endl;

    return (userChoice == 'y');
}