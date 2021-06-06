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
	Sedan* a = new Sedan();
	Trailer* b =  new Trailer(10);
	a->AddTrailer(b);
	Sedan* c = new Sedan();
	*c = *a;

	return 0;

	_CrtDumpMemoryLeaks();

}