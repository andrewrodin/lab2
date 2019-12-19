#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "geometr.h"
#include "factory.h"

using namespace std;


//фунция вывода на экран списка имен всех объектов
void Factory::ListAllObjects()
{
	cout << endl << "Список объектов: " << endl;
	cout << "--------------------------------------" << endl;
	OutListObject();// вывод нумерованного списка объектов
	cout << "--------------------------------------" << endl;
}
// функция вывода на консоль нумерованного списка объектов
void Factory::OutListObject()
{
 int n=pObjects.size();// получаем число объектов в хранилище
 //цикл вывода на консоль имён объектов по порядку номеров
 for(int i=0;i<n;i++)	cout << (i+1)<< ":" << pObjects[i]->GetName()<< endl;
 
}

//Функция вывода на консоль значения объекта из хранилища
void Factory::ShowObject(void )
{
  int item,n;
  
  n=pObjects.size();// получаем число объектов в хранилище
  
   if(n==0){	cout <<"!!!!! В хранилище нет объектов."<< endl;  	return;	}
  
  cout <<"Выберите номер объекта:"<< endl;
  
  OutListObject();// вывод нумерованного списка объектов
  item=SelectItem(n);// запрашиваем номер объекта для вывода наконсоль его значения
  
  // для показа значения изпользуется виртуальная функция, 
  //переопределенная в каждом классе-потомке
  pObjects[item-1]->Show();
 
}

// удаление объекта из хранилища
void Factory::DeleteObject(void)
{
	int item,n;
  
  n=pObjects.size(); // число объектов в хранилище
  
  if(n==0)	 { 	cout <<"!!!!! В хранилище нет объектов."<< endl; return;   }
  
  cout<<"------------------------------------"<<endl;
  cout <<"Вы берите номер удаляемого объекта:"<<endl;

  OutListObject();// вывод нумерованного списка объектов
  
  	item=SelectItem(n);// запрашиваем номер объекта для его удаления из хранилища
  	item--;
  	
  	string name=pObjects[item]->GetName();// временно сохраняем имя объекта для отображения в сообщении об удалении
  	
	pObjects.erase(pObjects.begin() + item );//удаляем объект из хранилища
	
    cout <<"Объект < "<< name << " > удален  из хранилища. " << endl;
}

//фунция добавления нового обекта в хранилище
void Factory::AddObject(void )
{ 
 int item;
 GeometricalObj *pNewObj; // указатель на объект базового абстрактного класса
 
 string name;
double value,x1,x2,x3,y1,y2,y3;
		
		cout << "Выберите тип добавляемого объекта:"<< endl;
		cout << "1.Треугольник"<<endl;
		cout << "2.Квадрат"<<endl;
		item=SelectItem(2); // запрос выбора пункта меню
		
		// запрос имени объекта
		cout <<"Введите имя:";
		cin>> name;
		cin.get();
	
		// запрос значения объекта
		
		switch(item)
		{
			case 1:cout << "Введите координаты 1-й точки:";
				cin >> x1>> y1;
				cout << "Введите координаты 2-й точки:";
				cin >> x2 >> y2;
				cout << "Введите координаты 3-й точки:";
				cin >> x3 >> y3;
					pNewObj = new Triangle(name,x1,y1,x2,y2,x3,y3); //создаем треугольник
					break;
			case 2: 
						cout << "Введите длину стороны:";
						cin >> value;
					if( value < 0 )// проверяем на корректность значение стороны
					{cout <<endl<<"!!!!! Некорректное значение. Длина должна быть больше нуля."<< endl;
						return;
					}
					pNewObj= new Quadrate(name,value); //создаем десятичную строку
					break;
		}// end switch
		
		
		pObjects.push_back(pNewObj);// помещаем объект-строку в хранилище
		cout <<"Объект успешно добавлен в хранилище."<< endl;
}
	// операции над геометрическими объектами
void Factory::Operations()
{

  int item,item1,item2,n;
  GeometricalObj *ob1,*ob2;
  double dx,dy;
  
  n=pObjects.size(); // число объектов в хранилище

 cout << "Выберите тип операции над объектами:" << endl;
 cout << "1.Сравнение по площади" << endl;
 cout << "2.Перемещение на плоскости" << endl;

 item = SelectItem(2); // запрос выбора пункта меню

 switch (item)
 {
 case 1:// сравнение по площадям
		{	
			OutListObject();
			cout << "Выберите 1-й объект:";
			item1=SelectItem(n); // запрос выбора пункта меню
			cout << "Выберите 2-й объект:";
			item2=SelectItem(n); // запрос выбора пункта меню
			ob1=pObjects[item1-1];
			ob2=pObjects[item2-1];
			cout << "Площадь " << ob1->GetName() << ":" << ob1->Square() << endl;
			cout << "Площадь " << ob2->GetName() << ":" << ob2->Square() << endl;
			cout << "Результат сравнения площадей: "; 
			int r = Compare(ob1, ob2);
			if (r < 0) cout << ob1->GetName() << " меньше " << ob2->GetName() << endl;
			else if( r==0)cout << ob1->GetName() << " равен " << ob2->GetName() << endl;
			else cout << ob1->GetName() << " больше  " << ob2->GetName() << endl;

			}break;

 case 2:// перемещение на плоскости
		 {	
			OutListObject();
			cout << "Выберите объект для перемещения:";
			item1=SelectItem(n); // запрос выбора объекта по номеру
			ob1=pObjects[item1-1];
			cout << "Введите величину сдвига по X:";
			// запрос значения 
			cin >> dx;
			cout << "Введите величину сдвига по Y:";
			// запрос значения 
			cin >> dy;
			ob1->Move(dx,dy);// перемещаем объект на заданные смещения
			cout << "Результат перемещения: "<<endl; ob1->Show();
			}break;


 }

}

//функция реализует ввод с консоли выбора пользователя
// от 1 до n
int Factory::SelectItem(int n)
{
	int item;
	while( true ) // бесконечный цикл пока не введут верное значение
	{
		cin >> item;
		if( (item > 0 && item <= n  ) && (cin.peek()=='\n')) 
		{ cin.get();
		  break; // выход из цикла
		}
		else
		{// ввели неверное значение
		cout <<"Ошибочный выбор. Повторите ввод.(от 1 до "<< n <<"):"<<endl;
		cin.clear();
		
		while( cin.get()!='\n'){	}; // ждем нажатия клавиши Enter
		
		}
	}
	return item;
}
