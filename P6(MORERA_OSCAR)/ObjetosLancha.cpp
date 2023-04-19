
#include "Lancha.h";
#include <iostream>
#include <windows.h>

Lancha::Lancha(int sspeed, int kkm, int nnitro, std::string nnameRunner) {
	speed = sspeed;
	km = kkm;
	nitro = nnitro;
	nameRunner = nnameRunner;
}
int Lancha::getSpeed() {
	return speed;
	}
int Lancha::getNitro() {
	return nitro;
}
int Lancha::getDistance() {
	return km;
}

int Lancha::increaseSpeed() {
	speed = speed + rollDice();
	return speed;
}

int Lancha::rollDice() {
	int h = 1 + rand() % (7 - 1);
	return h;
}

int Lancha::addTurbo() {
	nitro = 1;
	return nitro;
}
int Lancha::distanceTraveled() {
	km = km + speed * 100;
	return km;
}
std::string Lancha::getNameRunner() {
	return nameRunner;
}

void Lancha::setSpeed(int Sspeed) {
	speed = Sspeed;
}
void Lancha::setDistance(int Kkm) {
	km = Kkm;
}
void Lancha::setNitro(int Nnitro) {
	nitro = Nnitro;
}
void Lancha::setNameRunner(std::string NnameRunner) {
	nameRunner = NnameRunner;
}

void Lancha::printInfo() {
	std::cout << "Un corredor es " << getNameRunner() << " y tiene una velocidad inicial de " << getSpeed() <<  std::endl;
}

void Lancha::addSpeed() {
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Es el turno del corredor " << getNameRunner() << std::endl;
	Sleep(1000);
	std::cout << "Lanzas el dado para incrementar tu velocidad." << std::endl;
	Sleep(1000);
	std::cout << "El corredor " << getNameRunner() << ", aumenta su velocidad hasta " << increaseSpeed() << std::endl;
}



void Lancha::printKmTraveled() {
	Sleep(1000);
	std::cout << "La distancia del corredor " << getNameRunner() << " es " << distanceTraveled() <<  " km " << std::endl;
	Sleep(1000);
}


void Lancha::checkTurbo() {
	if (getNitro() == 1) {
		askTurbo();
	}
	else if (getNitro() == 0) {
		
	}
}
void Lancha::askTurbo() {
	int option = 0;
	std::cout << "Quiere el corredor utilizar el nitro?" << std::endl;
	std::cout << "Presiona 1 si lo quieres utilizar, 2 si quieres seguir corriendo igual" << std::endl;
	std::cin >> option;
	if (option == 1) {
		int nitror = rand() % 2;
		if (nitror == 0) {
			speed /= 2;
			std::cout << "Pierdes la mitad de velocidad. Su velocidad ahora es de " << speed  << std::endl;
			nitro = 0;
		}
		else if (nitror == 1) {
			speed *= 2;
			std::cout << "Doblas tu velocidad. Tu velocidad ahora es de " << speed << std::endl;
			nitro = 0;
		}
		std::cout << "Pierdes el nitro de momento" << std::endl;
	}
	else if (option == 2) {
		std::cout << "Te reservas el turbo." << std::endl;
	}
}
void Lancha::reloadTurbo() {
	if (nitro = 0){
	std::cout << "Lanzaras una moneda para probar si recuperas el turbo."<< std::endl;
	int h = rand() % (2);
	if (h == 0) {
		std::cout << "Has sacado cara. No recuperas el turbo" << std::endl;
	}
	else if (h == 1) {
		std::cout << "Has sacado cruz. Recuperas el turbo" << std::endl;
		addTurbo();
	}
	}
	else {
		std::cout << "Ya dispones de turbo. No dispondras del lanzamiento de moneda" << std::endl;
	}
}


void Lancha::situations() {
	std::cout << "Dado de la suerte" << std::endl;
	int p = rand() % 4;
	if (p == 0) {
		std::cout << "Se te suman 5 puntos de velocidad" << std::endl;
		speed = speed + 5;
	}
	else if (p == 1) {
		std::cout << "Te has cruzado con una roca. Tienes que parar a reparar. Tu velocidad se pone en 0" << std::endl;
		speed = 0;
	}
	else if (p == 2) {
		std::cout << "Te has cruzado con un atajo. Aumentas en 1000 km tu distancia" << std::endl;
		km = km + 1000;
	}
	else if (p == 3) {
		std:: cout << "Te has equivocado de camino. Retrocede 1000 km" << std::endl;
		if (km <= 1000) {
			km = 0;
		}
		else {
			km = km - 1000;
		}
	}
	
	std::cout << "El turno del corredor " << getNameRunner() << " ha acabado" << std::endl;

}
