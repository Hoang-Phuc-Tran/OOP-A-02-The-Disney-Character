#include "DisneyCharacter.h"



int main()
{
	DisneyCharacter mickey("Mickey", "1929-01-01", 100, 'M');

	DisneyCharacter minnie("Minnie", "1930-01-01");

	minnie.SameMovies(mickey);

	mickey.ShowInfor();

	minnie.ShowInfor();

	minnie.PlaceCharacter('E');

	return 0;
}