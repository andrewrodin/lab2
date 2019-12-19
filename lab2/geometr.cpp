#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>
#include <math.h>
#include "geometr.h"

using namespace std;

// функция вывода значения объекта-"треугольник" на консоль
void Triangle::Show(void)
{   cout <<"Triangle:\nname:" << name<< endl;
	cout << "Points:";
	cout <<"(" << x1 << ","<< y1 <<")," ;
	cout <<"(" << x2 << ","<< y2<<")," ;
	cout <<"(" << x3 << ","<< y3 <<")" << endl;

}
// Площадь треугольника
	double Triangle::Square()
	{
		double s,p,s1,s2,s3;
		//вычисляем длины трех сторон
		s1=distance(x1,y1,x2,y2);
	
		s2=distance(x2,y2,x3,y3);
	
		s3=distance(x1,y1,x3,y3);

		p=(s1+s2+s3)/2;// полупериметр

		// расчет по формуле Герона
		s=sqrt( p * (p-s1) * (p-s2) * (p-s3) );
	
		return s;
	}
// конструктор с  параметрами: имя и координаты трёх вершин
Triangle::Triangle(std::string _name,double _x1,double _y1,double _x2,double _y2,double _x3,double _y3)
{
	name = _name;
 x1=_x1;
 x2=_x2;
 x3=_x3;
 y1=_y1;
 y2=_y2;
 y3=_y3;
}
// сдвиг треугольника на заданные смещения
void Triangle::Move(double dx,double dy)
{
	
	x1+=dx;
	x2+=dx;
	x3+=dx;
	y1+=dy;
	y2+=dy;
	y3+=dy;
}


// вычисление площади квадрата
	double Quadrate::Square()
	{
		double s;
		s=distance(x1,y1,x2,y2);
		return s*s;
		
	}



//конструктор по-умолчанию
Quadrate::Quadrate():Triangle()
{
	x4 = y4 = 0;
}
Quadrate::Quadrate(std::string _name): Triangle(_name)// конструктор
{
	// вызов подобного конструктора базового класса
	x4 = y4 = 0;
}

// конструктор с двумя параметрами: имя и значение длины стороны квадрата
Quadrate::Quadrate(std::string _name,double size):Triangle(_name)
{
  x1=y1=0;
  x2=0;     y2=size; 
  x3=y3=size;
  x4=size;  y4=0;
  
}
	
// сдвиг квадрата на заданные смещения
void Quadrate::Move(double dx,double dy)
{
	Triangle::Move(dx,dy);// функция смещения базового класса
	x4+=dx;
	y4+=dy;
}
// показ всех полей данных квадрата
void Quadrate::Show()
{
 	cout <<"Quadrate:\nname:" << name << endl;
	cout << "Points:";
	cout <<"("<< x1 << ","<< y1 <<")," ;
	cout <<"(" <<x2 << ","<< y2 <<")," ;
	cout << "(" << x3 << "," << y3 << "),";
	cout <<"(" << x4 << ","<< y4 <<")" << endl;
	

}


// вычисление расстояния между двумя точками
double distance(double x1,double y1,double x2,double y2)
{
 double dx,dy;
 dx=x2-x1;
 dy=y2-y1;
 
 return sqrt(dx*dx + dy*dy);
}

// функцияя сравнения объектов по площади
// возвращает:
// -1 если ob1 < ob2
// 0 если ob1 = ob2
// 1 если ob1 > ob2
int Compare(GeometricalObj  *ob1,GeometricalObj *ob2)
{ double s;
	s=ob1->Square()-ob2->Square();
	return (s < 0 )? -1 : ((s==0)? 0 : 1) ;
}
