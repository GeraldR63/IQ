
#include <futter.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <sys/stat.h>

futtern::futtern()
{
lock=false;
semaphore="data/semaphore.dat";
}

futtern::~futtern()
{
}


void futtern::erzeuge_futter()
{
						warte_auf_futter(semaphore);
						fstream f;												
						string s="data/futter.dat";
						f.open(s.c_str(),ios::out | ios::trunc);	  						
						futtern::futter.serialize(f);
						f.close();		
						remove(semaphore);
                        

}


void futtern::hole_futter ()
{
                        warte_auf_futter(semaphore);
						ifstream f;						
						string s="data/futter.dat";
						f.open(s.c_str(),ios::in  );	  
                        futtern::futter.deserialize(f);																						
					    f.close();		  												
						
						remove(semaphore);
}

bool futtern::exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

void futtern::warte_auf_futter(const std::string& name)
{
   while (exists(semaphore)) //So lange die Semaphore existiert warten
   {
     usleep (std::rand()%100);          //Immer verschieden lang warten..
   }
   
   fstream f;												
   string s=semaphore;
   f.open(s.c_str(),ios::out | ios::trunc);	  						
   futtern::futter.serialize(f);
   f.close();		

}

