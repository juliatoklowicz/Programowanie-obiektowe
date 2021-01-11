#include <iostream>
#include <memory>
#include "Wezel.h"

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        unique_ptr<Wezel>(new Wezel());
    }

    for (int i = 0; i < 10; i++) 
	{
		shared_ptr<Wezel> w1 = make_shared<Wezel>();
	}

	for (int i = 0; i < 10; i++) 
	{
		shared_ptr<Wezel> w1 = make_shared<Wezel>();
		shared_ptr<Wezel> w2 = make_shared<Wezel>();
		w1->next = w2;
		w2->next = w1;
	}

    //6. Tak, typ wskaznikow zostal zmieniony na taki, dzieki ktoremu mozemy przypisywac ich wartosci do innych wskaznikow
    //9. Nie, ponieważ obiekty na ktore nadal sa wskazania nie moga zostac usuniete

    return 0;
}