#include <iostream>

using namespace std;

int choosingFloor, choosingRoom;
const int floors = 3, rooms = 5;

/// <summary>
/// metoda, która zwraca losową liczbę w określonym zakresie
/// </summary>
/// <param name="min">minimalna liczba</param>
/// <param name="max">maksymalna liczba</param>
/// <returns>losowa liczba</returns>
int GetRandomNumber(int min, int max)
{
	// otrzymać losową liczbę
	return min + rand() % (max - min + 1);
}

/// <summary>
/// pobierz piętro i pokój od użytkownika
/// </summary>
void ChooseRoom() {
	printf("prosze podac pietro (0 - %d): ", floors - 1);
	cin >> choosingFloor;

	printf("prosze podac pietro (1 - %d): ", rooms);
	cin >> choosingRoom;
	choosingRoom--;
}

int main()
{
	srand(time(NULL));

	unsigned int hotel[floors][rooms]{};
	int i{}, actualFloor{},
		actualRoom{}, totalGuests{}, choosingOperation;

	// wypełnić hotel gośćmi
	do {
		bool rented = GetRandomNumber(0, 1) == 1 ? true : false;

		rented ? totalGuests += hotel[actualFloor][actualRoom] = GetRandomNumber(1, 2) :
			hotel[actualFloor][actualRoom] = 0;

		// jeśli zakończono wypełnianie bieżącego piętra, przejdź do następnego piętra
		if (actualRoom > floors) {
			actualFloor++;
			actualRoom = 0;
		}
		else
			actualRoom++;
		i++;
	} while (floors * rooms > i);

	// wybrać, co zrobić z hotelem
	printf("goscie w hotelu: %d\n\n1) zameldowac sie \
		\n2) eksmitowac\n3) pokazac wszystkie pokoje hotelowe", totalGuests);
	
	while (true) {
		cout << "\nProsze wybrac opcje: ";
		cin >> choosingOperation;

		switch (choosingOperation) {
			// zameldować się
			case 1: 
				ChooseRoom();
				// zameldować się gościa
				if (hotel[choosingFloor][choosingRoom] == 0)
					hotel[choosingFloor][choosingRoom] = ~hotel[choosingFloor][choosingRoom] >> 31;
				else if (hotel[choosingFloor][choosingRoom] == 1)
					hotel[choosingFloor][choosingRoom] <<= 1;
				break;

			// eksmitowac
			case 2:
				ChooseRoom();
				// eksmitowac gościa
				hotel[choosingFloor][choosingRoom] >>= 1;
				break;

			// pokazać wszystkie pokoje hotelowe
			case 3:
				cout << "\n";
				actualFloor = actualRoom = 0;

				for (int k = 0; k < floors * rooms; k++) {
					cout << hotel[actualFloor][actualRoom] << " ";

					if (actualRoom > floors) {
						actualFloor++;
						actualRoom = 0;
						cout << "\n";
					}
					else
						actualRoom++;
				}
				break;

			default:
				cout << " -- nie ma takiej operacji --\n";
		}
	}
}