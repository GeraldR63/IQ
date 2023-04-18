#ifndef BRAIN_H
#define BRAIN_H


#include <cell.h>
#include <constants.h>

// Basiert auf der "gefuehlten Funktionsweise" von Gerald Roehrbein und bildet die Arbeitsweise meines Gehirns mehr oder minder nach
// Exakt kann dies wohl nicht erfolgen aber in guter Annaehrung.

extern long lebende_zellen;
class brain
{
 
 class cell cell; // Zentrale Zelle
 short iq;         // Wenn die Antwort gut ist steigt der IQ, ist sie schlecht sinkt er. Prozent. Das System versucht immer die 100% zu erreichen.
 
   public:
           brain(void);
           ~brain();
           void init (void);
		   bool lebendig() { return lebende_zellen>1; } // So lange noch eine Zelle aktiv ist lebt das System
           
};

#endif
