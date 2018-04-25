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

  for (int i = 0; i < num; i++) {
    // construct item
    char item[32];
    sprintf(item, "%s%d", "BLACK", i);
    printf("Deposit one BLACK into buffer\n");

    write(scullbuffer, item, 32);
  }

  sleep(3);
  close(scullbuffer);
}