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
  //set up a timer
  char buffer_out[] = "Hello Corerain! 123456123";
  int size = sizeof(buffer_out);
  char buffer_in[size];
  memset(buffer_in, 0, sizeof(buffer_in));
  Proctimer a_timer;

  int usb_fd;
  int hard_fd;
  int baud_rate = atoi(argv[1]);
  usb_fd = serialOpen("/dev/ttyUSB0", baud_rate);
  hard_fd = serialOpen("/dev/ttyAMA0", baud_rate);
  serialFlush(hard_fd);
  serialFlush(usb_fd);
  while(true)
  {
    printf("Baud Rate: %d\n", baud_rate);
    a_timer.get_start_time();
    for(int i = 0; i < size; i++)
    {
      write(hard_fd, buffer_out+i, 1);
      read(usb_fd, buffer_in+i, 1);
    }

    a_timer.get_end_time("Serial read");
    printf("Received Message: %s\n", buffer_in);
    printf("Buffer length: %d\n", sizeof(buffer_in));
    //printf("%s\n", buffer_out);
    memset(buffer_in, 0, sizeof(buffer_in));
    printf("Empty Buffer: %s\n", buffer_in);
    serialFlush(usb_fd);
    serialFlush(hard_fd);
  }

  serialClose(usb_fd);
  serialClose(hard_fd);
  return 0;
}
