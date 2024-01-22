#include <iostream>
#include <fstream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Usun element tablicy"<<endl;
    cout<<"3. Wyœwietl elementy tablicy"<<endl;
    cout<<"4. Zapisz do pliku"<<endl;
    cout<<"5. Wczytaj z pliku"<<endl;
    cout<<"6. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

void DodajElement(int*& p, int& le, int wartosc)
{
    int* dat = new int[le + 1];

    for (int i = 0; i < le; i++)
    {
        dat[i] = p[i];
    }

    dat[le] = wartosc;
    delete[] p;
    p = dat;
    le++;
}

void UsunElement(int*& p, int& le, int indeks)
{
    if (indeks >= 0 && indeks < le)
    {
        int* dat = new int[le - 1];

        for (int i = 0; i < indeks; i++)
        {
            dat[i] = p[i];
        }

        for (int i = indeks + 1; i < le; i++)
        {
            dat[i - 1] = p[i];
        }

        delete[] p;
        p = dat;
        le--;
    }
    else
    {
        cout << "Nieprawidlowy indeks" << endl;
    }
}

void ZapiszDoPliku(const int* p, int le, const string& Nazwa)
{
    ofstream plik(Nazwa);

    if (plik.is_open())
    {
        for (int i = 0; i < le; i++)
        {
            plik << p[i] << " ";
        }

        plik.close();
        cout << "Dane zostaly zapisane do pliku." << endl;
    }
    else
    {
        cout << "Blad otwarcia pliku do zapisu." << endl;
    }
}

void WczytajZPliku(int*& p, int& le, const string& Nazwa)
{
    ifstream plik(Nazwa);

    if (plik.is_open())
    {
        int wartosc;
        while (plik >> wartosc)
        {
            DodajElement(p, le, wartosc);
        }

        plik.close();
        cout << "Dane zostaly wczytane z pliku." << endl;
    }
    else
    {
        cout << "Blad otwarcia pliku do odczytu." << endl;
    }
}






int main()
{
    int m;
    int *p = NULL;
    int le = 0;

    while(true)
    {
        m = Menu();

        switch(m)
        {
        case 6:
            {
                delete[] p;
                return 0;
            }
        case 1:
            {
                int wartosc;
                cout << "Podaj wartosc elementu tablicy: ";
                cin >> wartosc;
                DodajElement(p, le, wartosc);
                break;
                }
        case 2:
            {
                int indeks;
                cout << "Podaj indeks elementu, ktory chcesz usunac: ";
                cin >> indeks;
                UsunElement(p, le, indeks);
                break;
            }
        case 3:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<le;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 4:
            {
                string Nazwa;
                cout << "Podaj nazwe pliku do zapisu: ";
                cin >> Nazwa;
                ZapiszDoPliku(p, le, Nazwa);
                break;}
        case 5:
            {
                string Nazwa;
                cout << "Podaj nazwe pliku do wczytania: ";
                cin >> Nazwa;
                WczytajZPliku(p, le, Nazwa);
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
                break;
            }

        }
    }

    return 0;
}
