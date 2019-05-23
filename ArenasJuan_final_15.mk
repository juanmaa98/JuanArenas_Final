ArenasJuan_final_15.pdf : graficar.py datos.dat
	python3 graficar.py
    
datos.dat : ArenasJuan_final_15.cpp
	g++ ArenasJuan_final_15.cpp
	./a.out