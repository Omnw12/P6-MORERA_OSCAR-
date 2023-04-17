#include <iostream>
#include "Lancha.h"
#include <windows.h>

void jugar(Lancha& lancha) {
	
	lancha.addSpeed();
	lancha.checkTurbo();
	lancha.printKmTraveled();
	lancha.reloadTurbo();
	lancha.situations();
}
void rules() {
	std::cout << "Bienvenido a las carreritas. Dos jugadores disputarán una carrera de lanchas. La velocidad aumentara en base de un dado, cada punto de velocidad seran 100km. Dispondran de un turbo con un uso que se podra recargar aleatoriamente al final de cada turno." << std::endl;
	std::cout << "El turbo doblara tu velocidad o te la reducira a la mitad. Al final de cada turno te encontraras con un obstaculo que te cambiara tus estadisticas o tu carrera." << std::endl;
}
int main() {
	srand(time(NULL));

	Lancha lancha1(0, 0, 1, "Oscar");
	Lancha lancha2(0, 0, 1, "Greg");

	rules();
	Sleep(5000);
	lancha1.printInfo();
	Sleep(2000);
	lancha2.printInfo();
	Sleep(2000);
	

	int turno = 5;
	while (turno> 0) {
		jugar(lancha1);
		Sleep(2000);
		jugar(lancha2);
		Sleep(2000);
		turno--;
	}
	if (lancha1.getDistance() > lancha2.getDistance()) {
		std::cout << "El corredor " << lancha1.getNameRunner() << " dispone de " << lancha1.getDistance() << "km. Ha ganado " << std::endl;
	}
	else if (lancha2.getDistance() > lancha1.getDistance()) {
		std::cout << "El corredor " << lancha2.getNameRunner() << " dispone de " << lancha2.getDistance() << "km. Ha ganado " << std::endl;
	}
	return 0;
	}

