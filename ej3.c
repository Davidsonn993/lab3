#include <stdio.h>
#include <stdlib.h>
#include <time.h>                    //biblioteca necesaria para el rand
#define SIZE 10                       //definimos el caso mas grande

int min(int a, int b, int c) {         //creamos esta función para comparar los posibles tamaños
    int smallest = a;
    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;
    return smallest;
}

void crear_matriz_cuadrada(int dimension, int matrix[][SIZE]) {  // creamos esta otra funcíon para crear la matriz
                                                  // Llenamos  la matriz con unos y ceros aleatorios
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = rand() % 2;                  //utilizamos la funcion rand para crear numeros aleatorios
        }                                              //se divide entre 2 para que la provabilidad sea pareja si el
    }                                                  //numero es par el resultado es 0 y si es impar 1 
                                                         
                                                      
    printf("La matriz generada es:\n");                 // Imprimir la matriz generada
      for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
                                                        //funcion para encontrar el cuadrado mas grande
int findLargestSquare(int dimension, int matrix[][SIZE]) { //resive dimension y matrix como parametro
    int maxSquareSize = 0;
    int dp[SIZE][SIZE] = {0}; // Esta matriz DP almacenará el tamaño del cuadrado más grande que termina en (i, j)

                                                // Inicializar la primera fila y la primera columna de la matriz DP
    for (int i = 0; i < dimension; i++) {                 //lo que se hace es revisar primero fila y colunma 0 de 
							  //encontrar un 1 modifica maxSquareSise
        dp[i][0] = matrix[i][0];                          //definimos una matriz dp en donde almacenamos los datos
        dp[0][i] = matrix[0][i];                      //de matrix 
        if (matrix[i][0] == 1) maxSquareSize = 1;
        if (matrix[0][i] == 1) maxSquareSize = 1;
    }

                                                      // Llenar el resto de la matriz DP
    for (int i = 1; i < dimension; i++) {
        for (int j = 1; j < dimension; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1; //llamamos la funcion min para encotrar el
                if (dp[i][j] > maxSquareSize) {                   // cuadrado mas pequeño que vamos a comparar con
                    maxSquareSize = dp[i][j];               //con el cuadrado mas grande anteriormente, si es mas
                }                                     //grande lo almacenamos en la matriz dp
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxSquareSize;
}

int main() {
    int dimension;                //definimos dimension
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios

    printf("Ingrese la dimension de la matriz cuadrada (entre 1 y 10): ");
    scanf("%d", &dimension);     //scanf para ingresar dimension

    if (dimension < 1 || dimension > 10) {               //por si no esta dentro del rango mostrar una nota
        printf("La dimension de la matriz debe estar entre 1 y 10.\n");
        return 1;
    }

    int matrix[SIZE][SIZE]; // Definir la matriz
    crear_matriz_cuadrada(dimension, matrix);      //llamamos funcion para crear matriz

    int Resultado  = findLargestSquare(dimension, matrix); // creamos la variable Resultado
    printf("El tamaño del cuadrado más grande de unos es: %d\n", Resultado);

    return 0;
}
