#include <iostream>
using namespace std;

int factorial(int num);
int tail_factorial(int num);
int tail_aux(int num, int aux);

int main()
{
    int num;
    int result;
    
    cout << "Enter the number to calculate the factorial: ";
    cin >> num;

    result = factorial(num);
    cout << "Recursion -> Factorial is: "<< result << endl;
    
    result = tail_factorial(num);
    cout << "Tail recursion -> Factorial is: "<< result << endl;
    
    return 0;

}

int factorial(int num)
{
    if(num == 1)
    {
        return 1;
    }
    else
    {
        return (num * factorial(num - 1));
    }
}

int tail_aux(int num, int aux)
{
    if(num == 1)
        return aux;
    else
        return tail_aux((num - 1), (aux * num));
}

int tail_factorial(int num)
{
    return tail_aux(num , 1);
}

