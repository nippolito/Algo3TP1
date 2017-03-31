//g++ -o asd.exe Backtrack.cpp
// ./asd.exe

#include <iostream>
#include <vector>

using namespace std;

bool MayQueAnterior(std::vector<int>& ent, int cant, std::vector<int>& sal){
	bool flag = true;
	int i = cant;
	while(i != 0 && flag){
		i--;
		if(sal[i] == 1){
			flag = false;
		}
	}
	if(flag || ent[i] < ent[cant]){
		return true;
	}else{
		return false;
	}
}

bool MenQueAnterior(std::vector<int>& ent, int cant, std::vector<int>& sal){
	bool flag = true;
	int i = cant;
	while(i != 0 && flag){
		i--;
		if(sal[i] == 2){
			flag = false;
		}
	}
	if(flag || ent[i] > ent[cant]){
		return true;
	}else{
		return false;
	}	
}

bool PintaRojo(std::vector<int>& ent, int cant, std::vector<int>& sal){
	if(MayQueAnterior(ent, cant, sal)){
		return true;
	}else{
		return false;
	}
}

bool PintaAzul(std::vector<int>& ent, int cant, std::vector<int>& sal){
	if(MenQueAnterior(ent, cant, sal)){
		return true;
	}else{
		return false;
	}
}

void mostrarVector(std::vector<int>& vec){
	cout << "[";
	for(int i = 0; i < vec.size() - 1; i++){
		cout << vec[i] << ", ";
	}
	cout << vec[vec.size() - 1] << "]" << endl;
}

int minDeVector(std::vector<int>& vec){
	int min = vec[0];
	for(int i = 1; i < vec.size(); i++){
		if(vec[i] < min){
			min = vec[i];
		}
	}
	return min;
}

void ColorearAux(std::vector<int>& ent, int n, int cant, std::vector<int>& sal, std::vector<int>& res){  // optimizar 
	if(cant == n){
		int sincolorear = 0;
		for(int i = 0; i < sal.size(); i++){
			if(sal[i] == 3){
				sincolorear++;
			}
		}
		res.push_back(sincolorear);
		return;
	}
		if(PintaRojo(ent, cant, sal)){
			sal[cant] = 1;
			ColorearAux(ent, n, cant+1, sal, res);
		}
		if(PintaAzul(ent, cant, sal)){
			sal[cant] = 2;
			ColorearAux(ent, n, cant+1, sal, res);
		}
		sal[cant] = 3;
		ColorearAux(ent, n, cant+1, sal,res);
}

int Colorear(std::vector<int>& ent, int n){
	std::vector<int> vc(n);
	std::vector<int> result(0);
	ColorearAux(ent, n, 0, vc, result);
	// mostrarVector(result);
	return minDeVector(result);
}


// void ColorearAux(std::vector<int>& ent, int n, int cant, std::vector<int>& sal){
// 	if(cant == n){
// 		mostrarVector(sal);
// 		int res = 0;
// 		for(int i = 0; i < sal.size(); i++){
// 			if(sal[i] == 3){
// 				res++;
// 			}
// 		}
// 		cout << res << endl;
// 		return;
// 	}
// 	for(int i = cant; i < n; i++){
// 		if(PintaRojo(ent, i, sal)){
// 			// std::vector<int> salc1 = sal;
// 			// salc1[i] = 1;
// 			sal[i] = 1;
// 			ColorearAux(ent, n, i+1, sal);
// 		}
// 		if(PintaAzul(ent, i, sal)){
// 			// std::vector<int> salc2 = sal;
// 			// salc2[i] = 2;
// 			sal[i] = 2;
// 			ColorearAux(ent, n, i+1, sal);
// 		}
// 		sal[i] = 3;
// 		ColorearAux(ent, n, i+1, sal);
// 	}
// }

// void Colorear(std::vector<int>& ent, int n){
// 	std::vector<int> vc(n);
// 	ColorearAux(ent, n, 0, vc);
// 	return;
// }