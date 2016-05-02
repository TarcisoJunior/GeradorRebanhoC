/*************************************************************************/
/*                                                                       */
/*        The urand function is a uniform random number generator based  */
/*  on theory and suggestions given in Forsythe, G.E., Malcolm, M.A., &  */
/*  Moter, C.B. Computer Methods For Mathematical Computations,          */
/*  Prentice-Hall, 1977.                                                 */
/*        The integer y should be initialized to an arbitrary integer    */
/* prior to the first call to urand. The calling program should not      */
/* alter the value of iy between subsequent calls to to urand. Values    */
/* of urand will be returned in the interval (0,1).                      */
/*                                                                       */
/*************************************************************************/
 
#include <math.h>
 
float urand(int *y)
{

    /* initialized data */
    static int m2 = 0;
    static int two = 2;
 
    /* local variables */
    static int m;
    static float s;
    static float halfm;
    static int a, c, mc;
 
    /* if first entry then ... */
    if (m2 == 0) {
 
        /* compute machine integer word length */
	m = 1;
	do {
            m2 = m;
            m = two * m2;
	} while( m > m2 );
	halfm = (float) m2;
 
        /* compute multiplier and increment for linear  */
        /* congruential method                          */
        a = ( (int) ( halfm * atan(1.) / 8.) << 3 ) + 5;
        c = ( (int) ( halfm * ( 0.5 - sqrt(3.) / 6.)) << 1 ) + 1;
        mc = m2 - c + m2;
 
        /*   s is the scale factor for converting to floating point */
	s = 0.5 / halfm;
    }
 
    /* compute next random number */
    *y *= a;
 
    /*  the following statement is for computers which do not */
    /*  allow integer overflow on addition                    */
    if (*y > mc)
       *y = *y - m2 - m2;
    *y += c;
 
    /* the following statement is for computers where the word */
    /* length for addition is greater than for multiplication  */
    if (*y / 2 > m2)
       *y = *y - m2 - m2;
 
    /* the following statement is for computers where integer    */
    /* overflow affects the sign bit                             */
    if (*y < 0)
       *y = *y + m2 + m2;
 
    return ( (float) (*y) * s );
}
