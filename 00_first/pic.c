#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
  int file_id=open("./neat.ppm",O_WRONLY | O_CREAT,0666);
  if (file_id == -1){
    printf("There was a problem opening the pic file:  %s\n",strerror(errno));
    return 0;
  }
  write(file_id,"P3 1000 1000 256 ",17);
  int x=0;
  int red;
  int green;
  int blue;
  char buf[13];
  while (x<1000000){
    red=sin(x);
    blue=cos(x);
    green=tan(x);
    sprintf(buf,"%d %d %d ",red,blue,green);
    write(file_id,buf,strlen(buf));
    x++;
  }
  close(file_id); 
  return 0;
}
