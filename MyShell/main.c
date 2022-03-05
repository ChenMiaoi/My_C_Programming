#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define SIZE 256
#define NUM 16

int main()
{
	char cmd[SIZE];
	char computer[SIZE];
	gethostname(computer, SIZE);
	while (1){
		cmd[0] = 0;
		char* env = getenv("PWD");
		char* temp = env + strlen(env) - 1;
		while (*temp != '/'){
			temp--;
		}
		env = temp + 1;
		printf("[%s@%s %s]@ ", getlogin(), computer, env);
		fgets(cmd, SIZE, stdin);
		cmd[strlen(cmd) - 1] = '\0';
		char* args[NUM];
		args[0] = strtok(cmd, " ");
		int i = 1;
		do
		{
			args[i] = strtok(NULL, " ");
			if (args[i] == NULL){
				break;
			}
			++i;
		} while (1);

		pid_t id = fork();
		if (id < 0){
			perror("fork error!\n");
			continue;
		}
		if (id == 0){
			execvp(args[0], args);
			exit(1);
		}
		int status = 0;
		pid_t ret = waitpid(id, &status, 0);
		if (ret > 0){
			printf("status code : %d\n", (status >> 8) & 0xff);	//WEIXTSTATUS(status)

		}
	}
	return 0;
}