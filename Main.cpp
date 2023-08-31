// Main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "curve_3D.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

void printToScr(char* title, point P)
{
	std::cout << title << '\t' << P.x << '\t' << P.y << '\t' << P.z << '\n';
}

void printToFile(std::ofstream* out, char* title, point P)
{
	*out << title << '\t' << P.x << '\t' << P.y << '\t' << P.z << '\n';
}

/* функция-компаратор для сортировки методами библиотеки STL */
bool comparator(periodic_curve_3D* a, periodic_curve_3D* b)
{
	return a->getSemiMajorAxis() < b->getSemiMajorAxis();
}

int main(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(NULL));
	const char* path = "Result.txt";
	std::ofstream* out = new std::ofstream;
	out->open(path, std::ios_base::out);

	std::vector <periodic_curve_3D> box_one;	// первый контейнер

	double a, b, step;		// большая, малая полуоси и шаг винтовой кривой
	int type;
	int N = round((double)rand() / RAND_MAX * 50) + 50;	// количество объектов в первом контейнере

	/* цикл заполнения первого контейнера объектами типов Circle, ellipse, Helix */
	for (int i = 0; i < N; i++)
	{
		a = (double)rand() / RAND_MAX * 100.0 + 1;			// случайные
		b = (double)rand() / RAND_MAX * 100.0 + 1;			// значения
		step = (double)rand() / RAND_MAX * 20.0;			// типа и параметров
		type = floor((double)rand() / RAND_MAX * 3) + 1;	// кривых

		if (type == CIRCLE)
		{
			Circle C{ a };
			box_one.push_back(C);
		}
		if (type == ELLIPSE)
		{
			ellipse E{ a, b };
			box_one.push_back(E);
		}
		if (type == HELIX)
		{
			Helix_3D H{ a, step };
			box_one.push_back(H);
		}
	}

	/* печать точек кривых и векторов из первого контейнера на экран и в файл */
	for (int i = 0; i < box_one.size(); i++)
	{
		char* ch = "";
		type = box_one[i].getType();

		switch (type)
		{
		case CIRCLE:
			ch = "Circle";
			break;
		case ELLIPSE:
			ch = "Ellipse";
			break;
		case HELIX:
			ch = "Helix";
			break;
		}

		std::cout << '\n' << "#" << i << '\t' << ch << '\n';
		printToScr("Coordinates of point", box_one[i].getPointOfCurve(M_PI / 4));
		printToScr("Coordinates of vector", box_one[i].getVectorOfDerivate(M_PI / 4));

		*out << "\n#" << i << " " << ch << "\t\tx\t" << "y\t" << "z\n";
		printToFile(out, "Coordinates of point", box_one[i].getPointOfCurve(M_PI / 4));
		printToFile(out, "Coordinates of vector", box_one[i].getVectorOfDerivate(M_PI / 4));
	}

	std::vector <periodic_curve_3D*> box_two;	// второй контейнер

	/* заполнение второго контейнера указателями на объекты типа Circle из первого */
	for (int i = 0; i < box_one.size(); i++)
		if (box_one[i].getType() == CIRCLE)
			box_two.push_back((periodic_curve_3D*)&box_one[i]);

	/* сортировка объектов во втором контейнере по возрастанию значений радиусов */
	sort(box_two.begin(), box_two.end(), comparator);

	/* результат сортировки */
	std::cout << "\nSort result\n";
	for (int i = 0; i < box_two.size(); i++)
			std::cout << box_two[i]->getSemiMajorAxis() << '\n';

	double sumRadius = 0.0;

	/* вычисление суммы радиусов окружностей во втором контейнере */
	for (int i = 0; i < box_two.size(); i++)
		sumRadius += box_two[i]->getSemiMajorAxis();

	std::cout << "\nSum of radii in 2nd container: " << sumRadius << '\n';

	out->close();
	delete out;

	std::cin.get();

	return 0;
}