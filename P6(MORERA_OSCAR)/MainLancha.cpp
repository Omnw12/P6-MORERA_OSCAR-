#include <iostream>
#include "Lancha.h"
#include <windows.h>

void jugar(Lancha& lancha) {
	lancha.addSpeed();
	std::cout << "" << std::endl;
	lancha.checkTurbo();
	std::cout << "" << std::endl;
	lancha.printKmTraveled();
	std::cout << "" << std::endl;
	lancha.reloadTurbo();
	std::cout << "" << std::endl;
	lancha.situations();
	std::cout << "" << std::endl;
	

}
void rules() {
	std::cout << "Bienvenido a las carreritas. Dos jugadores disputaran una carrera de lanchas. La velocidad aumentara en base de un dado, cada punto de velocidad seran 100km. Dispondran de un turbo con un uso que se podra recargar aleatoriamente al final de cada turno." << std::endl;
	std::cout << "El turbo doblara tu velocidad o te la reducira a la mitad. Al final de cada turno te encontraras con un obstaculo que te cambiara tus estadisticas o tu carrera." << std::endl;
	std::cout << "La carrera comenzara en el punto 0." << std::endl;
}
int main() {
	srand(time(NULL));

	Lancha lancha1(0, 0, 1, "Oscar");
	Lancha lancha2(0, 0, 1, "Greg");

	
	rules();
	std::cout << "" << std::endl;
	Sleep(5000);
	lancha1.printInfo();
	Sleep(2000);
	lancha2.printInfo();
	Sleep(2000);


	int turno = 1;
	while (turno <  6) {
		system("cls");
		std::cout << "Turno " << turno << std::endl;
		jugar(lancha1);
		jugar(lancha2);
		system("cls");
		turno++;
	}
	if (lancha1.getDistance() > lancha2.getDistance()) {
		std::cout << "El corredor " << lancha1.getNameRunner() << " dispone de " << lancha1.getDistance() << "km. Ha ganado " << std::endl;
	}
	else if (lancha2.getDistance() > lancha1.getDistance()) {
		std::cout << "El corredor " << lancha2.getNameRunner() << " dispone de " << lancha2.getDistance() << "km. Ha ganado " << std::endl;
	}
	return 0;
	}

