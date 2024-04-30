int calc(int n){                                            //creamos la funcion calc donde tenemos la formula
    return (n * (n + 1)) / 2;
}

int main() {                                               //funcion main, donde se empiesa a ejecutar el codigo
    int n;
    
    printf("Los primeros 100 números triangulares son:\n");
    for (n = 1; n <= 100; n++) {                               //un for para hecer las reiteraciones de 1 a 100
        printf("%d ", calc(n));                                //vamos mostrando los numeros
    }
    
  printf("\n");                                              //imprimimos un espacio entre numeros
    
    return 0;                                                  //retorno exitoso
}
