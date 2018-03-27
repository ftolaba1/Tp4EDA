#include "curses.h"

#define OPLINE 20

static void printEventList(int numMsg);
static void printFsmStatusList(int BoardStatus);

enum{SEND_READY = 7, RECIEVE_READY, SEND_MOVE, RECIEVE_MOVE, TIMEOUT, TIMEOUT2, ACK, SEND_QUIT, RECIEVE_QUIT, ERROR};
enum{StatusTitle = 6, EVENT_RECIEVED, LAST_EVENT, ACCION_EXEC, ACTUAL_STATE };

void colorInit(void)
{
	start_color();

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_WHITE);
	init_pair(7, COLOR_GREEN, COLOR_BLUE);
	init_pair(8, COLOR_BLUE, COLOR_GREEN);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_YELLOW);
}

void printInitMsg(void)
{
	printw("Bienvenido al programa de simulación del protocolo de comunicación de Servidor/Cliente\n");
	printw("Presione 'S' para simular SERVIDOR o 'C' para CLIENTE: ");
}

void printErrMsg(void)
{
	move(3, 0);
	printw("Ha ingresado un caracter no valido, vuelva a intentar ");
}

void printMenu(char mode)
{
	if (mode = 's')
	{
		printw("Simulacion de Servidor");
	}
	else if (mode = 'c')
	{
		printw("Simulacion de Cliente");
	}
	color_set(2, NULL);
	move(1, 0);
	printw("La simulacion se realiza mediante la suposicion de eventos por teclado.\n");
	printw("Al llegar un evento, se actualiza el status de maquina de estado.\n");
	move(4, 0);
	color_set(3, NULL);
	printw("Eventos:");

	for (int i = SEND_READY; i <= ERROR; i++)		//itera hasta el final que la variable sea la ultima del enum de eventos
	{
		color_set(3, NULL);
		move(i, 0);
		printEventList(i);
		color_set(4, NULL);
		printFsmStatusList(i);
	}
}

void printRefreshStatus(int what2print, void* msg)
{
	if (what2print == );
}



static void printEventList(int numMsg)
{
	switch (numMsg)
	{
		case SEND_READY:						
			printw("SEND_READY =");
			move(numMsg, OPLINE);
			printw("A");
			break;
		case RECIEVE_READY:
			printw("RECIEVE_READY =");
			move(numMsg, OPLINE);
			printw("B");
			break;
		case SEND_MOVE:
			printw("SEND_MOVE =");
			move(numMsg, OPLINE);
			printw("C");
			break;
		case RECIEVE_MOVE:
			printw("RECIEVE_MOVE =");
			move(numMsg, OPLINE);
			printw("D");
			break;
		case TIMEOUT:
			printw("TIMEOUT =");
			move(numMsg, OPLINE);
			printw("E");
			break;
		case TIMEOUT2:
			printw("TIMEOUT2 =");
			move(numMsg, OPLINE);
			printw("F");
			break;
		case ACK:
			printw("ACK =");
			move(numMsg, OPLINE);
			printw("G");
			break;
		case SEND_QUIT:
			printw("SEND_QUIT =");
			move(numMsg, OPLINE);
			printw("H");
			break;
		case RECIEVE_QUIT:
			printw("RECIEVE_QUIT =");
			move(numMsg, OPLINE);
			printw("I");
			break;
		case ERROR:
			printw("ERROR =");
			move(numMsg, OPLINE);
			printw("J");
			break;
		default:
			break;
	}
}

static void printFsmStatusList(int BoardStatus)
{
	switch (BoardStatus)
	{
	case StatusTitle:
		move(BoardStatus, OPLINE + 10);
		printw("| Status de la FSM");
		break;
	case EVENT_RECIEVED:
		move(BoardStatus, OPLINE + 10);
		printw("| Evento Recibido");
		break;
	case LAST_EVENT:				
		move(BoardStatus, OPLINE + 10);
		printw("| Ultimo Evento Recibido");
		break;
	case ACCION_EXEC:
		move(BoardStatus, OPLINE + 10);
		printw("| Accion Ejecutada");
		break;
	case ACTUAL_STATE:
		move(BoardStatus, OPLINE + 10);
		printw("| Estado Actual");
		break;
	default:
		break;
	}
}