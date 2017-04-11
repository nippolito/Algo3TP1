#include <assert.h>
#include <fstream>
#include <chrono>
#include <random>
#include "ProgDinam.cpp"

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
	int c = MinSinPintarProgDinam(vec5, vec5.size());
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
	int c = MinSinPintarProgDinam(vec3, vec3.size());	
	assert(c == 0);
	cout << "Ejemplo 1 de la práctica pasado" << endl;
}

void MismoNum3Veces(){
	std::vector<int> vec6(3);
	vec6[0] = 3;
	vec6[1] = 3;
	vec6[2] = 3;
	int c = MinSinPintarProgDinam(vec6, vec6.size());
	assert(c == 1);
	cout << "Arreglo de long 3 con los 3 números igual funciona bien" << endl;
}

void MismoNumNVeces(int n){
	std::vector<int> vec(n);
	for(int i = 0; i < n; i++){
		vec[i] = 5;
	}
	int c = MinSinPintarProgDinam(vec, vec.size());
	assert(c == n-2);
	cout << "Arreglo de long " << n << " con los " << n << " números iguales funciona bien" << endl;
}

void Prueba(){			// 
	std::vector<int> vec(3);
	vec[0] = 3;
	vec[1] = 2;
	vec[2] = 7;
	MinSinPintarProgDinam(vec, vec.size());
}

void Prueba1(){			// 
	std::vector<int> vec(4);
	vec[0] = 3;
	vec[1] = 2;
	vec[2] = 7;
	vec[3] = 9;
	MinSinPintarProgDinam(vec, vec.size());
}

void Prueba2(){			// 
	std::vector<int> vec(6);
	vec[0] = 3;
	vec[1] = 2;
	vec[2] = 7;
	vec[3] = 6;
	vec[4] = 8;
	vec[5] = 11;
	// vec[6] = 4;
	MinSinPintarProgDinam(vec, vec.size());
}

void MaxMinMaxMin(){				// agregar a Tests algunos de estos
	std::vector<int> vec4(6);
	vec4[0] = 200;
	vec4[1] = 150;
	vec4[2] = 199;
	vec4[3] = 151;
	vec4[4] = 198;
	vec4[5] = 152;

	ColorearPodaConVec(vec4, vec4.size());
	cout << endl;
	std::vector<int> vec5(12);
	vec5[0] = 200;
	vec5[1] = 150;
	vec5[2] = 199;
	vec5[3] = 151;
	vec5[4] = 198;
	vec5[5] = 152;
	vec5[6] = 197;
	vec5[7] = 153;
	vec5[8] = 196;
	vec5[9] = 154;
	vec5[10] = 195;
	vec5[11] = 155;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	ColorearPodaConVec(vec5, vec5.size());
	end = std::chrono::system_clock::now();

	std::chrono::duration<double, std::milli> elapsed_seconds = end-start;

	cout << elapsed_seconds.count() << endl;

}

void writeFile(){										// este test genera para todo n entre 1 y 100, un total de 80 casos aleatorios de longitud n + 10 ordenados crec + 10 ordenados decrec
	fstream e("ent.txt", ios::out);
	for(int n = 1; n < 101; n++){						// genera 80 casos para n entre 1 y 25 random
		for(int i = 0; i < 80; i++){					// genera los 80 casos de cada n al azar
			e << n << endl;
			for(int j = 0; j < n; j++){
				int v = rand() % 100000;				// v es un entero que está en el rango [0, 100000]
				if(j < (n-1)){
					e << v << " ";
				}else{
					e << v << endl;
				}
			}	
		}
	}

	for(int y = 1; y < 101; y++){					// genera 10 casos para n entre 1 y 25, ordenados creciente
		int prim = 0;
		for(int h = 0; h < 10; h++){
			e << y << endl;
			for(int z = prim; z < y + prim; z++){
				if(z < (y - 1 + prim)){
					e << z << " ";
				}else{
					e << z << endl;
				}
			}
			prim = prim + 100;
		}
	}

	for(int y = 1; y < 101; y++){					// genera 10 casos para n entre 1 y 25, ordenados decreciente
		int prim = 9;
		for(int h = 0; h < 10; h++){
			e << y << endl;
			for(int z = prim; z > prim - y; z--){
				if(z > (prim - y + 1)){
					e << z << " ";
				}else{
					e << z << endl;
				}
			}
			prim = prim + 100;
		}
	}

	e.close();										
}

void writeFileParaCorrec(){
	fstream e("entCorrec.txt", ios::out);
	for(int n = 1; n < 31; n++){						// genera 10 casos para n entre y 31 random
		for(int i = 0; i < 10; i++){					// genera los 40 casos de cada n al azar
			e << n << endl;
			for(int j = 0; j < n; j++){
				int v = rand() % 100000;				// v es un entero que está en el rango [0, 100000]
				if(j < (n-1)){
					e << v << " ";
				}else{
					e << v << endl;
				}
			}	
		}
	}
	e.close();
}

void expParaCorrec(){					// debes correr este algoritmo y chequear si son iguales salidasSinPoda y salidasPoda y salidasDinam ---- OK
	writeFileParaCorrec();

	fstream e ("entCorrec.txt", ios::in | ios::out);
	fstream s ("salidasSinPoda.txt", ios::out);

	for(int i = 0; i < (10 * 30); i++){
		int n;
		e >> n;
		std::vector<int> ent(n);
		int aux;
		for(int j = 0; j < n; j++){
			e >> aux;
			ent[j] = aux;
		}
		int res = Colorear(ent, n);
		s << res << endl;
	}

	e.close();
	s.close();

	fstream e2 ("entCorrec.txt", ios::in | ios::out);
	fstream s2 ("salidasPoda.txt", ios::out);

	for(int i = 0; i < (10 * 30); i++){
		int n;
		e2 >> n;
		std::vector<int> ent2(n);
		int aux;
		for(int j = 0; j < n; j++){
			e2 >> aux;
			ent2[j] = aux;
		}
		int res = ColorearPoda(ent2, n);
		s2 << res << endl;
	}

	e2.close();
	s2.close();

	fstream e3 ("entCorrec.txt", ios::in | ios::out);
	fstream s3 ("salidasDinamica.txt", ios::out);

	for(int i = 0; i < (10 * 30); i++){
		int n;
		e3 >> n;
		std::vector<int> ent3(n);
		int aux;
		for(int j = 0; j < n; j++){
			e3 >> aux;
			ent3[j] = aux;
		}
		int res = MinSinPintarProgDinam(ent3, n);
		s3 << res << endl;
	}

	e3.close();
	s3.close();


}

void expSinPodaParaTiempo(){
	writeFile();

	fstream e ("ent.txt", ios::in | ios::out);
	fstream s ("salidasSinPodaTiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (25 * 80) + (25 * 10 * 2); i++){
		int n;
		e >> n;
		s << n;
		s << ",";
		std::vector<int> ent(n);
		int aux;
		for(int j = 0; j < n; j++){
			e >> aux;
			ent[j] = aux;
		}
		start = std::chrono::system_clock::now();
		Colorear(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 25*80){
			s << "Random" << endl;
		}else{
			if(i >= 25*80 && i < (25*80 + 25*10)){
				s << "Creciente" << endl;
			}else{
				s << "Decreciente" << endl;
			}
		}

	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();	
}

void expConPodaParaTiempo(){			// estoy corriendo primero el SinPoda para que me genere el archivo aleatorio y probar con los dos el mismo archivo
	fstream e ("ent.txt", ios::in | ios::out);
	fstream s ("salidasConPodaTiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (40 * 40 + 40 * 10 + 40 * 10); i++){
		int n;
		e >> n;
		s << n;
		s << ",";
		std::vector<int> ent(n);
		int aux;
		for(int j = 0; j < n; j++){
			e >> aux;
			ent[j] = aux;
		}
		start = std::chrono::system_clock::now();
		ColorearPoda(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 40*40){
			s << "Random" << endl;
		}else{
			if(i >= 40*40 && i < (40*40 + 40*10)){
				s << "Creciente" << endl;
			}else{
				s << "Decreciente" << endl;
			}
		}
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();
}

void expDinamicaParaTiempo(){
	writeFile();

	fstream e ("ent.txt", ios::in | ios::out);
	fstream s ("salidasDinamicaTiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (100 * 80 + 100 * 10 + 100 * 10); i++){
		int n;
		e >> n;
		s << n;
		s << ",";
		std::vector<int> ent(n);
		int aux;
		for(int j = 0; j < n; j++){
			e >> aux;
			ent[j] = aux;
		}
		start = std::chrono::system_clock::now();
		MinSinPintarProgDinam(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 100*80){
			s << "Random" << endl;
		}else{
			if(i >= 100*80 && i < (100*10 + 100*10)){
				s << "Creciente" << endl;
			}else{
				s << "Decreciente" << endl;
			}
		}
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();
}

void correrTestsPracticaBacktrackConPoda(){			// salvo los de entrada 200, son todos correctos.
	std::chrono::time_point<std::chrono::system_clock> start, end;

	fstream s ("salidasTestsCatedra.txt", ios::out);
	for(int i = 1; i < 15; i++){
		string st = "t" + std::to_string(i);
		if(st != "t4"){
			fstream e (st, ios::in);
			int n;
			e >> n;
			std::vector<int> ent(n);
			int aux;
			for(int j = 0; j < n; j++){
				e >> aux;
				ent[j] = aux;
			}
			start = std::chrono::system_clock::now();
			int res = ColorearPoda(ent, n);
			end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
			s << res;
			s << ",";
			s << elapsed_seconds.count() << endl;
		}
	}
}

void correrTestsPracticaBacktrackSinPoda(){			// salvo los de entrada 200, son todos correctos.
	std::chrono::time_point<std::chrono::system_clock> start, end;

	fstream s ("salidasTestsCatedraSinPoda.txt", ios::out);
	for(int i = 1; i < 15; i++){
		string st = "t" + std::to_string(i);
		if(st != "t4"){
			fstream e (st, ios::in);
			int n;
			e >> n;
			std::vector<int> ent(n);
			int aux;
			for(int j = 0; j < n; j++){
				e >> aux;
				ent[j] = aux;
			}
			start = std::chrono::system_clock::now();
			int res = Colorear(ent, n);
			end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
			s << res;
			s << ",";
			s << elapsed_seconds.count() << endl;
		}
	}
}

void correrTestsPracticaDinamica(){				// son todos correctos
	std::chrono::time_point<std::chrono::system_clock> start, end;

	fstream s ("salidasTestsCatedraDinamica.txt", ios::out);
	for(int i = 1; i < 21; i++){
		string st = "t" + std::to_string(i);
		fstream e (st, ios::in);
		int n;
		e >> n;
		std::vector<int> ent(n);
		int aux;
		for(int j = 0; j < n; j++){
			e >> aux;
			ent[j] = aux;
		}
		start = std::chrono::system_clock::now();
		int res = MinSinPintarProgDinam(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
		s << res;
		s << ",";
		s << elapsed_seconds.count() << endl;
	}	
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
	// expParaCorrec();
	// correrTestsPracticaDinamica();
	expDinamicaParaTiempo();
	// Prueba();
	// Prueba1();
	// Prueba2();
	// expSinPodaParaTiempo();
	// expConPodaParaTiempo();
	// MaxMinMaxMin();
	// correrTestsPracticaBacktrackSinPoda();
	



	return 0;
}