#include <vector>
#include <iostream>
using namespace std;
int numberOfOnes(vector<vector<int>> &V)
{
    int maxOnes = INT32_MIN;
    int maxOnesRow = -1;
    int columns = V[0].size();
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            int onesCount = columns - j;
            if (V[i][j] == 1)
            {
                if (onesCount > maxOnes)
                {
                    maxOnes = onesCount;
                    maxOnesRow = i;
                }
            break;
            }
        }
    }
    return maxOnesRow;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vect(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cin >> vect[i][j];
        }
    }
    cout << endl;
    int row = numberOfOnes(vect);
    cout << row;
}