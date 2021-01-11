#ifndef FABRYKAPRACOWNIKOW_H
#define FABRYKAPRACOWNIKOW_H
#include "FabrykaOsob.h"
#include "Pracownik.h"

class FabrykaPracownikow : public FabrykaOsob
{
	Pracownik* utworz();
};

#endif