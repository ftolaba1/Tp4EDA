#include "curses.h"
#include <iostream>
//#include "ServerFsm.h"
#include "Front.h"


using namespace std;

char selectSimulationMode(void);


int main(void)
{
	WINDOW * winTest = NULL;                     //Variable en dónde se guarda la terminal (Window) en donde voy a trabajar.

	char option;

	winTest = initscr();
	if (winTest != NULL)
	{
		colorInit();
		//Esta opción hace que siempre que se llame a una función que escribe se refresque la pantalla.
		immedok(winTest, TRUE);

		//Con las dos opciones de abajo elijo que el getch()sea no bloqueante (nodelay TRUE) y que no
		//muestr los caracteres cuando el usuario los escribe (noecho).
		nodelay(winTest, TRUE);
		noecho();
		
		option = selectSimulationMode();
		wclear(winTest);
		printMenu(option);
		getchar();
		endwin();
	}

	return 0;
}



char selectSimulationMode(void)
{
	char option;
	printInitMsg();

	option = getchar();
	while ((tolower(option) != 's') && (tolower(option) != 'c'))
	{
		printErrMsg();
		option = getchar();
	}
	return option;
}