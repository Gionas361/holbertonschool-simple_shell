#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/** Structure declarations */

typedef struct noarg
{
	char *noarg;
	char (*f);
} noarg_t;

typedef struct hasarg
{
	char *hasarg;
	char (*f)(char *condit);
} hasarg_t;

/** Funtion declarations */

int ls_run();
int pwd_run();
int cd_run(char *condit);
int cat_run(char *condit);
int echo_run(char *condit);
int mkdir_run(char *condit);


#endif
