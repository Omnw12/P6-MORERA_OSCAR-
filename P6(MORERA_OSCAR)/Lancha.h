#pragma once
#include <iostream>


class Lancha {
private:
	int speed;
	int km;
	int nitro;
	std::string nameRunner;



public:
	Lancha(int Sspeed, int Kkm, int Nnitro, std::string NnameRunner);

	int getSpeed();

	int getDistance();

	int getNitro();

	int increaseSpeed();

	int distanceTraveled();

	int rollDice();

	int addTurbo();

	std::string getNameRunner();
	
	void setSpeed(int Sp);

	void setDistance(int Km);

	void setNitro(int Nnitro);

	void setNameRunner(std::string NnameRunner);


	void printInfo();

	void addSpeed();

	void printKmTraveled();

	void askTurbo();

	void checkTurbo();

	void reloadTurbo();

	void situations();
};