# Variables
TIME =$(LOGPATH)$(shell date)
# Object Vars
OBJECTS = main.o Recomendacion.o Simbolo.o Preprocesador.o Articulo.o
# Compilation flags
CFLAGS = -c -std=c++17 -Wall

recomendacion: $(OBJECTS)
	g++ $(OBJECTS) -o recomendacion
	mv recomendacion ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

Recomendacion.o: ../src/Recomendacion.cpp ../include/Recomendacion.hpp
	g++ $(CFLAGS) ../src/Recomendacion.cpp

Simbolo.o: ../src/Simbolo.cpp ../include/Simbolo.hpp
	g++ $(CFLAGS) ../src/Simbolo.cpp

Preprocesador.o: ../src/Preprocesador.cpp ../include/Preprocesador.hpp
	g++ $(CFLAGS) ../src/Preprocesador.cpp

Articulo.o: ../src/Articulo.cpp ../include/Articulo.hpp
	g++ $(CFLAGS) ../src/Articulo.cpp


.PHONY: clean
clean:
	rm -rf ../build/*.o
	rm -rf ../bin/*

run:
	../bin/recomendacion ../inputs/input_file.txt

runLog:
	echo "\n\n\nExecuted ${TIME}" >> ../outputs/runDetails.txt
	make run >> ../outputs/runDetails.txt
	echo "You can find full output at outputs/runDetails.txt"
