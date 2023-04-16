
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
//int Lancha::rollEscenario() {
//	int h = 1 + rand() % (5 - 1);
//	return h;
//}
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
	std::cout << "El nombre del corredor es " << getNameRunner() << ", su velocidad es de " << getSpeed() << ", su distancia recorrida es de " << getDistance() << " y su Nitro es de " << getNitro() << std::endl;
}

void Lancha::addSpeed() {
	std::cout << "Es el turno del corredor " << getNameRunner() << std::endl;
	Sleep(1000);
	Sleep(1000);
	std::cout << "Lanzas el dado para incrementar tu velocidad." << std::endl;
	std::cout << "El corredor " << getNameRunner() << ", aumenta su velocidad hasta " << increaseSpeed() << std::endl;
}



void Lancha::printKmTraveled() {
	Sleep(1000);
	std::cout << "La distancia del corredor " << getNameRunner() << " es " << distanceTraveled() <<  " km " << std::endl;
	Sleep(1000);
	std::cout << "El turno del corredor " << getNameRunner() << " ha acabado" << std::endl;
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
		std::cout << "Ya no dispondrás de más turbo en toda la carrera" << std::endl;
	}
	else if (option == 2) {
		std::cout << "Te reservas el turbo." << std::endl;
	}
}

//void Lancha::setEscenario() {
//	std::cout << "Tiras un dado para saber que bioma sera donde correras" << std::endl;
//	rollEscenario();
//	if (rollEscenario() == 1) {
//		std::cout << "Te ha tocado el bioma de la jungla. ¡Cuidado con los monos!" << std::endl;
//	}
//	else if (rollEscenario() == 2) {
//		std::cout << "Te ha tocado el bioma del desierto. ¡Cuidado con los cocodrilos!" << std::endl;
//	}
//	else if (rollEscenario() == 3) {
//		std::cout << "Te ha tocado el bioma del pantano. " << std::endl;
//	}
//	else if (rollEscenario() == 4) {
//		std::cout << "Te ha tocado el bioma del rio." << std::endl;
//	}
//
//}