#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include "utility/cr_utility.h"
#include "utility/cr_serial.h"

using namespace std;

int main(int argc, char * argv[])
{
  int str_len = atoi(argv[2]);
 //set up a timer
  char buffer_in[str_len];
  memset(buffer_in, 0, sizeof(buffer_in));
  Proctimer a_timer;

  int hard_fd;
  int baud_rate = atoi(argv[1]);

  hard_fd = serialOpen("/dev/ttyAMA0", baud_rate);
  while(true)
  {
    printf("Baud Rate: %d\n", baud_rate);
    a_timer.get_start_time();
    for(int i = 0; i < str_len; i++)
    {
      buffer_in[i] = serialGetchar(hard_fd);
    }
    a_timer.get_end_time("Serial read");
    printf("Received Message: %s\n", buffer_in);
    printf("Buffer length: %d\n", sizeof(buffer_in));
    //printf("%s\n", buffer_out);
  }

  serialClose(hard_fd);
  return 0;
}
