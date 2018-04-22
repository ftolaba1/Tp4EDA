void colorInit(void);

void printMenu(char mode);

void printInitMsg(void);

void printErrMsg(void);

void printRefreshStatus(int lastevent, int Event, void* msg);

struct data_t 
{
	int LastEvent;
	int Event;
};