#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;
//////////////////////////
int integer(int min, int max) {
  static default_random_engine e{static_cast<long unsigned int>(time(0))};
  uniform_int_distribution<int> d{min, max};
  return d(e);
}

ostream& operator<<(ostream& A, const vector<int> &tab){
    A << "{ ";
    for (size_t i = 0; i < tab.size(); ++i)
    {
        A << tab[i] << " ";
    }
    A << "}";
    return A;
}
void main1() 
{
    cout << "Zadanie 1:" << endl;
    int rozm;
    cout << "Enter the vector size: ";
    cin >> rozm;
    vector<int> tab(rozm);
    for (size_t i = 0; i < tab.size(); ++i){
        tab[i] = integer(-20, 20);
    }

    cout << tab << endl; 

    for (auto it = tab.begin(); it != tab.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    int search;
    cout << "Enter the serched integer: ";
    cin >> search;

    auto find = find_if(tab.begin(), tab.end(), [search](int value){ return search == value; }); 

    if (find != tab.end()){
        cout << "Found: " << search << endl;

        auto removeIt = remove_if(tab.begin(), tab.end(), [search](int value){ return search == value; }); 
        tab.erase(removeIt, tab.end());
    }
    else{
        cout << "Didn't find: " << search << endl;
    }

    cout << tab << endl;}

    ////////////////////////////////

    ostream& operator<<(ostream& A, const list<int>& list){
    A << "{ ";
    for (auto it = list.begin(); it != list.end(); ++it){
        A << *it << " ";
    }
    A << "}";
    return A;
}
void main2() {

    cout << "Zadanie 2:" << endl;
    int rozm;
    cout << "Enter the list size: ";
    cin >> rozm;
    list<int> list(rozm);

    for (auto it = list.begin(); it != list.end(); ++it){
        *it = integer(-20, 20);
    }

    cout << list << endl; 

    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    int search;
    cout << "Eneter the serching integer: ";
    cin >> search;

    auto find = find_if(list.begin(), list.end(), [search](int value){ return search == value; }); 

    if (find != list.end()){
        cout << "Found " << search << endl;

        list.remove(search); 
    }
    else{
        cout << "Not found " << search << endl;
    }

    cout << list << endl;
}
////////////////////////////
void main3() 
{
    cout << "Zadanie 3" << endl;
    int rozm;
    cout << "Enter the vector size: ";
    cin >> rozm;
    vector<int> tab(rozm);
    for (size_t i = 0; i < tab.size(); ++i){
        tab[i] = integer(-20, 20);
    }

    cout << tab << endl;

    int search;
    cout << "Enter the serched integer: ";
    cin >> search;

    auto find = std::find(tab.begin(), tab.end(), search); 

    if (find != tab.end()){
        cout << "Found " << search << endl;

        auto remove = remove_if(tab.begin(), tab.end(), [search](int value){ return search == value; });
        tab.erase(remove, tab.end());
    }
    else{
        cout << "Not found " << search << endl;
    }

    cout << tab << endl;
    
}
//////////////////////////////
void main4() 
{
    cout << "Zadanie 4:" << endl;
     int rozm;
    cout << "Enter the vector size: ";
    cin >> rozm;
    vector<int> tab(rozm);
    for (size_t i = 0; i < tab.size(); ++i){
        tab[i] = integer(-20, 20);
    }

    cout << tab << endl; 

    auto min = min_element(tab.begin(), tab.end());
    auto max = max_element(tab.begin(), tab.end());
    auto min_max = minmax_element(tab.begin(), tab.end());

    cout << "Min: " << *min << endl;
    cout << "Max: " << *max << endl;
    cout << "Min & Max" << *min_max.first << " i " << *min_max.second << endl;

}
/////////////////////////////
void main5() 
{
    cout << "Zadanie 5:" << endl;
    vector<int> vector = {5, -2, 1, -3, 4};
    list<int> list = {5, 2, -1, 3, -4};

    cout << "Wektor" << endl;    
    sort(vector.begin(), vector.end()); 
    cout << vector << endl;

    sort(vector.rbegin(), vector.rend()); 
    cout << vector << endl;  
    sort(vector.rbegin(), vector.rend(), [](int x, int y) {
        return abs(x) > abs(y); 
    });
    cout << vector << endl;

    cout << "List" << endl;

    list.sort(); 
    cout << list << endl;
    
    list.sort(greater<int>());
    cout << list << endl;

    list.sort([](const int& x, const int& y)  
    {
        return abs(x) > abs(y); 
    });
    cout << list << endl;

}
////////////////////////////
void main6() 
{
    cout << "Zadanie 6:" << endl;
    vector<int> vector = {1, 2, 3, 2, 1, 2, 3, 3, 3};
    list<int> list = {1, 2, 3, 2, 1, 2, 3, 3, 3};

    cout << "Vector" << endl;
    for(int i = 1; i <= 3; ++i) 
    {
        int count = std::count(vector.begin(), vector.end(), i);
        cout << "The amount " << i << " is " << count << " times" << endl;
    }

    cout << "List" << endl;
    for(int i = 1; i <= 3; ++i) 
    {
        int count = std::count(list.begin(), list.end(), i);
        cout << "The amount " << i << " is " << count << " times" << endl;
    }
}
//////////////////////////
enum class TypRosliny { Fruit, Veget };

struct Roslina {
    TypRosliny type;
    std::string name;
};

using Koszyk = vector<Roslina>;
void main7()
{
    Koszyk koszyk;
    koszyk = { {TypRosliny::Fruit, "Mand"}, {TypRosliny::Veget, "March"}, {TypRosliny::Fruit, "Mango"} };
    koszyk.push_back({TypRosliny::Veget, "Salata"});
    for (size_t i = 0; i < koszyk.size(); ++i)
    {
        cout << koszyk[i].name << endl;   
    }
}
///////////
ostream& operator<<(ostream& A, const Roslina& roslina)
{
    A << roslina.name << " " << (int)roslina.type;
    return A;
}

ostream& operator<<(ostream &A, const Koszyk &koszyk)
{
    for (size_t i = 0; i < koszyk.size(); i++)
    {
        A << koszyk[i].name << " " << (int)koszyk[i].type << endl;
    }
    return A;
}

void main8()
{
    Koszyk koszyk;
    Roslina roslina;

    roslina.name = "Banan";
    roslina.type = TypRosliny::Fruit;

    koszyk = { 
        {TypRosliny::Fruit, "Mand"},
        {TypRosliny::Veget, "March"},
        {TypRosliny::Fruit, "Mango"},
        {TypRosliny::Veget, "Sal"}
        };

    cout << roslina << endl;
    cout << koszyk << endl;

}
//////////////////
bool czy_jest_gruszka(const Koszyk& koszyk)
{
    auto find = find_if(koszyk.begin(), koszyk.end(), [](const Roslina& roslina)
    {
        return roslina.name == "Gruszka";
    });
    return find != koszyk.end();
}

void main9(){
    Koszyk koszyk;
    koszyk = { 
        {TypRosliny::Fruit, "Mand"},
        {TypRosliny::Veget, "March"},
        {TypRosliny::Fruit, "Mango"},
        {TypRosliny::Veget, "Sal"}
        };

    if(czy_jest_gruszka(koszyk)){
        cout << "Its a pear" << endl;
    }
    else{
        cout << "Its not a pear" << endl;
    }
}
/////////////////
bool fruitsOnly(const Koszyk &koszyk) {
    return all_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina)
        { return roslina.type == TypRosliny::Fruit; } );
}

bool vegeOnly(const Koszyk &koszyk) {
    return all_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina)
        { return roslina.type == TypRosliny::Veget; } );
}

bool fruit(const Koszyk &koszyk) {
    return any_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina)
        { return roslina.type == TypRosliny::Fruit; } );
}

bool vege(const Koszyk &koszyk) {
    return any_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina)
        { return roslina.type == TypRosliny::Veget; } );
}

bool noFruit(const Koszyk &koszyk) {
    return none_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina)
        { return roslina.type == TypRosliny::Fruit; } );
}

bool noVege(const Koszyk &koszyk) {
    return none_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina)
        { return roslina.type == TypRosliny::Veget; } );
}

void pytania(const Koszyk &koszyk)
{
    if(fruitsOnly(koszyk))
    {
        cout << "Only fruits" << endl;
    }
    else
    {
        cout << "with vegetables" << endl;
    }

    if(vegeOnly(koszyk))
    {
        cout << "only vegetables" << endl;
    }
    else
    {
        cout << "with fruits" << endl;
    }

    if(fruit(koszyk))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    if(vege(koszyk))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    if(noFruit(koszyk))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    if(noVege(koszyk))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}

void main10()
{
    Koszyk all;
    Koszyk fruitOnly;
    Koszyk vegetOnly;
    all = { 
        {TypRosliny::Fruit, "Apple"},
        {TypRosliny::Veget, "Potatoe"},
        {TypRosliny::Fruit, "Mango"},
        {TypRosliny::Veget, "Carrot"}
        };

    fruitOnly = { 
        {TypRosliny::Fruit, "Berries"},
        {TypRosliny::Fruit, "Orange"},
        {TypRosliny::Fruit, "Mango"},
        {TypRosliny::Fruit, "Banana"}
        };

    vegetOnly = { 
        {TypRosliny::Veget, "Pepper"},
        {TypRosliny::Veget, "Cucumber"},
        {TypRosliny::Veget, "Cauliflower"},
        {TypRosliny::Veget, "Eggplant"}
        };

    cout << "---- everything ----" << endl;
    pytania(all);

    cout << "---- only fruits ----" << endl;
    pytania(fruitOnly);

    cout << "---- only vegetables ----" << endl;
    pytania(vegetOnly);

}
////////////////////
int countFruits(const Koszyk &koszyk)
{
    return count_if(koszyk.begin(), koszyk.end(),
            [](const Roslina &roslina) { return roslina.type == TypRosliny::Fruit; });
}

int countVege(const Koszyk &koszyk)
{
    return count_if(koszyk.begin(), koszyk.end(),
            [](const Roslina &roslina) { return roslina.type == TypRosliny::Veget; });
}

void main11()
{
    Koszyk koszyk;
    koszyk = { 
        {TypRosliny::Fruit, "Apple"},
        {TypRosliny::Veget, "Potatoe"},
        {TypRosliny::Fruit, "Banana"},
        {TypRosliny::Veget, "Cucumber"}
        };
    
    cout << "In the koszyk " << countFruits(koszyk) << " fruits i " << countVege(koszyk) << " vegetables." << endl;
}
//////////////////////////////
void removeFrom(Koszyk &koszyk, const TypRosliny typ, const char ch)
{
    auto usun = remove_if(koszyk.begin(), koszyk.end(),
        [typ, ch](const Roslina& roslina)
        {
            return roslina.type == typ && roslina.name[0] == toupper(ch);
        });
    koszyk.erase(usun, koszyk.end());
}

void main12()
{
    Koszyk koszyk;
    koszyk = { 
        {TypRosliny::Fruit, "Apple"},
        {TypRosliny::Veget, "Potatoe"},
        {TypRosliny::Fruit, "Banana"},
        {TypRosliny::Veget, "Cucumber"}
        };

    cout << koszyk << endl;
    removeFrom(koszyk, TypRosliny::Fruit, 'b');
    cout << koszyk << endl;
}
////////////////////////
bool operator<(const Roslina &a1, const Roslina &a2) 
{   
    return a1.name < a2.name;
}

void main13()
{
    Roslina roslina1;
    roslina1.name = "Cucumber";

    Roslina roslina2;
    roslina2.name = "Potatoe";

    if (roslina1 < roslina2)
    {
        cout << "Cucumber is smaller than potatoe" << endl;
    }
    else
    {
        cout << "Potatoe is smaller then cucumber" << endl;
    }
}
////////////////
int main(){

int numer;
    for(;;)
    {
        do
        {
            cout << std::endl << "Enter the number of the task" << endl;
            cin >> numer;
        } while (numer < 1 || numer > 13);

        switch (numer)
        {
        case 1:
            cout << "Task 1:" << endl;
            main1();
            break;
        case 2:
            cout << "Task 2:" << endl;
            main2();
            break;
        case 3:
            cout << "Task 3:" << endl;
            main3();
            break;
        case 4:
            cout << "Task 4:" << endl;
            main4();
            break;
        case 5:
            cout << "Task 5:" << endl;
            main5();
            break;
        case 6:
            cout << "Task 6:" << endl;
            main6();
            break;
        case 7:
            cout << "Task 7:" << endl;
            main7();
            break;
        case 8:
            cout << "Task 8:" << endl;
            main8();
            break;
        case 9:
            cout << "Task 9:" << endl;
            main9();
            break;
        case 10:
            cout << "Task 10:" << endl;
            main10();
            break;
        case 11:
            cout << "Task 11:" << endl;
            main11();
            break;
        case 12:
            cout << "Task 12:" << endl;
            main12();
            break;
        case 13:
            cout << "Task 13:" << endl;
            main13();
            break;
        default:
            break;
        }
    }
    return 0;
}