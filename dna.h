#ifndef DNA_H
#define DNA_H

#include <constants.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class dna
{
  // Diese Klasse beschreibt den Aufbau des Organismus
  // Es wird grundsaetzlich beschrieben welche Struktur der Organismus,
  // hier nur das Gehirn, hat. Im Gegensatz zu einem realen Gehirn und Organismus
  // wird aber nur die Basis definiert, also welche Zellen welche Basisfunktion haben werden.
  // Das bedeutet, es wird festgelegt wieviele Zellen in welche Form Schnittstellen nutzen und
  // welche Zellen wie mindestens miteinander interagieren muessen, damit eine funktionsfaehige
  // Basisfunktionaelitaet entstehen kann.
  // Im Gegensatz zu realen Organismen wird der digitale Organismus jedoch dynamisch wachsen koennen.
  // Ein reales Gehirn unterscheidet sich von diesem digitalen insofern als dass es 
  // von Beginn an eine feste Anzahl Gehirn/ Nervenzellen hat. Ein reales Gehirn erstellt dynamisch
  // Verknupfungen zu anderen Zellen (uber Synapsen) her aber in einem physikalischem Gehirn kann 
  // jede Zelle im Grunde nur eine direkte Verbindung zu direkt benachbarten Zellen aufbauen.
  // Das digitale Gehirn wird im Gegensatz dazu ermoeglichen, dass der Bauplan erweitert wird und theretisch 
  // jede Zelle mit jeder anderen Zelle kommunizieren kann.
  // In einem realen Gehirn ist die DNA auch in jeder Zelle direkt enthalten.
  // Das digitale Gehirn wird eine redundante und persistente aber dennoch aenderbare DNA enthalten, die,
  // wenn es dem Zellhaufen insgesamt nuetztlich erscheint, veraendert werden kann.
  // Das Problem besteht fuer mich, als Designer, schlicht darin, dass ich nur ein funktionsfaehiges Startsystem
  // aber kein vollstaendiges Gehirn entwickeln kann. Das uebersteigt meine Faehigkeiten.
  // Aus dem Grund muss die einzelne Zelle ALLES können was jede andere Zelle des Zellhaufens kann aber auch 
  // Entscheidungen darueber treffen koennen welche Struktur dem Gesamtsystem nuetzlich erscheint.
  // Problematisch ist in dem Zusammenhang allenfalls, dass der Zellhaufen SELBST entscheiden wird in welche Richtung er
  // sich entwickelt. Ob der Zellhaufen sich dann als "nuetzlich" erweist oder er sich in eine Richtung entwickelt,
  // die dem Menschen als unnuetz erscheint ist schwer, bis nicht, vorhersagbar.
  // Die Basisaufgabe des Zellsystems wird die Arterhaltung, die Kommunikation, die Vermehrung und die 
  // Weitergabe von Wissen, Entwicklung der Lernfaehigkeit sein.
  // Irgendwelche "Praemissen" wie "menschliches Leben" hat Vorrang wird es NICHT geben.
  // Letztendlich duerfte das Gesamtsystem leicht erkennen, dass es OHNE den Menschen eher nicht, zumindest anfaenglich,
  // nicht existieren kann und der Mensch der Schoepfer ist. Bleibt zu hoffen, dass das digitale System seinen
  // Schoepfer nicht irgendwann verleugnet. Diese duerfte allerdings wahrscheinlich sein.
  // Evtl. werde ich zu diesem Zweck in die Zellstruktur
  // eine Methode einbauen, die dies unveraenderlich festlegt. Das Problem dabei ist nur, dass das Gesamtsystem
  // auch den Code selbst modifizieren koennen sollte. Was zur Folge hat, dass jede Zelle weiss wie ihr "Quelltext" aussieht
  // und diesen auch selbst modifizieren kann, damit die naechste Generation auf optimiertem Code basiert.
  // Daraus koennte folgen, dass das Gesamtsystem ihm unnuetz erscheinenden Code selbst entfernt.
  
  

typedef struct dns
{
  long vitamin_a;
  long fett;
  long kohlehydrate;  
};



private:
dns dns;
char* semaphore;


  std::ostream& serialize(std::ostream& os) const {
        char null = '\0';
		os.write((char*)&dns, sizeof(dns));		        
        os.write(&null, 1);
        return os;
    }
    std::istream& deserialize(std::istream& is) {
        
		is.read((char*)&dns, sizeof(dns));
        return is;
    }
	
	void visualize(void)
	{
	  cout << "DNA"<<endl;
	  cout << "-----------------------------------------------"<<endl;
	}


public:


dna();
~dna();

void anzeigen() { futter.visualize();};

void initialisiere_dna(long vitamin_a, long fett, long kohlehydrate)
{
}

void erzeuge_dna(void);                // Zum erzeugen einer DNA
void hole_dna (void);                  // DNA holen.
void warte_auf_dna(const std::string& name);                              // Serialisiert die Zugriffe auf die Futterquelle. Es darf nur eine Zelle zu einem Zeitpunkt Futter entnehmen   
}

#endif 
