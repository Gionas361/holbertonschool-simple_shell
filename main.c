#include "main.h"

/**
   main - runs the program lmao.
   @argc: number of arguments.
   @argv: array of arguments.
   Return: status of the code
 */
int main(int argc, char **argv)
{
  char **v = argv;
  int c = argc;
  (void)c;
  (void)v;

  shell_loop_input();
  
  return (EXIT_SUCCESS);
}
