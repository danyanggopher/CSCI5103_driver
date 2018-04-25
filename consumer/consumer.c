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

  int scullbuffer = open("/dev/scullpipe0", O_RDONLY);
  sleep(2);

  for (int i = 0; i < num; i++) {
    // construct item
    char item[32];
    int res = read(scullbuffer, &item, 32);
    // deal with return value
    printf("the result value is %d", res);
    if (res == 0) {
      printf("The buffer is empty and no descriptor is openning for writing\n");
    } else if (res < 0) {
      printf("Error, cannot read\n");
    } else {
      printf("The Item received is %s\n", item);
    }
  }

  close(scullbuffer);
}
