#include <iostream>
#include <vector>
#include "Backtrack.cpp"

int ColorearPodaAux(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint, bool &hayRes, std::vector<int>& sal, int &i){  // optimizar 
	if(cant == n){
		if(sinpintar < res){
			res = sinpintar;
			hayRes = true;
		}
		mostrarVector(sal);
		i++;
		cout << i << endl;
		return res;
	}
	if(ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0) && (sinpintar < res)){
		sal[cant] = 1;
		ColorearPodaAux(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1, hayRes, sal, i);
	}
	if(ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0) && (sinpintar < res)){
		sal[cant] = 2;	
		ColorearPodaAux(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint, hayRes, sal, i);
	}
	if(!hayRes || (hayRes && (sinpintar + 1) < res)){
		sal[cant] = 3;
		ColorearPodaAux(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint, hayRes, sal, i);
	}
}

int ColorearPoda(std::vector<int>& ent, int n){
	std::vector<int> v(n);
	int res = ent.size();
	bool hayRes = false;
	int i = 0;
	ColorearPodaAux(ent, n, 0, 0, res, 0, 0, 0, 0, hayRes, v, i);
	cout << res << endl;
	// mostrarVector(result);
	return res;
}


int main(){
	std::vector<int> vec3(8);
	vec3[0] = 0;
	vec3[1] = 7;
	vec3[2] = 1;
	vec3[3] = 2;
	vec3[4] = 2;
	vec3[5] = 1;
	vec3[6] = 5;
	vec3[7] = 0;
	Colorear(vec3, vec3.size());
	cout << endl;
	ColorearPoda(vec3, vec3.size());
	return 0;
}


// ver cómo hacer para que me tome menos (o sea, que al encontrar un resultado con 0 deje de analizar. Se hace con un booleano y punto)