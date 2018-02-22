#!/usr/bin/env python
n=int(raw_input("cuantos numeros pseudoaleatorios:"))
seed=int(raw_input("valor de la semilla inicial:"))
#s2=str(seed**2)
#s3=s2[1:5]
for i in range(n):
	s2=str(seed**2)
	x=2*len(str(seed))
	ls=len(s2)
	if (ls<x):
		dif=x-ls
		for j in range(dif):
			s2="0"+s2
	s22=len(s2)/2
	izq=s22-2
	der=s22+2
	print izq, der		
	s3=s2[izq:der]
	s4=int(s3)/10000.0
	print s3, s4
	seed=int(s3)
			
		
	
