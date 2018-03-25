#include "ServerFsm.h"
#include "Front.h"


void
fsm::run(tevento ev, void* data)
{
	tabla[estado][ev].action(data);
	estado = tabla[estado][ev].proximoEstado;
};



void waitReadyConfirm(void* data)
{
	printRefreshStatus();
}

void errorComunication(void* data)
{

}

void waitMoveConfirm(void* data)
{

}

void quitAnswer(void* data)
{

}

void sendAck(void* data)
{

}

void doStuff(void* data)
{

}

void reSend(void* data)
{

}

void doNothing(void* data)
{

}