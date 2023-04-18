DATADIR=data

iq:  version iq.cpp iq.hpp brain.cpp brain.h cell.cpp cell.h futter.cpp futter.h dna.cpp dna.h makefile; gcc -o iq iq.cpp cell.cpp brain.cpp futter.cpp dna_2.cpp -I . -lstdc++ -lm -lthread -Werror
	test -d ${DATADIR} || mkdir ${DATADIR}

fuetterung:  fuetterung.cpp futter.cpp futter.h makefile; gcc -o fuetterung fuetterung.cpp futter.cpp -I . -lstdc++ -Werror 
	test -d ${DATADIR} || mkdir ${DATADIR}

run: iq fuetterung    
	./fuetterung 123 456 789 
	./iq

clean:
	test -r core && { rm core }
	test -r iq && { rm iq }
	rm data/*	
	ls -ltr

version: version.h 
	./version.sh




	
