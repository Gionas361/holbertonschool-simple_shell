#include "main.h"

/**
 * 
 */
int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  shell_loop();

  // Perform any shutdown/cleanup.

  return (EXIT_SUCCESS);
}

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;
  char *copy = argv[i];
  while (status)
  {
    printf("$ ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  }
}

/**
 * it will figure out which function it is
 * with the structure provided in the main.h
 * 
*/
char *function_call(char *string)
{
	noarg_t noarg[] = {
		{"ls", ls_run},
    {"pwd", pwd_run},
		{NULL, NULL}
	};

  hasarg_t hasarg[] = {
  	{"cd", cd_run},
		{"mkdir", mkdir_run},
		{"echo", echo_run},
		{"cat", cat_run},
    {NULL, NULL}
  };

  int n, h, nothasNUM = 2, hasNUM = 4;

  for (; n != nothasNUM ; n++)
  {
    if (argv[i] == noarg[n].noarg)
    {
      /** code to run function */

      return (0)
    }
  }

  for (; h != hasNUM ; h++)
  {
    if (argv[i] == hasarg[h].hasarg)
    {
      /** code to run function*/

      return (0)
    }
  }

  return (-1);
}

Parse:

ls -l | cd ../documents/

argv[0]:  = is function called (ls)
argv[]: - = condition for function
argv[]: | = new funtion after it