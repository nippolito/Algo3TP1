#include "Ej2.cpp"
#include <algorithm>

using namespace std;

// int MinSinPintarProgDinamAux(std::vector<int>& ent, std::vector<std::vector<std::vector<int> > >& cubo, int i, int n, int ultRo, int ultAz){
// 	if(i == -1){
// 		return 0;
// 	}
// 	// cout << "asd" << endl;
// 	if(cubo[i][ultRo][ultAz] != 10000){
// 		cout << "1" << endl;
// 		jk++;
// 		return cubo[i][ultRo][ultAz];
// 	}
// 	if((ultRo > n-1 && ultAz > n-1) || (ent[i] < ent[ultRo] && ent[i] > ent[ultAz])){
// 		cout << "2" << endl;
// 		jk++;
// 		cubo[i][ultRo][ultAz] = min({MinSinPintarProgDinamAux(ent, cubo, i-1, n, i, ultAz), MinSinPintarProgDinamAux(ent, cubo, i-1, n, ultRo, i), MinSinPintarProgDinamAux(ent, cubo, i-1, n, ultRo, ultAz) + 1});
// 		// cout << "ultRojo: " << ultRo << endl;
// 		// cout << "ultAzul: " << ultAz << endl;
// 		// cout << "i es: " << i << endl;
// 		// cout << cubo[i][ultRo][ultAz] << endl;
// 	}
// 	if((ultRo > n-1 || ent[i] < ent[ultRo]) && (ultAz <= n-1 && ent[i] <= ent[ultAz])){
// 		cout << "3" << endl;
// 		jk++;
// 		cubo[i][ultRo][ultAz] = min(MinSinPintarProgDinamAux(ent, cubo, i-1, n, i, ultAz), MinSinPintarProgDinamAux(ent, cubo, i-1, n, ultRo, ultAz) + 1);
// 		// cout << "asd" << endl;
// 	}
// 	if((ultAz > n-1 || ent[i] > ent[ultAz]) && (ultRo <= n-1 && ent[i] >= ent[ultRo])){
// 		cout << "4" << endl;
// 		jk++;
// 		cubo[i][ultRo][ultAz] = min(MinSinPintarProgDinamAux(ent, cubo, i-1, n, ultRo, i), MinSinPintarProgDinamAux(ent, cubo, i-1, n, ultRo, ultAz) + 1);
// 		// cout << "asdf" << endl;
// 	}
// 	if((ultRo <= n-1 && ultAz <= n-1) && ent[i] >= ent[ultRo] && ent[i] <= ent[ultAz]){
// 		cout << "5" << endl;
// 		jk++;
// 		cubo[i][ultRo][ultAz] = MinSinPintarProgDinamAux(ent, cubo, i-1, n, ultRo, ultAz) + 1;
// 		// cout << "asdfg" << endl;
// 	}
// 	cout << jk << endl;
// 	return cubo[i][ultRo][ultAz];
// }


int Ej3Aux(std::vector<int>& ent, std::vector<std::vector<std::vector<int> > >& cubo, int i, int n, int ultRo, int ultAz){
	int c = 0;
	int v = 0;
	int b = 0;
	if(i == -1){
		return 0;
	}
	if(cubo[i][ultRo][ultAz] != -1){			// si ya lo calculé, entonces lo devuelvo
		return cubo[i][ultRo][ultAz];
	}
	if(ultRo > n-1 || (ent[i] < ent[ultRo])){		// si se puede pintar de rojo, calculo el mínimo pintando ese de rojo
		c = Ej3Aux(ent, cubo, i-1, n, i, ultAz);
	}
	if(ultAz > n-1 || ent[i] > ent[ultAz]){			// si se puede pintar de azul, calculo el mínimo pintándolo de azul
		v = Ej3Aux(ent, cubo, i-1, n, ultRo, i);
	}
	b = Ej3Aux(ent, cubo, i-1, n, ultRo, ultAz) + 1;		// calculo el mínimo no pintándolo
	if((ultRo > n-1 || (ent[i] < ent[ultRo])) && (ultAz > n-1 || ent[i] > ent[ultAz])){			// si se podía pintar de rojo y de azul, entonces debo tomar el mínimo de las 3 posibilidades
		cubo[i][ultRo][ultAz] = min({c, b, v});
	}else{
		if((ultRo > n-1 || (ent[i] < ent[ultRo])) && !(ultAz > n-1 || ent[i] > ent[ultAz])){		// si se podía pintar de rojo pero no de azul, entonces debo tomar el mínimo entre pintarlo de rojo y no pintarlo
			cubo[i][ultRo][ultAz] = min(c, b);
		}else{
			if(!(ultRo > n-1 || (ent[i] < ent[ultRo])) && (ultAz > n-1 || ent[i] > ent[ultAz])){	// si se podía pintar de azul pero no de rojo, entonces debo tomar el mínimo entre pintarlo de azul y no pintarlo
				cubo[i][ultRo][ultAz] = min(v, b);
			}else{
				cubo[i][ultRo][ultAz] = b;						// si no se podía pintar de nada, devuelvo el mínimo de no pintarlo
			}
		}
	}
	return cubo[i][ultRo][ultAz];
}


int Ej3(std::vector<int>& ent, int n){
	std::vector<std::vector<std::vector<int> > > cube(n, std::vector<std::vector<int> > (n+1, std::vector<int>(n+1, -1))); // inicializa el cubo con todos sus elems en -1
	int r = n;
	int a = n;
	int res = Ej3Aux(ent, cube, n-1, n, r, a);
	// cout << res << endl;
	return res;
}





// int main(){
// 	std::vector<int> vec(3);
// 	vec[0] = 3;
// 	vec[1] = 2;
// 	vec[2] = 7;	
// 	MinSinPintarProgDinam(vec, vec.size());
// 	return 0;
// }