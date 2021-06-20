//Autor: Bruno Harlis
//Data: 20/06/2020

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Foi dado um vector de inteiros e foi proposto que fosse calculada a media dos numeros
* adjacentes ao indice e retornar quantas medias sao iguais ao indice. Caso nao houver numero a 
* esquerda ou direita, somar a 0 (zero).
*
* Exemplo:
* Entrada: nums = [0,1,2,3]
* Saída: [2]
* Explicacao: Indice [0] --- 0+1/2 = 0.5
*             Indice [1] --- 0+2/2 = 1 (ingual ao indice)
*             Indice [2] --- 1+3/2 = 2 (ingual ao indice)
*             Indice [3] --- 2+0/2 = 1
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 2.25 ms
* Memória Usada: 1 MB
*****************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int contarMediaAritmetica(vector<int> a) 
    {
        //Copiar o vector e converter para formato double
        vector<double>b{};
        copy(a.begin(), a.end(), back_inserter(b));

        double media{ 0 };
        int count{ 0 }; // contar quantas medias sao iguais ao indice

        for (unsigned i{ 0 }; i < b.size(); ++i)
        {
            //quando o indice eh 0
            if (i == 0)
            {
                media = (b[i + 1] + 0) / 2;
                if (media == b[i]) count++;
                continue;
            }

            //quando o indice eh o ultimo
            if(i == b.size() - 1)
            {
                media = (b[i - 1] + 0) / 2;
                if (media == b[i]) 
                    count++;
                continue;
            }

            //quando o indice esta no meio
            media = (b[i - 1] + b[i + 1]) / 2;
            if(media == b[i]) 
                count++;
        }

        return count;
    }
};

int main()
{
    vector<int> x{ 2, 4, 6, 6, 3 };

    Solution s;
    cout<< s.contarMediaAritmetica(x);

    return 0;
}
