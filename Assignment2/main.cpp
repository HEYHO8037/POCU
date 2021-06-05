#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(0);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	Boat b(0);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = b + a; // Boat + Airplane인 것에 유의
	bp.GetPassengersCount(); // 6 반환
	bp.GetMaxPassengersCount(); // 10 반환

	a.GetPassengersCount(); // 0 반환
	b.GetPassengersCount(); // 0 반환

	_CrtDumpMemoryLeaks();

}