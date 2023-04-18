#include <cell.h>
#include <brain.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <pthread.h> // Verwende POSIX Threads weil thread Klasse unter Solaris nicht verfuegbar
#include <unistd.h>
#include <math.h>    // Nur fuer Demozwecke. Spaeter entfernen.

using namespace std;
int size=0;          // Zaehler der real existierenden Zellen
                     // auf diesen Zaehler darf schreibend nicht direkt zugegriffen werden
//bool changing=false; // Semaphore fuer size. Size darf nur veraendert werden wenn changing false ist					 

cell::cell(cell *vorgaenger)
   {    
	lebende_zellen++;
	if (vorgaenger!=NULL)
		size=setID(vorgaenger->getID()+1);	
	else
	{
	    semaphore=false;
		size=setID(1);
	}
	
	setzeStartwerte(); //Initialisiert Basiseigenschaften der Zelle, die nichts mit ihren "Nutzdaten" zu tun haben.
                       //sondern Verhaltensweisen der Zelle steuern.
	
	// Nur dann Nutzbarkeitsfaktor und Wert initialisieren wenn die zugehoerigen persistenten Daten nicht existieren.
	if (!isPersistent())
	{
	    // Zelle mit Zufallswert im Rahmen zulaessiger Parameter initialisieren
		cell::data.nutzbarkeitsfaktor=std::rand()%100;
		cell::data.wert=std::rand()%10000;
		cell::data.amplitude=std::rand()%10000;
		// Zelle vorlaeufig persistent machen
		persistent();
	}
		
    cell:vorgaenger=vorgaenger;
	cell::nachfolger=NULL;
	threads=NULL;                               
	if (vorgaenger!=NULL) vorgaenger->init();
	
	
	
	nachbarn= new nb[MAXCELLS];            // Pointer auf Pointer von Zellen, die idealer Weise vergleichbarer Funktion dienen aber beliebig umgeschult werden koennen.
	                                       // Verknüpft alle Zellen miteinander und das auf komplexere Weise als im realen Gehirn moeglich, weil, theoretisch,
										   // jede Zelle mit jeder beliebigen anderen Zelle verbunden sein kann.
	                                       // So kann Sprachzentrum, Sehzentrum, Empathiezentrum, Belohungssystem etc. gebildet werden
										   // Besondere Beachtung gilt dem Belohnungssystem. Jede Zelle muss mit diesem in Verbindung stehen.
										   // Belohnung: Zustimmung, Schmerz, Mangel etc.
	
    if ( size <= MAXCELLS)
	{	
	//cout << "Alive "<<size<<" "<<id<<" "<<data.nutzbarkeitsfaktor<<" "<<data.wert<<endl ;	
    cell::nachfolger=new cell(this);		
	}
	                        //Aenderungen an der Semphore frei geben. Naechster.
   }

cell::~cell()
   {
       if (nachfolger!=NULL) {
         nachfolger->persistent();	   
	     delete nachfolger;
		 nachfolger=NULL;
		 }
	   lebende_zellen--;	 
       cout << "Dying "<<id<<endl ;
   
   }
   
void * cell::alive(void *eigentuemer)
// Interaktion zwischen Zellen und der Physik. Hier Problem Anbindung "Virtuelles Gehirn" an "Reale Physik", die leider nicht Zellular nachgebaut werden kann
// Chaotisches System der Braunschen Molekularbewegung nachempfunden
{    
	   cell *c= (cell *) eigentuemer;  // Zeiger auf Instanz des zum Thread gehoerenden Objektes
	                                   // Dies erlaubt dem Thread die Kommunikation zwischen den Zellen zu initialisieren aber auch dynamisch
									   // zu veraendern und zwar indem zum Einen uber Nachfolger und Vorgaenger sequentiell auf andere Zellen zugegriffen wird
									   // aber, uber das Pointerarray Nachbarn auch eine direkte Verknuepfung von jeder Zelle zu jeder bzw. allen Anderen Zellen
									   // herzustellen und (!!!) auch funktional zu nutzen.
									   // Das ist die Basis zur Schaffung eines "Organs".
									   // Das Problem der Methode besteht in der massiven Parallelität, die dies nach sich zieht.
									   // In einem echten Organismus arbeitet JEDE Zelle autonom. Jede Zelle hat ihren Stoffwechsel und tut etwas.
									   // Das Gehirn sagt nicht dem Auge und dem Sehnerv "sehe". Das machen diese eben massiv parallel "allein".
									   // Aus dem Grund kann diese Software mit der vorhandenen Technik nur den Grundgedanken von "Leben" zeigen
									   // und nur einfache Lebensformen nachempfinden. Das bedeutet Kleinsthirne wie bei Quallen oder Schnecken.
									   // Signale aufnehmen, Verarbeiten, daraus Verhalten ableiten.
									   // Prinzipiell ließe sich das zwar auch "einfacher" und "anders" programmieren aber eine einfache "Mechanik" auf der Basis
									   // boolscher Algebra und starrer Ablaufplaene und Funktionsdiagramme ist KEIN Leben.
        //if (!c->thread_running)
        //{		
									   
									   
	   	   
	   // Ersetzen durch Code zur Identifikation, Interaktion und funktionalen Gruppierung von Zellen
	   // zur Schaffung von Zellverbünden.
	   // Funktion auch "nachempfunde Zellteilung". DNA fehlt, kodiert hier den Stammdatensatz "Lebewesen", DIGI-DNA Datensatz muss implementiert werden.
	   // Einfache Zellhaufen mit Interaktion zur Aussenwelt. Also wenige Zellen, die aber bereits Spezialisierung haben.
	   // Evolution wird eher "nicht nachgebildet" bzw. startet auf hohem Level und findet durch Selbstmodifikation zur Optimierung des "Organismus" statt.
	   // Bedeutet ein Basissatz von Zellen für "Sehen, Hören, Reden" kann sich zur Optimierung dynamisch erweitern und seine Parameter anpassen (lernen!).
	   // Eine gewisse "Basis" muss bereits vorhanden sein, weil auch die DIGI-DNA aus heutiger Sicht "ja nicht" bei der Zeugung "vom Himmel" fällt.
	   // Das ist etwa die Antwort auf die Frage: Was war zuerst da? Die Henne oder das Ei? Weder noch.
	   // Jede Zelle kann in jeder technisch vorhandenen Art und Weise mit der Außenwelt agieren.
	   // Meint: Einen Ton erzeugen, einen Ton aufzeichen, ein Bildsignal aufnehmen. Ob die einzelne Zelle davon Gebrauch macht ergibt sich dann aus Sicht
	   // ihrer "Nutzbarkeit". Wenn es für die Zelle von Vorteil ist erzeugt sie Töne, ist es das nicht ist verarbeitet diese welche oder andernfalls speichert diese
	   // visuelle Daten. Dies hängt von den Zellen in unmittelbarer Nähe ab. Deren Funktion wird zu Beginn des "Lebenszyklus" von der DIGI-DNA vorgegeben.
	   // Das Wachstum hängt von der Speicherbarkeit des hereinkommenden Datenvolumens ab.
	   // Beispiel: Wenn eine Zelle eine Frequenz und deren Amplitude aufzeichnen kann aber ein Ton eine Abfolge ist wird das Audiosystem nach Möglichkeit "dynamisch" wachsen,
	   // um die reinfliessenden Daten speichern zu koennen. Das ist zwar, im Vergleich zu herkoemmlichen Speichermethoden extrem ineffizient aber
	   // so ist das Leben. Dafuer hat diese Methode andere Vorteile im Umgang mit aufgezeichneten und wiederzugebenden Daten.	   	 	   
	   // Ab hier nur Füllstoff zu Demozwecken. 
	   
	   int i=0;      
	   double result=0.0;
	   long Energieverbrauch=std::rand()%100;;  // Die tatsaechliche Hoehe des Energieverbrauchs richtet sich nach der Art der durchgefuehrten Aufgabe.	   
	   
	   while ( true )                 //Zelle lebt so lange der Energievorrat reicht.
	   {
		  result = result + sin(i) * tan(i); // Tue irgendwas....nur zu Demozwecken.		  
		  i++;                               // Zaehlt wie oft die Zelle etwas getan hat		  		  
		  
		  c->Energieverbrauch(Energieverbrauch); 	// Die Methode berechnet die vorhandene Energie neu
		  if (! c->amLeben()) 
		  {		  
		  break;          		// Wenn die Zelle tot ist, dann stirbt der Thread. Der Thread kann sterben bevor der Job erledigt ist
		  }
		  usleep (c->holeIndividualismus());  		// Unaebhaengig davon, dass der Code hier Fuellstoff ist wird diese Methode
													// bei jeder Art "realer" Verarbeitung benoetigt, um Zellen zu individualisieren,
													// also jeder Zelle ein eigenes Verhaltensmuster mitzugeben.
	   }	   
	   // Energieausstoss beim Versterben der Zelle.
	   printf("Zelle %ld verstarb nach %d Arbeitsschritten.\n",c->id,i); 	      
	   //}
	   //else
	   //printf("Thread fuer Zelle %ld existiert bereits.\n",c->id);
       
	   lebende_zellen--;  // Die Zelle ist tot wenn der Thread beendet ist.
	                      // Allerdings muss dann auch die Instanz der Zelle entfernt werden.
	   c->z=tot;			  // Zelle ist nun fuer tot erklaert aber muss noch verrotten, also aus dem Speicher entfernt werden.	  
   pthread_exit(NULL);		 
}   

void cell::init ()
           { 
			 if (!threads)
			 {		   
			 if (nachfolger!=NULL)
			 {			 
			 nachfolger->init();
			 nachfolger->transient();
			 }			 
             //cout << "Zelle "<<id<<" zum Leben erweckt." <<endl ;			 
			 			 
			 threads=new pthread_t;
			 int rc;
			 cell *t=this; // ToDo: An den Thread statt des Long die Instanz uebergeben. Dann kann man auf alles aus dem Thread zugreifen.			 			 
			 rc=pthread_create(threads,NULL, alive, (void *) t);			 
			 //thread_running=true;
			 }
           }
