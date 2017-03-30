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

void ColorearAux(std::vector<int>& ent, int n, int cant, std::vector<int>& sal, std::vector<int>& res){
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
	for(int i = cant; i < n; i++){
		if(PintaRojo(ent, i, sal)){
			sal[i] = 1;
			ColorearAux(ent, n, i+1, sal, res);
		}
		if(PintaAzul(ent, i, sal)){
			sal[i] = 2;
			ColorearAux(ent, n, i+1, sal,res);
		}
		sal[i] = 3;
		ColorearAux(ent, n, i+1, sal,res);
	}
}

int Colorear(std::vector<int>& ent, int n){
	std::vector<int> vc(n);
	std::vector<int> result(0);
	ColorearAux(ent, n, 0, vc, result);
	//mostrarVector(result);
	return minDeVector(result);
}


int main(){				// agregarle varios tests (ver cómo carajo se testeaba jaja, dos tests pueden ser los de la cátedra, otro todos los números iguales, etc...)
	// std::vector<int> vec1(3);
	// std::vector<int> vec2(3);
	// vec1[0] = 3;
	// vec1[1] = 0;
	// vec1[2] = 2;
	// std::vector<int> vec3(8);
	// std::vector<int> vec4(8);
	// vec3[0] = 0;
	// vec3[1] = 7;
	// vec3[2] = 1;
	// vec3[3] = 2;
	// vec3[4] = 2;
	// vec3[5] = 1;
	// vec3[6] = 5;
	// vec3[7] = 0;
	std::vector<int> vec5(12);
	vec5[0] = 3;
	vec5[1] = 11;
	vec5[2] = 0;
	vec5[3] = 1;
	vec5[4] = 3;
	vec5[5] = 5;
	vec5[6] = 2;
	vec5[7] = 4;
	vec5[8] = 1;
	vec5[9] = 0;
	vec5[10] = 9;
	vec5[11] = 3;
	// std::vector<int> vec6(3);
	// vec6[0] = 3;
	// vec6[1] = 3;
	// vec6[2] = 3;
	//return Colorear(vec3, vec3.size());
	int c = Colorear(vec5, vec5.size());		// devolvió 2, lo que tiene que devolver. El tema es que la consola no me lo devuelve cuando pongo return... pero por ahí no importa
	cout << c << endl;
	return c;

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
}