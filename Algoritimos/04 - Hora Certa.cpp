//Autor:Bruno Harlis
//Data: 21/06/2020

/*****************************************************************************************
* PROBLEMA
* Dato uma string, verificar se a string tem o formato padrao de hora "24:00"
* 
* Exemplo 1:
* Entrada: ["23:10:]
* Saida: true
* 
* Exemplo 2:
* Entrada: ["31:40"]
* Saida: false
*****************************************************************************************/
#include <iostream>

using namespace std;

bool horaCerta(string& s)
{
    //verifica se a string tem o padrao "00:00"
    if (s.size() != 5) return false;

    //verifica se os 3 primeiros digitos segem o padrao de "00:--" ao "19:--"
    if (s[0] == '0' || s[0] == '1' && s[1] >= 48 && s[1] <= 57 && s[2] == ':')
        //verifica se os digitos finais segem o padrao de "---00" ao "---59"
        if (s[3] >= 48 && s[3] <= 53 && s[4] >= 48 && s[4] <= 57)
            return true;
        else
            return false;
    else
        //verifica se os 3 primeiros digitos segem o padrao de "20:--" ao "23:--"
        if (s[0] == '2' && s[1] >= 48 && s[1] <= 51 && s[2] == ':')
            //verifica se os digitos finais segem o padrao de "---00" ao "---59"
            if (s[3] >= 48 && s[3] <= 53 && s[4] >= 48 && s[4] <= 57)
                return true;
            else
                return false;
        else
            return false;
}

int main()
{
    string x{ "03:09" };
    
    if (horaCerta(x))
        cout << x << endl;
    else
        cout << "Formato de hora errado" << endl;

    return 0;
}
