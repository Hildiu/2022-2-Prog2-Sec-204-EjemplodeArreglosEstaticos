/*-------------------------------------------------------------------------------
 * Realice un programa que permita almacenar 50 numeros generados al alzar en un
 * arreglo estatico, los imprima y luego el programa:
 * 1. Imprima los numeros que estan por encima del promedio
 * 2. Halle el dato mayor
 * 3. Halle la cantidad de numeros pares y la cantidad de numero impares
 ---------------------------------------------------------------------------------*/

#include <iostream>
using namespace  std;

float calcularPromedio( int  *pI, int ne );
int  hallarElMayor( int *pA, int ne);
void contar( int  *pI,  int  ne,  int  *pPares,  int  *pImpares);


int main()
{  int   arreglo[50];
    int nPares=0, nImpares=0;

    /*** ahora generamos los numeros al azar  y los guardamos en el arreglo*/
    srand(time(nullptr));
    for(int i=0; i<50; i++)
        arreglo[i] = rand() %100; //   6565454345
    /* recorro el arreglo e imprimo los datos*/
    for(int i=0; i<50; i++)
        cout << "arreglo[" << i << "]= " << arreglo[i] << "\n";
    float promedio = calcularPromedio(arreglo, 50);
    cout << "El promedio es: "<< promedio << "\n";
    for(int i=0; i<50; i ++)
        if( arreglo[i] >promedio)
            cout << arreglo[i] << "\n";
    /*2. ahora hallamos el dato mayor */
    int elMayor =  hallarElMayor(arreglo, 50);
    cout << "El dato mayor de arreglo es: " << elMayor << "\n";
    /*3. hallar la cantidad de numeros que son pares, y la cantidad que son impares*/

    contar(arreglo, 50, &nPares, &nImpares);
    cout << "Numeros pares : " << nPares << "\n";
    cout << "Numeros impares : " << nImpares << "\n";
    return 0;
}

void contar( int  *pI,  int  ne,  int  *pPares,  int  *pImpares)
{
   for(int i=0; i<ne; i++)
       if (pI[i] % 2 ==0)
           *pPares = *pPares + 1;
       else
           *pImpares = *pImpares + 1;
}


float calcularPromedio( int  *pI, int ne )
{
  float suma = 0;
  for(int x=0; x<ne; x++)
      suma = suma + pI[x];
  return (suma/ne);
}


int  hallarElMayor( int *pA, int ne)
{
  int elMayor = pA[0];
  for(int i=1; i<50; i++)
      if(pA[i]> elMayor)
          elMayor = pA[i];
  return elMayor;
}