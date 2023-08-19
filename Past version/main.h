#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/** Structure declarations */

typedef struct noarg
{
	char *process;
	char (*function);
} noarg_t;

/** Funtion declarations */

int ls_run(char **condit);
int pwd_run(char **condit);
int cd_run(char **condit);
int cat_run(char **condit);
int echo_run(char **condit);
int mkdir_run(char **condit);


#endif
