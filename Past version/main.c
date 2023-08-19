#include "main.h"
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " "


void shell_loop(void)
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

char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }

  return line;
}

char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int lsh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int lsh_execute(char **args)
{
  noarg_t func[] = {
		{"ls", ls_run},
    {"pwd", pwd_run},
  	{"cd", cd_run},
		{"mkdir", mkdir_run},
		{"echo", echo_run},
		{"cat", cat_run},
		{NULL, NULL}
	};

  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], func[i].process) == 0) {
      return (func[i].function)(args);
    }
  }

  return lsh_launch(args);
}

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








/**
 * it will figure out which function it is
 * with the structure provided in the main.h
 * 
*/
char *function_call(char *string)
{
  hasarg_t hasarg[] = {

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