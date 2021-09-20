// Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда, время отправления.
// Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN (записи
// должны быть размещены в алфавитном порядке по названиям пунктов назначения); вывод на экран информации о поездах, 
// отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).


#include <iostream>
using namespace std;
struct TRAIN
{
    char station[100];
    int number;
    float time;
};
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int s = 3;
    TRAIN t[s], m;
    int change;
    int n = 0;
    for (int i = 0; i < s; i++)
    {
        cout << "Введите пункт назначения: ";
        cin >> t[i].station;
        cout << "Введите номер поезда: ";
        cin >> t[i].number;
        cout << "Введите время отправления: ";
        cin >> t[i].time;
    }
    while (true) {
        cout << "\n1-Вывести весь список поездов." << endl;
        cout << "2-Поиск поезда по времени." << endl;
        cout << "3-Выход" << endl;
        cout << "Выберите действие: ";
        cin >> change;
        switch (change)
        {
        case 1://cout << "Номер\tВремя\tПункт назначения" << endl;
            for (int i = 0; i < s- 1; i++)
                for (int j = i + 1; j < s; j++)

                    if (strcmp(t[i].station, t[j].station) > 0)
                    {
                        
                        m = t[i]; 
                        t[i] = t[j];
                        t[j] = m;
                    }

                    for (int i = 0; i < s; i++)
                    {
                        /*cin>>t[i].station;*/
                        cout << "Пункт назначения: " << t[i].station << endl;
                        cout << "Время отправления: " << t[i].time << endl;
                        cout << "Номер поезда: " << t[i].number << endl;
                    }
        case 2:float time;
            cout << "Введите время: ";
            cin >> time;
            for (int i = 0; i < s; i++)
            {
                if (t[i].time > time) 
                {
                    cout << "Пункт назначения: " << t[i].station << endl;
                    cout << "Время отправления: " << t[i].time << endl;
                    cout << "Номер поезда: " << t[i].number << endl;
                    n++;
                }
            }
            if (n == 0)
                cout << "Увы, поезда на данное время нет!" << endl; 
            break;
        case 3:exit(0);
        default: cout << "Можете просмотреть другое время!";
        }
    }
    return 0;
}