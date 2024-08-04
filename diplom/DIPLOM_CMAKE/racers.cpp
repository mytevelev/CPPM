#include "racers.h"

double Camel::calculateTotalTime(double distance) const 
{
	double speed = 10;  // скорость
	double travelTime = 30;  // до отдыха
	double totalTravelTime = distance / speed; // за сколько пройдет без остановки
	int restCount = static_cast<int>(totalTravelTime / travelTime); // сколько отдыхов
	double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

	if ( restCountFull == static_cast<double>(restCount) ) restCount--;

	double totalTime = totalTravelTime;     
	for (int i = 1; i <= restCount; ++i) 
	{
		if (i == 1) 
		{
			totalTime += 5;
		}
		else 
		{
			totalTime += 8;
		}
	}
	return totalTime;
}


double SpeedCamel::calculateTotalTime(double distance) const {
	double speed = 40;
	double travelTime = 10;
	double totalTravelTime = distance / speed;
	int restCount = static_cast<int>(totalTravelTime / travelTime);
	double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

	if (restCountFull == static_cast<double>(restCount)) restCount--;

	double totalTime = totalTravelTime;
	for (int i = 1; i <= restCount; ++i) {
		if (i == 1) {
			totalTime += 5;
		}
		else if (i == 2) {
			totalTime += 6.5;
		}
		else {
			totalTime += 8;
		}
	}
	return totalTime;
}


double Centaur::calculateTotalTime(double distance) const {
	double speed = 15;
	double travelTime = 8;
	double totalTravelTime = distance / speed;
	int restCount = static_cast<int>(totalTravelTime / travelTime);

	double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

	if (restCountFull == static_cast<double>(restCount)) restCount--;
	double totalTime = totalTravelTime;
	for (int i = 1; i <= restCount; ++i) {
		totalTime += 2;
	}
	return totalTime;
}



double AllTerrainBoots::calculateTotalTime(double distance) const {
	double speed = 6;
	double travelTime = 60;
	double totalTravelTime = distance / speed;
	int restCount = static_cast<int>(totalTravelTime / travelTime);
	double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

	if (restCountFull == static_cast<double>(restCount)) restCount--;
	double totalTime = totalTravelTime;
	for (int i = 1; i <= restCount; ++i) {
		if (i == 1) {
			totalTime += 10;
		}
		else {
			totalTime += 5;
		}
	}
	return totalTime;
}



double MagicCarpet::calculateTotalTime(double distance) const {
	double speed = 10;
	double reduction = 0;

	if (distance >= 1000 && distance < 5000) {
		reduction = 3;
	}
	else if (distance >= 5000 && distance < 10000) {
		reduction = 10;
	}
	else if (distance >= 10000) {
		reduction = 5;
	}

	double reducedDistance = distance * (1 - reduction / 100);
	return reducedDistance / speed;
}


double Eagle::calculateTotalTime(double distance) const {
	double speed = 8;
	double reduction = 6; // Всегда 6%
	double reducedDistance = distance * (1 - reduction / 100);
	return reducedDistance / speed;
}

double Broom::calculateTotalTime(double distance) const {
	double speed = 20;
	int reduction = static_cast<int>(distance / 1000); // Увеличивается на 1% за каждую 1000 у.е. расстояния
	double red = reduction;  // to float
	double reducedDistance = distance * (1 - red / 100);
	return reducedDistance / speed;
}


