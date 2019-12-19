#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

using namespace std;


// Базовый  абстрактный класс геометрического объекта
class GeometricalObj
{ 
protected:
string name; // имя объекта

public: 

virtual const std::string& GetName(){return name; }
virtual double Square()=0; // вычисление площади
virtual void Show(void)=0;// отображение данных объекта на консоль
virtual void Move(double dx,double dy)=0;
};

// класс Треугольник 
class Triangle : public GeometricalObj
{
	protected:
		double x1,y1,x2,y2,x3,y3; // координаты трех точек вершин треугольника
		
	public:
	//конструктор по-умолчанию
	Triangle(){	x1=x2=x3=y1=y2=y3=0; }
	Triangle(std::string _name) { name = _name;  x1 = x2 = x3 = y1 = y2 = y3 = 0; }// конструктор с параметром: имя объекта
	Triangle(std::string _name,double x1,double y1,double x2,double y2,double x3,double y3);// конструктор с  параметрами
	~Triangle(){} // деструктор

	
 	virtual double Square();
  	virtual void Show(void);
	virtual void Move(double dx,double dy);
 
};

 
// Класс Квадрат 
// наследник от класса Triangle
class Quadrate : public Triangle
{
	protected:
		double x4,y4;// добавлена координаты четвертой вершины
	
	public:
		Quadrate();// конструктор
		Quadrate(std::string _name);// конструктор
		Quadrate(std::string _name,double _val);// конструктор
		virtual double Square();
		virtual void Show(void);
		virtual void Move(double dx,double dy);

};

int Compare(GeometricalObj  *ob1,GeometricalObj *ob2);
Quadrate operator+(Quadrate &os1,Quadrate  os2);
//bool isQuadrate(string s);
double distance(double x1,double y1,double x2,double y2);
