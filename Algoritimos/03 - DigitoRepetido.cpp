//Autor:Bruno Harlis
//Data: 21/06/2020

/*****************************************************************************************
* Dado um array de inteiros a, sua tarefa é calcular os dígitos que ocorrem o maior número de vezes no array. 
* Retorne o array desses dígitos em ordem crescente.
* 
* Exemplo
* Para a = [25, 2, 3, 57, 38, 41], a saída deve ser digitosMaisFrequentes(a) = [2, 3, 5].
* 
* Aqui está o número de vezes que cada dígito aparece no array:
* 0 -> 0
* 1 -> 1
* 2 -> 2
* 3 -> 2
* 4 -> 1
* 5 -> 2
* 6 -> 0
* 7 -> 1
* 8 -> 1
* O maior número de vezes que qualquer número ocorre na matriz é 2, e os dígitos que aparecem 2 vezes são 2, 3 e 5. 
* Portanto, a resposta é [2, 3, 5].
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