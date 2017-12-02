#include <iostream>
using namespace std;

struct Date_Name
{
	string date;
	string name;
};

using namespace std;

int main() {
	int num;
//	cout << "Введите количество дат(событий)";
	cin >> num;
	Date_Name *mas = new Date_Name[num];
	for (int i = 0; i < num; i++)
	{
//	cout << "Введите дату в формате дд.мм.гггг";
	cin >> mas[i].date;
//	cout << "Введите дату в формате дд.мм.гггг";
	cin >> mas[i].name;
	};
	
	string s;
//	cout << "Ведите дату или событие, которое нуж
	int k=0;


           
	for (int i = 0; i < num; i++)
	{
		if (s == mas[i].date)
		{
		cout << "True";
		k = k+1;
		}
		if (s == mas[i].name)
		{
		cout << "True";
		k = k+1;
		}
	
	}
            
	
	if (k == 0)
	cout << "False";


	return 0;
}
