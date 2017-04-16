#include <assert.h>
#include <fstream>
#include <chrono>
#include <random>
#include "../Ej4.cpp"

// g++ -std=c++11 -o name file.cpp

// std::milli - miloseconds, std::micro - microseconds, std::nano - nanoseconds

// Demostrar que los dos cumplen principio de optimalidad, agregar árbol en el de dinámica para demostrar que hay subproblemas iguales
// Hacer todo del Ej4
// Fijarse peores y mejores casos de todos los ejercicios (peor caso punto 2 y 3, mejores casos en esos dos ya los tengo)
// Hacer Makefile

void Ejemplo1(){
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
	int c = Ej4(vec5, vec5.size());
	assert(c == 2);
	cout << "Ejemplo 2 de la practica pasado" << endl;
}

void Ejemplo2(){
	std::vector<int> vec3(8);
	vec3[0] = 0;
	vec3[1] = 7;
	vec3[2] = 1;
	vec3[3] = 2;
	vec3[4] = 2;
	vec3[5] = 1;
	vec3[6] = 5;
	vec3[7] = 0;
	int c = Ej4(vec3, vec3.size());	
	assert(c == 0);
	cout << "Ejemplo 1 de la práctica pasado" << endl;
}

void MismoNum3Veces(){
	std::vector<int> vec6(3);
	vec6[0] = 3;
	vec6[1] = 3;
	vec6[2] = 3;
	int c = Ej3(vec6, vec6.size());
	assert(c == 1);
	cout << "Arreglo de long 3 con los 3 números igual funciona bien" << endl;
}

void MismoNumNVeces(int n){
	std::vector<int> vec(n);
	for(int i = 0; i < n; i++){
		vec[i] = 5;
	}
	int c = Ej3(vec, vec.size());
	assert(c == n-2);
	cout << "Arreglo de long " << n << " con los " << n << " números iguales funciona bien" << endl;
}

void MismoNumTiemposPodavsSinPoda(){		// compara el poda y sin poda con entrada de longitud 15, todos iguales
	std::vector<int> vec(50);
	for(int i = 0; i < 50; i++){
		vec[i] = 10;
	}

	std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;

	start1 = std::chrono::system_clock::now();
	Ej1(vec, vec.size());
	end1 = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> elapsed_seconds = end1-start1;
	cout << elapsed_seconds.count() << endl;


	start2 = std::chrono::system_clock::now();
	Ej2(vec, vec.size());
	end2 = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> elapsed_seconds2 = end2-start2;
	cout << elapsed_seconds2.count() << endl;

	cout << "La diferencia es de: > " << elapsed_seconds / elapsed_seconds2 << endl;
}

void Prueba(){			// 
	std::vector<int> vec(3);
	vec[0] = 3;
	vec[1] = 2;
	vec[2] = 7;
	Ej3(vec, vec.size());
}

void Prueba1(){			// 
	std::vector<int> vec(4);
	vec[0] = 3;
	vec[1] = 2;
	vec[2] = 7;
	vec[3] = 9;
	Ej3(vec, vec.size());
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
	Ej3(vec, vec.size());
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

void writeFileEj3(){										// este test genera para todo n entre 1 y 100, un total de 80 casos aleatorios de longitud n + 10 ordenados crec + 10 ordenados decrec
	fstream e("TestDinam.txt", ios::out);
	for(int n = 1; n < 301; n++){						// genera 50 casos para n entre 1 y 200 random
		for(int i = 0; i < 50; i++){					// genera los 80 casos de cada n al azar
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

	for(int y = 1; y < 301; y++){					// genera 10 casos para n entre 1 y 200, ordenados creciente
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

	for(int y = 1; y < 301; y++){					// genera 10 casos para n entre 1 y 200, ordenados decreciente
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

	for(int y = 1; y < 301; y++){					// genera 10 casos para n entre 1 y 200, MayMenMayMen
		int prim = 500;
		for(int h = 0; h < 10; h++){
			e << y << endl;
			int i = 1;
			int t = prim;
			int num = 0;
			for(int z = prim; z < prim + y; z++){
				if(z < (prim + y - 1)){
					if(t % 2 == 0){
						num = prim + i;
					}else{
						num = prim - i;
					}
					e << num << " ";
				}else{
					if(t % 2 == 0){
						num = prim + i;
					}else{
						num = prim - i;
					}
					e << num << endl;
				}
				i++;
				t++;
			}
			prim = prim + 50;
		}
	}

	for(int y = 1; y < 301; y++){				// genera 10 casos para n entre 1 y 200 con números todos iguales
		for(int h = 0; h < 10; h++){
			e << y << endl;
			for(int z = 0; z < y; z++){
				if(z < y - 1){
					e << y << " ";
				}else{
					e << y << endl;
				}	
			}
		}
	}

	for(int y = 1; y < 301; y++){				// genera 10 casos para n entre 1 y 200 con números todos iguales
		int pr = 1;
		for(int h = 0; h < 10; h++){
			e << y << endl;
			int a = pr;
			int b = pr;
			for(int z = 0; z < y; z++){
				if(z % 2 != 0 && (z != 0)){
					b = a;
					a = b + 3;
				}else{
					b = a;
					a = b - 1;
				}
				if(z < y - 1){
					e << a << " ";
				}else{
					e << a << endl;
				}	
			}
		}
	}

	e.close();										
}

void writeFilePeorCasoDinam(int n){
	fstream e("EntradasPeorCasoDinam.csv", ios::out);
	for(int y = 1; y < n+1; y++){				// genera 10 casos para n entre 1 y n con números todos iguales
		int pr = 1;
		for(int h = 0; h < 10; h++){
			e << y << endl;
			int a = pr;
			int b = pr;
			e << a << " ";
			for(int z = 1; z < y; z++){
				if(z % 2 != 0){
					b = a;
					a = b + 3;
				}else{
					b = a;
					a = b - 1;
				}
				if(z < y - 1){
					e << a << " ";
				}else{
					e << a << endl;
				}	
			}
			pr++;
		}
	}
	e.close();
}

void writeFileEj1(){
	fstream e("TestSinPoda.txt", ios::out);
	for(int n = 1; n < 37; n++){						// genera 40 casos para n entre 1 y 36 random
		for(int i = 0; i < 40; i++){
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

	for(int y = 1; y < 28; y++){					// genera 10 casos para n entre 1 y 27, ordenados creciente
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

	for(int y = 1; y < 28; y++){					// genera 10 casos para n entre 1 y 27, ordenados decreciente
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

	for(int y = 1; y < 37; y++){					// genera 10 casos para n entre 1 y 36 de números iguales
		for(int h = 0; h < 10; h++){
			e << y << endl;
			for(int z = 0; z < y; z++){
				if(z < y - 1){
					e << y << " ";
				}else{
					e << y << endl;
				}	
			}
		}
	}

	e.close();										
}

void writeFileEj2(){
	fstream e("TestConPoda.txt", ios::out);
	for(int n = 1; n < 51; n++){						// genera 40 casos para n entre 1 y 46 random (en intervalos de 5)
		for(int i = 0; i < 40; i++){
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

	for(int y = 1; y < 51; y++){					// genera 10 casos para n entre 1 y 50, ordenados creciente (en intervalos de 5)
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

	for(int y = 1; y < 51; y++){					// genera 10 casos para n entre 1 y 50, ordenados decreciente (en intervalos de 5)
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

	for(int y = 1; y < 51; y++){				// genera 10 casos para n entre 1 y 50 con números todos iguales
		for(int h = 0; h < 10; h++){
			e << y << endl;
			for(int z = 0; z < y; z++){
				if(z < y - 1){
					e << y << " ";
				}else{
					e << y << endl;
				}	
			}
		}
	}

	e.close();										
}

void writeFileEj2Random(){
	fstream e("PodaRandom.txt", ios::out);
	for(int n = 1; n < 71; n++){						// genera 40 casos para n entre 1 y 70 random (en intervalos de 5)
		for(int i = 0; i < 40; i++){
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

void expTiempoEj2Random(){
	writeFileEj2Random();
	fstream e ("PodaRandom.txt", ios::in | ios::out);
	fstream s ("PodaRandomSalidasTiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (70 * 40); i++){
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
		Ej2(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		s << "Random" << endl;
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();
}

void writeFileParaCorrec(){
	fstream e("entCorrec.txt", ios::out);
	for(int n = 1; n < 31; n++){						// genera 10 casos para n entre y 31 random
		for(int i = 0; i < 10; i++){					// genera los 10 casos de cada n al azar
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
		int res = Ej1(ent, n);
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
		int res = Ej2(ent2, n);
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
		int res = Ej3(ent3, n);
		s3 << res << endl;
	}

	fstream e4 ("entCorrec.txt", ios::in | ios::out);
	fstream s4 ("salidasDinamicaEj4.txt", ios::out);

	for(int i = 0; i < (10 * 30); i++){
		int n;
		e4 >> n;
		std::vector<int> ent4(n);
		int aux;
		for(int j = 0; j < n; j++){
			e4 >> aux;
			ent4[j] = aux;
		}
		int res = Ej4(ent4, n);
		s4 << res << endl;
	}

	e4.close();
	s4.close();
}

void expEj1ParaTiempo(){
	writeFileEj1();

	fstream e ("TestSinPoda.txt", ios::in | ios::out);
	fstream s ("salidasSinPodaTiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (36 * 40) + (27 * 10 * 2) + (36 * 10); i++){
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
		Ej1(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 36*40){
			s << "Random" << endl;
		}else{
			if(i >= 36*40 && i < (36*40 + 27*10)){
				s << "Creciente" << endl;
			}else{
				if(i >= (36*40+27*10) && (i < (36 * 40 + 27*10 + 27 * 10))){
					s << "Decreciente" << endl;
				}else{
					s << "Iguales" << endl;
				}
			}
		}
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();	
}

void expEj2ParaTiempo(){			// casos creciente, decreciente e iguales
	writeFileEj2();
	fstream e ("TestConPoda.txt", ios::in | ios::out);
	fstream s ("salidasConPodaTiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (50 * 40 + 50 * 10 + 50 * 10 + 50 * 10); i++){
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
		Ej2(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 40*50){
			s << "Random" << endl;
		}else{
			if(i >= 40*50 && i < (40*50 + 10*50)){
				s << "Creciente" << endl;
			}else{
				if(i >= (40*50 + 10*50) && i < (40*50 + 10*50 + 10*50)){
					s << "Decreciente" << endl;
				}else{
					s << "Iguales" << endl;				
				}

			}
		}
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();
}

void PruebaEj3Entrada1000(){		// tardó 69 segs aprox
	vector<int> ent(1000);
	for(int i = 0; i < 1000; i++){
		int v = rand() % 100000;
		ent[i] = v;
	}

	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	Ej3(ent, ent.size());
	end = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
	cout << elapsed_seconds.count() << endl;
}

void expEj3ParaTiempo(){
	writeFileEj3();

	fstream e ("TestDinam.txt", ios::in | ios::out);
	fstream s ("salidasEj3Tiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (300 * 50 + 300 * 10 + 300 * 10 + 300 * 10 + 300 * 10); i++){
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
		Ej3(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 300*50){
			s << "Random" << endl;
		}else{
			if(i >= 300*50 && i < (300*50 + 300*10)){
				s << "Creciente" << endl;
			}else{
				if(i >= (300 * 50 + 300 * 10) && i < (300*50 + 300*10 + 300*10)){
					s << "Decreciente" << endl;	
				}else{
					if(i >= 300 * 50 + 300*10 + 300*10 && i < (300*50 + 300*10 + 300*10 + 300*10)){
						s << "MayMen" << endl;
					}else{
						s << "Iguales" << endl;
					}
					
				}		
			}
		}
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();
}

void expEj4ParaTiempo(){

	fstream e ("TestDinam.txt", ios::in | ios::out);
	fstream s ("salidasEj4Tiempo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 0; i < (300 * 50 + 300 * 10 + 300 * 10 + 300 * 10 + 300 * 10); i++){
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
		Ej4(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
		s << elapsed_seconds.count();
		s << ",";
		if(i < 300*50){
			s << "Random" << endl;
		}else{
			if(i >= 300*50 && i < (300*50 + 300*10)){
				s << "Creciente" << endl;
			}else{
				if(i >= (300 * 50 + 300 * 10) && i < (300*50 + 300*10 + 300*10)){
					s << "Decreciente" << endl;	
				}else{
					if(i >= 300 * 50 + 300*10 + 300*10 && i < (300*50 + 300*10 + 300*10 + 300*10)){
						s << "MayMen" << endl;
					}else{
						s << "Iguales" << endl;
					}
					
				}		
			}
		}
	}

	// std::cout << "Sin poda tardó: " << elapsed_seconds.count() << " ms" << endl;

	e.close();
	s.close();
}

void correrTestsPracticaEj2(){			// salvo los de entrada 200, son todos correctos.
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
			int res = Ej2(ent, n);
			end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
			s << res;
			s << ",";
			s << elapsed_seconds.count() << endl;
		}
	}
}

void correrTestsPracticaEj1(){			// salvo los de entrada 200, son todos correctos.
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
			int res = Ej1(ent, n);
			end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
			s << res;
			s << ",";
			s << elapsed_seconds.count() << endl;
		}
	}
}

void correrTestsPracticaEj3(){				// son todos correctos
	std::chrono::time_point<std::chrono::system_clock> start, end;

	fstream s ("salidasTestsCatedraEj3.txt", ios::out);
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
		int res = Ej3(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
		s << res;
		s << ",";
		s << elapsed_seconds.count() << endl;
	}	
}

void correrTestsPracticaEj4(){				// son todos correctos
	std::chrono::time_point<std::chrono::system_clock> start, end;

	fstream s ("salidasTestsCatedraEj4.txt", ios::out);
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
		int res = Ej4(ent, n);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> elapsed_seconds = end-start;			
		s << res;
		s << ",";
		s << elapsed_seconds.count() << endl;
	}	
}

void FuncionEneCubo(int n){
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				res++;
			}
		}
	}
}

void expFuncionEneCubo(int n){
	fstream s ("salidasFuncionEneCubo.csv", ios::out);

	s << "Long_Entrada,Tiempo_ms" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < 100; j++){
			s << i;
			s << ",";
			start = std::chrono::system_clock::now();
			FuncionEneCubo(i);
			end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> elapsed_seconds = end-start;
			s << elapsed_seconds.count() << endl;
		}
	}
}

int main(){
	// expParaCorrec();
	// correrTestsPracticaDinamica();
	// expDinamicaParaTiempo();
	// MismoNumTiemposPodavsSinPoda();
	// expSinPodaParaTiempo();
	// expConPodaParaTiempo();
	// MaxMinMaxMin();
	// correrTestsPracticaBacktrackSinPoda();
	// expSinPodaParaTiempo();
	// expConPodaParaTiempo();
	// expTiempoBackPodaRandom();
	// expDinamicaParaTiempo();
	// PruebaDinamicaEntrada1000();
	// correrTestsPracticaEj4();
	expEj3ParaTiempo();
	expEj4ParaTiempo();
	// expSinPodaParaTiempo();
	// expEj4ParaTiempo();
	// expFuncionEneCubo(300);



	return 0;
}