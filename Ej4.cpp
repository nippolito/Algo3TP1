#include "Ej3.cpp"

using namespace std;

void MostrarMatriz(std::vector<std::vector<int> >& matriz, int n){
	for(int fila = 0; fila < n; fila++){
		for(int column = 0; column < n; column++){
			if(column == 0){
				cout << "[" << matriz[fila][column];
			}else{
				if(column > 0 && column < n-1){
					cout << ", " << matriz[fila][column];
				}else{
					cout << ", " << matriz[fila][column] << "]" << endl;
				}
			}
		}
	}
}

int BuscarMax(std::vector<std::vector<int> >& matriz, int n){
	int res = 0;
	for(int fila = 0; fila < n; fila++){
		for(int column = 0; column < n; column++){
			if(matriz[fila][column] > res){
				res = matriz[fila][column];
			}
		}
	}
	return res;
}


int MaxAntQuePuedeAzul(std::vector<int>& ent, std::vector<std::vector<int> >& matriz, int i, int j, int fila){
	int res = matriz[fila][i];
	for(int k = i + 1; k < j; k++){
		if(ent[j-1] < ent[k-1] && matriz[fila][k] > res){
			res = matriz[fila][k];
		}
	}
	return res;
}

int MaxAntQuePuedeRojo(std::vector<int>& ent, std::vector<std::vector<int> >& matriz, int i, int j, int columna){
	int res = matriz[i][columna];
	for(int k = i + 1; k < j; k++){
		if(ent[j-1] > ent[k-1] && matriz[k][columna] > res){
			res = matriz[k][columna];
		}
	}
	return res;
}

void Ej4Aux(std::vector<int>& ent, int n, std::vector<std::vector<int> >& matriz){
	for(int fila = 0; fila < n+1; fila++){
		for(int column = 0; column < n+1; column++){
			if(fila == column){
				matriz[fila][column] = 0;
			}
			if(fila > column){
				matriz[fila][column] = MaxAntQuePuedeRojo(ent, matriz, 0, fila, column) + 1;
			}
			if(fila < column){
				matriz[fila][column] = MaxAntQuePuedeAzul(ent, matriz, 0, column, fila) + 1;
			}
		}
	}
}


int Ej4(std::vector<int>& ent, int n){
	std::vector<std::vector<int> > matriz(n+1, std::vector<int>(n+1, 0));
	cout << matriz[0].size() << endl;
	Ej4Aux(ent, n, matriz);
	MostrarMatriz(matriz, n+1);
	int max = BuscarMax(matriz, n+1);
	cout << max << endl;
	int res = n - max;
	cout << res << endl;
	return res;
}

// int main(){
// 	vector<int> vec(4);
// 	vec[0] = 100;
// 	vec[1] = 101;
// 	vec[2] = 102;
// 	vec[3] = 99;
// 	int t = ProgDinamBottomUp(vec, vec.size());
// 	cout << t << endl;
// }