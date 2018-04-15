#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BuscarMax(std::vector<std::vector<int> >& matriz, int n){
	int res = 0;
	for(int fila = 0; fila < n; fila++){			// recorre toda la matriz y se queda con el valor más alto
		for(int column = 0; column < n; column++){
			if(matriz[fila][column] > res){
				res = matriz[fila][column];
			}
		}
	}
	return res;
}

int MaxAntQuePuedeAzul(std::vector<int>& ent, std::vector<std::vector<int> >& matriz, int i, int j, int fila){
	int res = matriz[fila][i];			// fija el de la columna 0 como resultado
	for(int k = i + 1; k < j; k++){		// recorre la fila para encontrar al máximo (también se debe poder pintar)
		if(ent[j-1] < ent[k-1] && matriz[fila][k] > res){
			res = matriz[fila][k];
		}
	}
	return res;
}

int MaxAntQuePuedeRojo(std::vector<int>& ent, std::vector<std::vector<int> >& matriz, int i, int j, int columna){
	int res = matriz[i][columna];		// fija el de la fila 0 como resultado
	for(int k = i + 1; k < j; k++){		// recorre la columna para encontrar el máximo (también se debe poder pintar)
		if(ent[j-1] > ent[k-1] && matriz[k][columna] > res){
			res = matriz[k][columna];
		}
	}
	return res;
}

void Ej4Aux(std::vector<int>& ent, int n, std::vector<std::vector<int> >& matriz){
	for(int fila = 0; fila < n+1; fila++){
		for(int column = 0; column < n+1; column++){
			if(fila == column){				// si misma pos último rojo y último azul (no se puede)
				matriz[fila][column] = 0;
			}
			if(fila > column){				// si tengo que recorrer la columna
				matriz[fila][column] = MaxAntQuePuedeRojo(ent, matriz, 0, fila, column) + 1;
			}
			if(fila < column){				// si tengo que recorrer la fila
				matriz[fila][column] = MaxAntQuePuedeAzul(ent, matriz, 0, column, fila) + 1;
			}
		}
	}
}

int Ej4(std::vector<int>& ent, int n){
	std::vector<std::vector<int> > matriz(n+1, std::vector<int>(n+1, 0));
	Ej4Aux(ent, n, matriz);			// lleno la matriz
	int max = BuscarMax(matriz, n+1);		// tomo el máximo de la matriz
	int res = n - max;				// el resultado es #números - máximo
	return res;
}



int main(){
	int longitud;
	cout << "Inserte la longitud de la secuencia > ";
	cin >> longitud;
	vector<int> vec(longitud);
	int num;
	int i = 0;
	cout << "Inserte los números separados por un espacio > ";
	while(i < longitud){
		cin >> num;
		vec[i] = num;
		i++;
	}
	int t = Ej4(vec, longitud);
	cout << "La cantidad de no pintados es " << t << endl;
	return t;
}