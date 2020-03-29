
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define LOG2N  6
#define N      (1 << LOG2N)
#define N_2    (1 << (LOG2N-1))

//-----------------------------------------------------------------------------
// Typedefs
//-----------------------------------------------------------------------------

typedef struct {
   char re;  
   char im;
} complex_t; 

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void fft(complex_t * a);


 