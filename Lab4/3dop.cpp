//	Определить структуру для представления информации о наличии санаторных путевок, содержащую следующие поля : Название санатория, Место расположения, Лечебный профиль, 
//	Количество путевок. Представить введенные данные в виде таблицы, сгруппировав их по лечебным профилям санаториев. В пределах каждой группы данные отсортировать по названиям 
//	санаториев. Организовать поиск информации и вывод результатов.


#include <iostream>
using namespace std;
struct SAN
{
    char name[100];
    char place[100];
    char medprof[100];
    int  number;
    char profil[100];
};
int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int s = 3;
    SAN t[s], m;
    int change;
    int n = 0;
    for (int i = 0; i < s; i++)
    {
        
        cout << "Введите Название санатория: ";
        cin >> t[i].name;
        cout << "Введите Место расположения: ";
        cin >> t[i].place;
        cout << "Введите Лечебный профиль: ";
        cin >> t[i].medprof;
        cout << "Введите Количество путевок: ";
        cin >> t[i].number;

    }
    while (true) {
        cout << "\n1-Вывести весь список санаториев." << endl;
        cout << "2-Поиск санатория по профилю." << endl;
        cout << "3-Выход" << endl;
        cout << "Выберите действие: ";
        cin >> change;
        switch (change)
        {
        case 1:
           // cout << "Санаторий\tМесто расположения\tЛечебный профиль\tКол-во путевок" << endl;
            for (int i = 0; i < s - 1; i++) 
            {
                for (int j = i + 1; j < s; j++) 
                {

                    if (strcmp(t[i].name, t[j].name) > 0)
                    {
                        m = t[i];
                        t[i] = t[j];
                        t[j] = m;
                    }
                    /*if (strcmp(t[i].place, t[j].place) > 0)
                    {
                        m = t[i];
                        t[i] = t[j];
                        t[j] = m;
                    }
                    if (strcmp(t[i].medprof, t[j].medprof) > 0)
                    {
                        m = t[i];
                        t[i] = t[j];
                        t[j] = m;
                    }*/
                }
            }
                printf("|-------------------------------------------------------------------------------|\n");
                printf("| Санаторий |   Место расположения   |  Лечебный профиль  |  Количество путевок |\n");
                printf("|-------------------------------------------------------------------------------|\n");
                for (int i = 0; i < s; i++)
                {
                    printf("|%-12s|%-12s|%20s|%15d|\n",  t[i].name, t[i].place, t[i].medprof, t[i].number);
                    //printf("|---------------------------------------------------------------------------|\n");
                }
                /*cin>>t[i].station;*/
                /*cout << t[i].name << endl;
                cout << t[i].place << endl;
                cout << t[i].medprof << endl;*/
        case 2:
            char profil[100];

            cout << "Введите лечебный профиль: ";
            cin >> profil;
            for (int i = 0; i < s; i++)
            {
                if (strcmp(t[i].medprof,profil)==0)
                {
                    cout << "Санаторий: " << t[i].name << endl;
                    cout << "Местоположение: " << t[i].place << endl;
                    cout << "Лечебный профиль: " << t[i].medprof << endl;
                    n++;
                }
            }
            if (n == 0)
                cout << "Увы, такого профиля нет!" << endl;
            break;

        case 3:exit(0);
        default: cout << "Можете просмотреть другие профили!";
        }
    }
    return 0;
}