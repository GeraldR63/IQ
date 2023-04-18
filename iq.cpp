#include <iostream>
#include <iq.hpp>
#include <cell.h>
#include <brain.h>
#include <version.h>
#include <signal.h>

extern long lebende_zellen;

void sig_handler(int signo)
{
   printf("Signalhandler, aufraeumen im Notfall!\n");
   remove("data/semaphore.dat");          // Bei Programmabbruechen kann es passieren, dass die Semaphore noch existiert  
   exit(1);
}

int main (int argc, char *argv[])
{
    printf("Lebenszyklus gestartet\n\r");
	
	if (signal(SIGINT, sig_handler) == SIG_ERR)  // Falls das Programm mit CTRL+C beendet wird ggf. die Semaphore wegraeumen
        printf("\nKann CTRL+C nicht abfangen.\n");  		
  
  std::srand(std::time(0));  // Den Zufallsgenerator initialisieren, damit "echter" Zufall eintritt.
                             // Das Programm also bei jedem Aufruf andere Ergebnisse produziert.  
  brain brain;
  
  while (lebende_zellen>1) // Die Wurzelzelle des Gehirns kann nicht wirklich versterben. Daher >1.
  {
    //cout << "Es leben noch "<<lebende_zellen<<endl;
    usleep (std::rand()%100);          //Immer verschieden lang warten..
  }
  
  printf("Lebenszyklus beendet,\n\rAutor %s\n\rBuild %s\n\rBuild# %s\n\r",author,release,build);
return 0;
}

