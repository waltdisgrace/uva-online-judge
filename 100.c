/* UVa Online Judge
 * 100 - The 3n+1 Problem
 * Author: Grace Chin */

#include <stdio.h>

#define DEBUG 0

unsigned int get_cycle_length( unsigned int n ) ;

int main( int argc, char* argv[] ) {

  unsigned int i ; /* 0 < i < 10,000 */
  unsigned int j ; /* 0 < i < 10,000 */
  unsigned int n ;
  unsigned int cycle_length ;
  unsigned int maximum_cycle_length = 0 ;

  /* Get input */
  printf( "Please enter an i and a j: " ) ;

  while ( scanf( "%u %u", &i, &j ) ) {

    if ( DEBUG == 1 ) {
      printf( "\n" ) ;
    }
    
    /* For i to j, including i and j... */
    for ( n = i ; n < ( j + 1 ) ; n++ ) { 

      /* Get cycle length */
      cycle_length = get_cycle_length( n ) ;

      if ( DEBUG == 1 ) {
	printf( "n is %u.\n", n ) ;
	printf( "The cycle length is %u.\n", cycle_length ) ;
      }

      /* Update maximum cycle length */
      if ( cycle_length > maximum_cycle_length ) {

	maximum_cycle_length = cycle_length ;

	if ( DEBUG == 1 ) {
	  printf( "The maxiumum cycle length has been updated to %u.\n", cycle_length ) ;	  
	}

      }

      if ( DEBUG == 1 ) {
	printf( "\n" ) ;
      }
      
    }
  
    /* Print output */
    printf( "%u %u %u\n", i, j, maximum_cycle_length ) ;

    /* Reset maximum cycle length */
    maximum_cycle_length = 0 ;

  }
  
  return 0 ;

}

unsigned int get_cycle_length( unsigned int n ) {

  unsigned int cycle_length = 1 ;

  if ( DEBUG == 2 ) {
    printf( "\n" ) ;
  }
  
  /* Repeat as long as n is not 1... */
  while ( n != 1 ) {

    if ( DEBUG == 2 ) {
      printf( "n is %u.\n", n ) ;
    }
    
    /* If n is odd... */
    if ( n % 2 == 1 ) {

      /* Multiply n by 3 and add 1. */
      n = ( 3 * n ) + 1 ;

      if ( DEBUG == 2 ) {
	printf( "n is odd, so n has been updated to 3n+1, which is %u.\n", n ) ;
      }

      /* Update cycle length. */
      cycle_length += 1 ;
	
      if ( DEBUG == 2 ) {
	printf( "The cycle length has been updated to %d.\n", cycle_length ) ;
      }

      /* If n is even... */
    } else {

      /* Divide n by 2. */
      n = n / 2 ;
	  
      if ( DEBUG == 2 ) {
	printf( "n is not odd, so n has been updated to n/2, which is %u.\n", n ) ;	  
      }

      /* Update cycle length. */
      cycle_length += 1 ;

      if ( DEBUG == 2 ) {
	printf( "The cycle length has been updated to %u.\n", cycle_length ) ;
      }
	
    }

    if ( DEBUG == 2 ) {
      printf( "\n" ) ;
    }
    
  }

  return cycle_length ;

}
