#include "curses.h"
#include <iostream>
#include "ServerFsm.h"
#include "Front.h"
//#include "ClientFsm.h"

#define KEYOPTIONFORSERVER 's'
#define KEYOPTIONFORCLIENT 'c'

using namespace std;

char selectSimulationMode(void);


int main(void)
{
	WINDOW * winTest = NULL;                     //Variable en dónde se guarda la terminal (Window) en donde voy a trabajar.

	char option;
	int i = 0;

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
		
		fsm_server simulatorServer;
		//fsm_client simulator;

		if (option)
		{
			do
			{
				i = getch();
				if (i != ERR)
				{
					if (toupper(i) >= 'A' && toupper(i) <= 'G')
					{
						simulatorServer.run((toupper(i) - 'A'), (void *) "hola");
					}
				}
			} while (toupper(i) != 'Q' & (simulatorServer.get_state() != SHUTDOWN));
		}
		else
		{

		}
		endwin();
	}

	return 0;
}



char selectSimulationMode(void)
{
	char option;
	printInitMsg();

	option = getchar();
	while ((tolower(option) != KEYOPTIONFORSERVER) && (tolower(option) != KEYOPTIONFORCLIENT))
	{
		printErrMsg();
		option = getchar();
	}
	return option;
}