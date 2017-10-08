#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void mysh_parse_command(const char* command, 
						int* argc, char*** argv) {

	char tempBuf[50];
	int blankFlag = 0;
	int tempIdx = 0;
	int SIZEOFSTRING = sizeof(char);
	*argc = 0;

	argv[0] = (char**)malloc(sizeof(char*) * 20);
	
	for (int i = 0; command[i] != '\0'; i++) {
		if(command[i] == ' ' || command[i] == '\n' || command[i] == '\t')
			continue;

		blankFlag++;
		SIZEOFSTRING += sizeof(char);

		tempBuf[tempIdx++] = command[i];

		if (command[i + 1] == ' ' || command[i + 1] == '\t' ||
				command[i + 1] == '\n' || command[i + 1] == '\0') {
			tempBuf[tempIdx] = '\0';
			argv[0][*argc] = (char*)malloc(SIZEOFSTRING);
			strcpy(argv[0][(*argc)++], tempBuf);
			SIZEOFSTRING = sizeof(char);
			tempIdx = 0;
		}
	}

	if(blankFlag == 0){
		argv[0][0] = (char*)malloc(sizeof(char));
		strcpy(argv[0][0], "");
		(*argc)++;
	}
}
