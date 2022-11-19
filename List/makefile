hepsi : derle calistir

derle:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Kontrol.cpp
	g++ -I ./include/ -o ./lib/Sayilistesi.o -c ./src/Kontrol.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/Kontrol.cpp
	g++ -I ./include/ -o ./lib/Kontrol.o -c ./src/Kontrol.cpp
	g++ -I ./include/ -o ./bin/test.exe ./lib/Kontrol.o ./src/Main.cpp
	
calistir:
	./bin/test.exe