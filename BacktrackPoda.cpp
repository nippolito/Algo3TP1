#include "Backtrack.cpp"


int ColorearPodaAuxConVec(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint, bool &hayRes, std::vector<int>& sal){
	if(cant == n){
		if(sinpintar < res){
			res = sinpintar;
			hayRes = true;
		}
		mostrarVector(sal);
		return res;
	}
	if((ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0)) && (sinpintar < res)){
		sal[cant] = 1;
		ColorearPodaAuxConVec(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1, hayRes, sal);
	}
	if((ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0)) && (sinpintar < res)){
		sal[cant] = 2;	
		ColorearPodaAuxConVec(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint, hayRes, sal);
	}
	if(!hayRes || (hayRes && (sinpintar + 1) < res)){
		sal[cant] = 3;
		ColorearPodaAuxConVec(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint, hayRes, sal);
	}
}

int ColorearPodaConVec(std::vector<int>& ent, int n){
	std::vector<int> v(n);
	int res = ent.size();
	bool hayRes = false;
	ColorearPodaAuxConVec(ent, n, 0, 0, res, 0, 0, 0, 0, hayRes, v);
	// cout << res << endl;
	// mostrarVector(result);
	return res;
}


int ColorearPodaAux(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint, bool &hayRes){
	if(cant == n){				// llegás a una hoja, hay que parar de recorrer
		if(sinpintar < res){		// si el resultado es mejor que el que ya tenías, vas a actualizarlo
			res = sinpintar;
			hayRes = true;
		}
		return res;
	}
	if((ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0)) && (sinpintar < res)){	// si el número se puede pintar de rojo y aparte esa solución te puede llevar a una mejor que la que ya hay, entonces seguí por la rama que corresponde a pintar a ese elemento de rojo
		ColorearPodaAux(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1, hayRes);
	}
	if((ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0)) && (sinpintar < res)){		// si el número se puede pintar de azul y aparte esa solución te puede llevar a una mejor que la que ya hay, entonces seguí por la rama que corresponde a pintar al elemento de azul
		ColorearPodaAux(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint, hayRes);
	}
	if(!hayRes || (hayRes && (sinpintar + 1) < res)){			// para seguir, o no se tiene que haber llegado a ninguna hoja todavía, o la rama que estás recorriendo tiene que poder superar el resultado que ya tenés
		ColorearPodaAux(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint, hayRes);			// avanza por la rama que corresponde a no pintar el elemento
	}
}

int ColorearPoda(std::vector<int>& ent, int n){
	int res = ent.size();
	bool hayRes = false;
	ColorearPodaAux(ent, n, 0, 0, res, 0, 0, 0, 0, hayRes);
	return res;
}



// int main(){
// 	std::vector<int> vec3(8);
// 	vec3[0] = 0;
// 	vec3[1] = 7;
// 	vec3[2] = 1;
// 	vec3[3] = 2;
// 	vec3[4] = 2;
// 	vec3[5] = 1;
// 	vec3[6] = 5;
// 	vec3[7] = 0;
// 	Colorear(vec3, vec3.size());
// 	cout << endl;
// 	ColorearPoda(vec3, vec3.size());
// 	return 0;
// }