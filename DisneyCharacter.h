#include<iostream>
#include<string>
using namespace std;


#define MAX_LENGTH 46


class DisneyCharacter 
{
private:

	string name;
	string creationDate;
	int numMovies;
	char whichPark;

public:
	
	// Constructors
	DisneyCharacter(string newName, string newDate, int newNumMovies, char newWhichPark);
	DisneyCharacter(string newName, string newDate);

	// Destructors
	~DisneyCharacter();

	// Accessors
	string GetName(void);
	string GetCreationDate(void);
	int GetNumMovies(void);
	char GetWhichPark(void);

	// Mutators
	bool SetNumMovies(int newNumMovies);
	bool SetWhichPark(char newWhichPark);

	// Print out the current value of all of the data members for the object
	void ShowInfor(void);

	// Place or position the character at a particular park
	bool PlaceCharacter(char whichPark);

	// set the number of movies
	void SameMovies(DisneyCharacter& anotherCharacter);

	// method used to transform a single character "whichPark" into a string for output
	string GetStringWhichPark(void);
};
