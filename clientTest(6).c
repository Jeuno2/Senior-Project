// ClientTest.c
// opens fifo1 for writing and fifo2 for reading

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

main (void)
{
  int fda;	// to write to server
  int fdb;	// to read response from server
  char charbuff[1];	// buffer holds a character
  char outchar[7];	// server puts string here
 
  memset(charbuff,0,1); 
  memset(outchar,0,7); 


  if((fda=open("FIFO1", O_WRONLY))<0)
     printf("cant open fifo to write");

  if((fdb=open("FIFO2", O_RDONLY))<0)
     printf("cant open fifo to read");

  printf("Client: Please enter a character: ");
  scanf("%c", &charbuff);


  write(fda, charbuff, 1);
  printf("\nClient: Got the character sent, now waiting for response ");
  read(fdb, outchar, 7);
  printf("\nClient: received from server %s", outchar);

  close(fda);
  close(fdb);

  printf ("\nall done!\n");
   
}


