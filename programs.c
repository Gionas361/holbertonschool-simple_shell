#include "main.h"

/**
  * num_of_builtins - gets the number of builtin programs.
  * Return: size of them
  */
int num_of_builtins()
{
  return (sizeof(programs) / sizeof(char *));
}

/**
  * cd_run - checks for the argument for cd.
  * @args: Arguments for the function.
  * Return: 1.
  */
int cd_run(char **args)
{
  /** expects argument, else show error */
  if (args[1] == NULL)
  {
    fprintf(stderr, "lsh: expected an argument for \"cd\"\n");
  }
  else
  {
    if (chdir(args[1]) != 0)
    {
      perror("lsh");
    }
  }

  /** to keep the shell running */
  return (1);
}

/**
  * help_run - info for the shell.
  * @args: Arguments for the function.
  * Return: 1.
  */
int help_run(char **args)
{
  int i = 0;

  printf("TEST\n");
  printf("Programs in the shell:");

  /** prints the programms of the shell */
  for (; i < num_of_builtins() ; i++) {
    printf("  %s\n", programs[i]);
  }

  /** to keep the shell running */
  return (1);
}

/**
  * exit_run - stops the shell
  * @args: Arguments for the function.
  * Return: 0.
  */
int exit_run(char **args)
{
  return (0);
}
