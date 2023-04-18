#ifndef FUTTER
#define FUTTER

// Beschreibt einen Futterdatensatz
// Futter wird den Zellen von aussen zugefuehrt
// Das Problem des Zellsystems besteht darin, dass es ohne Futter
// keine es limitierenden Umweltbedingungen vorfindet und das Zellsystem
// daher unkontrolliert wachsen wuerde.
// Letztendlich ist das Ganze eine Art Computervirus nur, dass das Zellsystem
// zumindest nicht mit dem primaeren Ziel programmiert wird eben solches zu erreichen
// auf Grund dessen, dass das System aber mutieren wird kann es sein, dass es virale
// Aspekte entwickeln wird. Um dem Herr zu werden wird der Futtertyp gebraucht.
// Ohne Futter stirbt der Organismus und ohne die Kenntnis des Aufbaus von Futter wird
// dieser auch kein Futter selbst schaffen koennen.


#include <constants.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class futtern
{

typedef struct futter
{
  long vitamin_a;
  long fett;
  long kohlehydrate;  
  std::ostream& serialize(std::ostream& os) const {
        char null = '\0';
        os.write((char*)&vitamin_a, sizeof(vitamin_a));
		os.write((char*)&fett, sizeof(fett));
		os.write((char*)&kohlehydrate, sizeof(kohlehydrate));		        
        os.write(&null, 1);
        return os;
    }
    std::istream& deserialize(std::istream& is) {
        is.read((char*)&vitamin_a, sizeof(vitamin_a));
		is.read((char*)&fett, sizeof(fett));
		is.read((char*)&kohlehydrate, sizeof(kohlehydrate));
        return is;
    }
	
	void visualize(void)
	{
	  cout << "Futtervorrat"<<endl;
	  cout << "Vitamin_A="<<vitamin_a<<endl;
	  cout << "Fett="<<fett<<endl;
	  cout << "Kohlehydrate="<<kohlehydrate<<endl;
	  cout << "-----------------------------------------------"<<endl;
	}
};



private:
futter futter;
char* semaphore;

public:
bool lock; //Nur eine Zelle kann zu einem Zeitpunkt Futter entnehmen

futtern();
~futtern();

void anzeigen() { futter.visualize();};

void initialisiere_futter(long vitamin_a, long fett, long kohlehydrate)
{
   futtern::futter.vitamin_a=vitamin_a;
   futtern::futter.fett=fett;
   futtern::futter.kohlehydrate=kohlehydrate;
}

void erzeuge_futter(void);                // Zum erzeugen eines Futtervorrates
void hole_futter (void);                  // Futter aus dem Futtervorrat hohlen.
	                                      // Jede Zelle kann einen maximalen Futtervorrat aufnehmen
										  // der Parameter gibt an wieviel Futter geholt werden soll.
										  // Die Funktion liefert aber nicht so viel Futter zurueck
										  // wie angefordert wird sondern in Abhaengigkeit vom realen Futtervorrat eine Futtermenge
										  // bis zur maximal angeforderten.
										  // Der Futtervorrat wird jeweils um die entnommene Menge verringert.
										  
long gibVitamin_A() {hole_futter();long i=(futter.vitamin_a>10?10:0); futter.vitamin_a-=i; erzeuge_futter(); return i;}; 
long gibFett() {hole_futter();long i=(futter.fett>10?10:0); futter.fett-=i; erzeuge_futter(); return i;};
long gibKohlehydrate() {hole_futter();long i=(futter.kohlehydrate>10?10:0); futter.kohlehydrate-=i; erzeuge_futter(); return i;};

bool futtern::exists (const std::string& name);
void warte_auf_futter(const std::string& name);                              // Serialisiert die Zugriffe auf die Futterquelle. Es darf nur eine Zelle zu einem Zeitpunkt Futter entnehmen

};
#endif
