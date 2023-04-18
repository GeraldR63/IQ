#include <dna.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <sys/stat.h>

dba::dna()
{
semaphore="data/dna_semaphore.dat";
}

dna::~dna()
{
}


void dna::erzeuge_dna()
{
						warte_auf_dna(semaphore);
						fstream f;												
						string s="data/dna.dat";
						f.open(s.c_str(),ios::out | ios::trunc);	  						
						dna::serialize(f);
						f.close();		
						remove(semaphore);
                        

}


void futtern::hole_futter ()
{
                        warte_auf_dna(semaphore);
						ifstream f;						
						string s="data/dna.dat";
						f.open(s.c_str(),ios::in  );	  
                        dna::deserialize(f);																						
					    f.close();		  												
						
						remove(semaphore);
}

bool dna::exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

void dna::warte_auf_dna(const std::string& name)
{
   while (exists(semaphore)) //So lange die Semaphore existiert warten
   {
     usleep (std::rand()%100);          //Immer verschieden lang warten..
   }
   
   fstream f;												
   string s=semaphore;
   f.open(s.c_str(),ios::out | ios::trunc);	  						
   dna::serialize(f);
   f.close();		

}



