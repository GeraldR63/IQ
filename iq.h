#ifndef IQ
#define IQ


/*
 It thinks only if it is able to program itself.
 Means:

 It needs a full set of opcodes useable to be combined in a free way.

 It needs a base program (the initial job) to try and learn.
 Interrupt of false procedures must be given.

*/

typedef struct interface interface;
typedef interface *manager (void);
struct interface  /* Defintion of interface of data */
{
    interface *pinterface;
    interface *ninterface;
    int data;        /* Data is a model of opcodes of processor */
    manager *manager;
} ;

typedef struct cell cell;
typedef cell *handler (cell *);  /* Memory Management of brain, transient */
typedef cell *writer(cell *);    /* Memory Management of brain, persistent */
typedef cell *reader(cell *);    /* Memory Management of brain, persistent */

struct cell 
{
  /* Physical structure of brain */
  cell *pcell[DIMENSION];   
  cell *ncell[DIMENSION];   

 
  /* Position of Current dimension of this cell*/ 
  int dim[DIMENSION]; /* ={0,0,0};  */

  /* Logical structure of brain. Cell chain.
     Meaninig: Which cell depends on which cell
  */ 
  cell **lpcell;
  cell **lncell;

  interface interface;
  int data;
  handler *handler;
  writer *writer;
  reader *reader;

} ;

#endif
