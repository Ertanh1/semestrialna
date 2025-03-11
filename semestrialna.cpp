#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

const int MAX_TRIPS = 100;

//структура на морските пътувания
struct Trip {
	int tripNumber;
	char route[20];
	char shipName[20];
	char captainName[20];
	double ticketPriceClassI;
	double ticketPriceClassII;
	int passengersClassI;
	int passengersClassII;
	int departureDay;
	int arrivalDay;
	char status[20];
};

// Функция за добавяне на пътувания към масива
void addTrips(Trip trips[], int& tripCount) {
	// Въвеждане на брой пътувания, които да бъдат добавени
	int n;
	cout << "Enter the number of trips to add: ";
	cin >> n;
	// Итерация за добавяне на въведения брой пътувания
	for (int i = 0; i < n; ++i) {
		// Проверка дали не е достигнат максималният брой пътувания
		if (tripCount < MAX_TRIPS) {
			// Създаване на ново пътуване и инициализация на неговите полета
			Trip& newTrip = trips[tripCount];
			newTrip.tripNumber = tripCount + 1;

			// Въвеждане на информация за новото пътуване
			cout << endl;
			cout << "Enter route: ";

			cin >> newTrip.route;

			cout << "Enter ship name: ";
			cin >> newTrip.shipName;

			cout << "Enter captain name: ";
			cin >> newTrip.captainName;

			cout << "Enter ticket price for class I: ";
			cin >> newTrip.ticketPriceClassI;

			cout << "Enter ticket price for class II: ";
			cin >> newTrip.ticketPriceClassII;

			cout << "Enter number of passengers for class I: ";
			cin >> newTrip.passengersClassI;

			cout << "Enter number of passengers for class II: ";
			cin >> newTrip.passengersClassII;

			cout << "Enter departure day: ";
			cin >> newTrip.departureDay;

			cout << "Enter arrival day: ";
			cin >> newTrip.arrivalDay;

			strcpy_s(newTrip.status, sizeof(newTrip.status), "Waiting");
			cin.ignore();
			// Увеличаване на брояча на пътуванията
			tripCount++;
			cout << endl <<"Trip added successfully.\n";
		}
		else {
			cout << "Cannot add more trips. Maximum limit reached.\n";
		}
	}
}

// Функция за извеждане на всички пътувания
void displayTrips(Trip trips[], int tripCount) {
	// Проверка за наличие на пътувания в масива
	if (tripCount == 0) {
		cout << "No trips available.\n";
		return;
	}
	// Извеждане на хедъра на таблицата
	cout << "List of trips:\n";
	cout << left << setw(6) << "Trip" << setw(20) << "Route" << setw(20) << "Ship Name" << setw(20)
		<< "Captain" << setw(9) << "Price I" << setw(13) << "Price II" << setw(10) << "Passengers I"
		<< setw(15) << "Passengers II" << setw(10) << "Status" << setw(10) << "Departure" << setw(10) << "Arrival" << "\n";
	cout << setfill('-') << setw(150) << "" << setfill(' ') << "\n";
	// Допълнително форматиране и извеждане на информация за всяко пътуване
	for (int i = 0; i < tripCount; ++i) {
		cout << left << setw(6) << trips[i].tripNumber << setw(20) << trips[i].route << setw(20)
			<< trips[i].shipName << setw(20) << trips[i].captainName << fixed << setprecision(2)
			<< setw(10) << trips[i].ticketPriceClassI << setw(15) << trips[i].ticketPriceClassII
			<< setw(13) << trips[i].passengersClassI << setw(10) << trips[i].passengersClassII
			<< setw(12) << trips[i].status << setw(10) << trips[i].departureDay << setw(10) << trips[i].arrivalDay << "\n";
	}
}

// Функция за търсене и извеждане на пътувания в определен времеви период
void searchAndDisplayTrips(Trip trips[], int tripCount) {
	// Проверка за наличие на пътувания в масива
	if (tripCount == 0) {
		cout << "No trips available.\n";
		return;
	}
	// Въвеждане на ден за търсене
	int departureDay, arrivalDay;

	cout << "Enter the departure day: ";
	cin >> departureDay;

	cout << "Enter the arrival day: ";
	cin >> arrivalDay;
	cout << endl;
	cout << "Trips in the specified range [" << departureDay << " - " << arrivalDay << "]:" << endl;
	cout << left << setw(6) << "Trip" << setw(20) << "Route" << setw(20) << "Ship Name" << setw(20)
		<< "Captain" << setw(9) << "Price I" << setw(13) << "Price II" << setw(10) << "Passengers I"
		<< setw(15) << "Passengers II" << setw(10) << "Status" << setw(10) << "Departure" << setw(10) << "Arrival" << "\n";
	cout << setfill('-') << setw(150) << "" << setfill(' ') << "\n";
	// Извеждане на пътуванията в зададения времеви период
	for (int i = 0; i < tripCount; ++i) {
		if (trips[i].departureDay >= departureDay && trips[i].arrivalDay <= arrivalDay) {
			cout << left << setw(6) << trips[i].tripNumber << setw(20) << trips[i].route << setw(20)
				<< trips[i].shipName << setw(20) << trips[i].captainName << fixed << setprecision(2)
				<< setw(10) << trips[i].ticketPriceClassI << setw(15) << trips[i].ticketPriceClassII
				<< setw(13) << trips[i].passengersClassI << setw(10) << trips[i].passengersClassII
				<< setw(12) << trips[i].status << setw(10) << trips[i].departureDay << setw(10) << trips[i].arrivalDay << "\n";
		}
	}
}

// Функция за търсене и извеждане на пътувания до конкретна дестинация
void searchAndDisplayTripsToDestination(Trip trips[], int tripCount) {
	// Проверка за наличие на пътувания в масива
	if (tripCount == 0) {
		cout << "No trips available.\n";
		return;
	}
	// Въвеждане на дестинация за търсене
	char destination[20];

	cout << "Enter the destination: ";
	cin >> destination;
	// Извеждане на пътуванията до зададената дестинация
	cout << "Trips to destination '" << destination << "':\n";
	cout << left << setw(6) << "Trip" << setw(20) << "Route" << setw(20) << "Ship Name" << setw(20)
		<< "Captain" << setw(10) << "Price I" << setw(15) << "Price II" << setw(20) << "Status" << "\n";
	cout << setfill('-') << setw(112) << "" << setfill(' ') << "\n";

	for (int i = 0; i < tripCount; ++i) {
		// Проверка и извеждане на пътуванията до зададената дестинация
		if (strcmp(trips[i].route, destination) == 0) {
			cout << left << setw(6) << trips[i].tripNumber << setw(20) << trips[i].route << setw(20)
				<< trips[i].shipName << setw(20) << trips[i].captainName << fixed << setprecision(2)
				<< setw(10) << trips[i].ticketPriceClassI << setw(15) << trips[i].ticketPriceClassII
				<< setw(20) << trips[i].status << "\n";
		}
	}
}

// Функция за сортиране на пътувания по дестинация с Bubble Sort
void sortTripsByDestination(Trip trips[], int tripCount) {
	// Bubble сортиране на пътуванията по дестинация
	for (int i = 0; i < tripCount - 1; ++i) {
		for (int j = 0; j < tripCount - i - 1; ++j) {
			if (strcmp(trips[j].route, trips[j + 1].route) > 0) {
				// Сравнение и размяна на пътуванията, ако е необходимо
				Trip temp = trips[j];
				trips[j] = trips[j + 1];
				trips[j + 1] = temp;

				trips[j].tripNumber = j + 1;
				trips[j + 1].tripNumber = j + 2;
			}
		}
	}
}

// Функция за търсене и извеждане на завършени пътувания до дадена дестинация
void searchAndDisplayCompletedTripsToDestination(Trip trips[], int tripCount) {
	// Проверка за наличие на завършени пътувания в масива
	if (tripCount == 0) {
		cout << "No trips available.\n";
		return;
	}
	// Въвеждане на дестинация за търсене
	char destination[20];

	cout << "Enter the destination: ";
	cin >> destination;

	Trip completedTrips[MAX_TRIPS];
	int completedTripsCount = 0;
	// Извеждане на завършените пътувания до зададената дестинация
	for (int i = 0; i < tripCount; ++i) {
		if (strcmp(trips[i].route, destination) == 0 && strcmp(trips[i].status, "Completed") == 0) {
			completedTrips[completedTripsCount++] = trips[i];
		}
	}

	for (int i = 0; i < completedTripsCount - 1; ++i) {
		for (int j = 0; j < completedTripsCount - i - 1; ++j) {
			if (completedTrips[j].departureDay > completedTrips[j + 1].departureDay) {

				Trip temp = completedTrips[j];
				completedTrips[j] = completedTrips[j + 1];
				completedTrips[j + 1] = temp;
			}
		}
	}

	cout << "Completed trips to destination '" << destination << "', sorted by departure day:\n";
	cout << left << setw(6) << "Trip" << setw(20) << "Route" << setw(20) << "Ship Name" << setw(20)
		<< "Captain" << setw(10) << "Price I" << setw(15) << "Price II" << setw(20) << "Status"
		<< setw(10) << "Departure" << setw(10) << "Arrival" << "\n";
	cout << setfill('-') << setw(140) << "" << setfill(' ') << "\n";

	for (int i = 0; i < completedTripsCount; ++i) {
		cout << left << setw(6) << completedTrips[i].tripNumber << setw(20) << completedTrips[i].route
			<< setw(20) << completedTrips[i].shipName << setw(20) << completedTrips[i].captainName
			<< fixed << setprecision(2) << setw(10) << completedTrips[i].ticketPriceClassI
			<< setw(15) << completedTrips[i].ticketPriceClassII << setw(20) << completedTrips[i].status
			<< setw(10) << completedTrips[i].departureDay << setw(10) << completedTrips[i].arrivalDay << "\n";
	}
}

// Функция за извеждане на пътувания по капитан и в определен времеви период
void displayTripsByCaptainAndDate(Trip trips[], int tripCount) {
	// Проверка за наличие на пътувания в масива
	if (tripCount == 0) {
		cout << "No trips available.\n";
		return;
	}
	// Въвеждане на име на капитан за търсене
	char captain[20];
	int departureDate, arrivalDate;
	// Въвеждане на времеви период за търсене
	cout << endl << "Enter captain name: ";
	cin >> captain;
	cout << endl << "Enter departure day: ";
	cin >> departureDate;
	cout << endl << "Enter arrival day: ";
	cin >> arrivalDate;
	// Извеждане на пътуванията, в които участва зададеният капитан и са в зададения времеви период
	cout << left << setw(6) << "Trip" << setw(20) << "Route" << setw(20) << "Ship Name" << setw(20)
		<< "Captain" << setw(10) << "Price I" << setw(15) << "Price II" << setw(20) << "Status"
		<< setw(10) << "Departure" << setw(10) << "Arrival" << "\n";
	cout << setfill('-') << setw(140) << "" << setfill(' ') << "\n";

	for (int i = 0; i < tripCount; ++i) {
		// Проверка и извеждане на пътуванията по капитан и времеви период
		if (strcmp(trips[i].captainName, captain) == 0 && trips[i].departureDay >= departureDate && trips[i].arrivalDay <= arrivalDate) {
			cout << left << setw(6) << trips[i].tripNumber << setw(20) << trips[i].route << setw(20)
				<< trips[i].shipName << setw(20) << trips[i].captainName << fixed << setprecision(2)
				<< setw(10) << trips[i].ticketPriceClassI << setw(15) << trips[i].ticketPriceClassII
				<< setw(20) << trips[i].status << setw(20) << trips[i].departureDay << setw(30) << trips[i].arrivalDay << "\n";
		}
	}
}

const string fileName = "trips.dat";

// Функция за запазване на пътувания в двоичен файл
void saveInFile(const Trip trips[], int tripCount) {
	if (tripCount == 0) {
		cout << "No trips available.\n";
		return;
	}
	// Отваряне на файл за запис в двоичен режим
	ofstream file(fileName, ios::binary | ios::out);
	// Проверка за наличие на файла
	if (!file) {
		cout << "\n Error in file \n";
		exit(1);
	}
	else {
		// Запис на броя пътувания
		file.write((char*)&tripCount, sizeof(int));


		file.write((char*)trips, sizeof(Trip) * tripCount);
		// Затваряне на файла
		file.close();
		cout << "\n Trips data has been successfully saved.\n";
	}
}

// Функция за четене на пътувания от двоичен файл
void readFromFile(Trip trips[], int& tripCount) {
	// Отваряне на файл за четене в двоичен режим
	ifstream file(fileName, ios::binary | ios::in);
	// Проверка за наличие на файла
	if (!file) {
		cout << "\n This file does not exist. Input information in the file using the menu!\n";
		return;
	}
	else {
		// Четене на информацията за всяко пътуване
		file.read((char*)&tripCount, sizeof(int));

		file.read((char*)trips, sizeof(Trip) * tripCount);
		// Затваряне на файла
		file.close();
		cout << "\n Trips data has been successfully read.\n";
	}
}

// Функция за обновяване на статуса на пътуванията в зависимост от текущия ден
void updateTripStatus(Trip trips[], int tripCount, int currentDay) {
	// Обновяване на статуса за всяко пътуване в масива
	for (int i = 0; i < tripCount; ++i) {
		// Обновяване на статуса в зависимост от текущия ден
		if (trips[i].status[0] == '\0') {
			// If the trip has no status, set it to "Waiting" by default
			strcpy_s(trips[i].status, sizeof(trips[i].status), "Waiting");
		}
		if (trips[i].departureDay == currentDay) {
			// If today is the departure day, set status to "In Progress"
			strcpy_s(trips[i].status, sizeof(trips[i].status), "In Progress");
		}
		else if (trips[i].departureDay < currentDay && currentDay <= trips[i].arrivalDay) {
			// If the trip is ongoing, set status to "In Progress"
			strcpy_s(trips[i].status, sizeof(trips[i].status), "In Progress");
		}
		else if (currentDay > trips[i].arrivalDay) {
			// If the trip has ended, set status to "Completed"
			strcpy_s(trips[i].status, sizeof(trips[i].status), "Completed");
		}
	}
}

// Функция за добавяне или обновяване на пътуване по номер на пътуване
void addOrUpdateTrip(Trip trips[], int& tripCount) {
	// Въвеждане на номер на пътуване за добавяне или обновяване
	int tripNumber;
	cout << "Enter trip number: ";
	cin >> tripNumber;
	// Проверка дали вече съществува пътуване с въведения номер
	int index = -1;
	for (int i = 0; i < tripCount; ++i) {
		if (trips[i].tripNumber == tripNumber) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Trip found
		cout << "Trip found. Updating details...\n";
		// Check if the trip is in Waiting status
		if (strcmp(trips[index].status, "Waiting") == 0) {
			// Обновяване на информацията за вече съществуващо пътуване
			cout << endl;

			cout << "Enter new captain name: ";
			cin >> trips[index].captainName;

			cout << "Enter new ticket price for class I: ";
			cin >> trips[index].ticketPriceClassI;

			cout << "Enter new ticket price for class II: ";
			cin >> trips[index].ticketPriceClassII;

			cout << "Enter new number of passengers for class I: ";
			cin >> trips[index].passengersClassI;

			cout << "Enter new number of passengers for class II: ";
			cin >> trips[index].passengersClassII;

			cout << "Enter new departure day: ";
			cin >> trips[index].departureDay;

			cout << "Enter new arrival day: ";
			cin >> trips[index].arrivalDay;

			while (trips[index].arrivalDay <= trips[index].departureDay)
			{
				cout << "Enter a valid arrival day: ";
				cin >> trips[index].arrivalDay;
			}

			cout << "Trip updated successfully.\n";
		}
		else {
			cout << "Trip status doesn't allow updates.\n";
		}
	}
	else {
		// Trip not found
		cout << "Trip not found.\n";
	}
}

// Функция за подменю с допълнителни функционалности
void submenu(Trip trips[], int tripCount, int currentDay) {

	int choiceSub = 0;
	do
	{
		// Извеждане на опциите в подменюто
		cout << endl;
		cout << "Submenu:\n";
		cout << "1. Display completed trips to destination\n";
		cout << "2. Display trips by captain\n";
		cout << "0. Exit submenu\n";
		cin >> choiceSub;
		cout << endl;
		// Обработка на избора в подменюто
		switch (choiceSub)
		{
		case 0:
			// Назад към основното меню
			cout << "Exiting submenu.\n";
			break;
		case 1:
			// Обновяване на статуса на пътуванията
			updateTripStatus(trips, tripCount, currentDay);
			searchAndDisplayCompletedTripsToDestination(trips, tripCount);
			break;
		case 2:
			// Добавяне или обновяване на информацията за пътуване
			updateTripStatus(trips, tripCount, currentDay);
			displayTripsByCaptainAndDate(trips, tripCount);
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (choiceSub != 0);


}

// Основна функция
int main() {

	Trip trips[MAX_TRIPS];// Масив от пътувания
	int tripCount = 0;// Брой налични пътувания

	int currentDay;// Текущ ден

	// Въвеждане на текущия ден
	cout << "Enter the current day: ";
	cin >> currentDay;

	// Извикване на функцията за обновяване на статуса на пътуванията според текущия ден
	updateTripStatus(trips, tripCount, currentDay);
	// Извикване на функцията за четене на пътувания от файл
	readFromFile(trips, tripCount);

	// Меню за взаимодействие с потребителя
	int choice = 0;
	do {
		cout << endl;
		cout << "Menu:\n";
		cout << "1. Add Trip\n";
		cout << "2. Display all Trips\n";
		cout << "3. Display trips by date\n";
		cout << "4. Display trips by destination\n";
		cout << "5. Sort trips by destination\n";
		cout << "6. Save in file\n";
		cout << "7. Read from file\n";
		cout << "8. Submenu\n";
		cout << "9. Update trips\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		// Обработка на избора в основното меню
		switch (choice) {
		case 0: 
			cout << "Exiting program.\n";
			// Изход от програмата
			saveInFile(trips, tripCount);
			break;
		case 1:
			// Добавяне на нови морски пътувания
			addTrips(trips, tripCount);
			break;

		case 2:
			// Извеждане на всички морски пътувания
			updateTripStatus(trips, tripCount, currentDay);
			displayTrips(trips, tripCount);
			break;

		case 3:
			// Търсене и извеждане на пътувания в определен времеви период
			updateTripStatus(trips, tripCount, currentDay);
			searchAndDisplayTrips(trips, tripCount);
			break;
		case 4:
			// Търсене и извеждане на пътувания в определен времеви период
			updateTripStatus(trips, tripCount, currentDay);
			searchAndDisplayTripsToDestination(trips, tripCount);
			break;
		case 5:
			// Сортиране на пътуванията по дестинация
			sortTripsByDestination(trips, tripCount);
			break;
		case 6:
			// Запазване на информацията във файл
			saveInFile(trips, tripCount);  // Записване във файл
			cout << "Saved...\n" << endl;
			cout << endl;
			break;
		case 7:
			// Четене на информацията от файл
			readFromFile(trips, tripCount);
			cout << "Readed...\n" << endl;
			cout << endl;
			break;
		case 8:
			// Подменю с допълнителни функционалности
			submenu(trips, tripCount, currentDay);
			break;
		case 9:
			// Добавяне или обновяване на информацията за пътуване
			addOrUpdateTrip(trips, tripCount);
			break;
		default:
			// Невалиден избор
			cout << "Invalid choice. Please try again.\n";
		}

	} while (choice != 0);


	return 0;
}
