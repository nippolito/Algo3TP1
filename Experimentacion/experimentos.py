# -*- coding: utf-8 -*-

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import random

# from pylab import *
# rcParams['figure.figsize'] = 15,5



# Always display all the columns
# pd.set_option('display.width', 5000)
# pd.set_option('display.max_columns', 60)

def Ejercicio1():
	df = pd.read_csv('../Testing/salidasSinPodaTiempo.csv')

	Random = df[df['Tipo'] == 'Random']
	Rand_count = Random.groupby('Long_Entrada').mean()
	Rand_count.plot(title='Random')
	plt.ylabel('Tiempo en ms')

	Crecientes = df[df['Tipo'] == 'Creciente']
	Crec_count = Crecientes.groupby('Long_Entrada').mean()
	Crec_count.plot(title='Random')
	plt.ylabel('Tiempo en ms')

	Decrecientes = df[df['Tipo'] == 'Decreciente']
	Decrec_count = Decrecientes.groupby('Long_Entrada').mean()
	Decrec_count.plot(title='Random')
	plt.ylabel('Tiempo en ms')

	plt.show()

def Ejercicio2():
	df = pd.read_csv('../Testing/salidasConPodaTiempo.csv')

	enes = range(1, 51)

	Random = df[df['Tipo'] == 'Random']
	Rand_count = Random.groupby('Long_Entrada').mean()
	Rand_count.plot(title='Random')
	plt.ylabel('Tiempo en ms')
	List1 = Rand_count.Tiempo_ms.tolist()

	Crecientes = df[df['Tipo'] == 'Creciente']
	Crec_count = Crecientes.groupby('Long_Entrada').mean()
	List2 = Crec_count.Tiempo_ms.tolist()
	# Crec_count.plot(title='Creciente')
	# plt.ylabel('Tiempo en ms')

	Decrecientes = df[df['Tipo'] == 'Decreciente']
	Decrec_count = Decrecientes.groupby('Long_Entrada').mean()
	List3 = Decrec_count.Tiempo_ms.tolist()
	# Decrec_count.plot(title='Decreciente')
	# plt.ylabel('Tiempo en ms')

	Iguales = df[df['Tipo'] == 'Iguales']
	Iguales_count = Iguales.groupby('Long_Entrada').mean()
	List4 = Iguales_count.Tiempo_ms.tolist()


	dataf1 = pd.DataFrame({'Crecientes': List2, 'Decrececientes': List3, 'Iguales': List4, 'Longitud': enes})
	dataf1.astype(float)
	dataf1.plot(title='Crecientes, Decrecientes e Iguales', x='Longitud', logy=True)
	plt.ylabel('Tiempo en ms')

	plt.show()

def Ejercicio2SoloRandom():
	df = pd.read_csv('../Testing/PodaRandomSalidasTiempo.csv')

	Random = df[df['Tipo'] == 'Random']
	Rand_count = Random.groupby('Long_Entrada').mean()
	Rand_count.plot(title='Random')
	plt.ylabel('Tiempo en ms')
	plt.show()


def Ejercicio3():
	df = pd.read_csv('../Testing/salidasEj3Tiempo.csv')
	enes = range(1, 201)
	complejidad = [(n**3) for n in enes]
	complej = pd.DataFrame({'Longitud': enes, 'Complejidad n^3': complejidad})
	complej = complej.astype(float)

	Random = df[df['Tipo'] == 'Random']
	Rand_count = Random.groupby('Long_Entrada').mean()
	List1 = Rand_count.Tiempo_ms.tolist()
	# dataf1 = pd.DataFrame({'Tiempos': List1, 'Complejidad n^3': complejidad, 'Longitud': enes})
	# dataf1.plot(title='Random', x='Longitud')
	# plt.ylabel('Tiempo en ms')

	Crecientes = df[df['Tipo'] == 'Creciente']
	Crec_count = Crecientes.groupby('Long_Entrada').mean()
	List2 = Crec_count.Tiempo_ms.tolist()
	# dataf = pd.DataFrame({'Tiempos': asd, 'Complejidad n^3': complejidad, 'Longitud': enes})
	# dataf.plot(x='Longitud', title='Creciente')
	# plt.ylabel('Tiempo en ms')

	Decrecientes = df[df['Tipo'] == 'Decreciente']
	Decrec_count = Decrecientes.groupby('Long_Entrada').mean()
	List3 = Decrec_count.Tiempo_ms.tolist()

	MayMen = df[df['Tipo'] == 'MayMen']
	MayMen_count = MayMen.groupby('Long_Entrada').mean()
	List4 = MayMen_count.Tiempo_ms.tolist()

	Iguales = df[df['Tipo'] == 'Iguales']
	Iguales_count = Iguales.groupby('Long_Entrada').mean()
	List5 = Iguales_count.Tiempo_ms.tolist()

	dataf = pd.DataFrame({'TiemposRand': List1, 'TiemposCrec': List2, 'TiemposDecrec': List3, 'TiemposMayMin': List4, 'Iguales': List5, 'Longitud': enes})
	dataf.plot(x='Longitud')
	plt.ylabel('Tiempo en ms')
	# dataf2 = pd.DataFrame({'Tiempos': List2, 'Complejidad n^3': complejidad, 'Longitud': enes})
	# dataf2.plot(title='Decreciente', x='Longitud')
	# plt.ylabel('Tiempo en ms')

	plt.show()




def main():
	df = pd.read_csv('salidasSinPodaTiempo.csv')
	# print df.describe()		# te devuelve un cuadrito con media de cada valor, min, max, etc
	# counts_df = df.groupby(['Tipo','Long_Entrada']).count()
	# counts_df = pd.DataFrame(counts_df, columns=['grid'])
	# counts_df.columns = ['count']
	# sorted_counts_df = counts_df.sort_values('count', ascending=True)
	# print sorted_counts_df.head()
	# asd = df.groupby(['Tipo','Long_Entrada']).mean()
	# print asd
	Crecientes = df[df['Tipo'] == 'Creciente']
	Crec_count = Crecientes.groupby('Long_Entrada').mean()
	Crec_count.plot()

	Random = df[df['Tipo'] == 'Random']
	Rand_count = Random.groupby('Long_Entrada').mean()
	Rand_count.plot()
	plt.show()


	# # nes20 = df[df['Longitud_Entrada'] == 20]
	# # tiempoMasQue40 = df["Tiempo_en_ms"] > 40
	# # TMas40 = df[tiempoMasQue40]
	# # a = TMas40['Longitud_Entrada'].value_counts()
	# # print a
	# # todo = df['Longitud_Entrada'].value_counts()
	# # asd = a / todo.astype(float)
	# # asd.plot(kind='bar')
	# # plt.show()
	# agrup = df.groupby('Long_Entrada')

	# agrup.mean().plot(kind="bar", logy="true")
	# # plt.show()

	# agrup2 = df.groupby(' Tipo')
	# agrup2.mean().plot(kind="bar", logy="true")
	# crec = df[df[' Tipo'] == 'Creciente']
	# crec.groupby('Long_Entrada')
	# crec.plot(kind="bar", logy="true")
	# plt.show()


Ejercicio2()








# df = pd.read_csv('ruta/archivo.csv') > lee el archivo
# df.head(n) > muestras los primeros n
# df > muestra todo el archivo
# df['LongEntrada'] > muestra los elementos de la columna LongEntrada. Podés seleccionar más columnas también
# df['LongEntrada'][:5] > muestra los elementos de la column LongEntrada hasta el 5
# df[10:15] > muestra los elementos del 10 al 15
# contador = df['LongEntrada'].value_counts() > define a la variable contador como el conteo de cuántos hay según cada LongEntrada
# var.plot(kind='bar') > te crea el plot en var, el tipo es una barra
# plt.show() > te muestra el último plot que creaste
# nes20 = df[df['Longitud_Entrada'] == 20] > cree una variable nes20 donde tengo solo los de long 20

"""	tiempoMasQue40 = df["Tiempo_en_ms"] > 40
	TMas40 = df[tiempoMasQue40]
	print TMas40['Longitud_Entrada'].value_counts()"""   # me muestra cuántos tienen tiempo mayor que 40 según cada n
""" a = TMas40['Longitud_Entrada'].value_counts()
	print a
	todo = df['Longitud_Entrada'].value_counts()
	asd = a / todo.astype(float)
	print asd"""

# df.groupby('Longitud_Entrada').mean() > devuelve la mediana de todos los valores con long_entrada == 1, == 2 ....