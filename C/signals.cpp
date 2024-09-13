#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<signal.h>
using namespace std;

void handler(int signo, siginfo_t *info, void *context)
{
	if(signo == SIGTSTP)
	{
		cout << "received SIGTSTP\n";
		pause();
	}
	if(signo == SIGCONT)
	{
		cout << "received SIGCONT. enter any number to continue...\n";
		int a;
		cin >> a;
	}
	if(signo == SIGTERM)
	{
		cout << "received SIGTERM\n";
		exit(0);
	}
}

int main(){
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_sigaction = &handler;

    if (sigaction(SIGTSTP, &sa, NULL) == -1
		|| sigaction(SIGCONT, &sa, NULL) == -1
		|| sigaction(SIGTERM, &sa, NULL) == -1)
 	{
		perror("sigaction");
		return EXIT_FAILURE;
	}

	cout << "my pid is " << getpid() << " . enter any number to continue...\n";
	int a;
	cin >> a;
	while(1)
	{
		cout << "going to keep on running " << (a++%10) << endl;
	}


    return 0;
}