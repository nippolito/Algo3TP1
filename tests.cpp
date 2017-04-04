#include <assert.h>
#include <fstream>
#include <chrono>
#include <random>
#include "BacktrackPoda.cpp"

// g++ -std=c++11 -o name file.cpp

// std::milli - miloseconds, std::micro - microseconds, std::nano - nanoseconds

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

void MismoNumNVeces(int n){
	std::vector<int> vec(n);
	for(int i = 0; i < n; i++){
		vec[i] = 5;
	}
	int c = Colorear(vec, vec.size());
	assert(c == n-2);
	cout << "Arreglo de long " << n << " con los " << n << " números iguales funciona bien" << endl;
}

void Prueba(){			// 
	std::vector<int> vec(3);
	vec[0] = 3;
	vec[1] = 2;
	vec[2] = 7;
	Colorear(vec, vec.size());
}

void writeFile(){
	fstream e("ent.txt", ios::in | ios::out);
	for(int i = 0; i < 150; i++){
		e << 30 << endl;
		for(int j = 0; j < 30; j++){
			int v = rand() % 100000;				// v es un entero que está en el rango [0, 100000]
			if(j < 49){
				e << v << " ";
			}else{
				e << v << endl;
			}
		}	
	}
}

void muchasEntradasLong30(){
	writeFile();

	fstream e ("ent.txt", ios::in | ios::out);
	fstream s ("salidas.txt", ios::in | ios::out);

	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();

	for(int i = 0; i < 150; i++){
		int n;
		e >> n;
		std::vector<int> ent(n);
		int aux;
		for(int j = 0; j < n; j++){
			e >> aux;
			ent[j] = aux;
		}
		// mostrarVector(ent);
		int res = Colorear(ent, n);
		s << res << endl;
	}

	end = std::chrono::system_clock::now();

	std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
	// std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	// std::cout << "finished computation at " << std::ctime(&end_time) << endl;
	std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();

	cout << endl;

	fstream e2 ("ent.txt", ios::in | ios::out);
	fstream s2 ("salidasPoda.txt", ios::in | ios::out);

	std::chrono::time_point<std::chrono::system_clock> start2, end2;

	start2 = std::chrono::system_clock::now();

	for(int i = 0; i < 150; i++){
		int n;
		e2 >> n;
		std::vector<int> ent2(n);
		int aux;
		for(int j = 0; j < n; j++){
			e2 >> aux;
			ent2[j] = aux;
		}
		// mostrarVector(ent);
		int res = ColorearPoda(ent2, n);
		s2 << res << endl;
	}

	end2 = std::chrono::system_clock::now();

	std::chrono::duration<double, std::milli> elapsed_seconds2 = end2-start2;
	// std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	// std::cout << "finished computation at " << std::ctime(&end_time) << endl;
	std::cout << "Con poda tardó: " << elapsed_seconds2.count() << " ms" << endl;

	cout << endl;
	cout << "La diferencia es de: " << elapsed_seconds.count() / elapsed_seconds2.count() << " veces" << endl;

	e2.close();
	s2.close();
}



int main(){				// agregarle varios tests (ver cómo carajo se testeaba jaja, dos tests pueden ser los de la cátedra, otro todos los números iguales, etc...)
	// Ej1();
	// Ej2();
	// MismoNum3Veces();
	// MismoNumNVeces(4);
	// MismoNumNVeces(5);
	// MismoNumNVeces(6);
	// MismoNumNVeces(7);
	// MismoNumNVeces(12);
	// Prueba();
	muchasEntradasLong30();
	



	return 0;
}