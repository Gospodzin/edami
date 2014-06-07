CC = g++
CFLAGS = -pedantic -O0 -g3 -Wall -std=c++0x -lboost -c

all: BoostTestMain

BoostTestMain: BoostTestMain.o PreDeCon.o Helpers.o Neighborhood.o EpsNeighborhood.o EpsNeighborhoodCalculation.o WeightedNeighborhood.o Point.o Dbscan.o Distances.o DataLoader.o
	$(CC) BoostTestMain.o PreDeCon.o Helpers.o Neighborhood.o EpsNeighborhood.o EpsNeighborhoodCalculation.o WeightedNeighborhood.o Point.o Dbscan.o Distances.o DataLoader.o -o BoostTestMain

BoostTestMain.o: BoostTestMain.cpp
	$(CC) $(CFLAGS) BoostTestMain.cpp
	
PreDeCon.o: PreDeCon.cpp
	$(CC) $(CFLAGS) PreDeCon.cpp

Distances.o: Distances.cpp
	$(CC) $(CFLAGS) Distances.cpp
	
Helpers.o: Helpers.cpp
	$(CC) $(CFLAGS) Helpers.cpp

Neighborhood.o: Neighborhood.cpp
	$(CC) $(CFLAGS) Neighborhood.cpp
	
EpsNeighborhood.o: EpsNeighborhood.cpp
	$(CC) $(CFLAGS) EpsNeighborhood.cpp
	
EpsNeighborhoodCalculation.o: EpsNeighborhoodCalculation.cpp
	$(CC) $(CFLAGS) EpsNeighborhoodCalculation.cpp
	
WeightedNeighborhood.o: WeightedNeighborhood.cpp
	$(CC) $(CFLAGS) WeightedNeighborhood.cpp
	
Point.o: Point.cpp
	$(CC) $(CFLAGS) Point.cpp
	
Dbscan.o: Dbscan.cpp
	$(CC) $(CFLAGS) Dbscan.cpp

DataLoader.o: DataLoader.cpp
	$(CC) $(CFLAGS) DataLoader.cpp
	
clean:
	rm -rf *o BoostTestMain