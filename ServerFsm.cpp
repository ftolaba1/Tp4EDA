#include "ServerFsm.h"
#include "Front.h"

void fsm_server::run(tevento ev, void* data)
{
	((data_t*)data)->LastEvent = ((data_t *)data)->Event;
	((data_t*)data)->Event = ev;
	tabla[estado][ev].action(data);
	estado = tabla[estado][ev].proximoEstado;
};

fsm_server::fsm_server()
{
	estado = READYTOCONNECT;
}

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