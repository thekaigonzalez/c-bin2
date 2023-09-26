// Copyright 2019-2023 Kai D. Gonzalez, Licensed under the GNU AGPL license.
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY 4096
#define bin(x) (isbinary (x) == 3)

int
isbinary (const char *__inp)
{
  int isBinary = 0;
  int i = 0;

  while (i < strlen (__inp))
    {
      if (__inp[i] == '0' && i == 0)
        { /* the first character is a 0, denoting a binary string literal */
          isBinary = 1;
        }

      else if (__inp[i] == 'b' && i == 1 && isBinary == 1)
        {
          isBinary = 2;
        }

      else if (isdigit (__inp[i]) && isBinary == 1 || 2)
        {
          isBinary = 3;
        }

      else if (!isdigit (__inp[i]))
        {
          isBinary = -1;
        }

      i += 1;
    }
  return isBinary;
}

int
bin2 (const char *bina)
{
  int x;
  x = 0;

  int b;
  b = 2;

  int bins[MAX_BINARY];

  int pre = 0;

  for (int i = strlen (bina) - 1; i >= pre; i--)
    {

      char *token = malloc (2);
      token[0] = bina[i];
      token[1] = '\0';

      int _z = atoi (token);
      int fn = _z * (pow (2, x));

      bins[x] = fn;

      x++;
    }

  int final = 0;

  for (int i = 0; i < x; ++i)
    {
      final += bins[i];
    }

  return (final);
}

main ()
{
  char *input_string = "0b110001";
  printf ("%i\n", bin2 (input_string));
}
