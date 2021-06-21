//Autor:Bruno Harlis
//Data: 21/06/2020

/*****************************************************************************************
* Dado um array de inteiros a, sua tarefa � calcular os d�gitos que ocorrem o maior n�mero de vezes no array. 
* Retorne o array desses d�gitos em ordem crescente.
* 
* Exemplo
* Para a = [25, 2, 3, 57, 38, 41], a sa�da deve ser digitosMaisFrequentes(a) = [2, 3, 5].
* 
* Aqui est� o n�mero de vezes que cada d�gito aparece no array:
* 0 -> 0
* 1 -> 1
* 2 -> 2
* 3 -> 2
* 4 -> 1
* 5 -> 2
* 6 -> 0
* 7 -> 1
* 8 -> 1
* O maior n�mero de vezes que qualquer n�mero ocorre na matriz � 2, e os d�gitos que aparecem 2 vezes s�o 2, 3 e 5. 
* Portanto, a resposta � [2, 3, 5].
*****************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> digitoRepetido(vector<int>& n)
{
    vector<int> numeros{ 0,0,0,0,0,0,0,0,0,0 };

    for (unsigned i{ 0 }; i < n.size(); ++i)
    {
        if (n[i] > 9)
        {
            numeros[n[i] % 10] += 1;
            int x = n[i] - (n[i] % 10);
            numeros[x / 10] += 1;
        }
        else
        {
            numeros[n[i]] += 1;
        }
    }

    //Ver a quantidade max que algum numero repetiu 
    int repeteMais{ 0 };
    for (unsigned i{ 0 }; i < numeros.size(); ++i)
    {
        if (numeros[i] > repeteMais) repeteMais = numeros[i];
    }

    vector<int> maisRepetidos{};
    for (unsigned i{ 0 }; i < numeros.size(); ++i)
    {
        if (repeteMais == numeros[i])
            maisRepetidos.push_back(i);
    }

    return maisRepetidos;
}

int main()
{
    vector<int> x{ 25, 2, 3, 57, 38, 41 };
    auto y{ digitoRepetido(x) };
    
    for(auto a:y)
        cout << a << " ";

    return 0;
}