#include <iostream>

using namespace std;

/// <summary>
/// metoda, która zwraca losową liczbę w określonym zakresie
/// </summary>
/// <param name="min">minimalna liczba</param>
/// <param name="max">maksymalna liczba</param>
/// <returns>losowa liczba</returns>
int GetRandomNumber(int min, int max)
{
	// otrzymać losową liczbę
	int num = min + rand() % (max - min + 1);

	return num;
}

int main()
{
	srand(time(NULL));

	const int floors = 3, rooms = 5;
	int hotel[floors][rooms]{}, i{}, actualFloor{}, actualRoom{},
		totalGuests{}, choosingOperation, choosingFloor, choosingRoom;

	do {
		bool rented;

		GetRandomNumber(0, 1) == 1 ? rented = false : rented = true;

		rented ? hotel[actualFloor][actualRoom] = GetRandomNumber(1, 2) : 
			hotel[actualFloor][actualRoom] = 0;
		totalGuests += hotel[actualFloor][actualRoom];

		if (actualRoom >= 4) {
			actualFloor++;
			actualRoom = 0;
		}
		else
			actualRoom++;
		i++;
	} while (floors * rooms > i);

	printf("goscie w hotelu: %d\n\n Prosze wybrac opcje: 1) zameldować sie \
		\n 2) eksmitowac\n 3) pokazac wszystkie pokoje hotelowe\n", totalGuests);
	
	while (true) {
		cin >> choosingOperation;

		switch (choosingOperation) {
			case 1: 
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				cout << "nie ma takiej operacji";
		}
	}

	cin >> choosingFloor;

	if (choosingFloor < floors && choosingFloor > floors) {

	}
}