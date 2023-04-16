#include <iostream>
#include "Lancha.h"

void jugar(Lancha& lancha) {
	//lancha.setEscenario();
	lancha.addSpeed();
	lancha.checkTurbo();
	lancha.printKmTraveled();
}

int main() {
	srand(time(NULL));

	Lancha lancha1(0, 0, 1, "Oscar");
	Lancha lancha2(0, 0, 1, "Greg");


	lancha1.printInfo();
	lancha2.printInfo();

	
	int turno = 5;
	while (turno> 0) {
		jugar(lancha1);
		jugar(lancha2);
		turno--;
	}
	if (lancha1.getDistance() > lancha2.getDistance()) {
		std::cout << "El corredor " << lancha1.getNameRunner() << " ha ganado " << std::endl;
	}
	else if (lancha2.getDistance() > lancha1.getDistance()) {
		std::cout << "El corredor " << lancha2.getNameRunner() << " ha ganado " << std::endl;
	}
	return 0;
	}

