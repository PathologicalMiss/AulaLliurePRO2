demo_fecha: fecha.o main.o
	g++ -o demo_fecha fecha.o main.o
fecha.o: fecha.cc fecha.hh
	g++ -c fecha.cc
main.o: main.cc fecha.hh
	g++ -c main.cc
tar: 
	tar -cvf fecha_def.tar fecha.hh fecha.cc main.cc fechas.dat 
clean:
	rm -f demo_fecha main.o fecha.o

.PHONY: clean tar
