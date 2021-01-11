#include <iostream>
#include "Stack.h"
#include "StackException.h"

using namespace std;

void foo(Stack& s) 
{
    try 
    {
        s.pop();
    }

    catch (StackException e) 
    {
        cout << e.what() << endl;
    }

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    try 
    {
        s.push(6);
    }

    catch (StackException e) 
    {
        cout << e.what() << endl;
    }
}

void bar(Stack& s)
{
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    try
    {
        s.push(6);
    }

    catch (StackException &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    int rozm, elem;

    Stack s1;
    foo(s1);
    Stack s2;
    bar(s2);

    Stack* s = nullptr;
    int x = 0;

    cout << "Menu: " << endl;
    cout << "1. Stworz stos." << endl;
    cout << "2. Dodaj element na stos." << endl;
    cout << "3. Zdejmij element ze stosu." << endl;
    cout << "4. Zakoncz." << endl;
    cout << "Podaj liczbe od 1 do 4: "; 
    cin >> x;

    while (x != 4)
    {
        switch (x)
        {
        case 1:
            if (s != nullptr)
            {
                delete s;
            }
            cout << "Podaj rozmiar stosu: ";
            cin >> rozm;
            s = new Stack(rozm);
            break;

        case 2:
            cout << "Podaj element ktory chcesz dodac na stos: ";
            cin >> elem;
            try
            {
                s->push(elem);
            }
            catch (StackException& e)
            {
                cout << e.what() << endl;
            }
            catch (exception e)
            {
                cout << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                cout << "Zdjeto ze stosu: "<< s->pop() << endl;
            }
            catch (StackException& e)
            {
                cout << e.what() << endl;
            }
            catch (exception e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        
        cout << "Podaj liczbe od 1 do 4: "; 
        cin >> x;
    }

    if (s != nullptr)
    {
        delete s;
    }
    return 0;
}

// 3. noexcept jest odpowiednikiem Override w Javie. Dzieki temu wyskoczy nam blad jesli bedziemy chcieli nadpisac
//funkcje ktora nie istnieje lub nie jest funckja virtualna

// 4. Poniewaz deklaracja wystepuje przy throw

// 5. Blad jest obsługiwany przez klase podstawowa

// 6. Blad jest obslugiwany przez klase pochodna