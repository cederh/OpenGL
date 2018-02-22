#!/usr/bin/env python

n = int(input("Cantidad de Pseudoaleatorios a generar: "))
seed= int(raw_input("\nIngrese el valor de la semilla inicial: "))

for i in range(n):

	s2 = str(seed**2)
	x = 2 * len(str(seed))
	ls = len(s2)
	
	if ls < x: 

		dif = x - ls

		for j in range(dif):

			s2 = "0" + s2

	s3 = s2[1:5]

	if len(s2) == 4:
		s3 = s2

	if len(s2) == 6:
		s3 = s2[1:5]

	if len(s2) == 8:
		s3 = s2[2:6]

	s4 = int(s3) / 10000.0
	print ("\n"), s3, s4
	seed = int(s3)