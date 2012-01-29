#include <stdio.h>

/* 
 * Nelson Sequence Generator
 * by Allison Nelson
 * 
 * Generates a Nelson Sequence and a couple stats about it
 * A Nelson Sequence is a sequence in which the "t"th term is the sum of the previous two
 * This is similar to the Fibonacci Sequence, but modified by a few variables
 * The user chooses the first two terms (f and s, respectively)
 * and the sequence is carried out to the "t"th term. 
 * At this point, the "t"th term is saved and becomes the new s
 * A new line is started with f as the first number and the previous "t"th term as the second number
 *
 *
 */

unsigned int nelson_sequence (unsigned int f, unsigned int s, unsigned int t);

int main()
{
  int i;//loop counter
  int j;//loop counter
  int terms=9; //number of terms in the sequence
  int lines=3; //lines to compute (keep this at 3 for now)
  int f=1;// f is the first number on every line
  int s=1;// s is the second "starting" number used on the first line
  int nelsonnum; //"drop down" value
  int nn[10];//stores the "nelson numbers"
  int k;//loop counter

  //init array
  for(k=0;k<10;k++)
    {
      nn[k]=0;
    }
  int nn_index=0;

  //gets user input for f and s (this needs to be put into a function)
  char text[20];
  fputs("Enter f (first num on each line): ", stdout);
  fflush(stdout);
  if ( fgets(text, sizeof text, stdin) )
    {
      if ( sscanf(text, "%d", &f) == 1 )
	{
	  printf("number = %d\n", f);
	}
    }
  fputs("Enter s (second num for first line): ", stdout);
  fflush(stdout);
  if ( fgets(text, sizeof text, stdin) )
    {
      if ( sscanf(text, "%d", &s) == 1 )
	{
	  printf("number = %d\n", s);
	}
    }
  fputs("Enter t (number of terms in each line): ", stdout);
  fflush(stdout);
  if ( fgets(text, sizeof text, stdin) )
    {
      if ( sscanf(text, "%d", &terms) == 1 )
	{
	  printf("number = %d\n", terms);
	}
    }


  printf("\nNelson sequence with %i terms\n",terms);

  int a;
  int b;
  int sn;
  // "scrolls" through s values - change the limits to see different s values
  for (sn=1;sn<10;sn++)
    {
	  for (j=0; j<lines; j++)
	    {
	      for (i=0; i<terms; i++)
		{
		  //gets the i'th term with f and s
		  nelsonnum=nelson_sequence(f,s,i);
		  printf("%i ",nelsonnum);
		}
	      //new line, make a new "s"
	      s=nelsonnum;
	      //save that value
	      nn[nn_index]=nelsonnum;
	      nn_index++;
	      printf("\n");
	    }
	  printf("\nThe nelson numbers are: ");
	  nn_index=0;
	  //prints all the nelson numbers that were calculated
	  while (nn[nn_index]!=0)
	    {
	      printf("%i ",nn[nn_index]);
	      nn_index++;
	    }
	  printf("\nWhich means the power is: ");
	  //kinda hackish for now, only works for three lines
	  int num1=nn[1]-nn[0];
	  int num2=nn[2]-nn[1];
	  double power=(double)num2/num1;
	  printf("%f",power);
	  printf("\n\n");

	  //resetting nn array
	  for(k=0;k<10;k++)
	    {
	      nn[k]=0;
	    }
	  nn_index=0;
	  s=sn+1;
    }	  
}

// returns the "t"th term in a nelson sequence row
// f is the first number on every line
// s is the second "starting" number used on the first line
unsigned int nelson_sequence (unsigned int f, unsigned int s, unsigned int t)
{
  unsigned int n0 = f;
  unsigned int n1 = s;
  unsigned int naux;
  unsigned int i;
  if (t == 0)
    return f;
  for (i=0; i < t-1; i++) {
    naux = n1;
    n1 = n0 + n1;
    n0 = naux;
  }
  return n1;
}
