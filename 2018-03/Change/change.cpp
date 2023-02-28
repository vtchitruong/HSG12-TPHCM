#include <iostream>
#include <fstream>
#include <vector>

#define inputFile "change.inp"
#define outputFile "change.out"

using namespace std;

int n, k;
vector<vector<int>> d; // d[p][g] là số cách đổi p phiếu lấy quà với mức giá từ 1..g

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> k;

    f.close();
}

void Process()
{
    // Khởi tạo mảng d
    d.resize(n + 1, vector<int>(k + 1, 0)); // n hàng, k cột đều mang giá trị 0
    
    // Nếu mức giá g = 1 thì chỉ có duy nhất 1 cách đổi với bất kì số phiếu nào
    // Khởi tạo cột 1 đều mang giá trị là 1    
    for (int p = 1; p < n + 1; ++p)
    {
        d[p][1] = 1;
    }

    // p: phiếu, ứng với hàng; g: giá, ứng với cột
    for (int p = 1; p < n + 1; ++p)
    {
        for (int g = 2; g < k + 1; ++g)
        {            
            if (p < g)
            {
                d[p][g] = d[p][g - 1];
            }
            else if (p == g)
            {
                d[p][g] = d[p][g - 1] + 1;
            }
            else
            {
                d[p][g] = d[p][g - 1] + d[p - g][g];
            }
        }
    }
}

void Output()
{
    ofstream f;
    f.open(outputFile);

    f << d[n][k];

    f.close();
}

void show_d()
{
    for (int r = 0; r < n + 1; ++r)
    {
        for (int c = 0; c < k + 1; ++c)
        {
            cout << d[r][c] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    Input();
    Process();
    Output();

    show_d();

    return 0;
}