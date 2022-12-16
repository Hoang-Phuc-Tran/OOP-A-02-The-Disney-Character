#include <time.h>
#include "DisneyCharacter.h"
#pragma warning(disable: 4996)



/*  -- Method Header Comment
	Name	: DisneyCharacter -- CONSTRUCTOR
	Purpose : to instantiate a new DisneyCharacter object - given a set of attribute values
	Inputs	:	newName			String		name 
				newDate 		String		creationDate
				newNumMovies	int			the number of a movie
				newWhichPark	char		the DisneyWorld / DisneyLand parks 
	Outputs	:	NONE
	Returns	:	Nothing
*/
DisneyCharacter::DisneyCharacter(string newName, string newDate, int newNumMovies, char newWhichPark)
{
	// Check if the newName string is larger than 46
	if (newName.length() > MAX_LENGTH)
	{
		name = newName.substr(0, MAX_LENGTH) + "...";
	}
	else
	{
		name = newName;
	}
	
	int year, month, day;

	int n = sscanf(newDate.c_str(), "%d-%d-%d", &year, &month, &day);
	if (n != 3 || year <= 1500 || year >= 2500 || month > 12 || month < 0 || day < 0 || day > 31) 
	{
		creationDate = "";
	}
	else
	{
		creationDate = newDate;
	}

	//
	if (newNumMovies >= 0)
	{
		numMovies = newNumMovies;
	}
	else
	{
		numMovies = 0;
	}
	
	// 
	if (newWhichPark == 'M' || newWhichPark == 'S' || newWhichPark == 'A' || newWhichPark == 'E' ||
		newWhichPark == 'C' || newWhichPark == 'N')
	{
		whichPark = newWhichPark;
	}
	else
	{
		whichPark = 'N';
	}

}

/*  -- Method Header Comment
	Name	: DisneyCharacter -- CONSTRUCTOR
	Purpose : to instantiate a new DisneyCharacter object - given a set of attribute values
	Inputs	:	newName			String		name
				newDate 		String		creationDate
	Outputs	:	NONE
	Returns	:	Nothing
*/
DisneyCharacter::DisneyCharacter(string newName, string newDate)
{
	// Check if the newName string is larger than 46
	if (newName.length() > MAX_LENGTH)
	{
		name = newName.substr(0, MAX_LENGTH) + "...";
	}
	else
	{
		name = newName;
	}

	int year, month, day;

	int n = sscanf(newDate.c_str(), "%d-%d-%d", &year, &month, &day);
	if (n != 3 || year <= 1500 || year >= 2500 || month > 12 || month < 0 || day < 0 || day > 31)
	{
		creationDate = "";
	}
	else
	{
		creationDate = newDate;
	}

	numMovies = 0;

	whichPark = 'N';

}

/*  -- Method Header Comment
	Name	: DisneyCharacter -- DESTRUCTOR
	Purpose : to destroy the DisneyCharacter object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	outputs a final message from the object before being destroyed
	Returns	:	Nothing
*/
DisneyCharacter::~DisneyCharacter()
{
	cout << "\"" << name << " destroyed" << "\"" << endl;
}

/*  -- Method Header Comment
	Name	: GetName
	Purpose : this accessor will return a string name of object.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	a string
*/
string DisneyCharacter::GetName(void)
{
	return name;
}

/*  -- Method Header Comment
	Name	: GeCreationDate
	Purpose : this accessor will return a string the date.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	a string
*/
string DisneyCharacter::GetCreationDate(void)
{
	return creationDate;
}

/*  -- Method Header Comment
	Name	: GetNumMovies
	Purpose : this accessor will return a number of the movie.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	int
*/
int DisneyCharacter::GetNumMovies(void)
{
	return numMovies;
}

/*  -- Method Header Comment
	Name	: GetWhichPark
	Purpose : this accessor will return a single character indicated a park.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	a character
*/
char DisneyCharacter::GetWhichPark(void)
{
	return whichPark;
}

/*  -- Method Header Comment
	Name	: SetNumMovies
	Purpose : this mutator method is used to update/change the number of a movie
	Inputs	:	SetNumMovies	int	 a number of a movie
	Outputs	:	NONE
	Returns	:	retCode		bool	indicates whether the park was changed or not
*/
bool DisneyCharacter::SetNumMovies(int newNumMovies)
{
	bool retCode = false;
	
	if(newNumMovies >= 0)
	{
		numMovies = newNumMovies;

		retCode = true;
	}

	return retCode;
}

/*  -- Method Header Comment
	Name	: SetWhichPark
	Purpose : this mutator method is used to update/change the particular park
	Inputs	:	newWhichPark	char	 a particular park
	Outputs	:	NONE
	Returns	:	retCode		bool	indicates whether the park was changed or not
*/
bool DisneyCharacter::SetWhichPark(char newWhichPark)
{
	bool retCode = false;

	if (newWhichPark == 'M' || newWhichPark == 'S' || newWhichPark == 'A' || newWhichPark == 'E' ||
		newWhichPark == 'C' || newWhichPark == 'N')
	{
		whichPark = newWhichPark;
		retCode = true;
	}
	return retCode;
}

/*  -- Method Header Comment
	Name	: ShowInfor
	Purpose : this method is to be called in order to take a snapshot of the
			  current attribute values
	Inputs	:	NONE
	Outputs	:	attribute values are dumped to the screen
	Returns	:	Void
*/
void DisneyCharacter::ShowInfor(void)
{
	cout << name << " " << creationDate << " " << numMovies << " " << GetStringWhichPark() << endl;
}

/*  -- Method Header Comment
	Name	: PlaceCharacter
	Purpose : this method is used to set place or position the character at a particular park
	Inputs	:	a single character
	Outputs	:	NONE
	Returns	:	retCode		bool	indicates a park was changed or not
*/
bool DisneyCharacter::PlaceCharacter(char whichPark)
{
	bool retCode = false;

	if (whichPark == 'M' || whichPark == 'S' || whichPark == 'A' || whichPark == 'E' ||
		whichPark == 'C' || whichPark == 'N')
	{
		this->whichPark = whichPark;
		retCode = true;
	}
	return retCode;
}

/*  -- Method Header Comment
	Name	: SamMovies
	Purpose : this method is used to et the number of movies that this Disney Character has been 
	in to the same number of movies as the specified character (from the parameter list)
	Inputs	:	the address of an object of DisneyCharacter
	Outputs	:	NONE
	Returns	:	Void
*/
void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter)
{
	this->numMovies = anotherCharacter.GetNumMovies();
}

/*  -- Method Header Comment
	Name	: GetStringWhichPark
	Purpose : this method is used to convert a single charater to a string for input
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	a string indicates the DisneyWorld / DisneyLand parks
*/
string DisneyCharacter::GetStringWhichPark(void)
{
	string park;

	if (whichPark == 'M')
	{
		park = "Magic Kingdom";
	}
	if (whichPark == 'S')
	{
		park = "Disney Studios";
	}
	if (whichPark == 'A')
	{
		park = "Animal Kingdom";
	}
	if (whichPark == 'E')
	{
		park = "Epcot";
	}
	if (whichPark == 'C')
	{
		park = "California Adventure";
	}
	if (whichPark == 'N')
	{
		park = "The character is not placed";
	}

	return park;
}


