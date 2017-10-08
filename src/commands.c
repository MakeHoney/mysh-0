#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"

int do_cd(int argc, char** argv) {

	if (!validate_cd_argv(argc, argv) || chdir(argv[1]))
 	   return -1;
	  return 0;
}

int do_pwd(int argc, char** argv) {

	char buf[255];
	if (!validate_pwd_argv(argc, argv))
    	return -1;

	getcwd(buf, 255);
	printf("%s\n", buf);

	return 0;
}

int validate_cd_argv(int argc, char** argv) {
	int dotCount = 0;

	for(int i = 0 ; i < argc ; i++)
		if(!strcmp(argv[i], "."))
			dotCount++;

	if(argc >= 2) {
		if(strcmp(argv[0], "cd"))
			return 0;
	}

	if(dotCount > 1 || argc == 1)
		return 0;

	return 1;
}

int validate_pwd_argv(int argc, char** argv) {
	if(!strcmp(argv[0], "pwd") && argc == 1)
		return 1;

	return 0;
}
