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
  int red=0;
  int green=0;
  int blue=0;
  char buf[13];
  while (x<1000000){
    red+=abs(tan(x%90));
    red=red%256;
    blue+=abs(cos(x%360));
    blue=blue%256;
    green+=abs(sin(x%180));
    green=green%256;
    sprintf(buf,"%d %d %d ",red,green,blue);
    write(file_id,buf,strlen(buf));
    x++;
  }
  close(file_id); 
  return 0;
}
