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
	if(cant == 0 || MayQueAnterior(ent, cant, sal)){
		return true;
	}else{
		return false;
	}
}

bool PintaAzul(std::vector<int>& ent, int cant, std::vector<int>& sal){
	if(cant == 0 || MenQueAnterior(ent, cant, sal)){
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

void ColorearAux(std::vector<int>& ent, int n, int cant, std::vector<int>& sal){
	if(cant == n){
		mostrarVector(sal);
		int res = 0;
		for(int i = 0; i < sal.size(); i++){
			if(sal[i] == 3){
				res++;
			}
		}
		cout << res << endl;
		return;
	}
	for(int i = cant; i < n; i++){
		if(PintaRojo(ent, i, sal)){
			// std::vector<int> salc1 = sal;
			// salc1[i] = 1;
			sal[i] = 1;
			ColorearAux(ent, n, i+1, sal);
		}
		if(PintaAzul(ent, i, sal)){
			// std::vector<int> salc2 = sal;
			// salc2[i] = 2;
			sal[i] = 2;
			ColorearAux(ent, n, i+1, sal);
		}
		sal[i] = 3;
		ColorearAux(ent, n, i+1, sal);
	}
}

void Colorear(std::vector<int>& ent, int n){
	std::vector<int> vc(n);
	ColorearAux(ent, n, 0, vc);
	return;
}


int main(){
	std::vector<int> vec1(3);
	std::vector<int> vec2(3);
	vec1[0] = 3;
	vec1[1] = 0;
	vec1[2] = 2;
	Colorear(vec1, vec1.size());
	// ColorearAux(vec1, vec1.size(), 0, vec2);
	// std::vector<int> vec3(5);
	// std::vector<int> vec4(5);
	// vec3[0] = 7;
	// vec3[2] = 50;
	// vec3[1] = 1;
	// vec3[3] = 4;
	// vec3[4] = 5;
	// Colorear(vec3, vec3.size(), 0, vec4);
	// cout << PintaRojo(vec, 1, vec) << endl;
	// mostrarVector(vec);
	// for(int i = 0; i < 10; i++){
	// 	vec[i] = i;
	// 	cout << vec[i] << endl;
	// }
	// vec[0] = 3;
	// int array[5];
	// array[0] = 3;
	// cout << array[0] << endl;
	return 0;
}