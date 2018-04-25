#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char* argv[]) {
  int num = 0;
  sscanf(argv[1], "%d", &num);

  int scullbuffer = open("/dev/scullpipe0", O_WRONLY);
  sleep(2);

  for (int i = 0; i < num; i++) {
    // construct item
    char item[32];
    sprintf(item, "%s%d", "BLACK", i);

    int res = write(scullbuffer, item, 32);

    // deal with the return value
    if (res == 0) {
      printf("The buffer is full and no descriptor is openning for reading\n");
    } else if (res < 0) {
      printf("Error, cannot write\n");
    } else {
      printf("%s Deposited\n", item);
    }
  }

  close(scullbuffer);
}
