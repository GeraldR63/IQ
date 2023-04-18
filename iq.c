#include <stdio.h>
#include <iq.h>
#include <malloc.h>
#include <unistd.h>
#include "constants.h"


/* Virtual brain dimensions */

int main (void)
{
  
  int thoughts=0;
  
  printf("IQ V1.00\n\r");
    
  while ( 1==1 )
  {
     /* Simulate thinking */
	 cell cell;               /* Initial cell */
     printf ("Thinking.\n\r");
     sleep(1);
     if (thoughts++> LIFETIME) break;

  }
  printf("IQ 1.00 ended,\n\r");
return 0;
}

