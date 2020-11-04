//homework5_csobecks
#include <iostream>
#include "mpi.h"
#include <math.h> //sqrt=make a square root
#include <stdlib.h>
#include <time.h> //srand(time(NULL)) done at start of program then never again
using namespace std;

int main (int argc, char* argv[])
{
	//((double)rand()/RAND_MAX * 2.0 )-1
	int my_rank;
	int p;
	int source;
	int dest;
	
	srand(time(NULL));
	MPI_Status status;
	
	MPI_Init (&argc, &argv);
	
	MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);
	
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	if(my_rank == 0)
	{
		int totPts;
		
		cout << "how many points do you want to use" << endl;
		cin >> totPts;
		
		int PPN = totPts/(p-1);
		int loop;
		
		cout << "sending" << endl;
		for (loop=0;loop<p;loop++)
		{
			//cout << "ppn is " << PPN << endl;
			MPI_Send (&PPN,1,MPI_INT, loop, 0, MPI_COMM_WORLD);
			
		}
		
		int PIC;
		double PICT=0.0;
		
		for(loop=1;loop<p;loop++)
		{
			MPI_Recv(&PIC,1,MPI_INT,loop,0,MPI_COMM_WORLD,&status);
			PICT=PICT+PIC;
			//cout << PICT << endl;
			//cout << PIC << endl;
		}
		double Pi;
		double newPPN=PPN*(p-1)*1.0;
		Pi=(PICT/newPPN)*4.0;
		
		cout << "the value of Pi is " << Pi << endl;
	}
	else
	{
		int loop;
		int nump;
		double x;
		double y;
		double r;
		int pInC = 0;
		
		MPI_Recv(&nump, 1, MPI_INT, 0,0, MPI_COMM_WORLD, &status);
		
		for(loop=0;loop<nump;loop++)
		{
			x=((double)rand()/RAND_MAX*2)-1;
			y=((double)rand()/RAND_MAX*2)-1;
			//cout << x << "," << y << endl;
			r=sqrt(x*x + y*y);
			if(r<=1.0)
			{
				pInC++;
			}
		}
		//cout <<pInC<< endl;
		MPI_Send(&pInC,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	MPI_Finalize ();
}