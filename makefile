all: Server.out Client.out

Server.out: Server.o Block.o Cab.o Driver.o LuxuryCab.o Point.o StandardCab.o Trip.o Bfs.o GameFlow.o Map.o Matrix.o Passenger.o TaxiCenter.o Socket.o Udp.o
	g++ -std=c++0x Server.o Block.o Cab.o Driver.o LuxuryCab.o Point.o StandardCab.o Trip.o Bfs.o GameFlow.o Map.o Matrix.o Passenger.o TaxiCenter.o Socket.o Udp.o -lboost_serialization -I. -o Server.out

Client.out: Client.o Block.o Cab.o Driver.o LuxuryCab.o Point.o StandardCab.o Trip.o Map.o Matrix.o Bfs.o Socket.o Udp.o
	g++ -std=c++0x Client.o Block.o Cab.o Driver.o LuxuryCab.o Point.o StandardCab.o Trip.o Map.o Matrix.o Bfs.o Socket.o Udp.o -lboost_serialization -I. -o Client.out

Client.o: Client.cpp
	g++ -std=c++0x -c Client.cpp

Server.o: Server.cpp
	g++ -std=c++0x -c Server.cpp

Block.o: Block.cpp Block.h
	g++ -std=c++0x -c Block.cpp

Cab.o: Cab.cpp Cab.h
	g++ -std=c++0x -c Cab.cpp

Driver.o: Driver.cpp Driver.h
	g++ -std=c++0x -c Driver.cpp

LuxuryCab.o: LuxuryCab.cpp LuxuryCab.h
	g++ -std=c++0x -c LuxuryCab.cpp

Point.o: Point.cpp Point.h
	g++ -std=c++0x -c Point.cpp

StandardCab.o: StandardCab.cpp StandardCab.h
	g++ -std=c++0x -c StandardCab.cpp

Trip.o: Trip.cpp Trip.h
	g++ -std=c++0x -c Trip.cpp

Bfs.o: Bfs.cpp Bfs.h 
	g++ -std=c++0x -c Bfs.cpp

GameFlow.o: GameFlow.cpp GameFlow.h
	g++ -std=c++0x -c GameFlow.cpp

Map.o: Map.cpp Map.h
	g++ -std=c++0x -c Map.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -std=c++0x -c Matrix.cpp

Passenger.o: Passenger.cpp Passenger.h
	g++ -std=c++0x -c Passenger.cpp

TaxiCenter.o: TaxiCenter.cpp TaxiCenter.h
	g++ -std=c++0x -c TaxiCenter.cpp

Socket.o: Socket.cpp Socket.h
	g++ -std=c++0x -c Socket.cpp

Udp.o: Udp.cpp Udp.h
	g++ -std=c++0x -c Udp.cpp

clean:
	rm -f *.o a.out

