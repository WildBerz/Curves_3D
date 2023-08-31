#pragma once

#ifdef CURVE3D_EXPORT
	#define CLASS_DECLSPEC __declspec(dllexport)
#else
	#define CLASS_DECLSPEC __declspec(dllimport)
#endif

#define M_PI	3.1415926535897932384626433832795
#define M_2PI	6.283185307179586476925286766559

/* типы кривых */
#define CIRCLE		1
#define ELLIPSE		2
#define HELIX		3

struct point
{
	double x;
	double y;
	double z;
};

/* базовый класс периодических кривых в 3-мерном пространстве */
class CLASS_DECLSPEC periodic_curve_3D
{
public:
	periodic_curve_3D(double a, double b, double step);
	void setType(int type);
	virtual int getType();
	virtual point getPointOfCurve(double t);
	virtual point getVectorOfDerivate(double t);
	virtual double getSemiMajorAxis();
	virtual double getSemiMinorAxis();
	virtual double getStep();

private:
	int typeOfCurve;	// тип кривой
	double a;			// большая полуось (semi-major axis)
	double b;			// малая полуось (semi-minor axis)
	double step;		// шаг винтовой кривой
};

/* производный класс плоских окружностей */
class CLASS_DECLSPEC Circle : public periodic_curve_3D
{
public:
	Circle(double a);
	point getPointOfCurve(double t);
	point getVectorOfDerivate(double t);
	int getType();
};

/* производный класс плоских эллипсов */
class CLASS_DECLSPEC ellipse : public periodic_curve_3D
{
public:
	ellipse(double a, double b);
	point getPointOfCurve(double t);
	point getVectorOfDerivate(double t);
	int getType();
};

/* производный класс винтовой кривой (3D) */
class CLASS_DECLSPEC Helix_3D : public periodic_curve_3D
{
public:
	Helix_3D(double a, double step);
	point getPointOfCurve(double t);
	point getVectorOfDerivate(double t);
	int getType();
};