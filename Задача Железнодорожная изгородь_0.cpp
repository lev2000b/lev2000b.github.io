#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int k;
    string str= "";

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> k;
    fin.ignore();
    getline(fin,str);
    int l = str.length();
    char** table = new char* [l];
    bool isDown = true;
    int index=0;
    for (int i = 0; i < l; i++) {
        table[i] = new char[k];
        for (int y = 0; y < k; y++) {
            table[i][k] = NULL;
        }
        table[i][index] = str[i];
        if (index == 0)isDown = true;
        else if (index == k - 1)isDown = false;
        if (isDown) {
            index++;
        }
        else index--;
    }

    string res = "";
    for (int y = 0; y < k; y++)
    {
        for (int i = 0; i < l; i++)
        {
            char c = table[i][y];
            if (c != -51)res = res + c;
        }
    }

    for (int i = 0; i < l; i++) {
        char c = res[i];
        while (c == 32 && res[i + 1] == 32)res.erase(i+1,1);
    }

    fout << res;
    fout.flush();
    fout.close();
    fin.close();
}