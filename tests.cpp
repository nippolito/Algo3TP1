#include <assert.h>
#include "Backtrack.cpp"

void Ej1(){
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
	int c = Colorear(vec5, vec5.size());
	assert(c == 2);
	cout << "Ejemplo 2 de la practica pasado" << endl;
}

void Ej2(){
	std::vector<int> vec3(8);
	vec3[0] = 0;
	vec3[1] = 7;
	vec3[2] = 1;
	vec3[3] = 2;
	vec3[4] = 2;
	vec3[5] = 1;
	vec3[6] = 5;
	vec3[7] = 0;
	int c = Colorear(vec3, vec3.size());	
	assert(c == 0);
	cout << "Ejemplo 1 de la práctica pasado" << endl;
}

void MismoNum3Veces(){
	std::vector<int> vec6(3);
	vec6[0] = 3;
	vec6[1] = 3;
	vec6[2] = 3;
	int c = Colorear(vec6, vec6.size());
	assert(c == 1);
	cout << "Arreglo de long 3 con los 3 números igual funciona bien" << endl;
}





int main(){				// agregarle varios tests (ver cómo carajo se testeaba jaja, dos tests pueden ser los de la cátedra, otro todos los números iguales, etc...)
	Ej1();
	Ej2();
	MismoNum3Veces();
	return 0;
}