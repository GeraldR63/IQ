#include <brain.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
using namespace std;

long lebende_zellen=0;

brain::brain(void)
           {
		     //brain::cell = new cell(NULL);
             init();
           }

void brain::init (void)
           {
		   
   		   cell.init();
           }

brain::~brain()
           {
		      
			  /*
			  if (cell)
				{
				delete cell;
				cell=NULL;
				}
				*/
				
			  pthread_exit(NULL);				  
		      cout << "Dead."<< endl;
           }


