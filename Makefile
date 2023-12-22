all: trajets
CXXFLAGS = -std=c++11 -Wall # -DMAP

trajets: trajets.o classes/Trajet.o classes/TrajetSimple.o classes/TrajetCompose.o classes/Catalogue.o
	g++ $(CXXFLAGS) -o trajets trajets.o classes/Trajet.o classes/TrajetSimple.o classes/TrajetCompose.o classes/Catalogue.o

trajets.o: trajets.cpp classes/Trajet.h classes/TrajetSimple.h classes/TrajetCompose.h classes/Catalogue.h
	g++ $(CXXFLAGS) -c trajets.cpp

Trajet.o: Trajet.cpp classes/Trajet.h classes/TrajetSimple.h classes/TrajetCompose.h
	g++ $(CXXFLAGS) -c classes/Trajet.cpp

TrajetSimple.o: classes/TrajetSimple.cpp classes/TrajetSimple.h classes/Trajet.h
	g++ $(CXXFLAGS) -c classes/TrajetSimple.cpp

TrajetCompose.o: classes/TrajetCompose.cpp classes/TrajetCompose.h classes/TrajetSimple.cpp classes/TrajetSimple.h classes/Trajet.h
	g++ $(CXXFLAGS) -c classes/TrajetCompose.cpp

Catalogue.o: classes/Catalogue.cpp classes/Catalogue.h classes/Trajet.h classes/TrajetSimple.h classes/TrajetCompose.h
	g++ $(CXXFLAGS) -c classes/Catalogue.cpp

run: main
	./trajet

clean:
	rm -f trajets *.o classes/*.o
