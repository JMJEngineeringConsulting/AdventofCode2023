#include <stdint.h>
#include <stdio.h>
#include "day1_input.h"


#define LEN(arr) ((int)(sizeof (arr) / sizeof (arr)[0]))


int main ()
{
  printf ("Hello, World! This is a native C program compiled on the command "
          "line.\n");
  printf ("Advent of Code 2023, Day 1.\n");
  extern uint8_t input[1000][55];
  uint16_t i = 0;
  uint8_t j = 0;

  uint8_t first_num = 0;
  uint8_t first_num_found = 0;
  uint8_t last_num = 0;

  uint32_t running_sum = 0;

  // loop thru all input lines
  for (i = 0; i < LEN (input); i++)
    {
      // loop thru all characters on current line
      for (j = 0; j < sizeof (input[0]); j++)
        {
          if (input[i][j] >= '0' && input[i][j] <= '9')
            {
              if (!first_num_found)
                {
                  first_num = input[i][j] - 48;
                  first_num_found = 1;
                }

              last_num = input[i][j] - 48;
            }
        }

      // clear line flag
      first_num_found = 0;

      // Add to running sum
      running_sum += first_num * 10 + last_num;

      printf ("Line %d text: %s \n", i, input[i]);
      printf ("Line %d First Num: %d Last Num: %d Running Sum: %d \n", i,
              first_num, last_num, running_sum);
    }

  printf ("Final Answer: %d  \n", running_sum);

  return 0;
}