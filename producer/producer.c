/*
* producer.c
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
#include <time.h>
#include <sys/time.h>

#define ITEM_SIZE 32

int main(int argc, char * argv[]) {
  if (argc != 3) {
    printf("Usage: producer item_num producer_color");
    exit(-1);
  }
  struct timeval tv;
  int item_num = atoi(argv[1]);
  char* color = argv[2];
  int scull = open("/dev/scullbuffer0", O_WRONLY);
	if (scull == -1) {
		perror("Producer Scull Open failed: ");
    exit(-1);
	}
  sleep(2); /* delay to wait for other process to complete open*/
  char buf[ITEM_SIZE];
  int i, ret;
  for(i = 1; i <= item_num; i++) {
    memset(buf, '\0', ITEM_SIZE);
    if(gettimeofday(&tv, NULL)==-1) {
      perror("fail to ge time");
      break;
    }
    sprintf(buf, "%s %05d <%ld>", color, i, tv.tv_sec*1000+tv.tv_usec);
    ret =  write(scull, &buf, ITEM_SIZE);
    if (ret == 0){
      fprintf(stderr, "Producer %s: Buffer is Full and no consumers available\n", color);
      break;
    } else if (ret == -1) {
      perror("Reading by producer failed: \n");
      break;
    } else {
      printf("Iteration : %03d, Producer %s produced %s\n",i, color, buf);
    }
  }
  printf("Total number of Items produced by Producer %s : %d\n", color, i-1);
  close(scull);
  exit(0);
}
