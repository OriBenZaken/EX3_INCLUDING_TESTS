# Liz Aharonian 316584960
# Ori Ben Zaken 311492110

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: src/*.h src/*.cpp
	g++ -c src/*.cpp

