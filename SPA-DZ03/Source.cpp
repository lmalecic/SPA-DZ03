#include<iostream>
#include<chrono>
#include<thread>
#include<string>
#include<sstream>
#include "Board.h"

using namespace std;

int main() {
	bool graph[ROWS][COLUMNS] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	
	Board b(graph);
	b.draw();

	int option = 0;
	int row, col;
	stringstream message;

	while (option != 6)
	{
		system("cls");
		b.draw();
		cout << message.str();

		cout << "Odaberite opciju: " << endl;
		cout << "1) Postavi pocetnu tocku (A)" << endl;
		cout << "2) Postavi krajnju tocku (B)" << endl;
		cout << "3) Dodaj prepreku" << endl;
		cout << "4) Makni prepreku" << endl;
		cout << "5) Kreni" << endl;
		cout << "6) Izadji" << endl << endl;

		cin >> option;
		cin.ignore();

		message.str("");
		message.clear();

		system("cls");

		if (option != 6)
		{
			b.draw();
		}

		switch (option) {
		case 1:
			cout << "Unos koordinata pocetne tocke" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				message << "Pogresan unos; redak tocke mora biti broj od 1 do " << ROWS << ", a stupac broj od 1 do " << COLUMNS << "!\n\n";
				break;
			};

			if (!b.isPointValid(row, col)) {
				message << "Pogresan unos; tocka mora biti na slobodnom polju!\n\n";
				break;
			};

			if (make_pair(row, col) == b.getGoal())
			{
				message << "Pogresan unos; pocetna tocka ne moze biti ista kao krajnja!\n\n";
				break;
			}
			
			b.setStart(row, col);

			break;
		case 2:
			cout << "Unos koordinata krajnje tocke" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				message << "Pogresan unos; redak tocke mora biti broj od 1 do " << ROWS << ", a stupac broj od 1 do " << COLUMNS << "!\n\n";
				break;
			};

			if (!b.isPointValid(row, col)) {
				message << "Pogresan unos; tocka mora biti na slobodnom polju!\n\n";
				break;
			};

			if (make_pair(row, col) == b.getStart())
			{
				message << "Pogresan unos; krajnja tocka ne moze biti ista kao pocetna!\n\n";
				break;
			}

			b.setGoal(row, col);

			break;
		case 3:
			cout << "Unos koordinata nove prepreke" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				message << "Pogresan unos; redak prepreke mora biti broj od 1 do " << ROWS << ", a stupac broj od 1 do " << COLUMNS << "!\n\n";
				break;
			};

			if (make_pair(row, col) == b.getStart())
			{
				message << "Pogresan unos; prepreka ne moze biti na polju pocetne tocke!\n\n";
				break;
			}

			if (make_pair(row, col) == b.getGoal())
			{
				message << "Pogresan unos; prepreka ne moze biti na polju krajnje tocke!\n\n";
				break;
			}

			b.setObstacle(row, col);

			break;
		case 4:
			cout << "Unos koordinata prepreke koju zelite maknuti" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				message << "Pogresan unos; redak prepreke mora biti broj od 1 do " << ROWS << ", a stupac broj od 1 do " << COLUMNS << "!\n\n";
				break;
			};

			b.removeObstacle(row, col);

			break;
		case 5:
		{
			aStarSearch search = b.findPath(b.getStart(), b.getGoal());

			bool pathFound = search.run();

			if (!pathFound)
			{
				message << "Put od A do B ne postoji.\n\n";
				break;
			}

			vector<Point> path = search.getPath();
			for (auto it = path.rbegin(); it != path.rend(); ++it)
			{
				system("cls");
				b.draw(search, *it);
				this_thread::sleep_for(chrono::milliseconds(100));
			}
		}
			break;
		case 6:
			return 0;
		default:
			cout << "Molimo odaberite ispravnu opciju s navedenog popisa." << endl;
			break;
		}
	}

	return 0;
}