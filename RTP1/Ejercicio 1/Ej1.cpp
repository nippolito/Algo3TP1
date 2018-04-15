#include <iostream>
#include <vector>

using namespace std;

int Ej1Aux(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint){ 
	if(cant == n){		// llego a una hoja
		if(sinpintar < res){		// si la cantidad de sinpintar es menor que el mejor resultado que ya tengo, entonces lo actualizo
			res = sinpintar;
		}
		return res;
	}
	if(ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0)){	// si el número puede pintarse de rojo, entonces sigo por la rama que corresponde a pintar al elemento de rojo
		Ej1Aux(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1);
	}
	if(ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0)){	// si el número puede pintarse de azul, entonces sigo por la rama que corresponde a pintar al elemento de azul
		Ej1Aux(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint);
	}
	Ej1Aux(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint);
}

int Ej1(std::vector<int>& ent, int n){
	int res = ent.size();
	Ej1Aux(ent, n, 0, 0, res, 0, 0, 0, 0);
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
	int t = Ej1(vec, longitud);
	cout << "La cantidad de no pintados es " << t << endl;
	return t;
}