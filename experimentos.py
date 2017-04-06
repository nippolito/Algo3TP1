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

def main():
	df = pd.read_csv('salidasSinPodaTiempo.csv')
	# df.head(20)   # muestra los primeros 20
	df.describe()		# te devuelve un cuadrito con media de cada valor, min, max, etc
	# nes20 = df[df['Longitud_Entrada'] == 20]
	# tiempoMasQue40 = df["Tiempo_en_ms"] > 40
	# TMas40 = df[tiempoMasQue40]
	# a = TMas40['Longitud_Entrada'].value_counts()
	# print a
	# todo = df['Longitud_Entrada'].value_counts()
	# asd = a / todo.astype(float)
	# asd.plot(kind='bar')
	# plt.show()
	agrup = df.groupby('Long_Entrada')

	agrup.mean().plot()
	plt.show()



main()








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