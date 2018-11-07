#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/* Vamos a usar el algoritmo polar de Marsaglia para generar el array conteniendo la distribucion normal inspirado de https://en.wikipedia.org/wiki/Marsaglia_polar_method*/

float* arrayGausiano (int N, float mu, float sigma)
{
  float papillas[N];
  float* array;
  int i;
  printf("bien");
	for(i=0; i < N; i++)
	{
	 bool hasSpare = false;
	 double spare;
	 if(hasSpare) {
	 hasSpare = false;
	 papillas[i]=mu + sigma * spare;
	 }
	 hasSpare = true;
	 double u, v, s;
	 do{
	  u = ((double) rand()/(RAND_MAX))*2 - 1.0;
	  v = ((double) rand()/(RAND_MAX))*2 - 1.0;
	  s = u * u + v * v;
	 } while( (s >= 1.0) || (s == 0.0) );
	 s = sqrt(-2.0 * log(s)/s);
	 spare = v * s;
	 papillas[i]=mu + sigma * u * s;
	}
 array = papillas;

 return array;
}

/*Metodo para crear el archivo de los datos*/ 
void crearEldat(float* vector , int N,float mu, float sigma)
{
FILE *in;
char filename[100];
int i;

sprintf(filename, "sample.dat");
in = fopen(filename,"w");
	for(i=0; i < N; i++)
	{
	if (vector[i]>=(mu-3*sigma) && vector[i]<=(mu+3*sigma))
	 {
	  fprintf(in, "%f\n", vector[i]);
	 }
	}
fclose(in);
}

/*Metodo main para ejecutar las funciones anteriores*/
int main(int argc, char **argv)
{
int N;
float mu;
float sigma;
float* array;

N = atof(argv[1]);
mu = atof(argv[2]);
sigma = atof(argv[3]);

array = arrayGausiano(N, mu, sigma);
crearEldat(array, N, mu, sigma);

return 0;
}
