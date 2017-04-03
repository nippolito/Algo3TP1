#include <iostream>
#include <vector>
#include "Backtrack.cpp"

int ColorearPodaAux(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint, std::vector<int>& sal){  // optimizar 
	if(cant == n){
		if(sinpintar < res){
			res = sinpintar;
		}
		return res;
	}
	if(ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0)){
		sal[cant] = 1;
		ColorearAux(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1, sal);
	}
	if(ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0)){
		sal[cant] = 2;	
		ColorearAux(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint, sal);
	}
	sal[cant] = 3;
	ColorearAux(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint, sal);
}

int ColorearPoda(std::vector<int>& ent, int n){
	std::vector<int> v(n);
	int res = ent.size();
	ColorearAux(ent, n, 0, 0, res, 0, 0, 0, 0, v);
	cout << res << endl;
	// mostrarVector(result);
	return res;
}



