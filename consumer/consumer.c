/*
* consumer.c
* CSCI 5103 
* Kah Hin Lai
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

#define ITEM_SIZE 32

int main(int argc, char * argv[]) {
  if (argc != 3) {
    printf("Usage: consumer item_num consumer_id");
    exit(-1);
  }
  int item_num = atoi(argv[1]);
  char* id = argv[2];
  int scull = open("/dev/scullpipe0", O_RDONLY);
  if (scull == -1) {
		perror("Consumer Scull Open failed: ");
		exit (-1);
	}
  sleep(2); /* delay to wait for other process to complete open*/
  char buf[ITEM_SIZE];
  int i, ret;
  for (i = 1; i <= item_num; i++) {
    memset(buf, '\0', ITEM_SIZE);
    ret = read(scull, &buf, ITEM_SIZE);
    if (ret == 0){
      fprintf(stderr, "Consumer %s: Buffer is empty and no producers available\n", id);
      break;
    } else if (ret == -1) {
      perror("Reading by consumer failed: \n");
      break;
    } else {
      printf("Iteration : %03d, Consumer %s consumed %s\n",i, id, buf);
    }
  }
  printf("Total number of Items read by Consumer %s: %d\n", id, i-1);
  close(scull);
  exit(0);
}
