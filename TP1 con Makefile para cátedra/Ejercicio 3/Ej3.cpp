#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
	int t = Ej3(vec, longitud);
	cout << "La cantidad de no pintados es " << t << endl;
	return t;
}