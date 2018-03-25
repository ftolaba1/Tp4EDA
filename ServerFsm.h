
typedef enum { READYTOCONNECT, WAIT_EVENT, WAIT_ACK, SHUTDOWN }testado;
typedef enum { SEND_READY, RECIEVE_READY, ACK, SEND_MOVE_REQUEST, RECEIVED_MOVE_REQUEST, ERROR, RECEIVED_QUIT_REQUEST, SEND_QUIT_REQUEST, TIMEOUT1, TIMEOUT2 }tevento;
typedef void(*funpointer)(void* data);

struct cell
{
	testado proximoEstado;
	funpointer action;
};

void waitReadyConfirm(void* data);
void errorComunication(void* data);
void waitMoveConfirm(void* data);
void quitAnswer(void* data);
void sendAck(void* data);
void doStuff(void* data);
void reSend(void* data);
void doNothing(void* data);

class fsm
{
	private:
		const cell tabla[4][10] =
		{	//SEND_READY						RECIEVE_READY					 ACK							  SEND_MOVE_REQUEST			RECEIVED_MOVE_REQUEST	   ERROR				 	   RECEIVED_QUIT_REQUEST	 SEND_QUIT_REQUEST		  TIMEOUT					      TIMEOUT2
			{ { WAIT_EVENT,&waitReadyConfirm } ,{ WAIT_EVENT,&sendAck } , { SHUTDOWN,&errorComunication } ,{ WAIT_ACK,&waitMoveConfirm } ,{ WAIT_EVENT,&sendAck } ,{ SHUTDOWN,&errorComunication } ,{ SHUTDOWN,&sendAck } ,{ WAIT_ACK,&quitAnswer } ,{ SHUTDOWN,&errorComunication } ,{ SHUTDOWN,&errorComunication } },//READYTOCONNECT
			{ { WAIT_ACK,&waitReadyConfirm } ,{WAIT_EVENT,&waitReadyConfirm} , {SHUTDOWN,&errorComunication} , {WAIT_ACK,&waitMoveConfirm} , {WAIT_EVENT,&sendAck} , {SHUTDOWN,&errorComunication} , {SHUTDOWN,&sendAck} , {WAIT_ACK,&quitAnswer} , {SHUTDOWN,&errorComunication} , {SHUTDOWN,&errorComunication} },//WAIT_EVENT
			{ { WAIT_ACK,&waitReadyConfirm } ,{SHUTDOWN,&errorComunication} , {WAIT_EVENT,&doStuff} , {SHUTDOWN,&errorComunication} , {SHUTDOWN,&errorComunication} , {SHUTDOWN,&errorComunication} , {SHUTDOWN,&errorComunication} , {WAIT_ACK,&reSend} , {SHUTDOWN,&errorComunication} , {} },//WAIT_ACK
			{ { WAIT_ACK,&waitReadyConfirm } ,{SHUTDOWN,&doNothing},{SHUTDOWN,&doNothing},{SHUTDOWN,&doNothing},{SHUTDOWN,&doNothing},{SHUTDOWN,&doNothing},{SHUTDOWN,&doNothing},{WAIT_ACK,&doNothing},{SHUTDOWN,&doNothing} },//SHUTDOWN
		};
		testado estado;

	public:
	void run(tevento ev, void* data);
};