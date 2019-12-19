#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

using namespace std;

// Класс для организации работы меню пользователя
class Factory
{
	// хранилище указателей на объекты базового класса
std::vector <GeometricalObj*> pObjects; // вектор указателей на объекты строк потомков StringObj
public:
Factory(){		}
void AddObject(void);
void Operations();
void DeleteObject(void);
void ListAllObjects();
void ShowObject(void);
int SelectItem(int n);
void OutListObject();		
};

