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



class futtern
{

struct futter
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
	  cout << "Vitamin_A="<<vitamin_a<<endl;
	  cout << "Fett="<<fett<<endl;
	  cout << "Kohlehydrate="<<Kohlehydrate<<endl;
	}
};

private:
futter futter;

public:
void erzeuge_futter(futter *);            // Zum erzeugen eines Futtervorrates
futter * hohle_futter (futter *);         // Futter aus dem Futtervorrat hohlen.
	                                      // Jede Zelle kann einen maximalen Futtervorrat aufnehmen
										  // der Parameter gibt an wieviel Futter geholt werden soll.
										  // Die Funktion liefert aber nicht so viel Futter zurueck
										  // wie angefordert wird sondern in Abhaengigkeit vom realen Futtervorrat eine Futtermenge
										  // bis zur maximal angeforderten.
										  // Der Futtervorrat wird jeweils um die entnommene Menge verringert.
};


#endif