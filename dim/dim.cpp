#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;

public:
	Person() : name(nullptr), age(0) {}

	Person(const char* n, int a) : age(a) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		age = a;
	}

	Person(const Person& p) : age(p.age) {
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
		age = p.age;
	}

	Person& operator=(const Person& p) {
		if (this != &p) {
			delete[] name;
			name = new char[strlen(p.name) + 1];
			strcpy(name, p.name);
			age = p.age;
		}
		return *this;
	}

	~Person() {
		delete[] name;
	}

	void print() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

class Apartment {
private:
	Person* residents;
	int numResidents;

public:
	Apartment() : residents(nullptr), numResidents(0) {}

	Apartment(Person* p, int n) {
		numResidents = n;
		residents = new Person[numResidents];
		for (int i = 0; i < numResidents; ++i)
			residents[i] = p[i];
	}

	Apartment(const Apartment& other) {
		numResidents = other.numResidents;
		residents = new Person[numResidents];
		for (int i = 0; i < numResidents; ++i)
			residents[i] = other.residents[i];
	}

	Apartment& operator=(const Apartment& other) {
		if (this != &other) {
			delete[] residents;
			numResidents = other.numResidents;
			residents = new Person[numResidents];
			for (int i = 0; i < numResidents; ++i)
				residents[i] = other.residents[i];
		}
		return *this;
	}

	~Apartment() {
		delete[] residents;
	}

	void print() const {
		cout << "Квартира, мешканців: " << numResidents << endl;
		for (int i = 0; i < numResidents; ++i) {
			cout << "  ";
			residents[i].print();
		}
	}
};

class House {
private:
	Apartment* apartments;
	int numApartments;

public:
	House() : apartments(nullptr), numApartments(0) {}

	House(Apartment* a, int n) {
		numApartments = n;
		apartments = new Apartment[numApartments];
		for (int i = 0; i < numApartments; ++i)
			apartments[i] = a[i];
	}

	House(const House& other) {
		numApartments = other.numApartments;
		apartments = new Apartment[numApartments];
		for (int i = 0; i < numApartments; ++i)
			apartments[i] = other.apartments[i];
	}

	House& operator=(const House& other) {
		if (this != &other) {
			delete[] apartments;
			numApartments = other.numApartments;
			apartments = new Apartment[numApartments];
			for (int i = 0; i < numApartments; ++i)
				apartments[i] = other.apartments[i];
		}
		return *this;
	}

	~House() {
		delete[] apartments;
	}

	void print() const {
		cout << "Дім має " << numApartments << " квартир(и):" << endl;
		for (int i = 0; i < numApartments; ++i) {
			cout << "Квартира (кол)" << i + 1 << ":" << endl;
			apartments[i].print();
		}
	}
};


int main() {
	Person p1("Name1", 75);
	Person p2("Name2", 35);
	Person p3("Name3", 35);
	Person p4("Name4", 20);

	Person residents1[] = { p1, p2 };
	Person residents2[] = { p3, p4 };

	Apartment a1(residents1, 2);
	Apartment a2(residents2, 2);
	Apartment apartments[] = { a1, a2 };

	House house(apartments, 2);

	house.print();

}
