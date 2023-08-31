#include "stdafx.h"
#include "curve_3D.h"
#include <math.h>

/*--------------------------------------------------------------------------------------------------------------*/
/*				определение методов класса periodic_curve_3D					*/

periodic_curve_3D::periodic_curve_3D(double _a, double _b, double _step)
{
	if (fabs(_b) > fabs(_a))
	{
		a = fabs(_b);
		b = fabs(_a);
	}
	else
	{
		a = fabs(_a);
		b = fabs(_b);
	}

	step = fabs(_step);
}

void periodic_curve_3D::setType(int type)
{
	typeOfCurve = type;
}

int periodic_curve_3D::getType()
{
	return typeOfCurve;
}

/* метод возвращает значение кривой в точке (для заданного значения параметра t) */
point periodic_curve_3D::getPointOfCurve(double t)
{
	point P;
	P.x = a * cos(t);
	P.y = b * sin(t);
	P.z = step / M_2PI * t;

	return P;
}

/*  метод возвращает значение производной кривой в точке,    */
/*  геометрический смысл которой - компоненты направляющего  */
/*  вектора касательной к этой кривой в заданной точке       */
point periodic_curve_3D::getVectorOfDerivate(double t)
{
	point P;
	P.x = -a * sin(t);
	P.y = b * cos(t);
	P.z = step / M_2PI;

	return P;
}

double periodic_curve_3D::getSemiMajorAxis()
{
	return a;
}

double periodic_curve_3D::getSemiMinorAxis()
{
	return b;
}

double periodic_curve_3D::getStep()
{
	return step;
}



/*--------------------------------------------------------------------------------------------------------------*/
/*					определение методов класса Circle					*/	

Circle::Circle(double a) : periodic_curve_3D(a, a, 0)
{
	setType(CIRCLE);
}

int Circle::getType()
{
	return periodic_curve_3D::getType();
}

/* метод возвращает значение кривой в точке (для заданного значения параметра t) */
point Circle::getPointOfCurve(double t)
{
	return periodic_curve_3D::getPointOfCurve(t);
}

/*  метод возвращает значение производной кривой в точке,    */
/*  геометрический смысл которой - компоненты направляющего  */
/*  вектора касательной к этой кривой в заданной точке       */
point Circle::getVectorOfDerivate(double t)
{
	return periodic_curve_3D::getVectorOfDerivate(t);
}



/*--------------------------------------------------------------------------------------------------------------*/
/*					определение методов класса ellipse					*/

ellipse::ellipse(double a, double b) : periodic_curve_3D(a, b, 0)
{
	setType(ELLIPSE);
}

int ellipse::getType()
{
	return periodic_curve_3D::getType();
}

/* метод возвращает значение кривой в точке (для заданного значения параметра t) */
point ellipse::getPointOfCurve(double t)
{
	return periodic_curve_3D::getPointOfCurve(t);
}

/*  метод возвращает значение производной кривой в точке,    */
/*  геометрический смысл которой - компоненты направляющего  */
/*  вектора касательной к этой кривой в заданной точке       */
point ellipse::getVectorOfDerivate(double t)
{
	return periodic_curve_3D::getVectorOfDerivate(t);
}



/*--------------------------------------------------------------------------------------------------------------*/
/*					определение методов класса Helix					*/

Helix_3D::Helix_3D(double a, double step) : periodic_curve_3D(a, a, step)
{
	setType(HELIX);
}

int Helix_3D::getType()
{
	return periodic_curve_3D::getType();
}

/* метод возвращает значение кривой в точке (для заданного значения параметра t) */
point Helix_3D::getPointOfCurve(double t)
{
	return periodic_curve_3D::getPointOfCurve(t);
}

/*  метод возвращает значение производной кривой в точке,    */
/*  геометрический смысл которой - компоненты направляющего  */
/*  вектора касательной к этой кривой в заданной точке       */
point Helix_3D::getVectorOfDerivate(double t)
{
	return periodic_curve_3D::getVectorOfDerivate(t);
}
