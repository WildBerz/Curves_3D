#pragma once

#ifdef CURVE3D_EXPORT
	#define CLASS_DECLSPEC __declspec(dllexport)
#else
	#define CLASS_DECLSPEC __declspec(dllimport)
#endif

#define M_PI	3.1415926535897932384626433832795
#define M_2PI	6.283185307179586476925286766559

/* ���� ������ */
#define CIRCLE		1
#define ELLIPSE		2
#define HELIX		3

struct point
{
	double x;
	double y;
	double z;
};

/* ������� ����� ������������� ������ � 3-������ ������������ */
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
	int typeOfCurve;	// ��� ������
	double a;			// ������� ������� (semi-major axis)
	double b;			// ����� ������� (semi-minor axis)
	double step;		// ��� �������� ������
};

/* ����������� ����� ������� ����������� */
class CLASS_DECLSPEC Circle : public periodic_curve_3D
{
public:
	Circle(double a);
	point getPointOfCurve(double t);
	point getVectorOfDerivate(double t);
	int getType();
};

/* ����������� ����� ������� �������� */
class CLASS_DECLSPEC ellipse : public periodic_curve_3D
{
public:
	ellipse(double a, double b);
	point getPointOfCurve(double t);
	point getVectorOfDerivate(double t);
	int getType();
};

/* ����������� ����� �������� ������ (3D) */
class CLASS_DECLSPEC Helix_3D : public periodic_curve_3D
{
public:
	Helix_3D(double a, double step);
	point getPointOfCurve(double t);
	point getVectorOfDerivate(double t);
	int getType();
};