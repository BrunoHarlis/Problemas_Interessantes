//Autor:Bruno Harlis
//Data: 21/06/2020

/*****************************************************************************************
 * Você recebe um array de strings arr. Sua tarefa é construir uma string a partir das palavras
 * em arr, começando com o caractere 0 de cada palavra (na ordem em que aparecem em arr), seguido
 * pelo caractere 1, então o caractere 2, etc. Se uma das palavras não tiver o caracter i, pule essa palavra.
 * Retorne a string resultante.
 * 
 * Exemplo
 * Para arr = ["Daisy", "Rose", "Hyacinth", "Poppy"], a saída deve ser lendoVerticalmente(arr) =" DRHPaoyoisapsecpyiynth ".
 * 
 * Primeiro, acrescentamos todos os caracteres 0 e obtemos a string " DRHP ";
 * Em seguida, acrescentamos todos os caracteres 1 e obtemos a string " DRHPaoyo ";
 * Em seguida, acrescentamos todos os caracteres 2 e obtemos a string " DRHPaoyoisap ";
 * Em seguida, acrescentamos todos os caracteres 3 e obtemos a string " DRHPaoyoisapaecp ";
 * Em seguida, acrescentamos todos os caracteres 4 e obtemos a string " DRHPaoyoisapaecpyiy ";
 * Finalmente, apenas as letras no arr [2] são deixadas, então acrescentamos os caracteres restantes e obtemos " DRHPaoyoisapaecpyiynth ";
 * *****************************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string unirNome(vector<string> &nomes)
{
    int maiorNome{0};
    string nome{""};

    if (nomes.size() == 0)
        return nome;
    if (nomes.size() == 1)
        return nomes[0];

    //pega o tamanho do maior nome
    for (int i{0}; i < nomes.size(); ++i)
    {
        if (maiorNome < nomes[i].size())
            maiorNome = nomes[i].size();
    }

    //Une a string caractere por caractere
    int count{0};
    while (count < maiorNome)
    {
        for (int i{0}; i < nomes.size(); ++i)
        {
            if (count < nomes[i].size())
                nome += nomes[i][count];
        }

        count++;
    }

    return nome;
}

int main()
{
    vector<string> x{"Daisy", "Rose", "Hyacinth", "Poppy"};

    if (unirNome(x) == "DRHPaoyoisapsecpyiynth")
        cout << unirNome(x) << endl;
    else
        cout << "Nao eh igual, seu burro!" << endl;

    return 0;
}