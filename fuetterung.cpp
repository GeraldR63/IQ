#include <stdio.h>
#include <futter.h>





int main(int argc, char *argv[])
{
  if (argc==4)
  {
  futtern futtern;
  futtern.initialisiere_futter(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));  
  futtern.erzeuge_futter();  
  futtern.hole_futter();
  futtern.anzeigen();
  }
  else
  {
  cout << "---------------------------------------------------------------------------------"<<endl;
  cout << "Programm erwartet 3 numerische Parameter"<<endl;
  cout << "Vitamin_A, Fett, Kohlehydrate"<<endl;
  cout << "Diese Werte regulieren das Wachstum des Zellhaufens und seine Arbeitsintensitaet."<<endl;
  cout << "---------------------------------------------------------------------------------"<<endl;  
  }    
  return 0;
}
