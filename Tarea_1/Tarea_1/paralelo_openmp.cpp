#include "pch.h"
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <iostream> // Para cout
#include <omp.h> // Para OpenMP

#define N 1000
#define Chunk_size 100
#define mostrar 10

void imprimirArreglo(float* d);

int main()
{
	float arreglo1[N], arreglo2[N], arreglo3[N];
	int i;
	int pedazos = Chunk_size;
	std::cout << "Sumando Arreglos Paralelamente\n";

	// Inicializar la semilla para la generación de números aleatorios
	srand(static_cast<unsigned int>(time(0)));

	for (i = 0; i < N; i++) {
		arreglo1[i] = rand() % 100 + 1; // Números aleatorios entre 1 y 100
		arreglo2[i] = rand() % 100 + 1; // Números aleatorios entre 1 y 100
	}

#pragma omp parallel for shared(arreglo1, arreglo2, arreglo3,pedazos) private(i) schedule(static, pedazos)
	for (i = 0; i < N; i++) {
		arreglo3[i] = arreglo1[i] + arreglo2[i];
	}
	std::cout << "Arreglo 1: ";
	imprimirArreglo(arreglo1);
	std::cout << "Arreglo 2: ";
	imprimirArreglo(arreglo2);
	std::cout << "Arreglo 3: ";
	imprimirArreglo(arreglo3);
	return 0;
}

void imprimirArreglo(float* d) {
	int i;
	for (i = 0; i < mostrar; i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
}
