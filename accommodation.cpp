#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countOnes(const string &str)
{
    return count(str.begin(), str.end(), '1');
}

int calculateMaxPairs(const string &str, int stringLength)
{
    int maxPairs = 0;
    int j = 0;

    while (j < stringLength - 1)
    {
        if (str[j] == '1' && str[j + 1] == '1')
        {
            maxPairs++;
            j += 2;
        }
        else
        {
            j++;
        }
    }

    return min(maxPairs, stringLength / 4);
}

int calculateMinPairs(const string &str, int stringLength)
{
    int numOnes = countOnes(str);
    int minPairs = numOnes - calculateMaxPairs(str, stringLength);
    return minPairs;
}

int calculateMinPairsCount(const string &str, int stringLength)
{
    int minPairsCount = 0;
    int j = 0;

    while (j < stringLength - 1)
    {
        if (str[j] == '0' || str[j + 1] == '0')
        {
            minPairsCount++;
            j += 2;
        }
        else
        {
            j++;
        }
    }

    return min(stringLength / 4, minPairsCount);
}

int calculateTotalMaxPairs(const string &str, int stringLength)
{
    int numOnes = countOnes(str);
    int minPairsCount = calculateMinPairsCount(str, stringLength);
    return numOnes - ((stringLength / 4) - minPairsCount);
}

int main()
{
    int numStrings, stringLength;
    cin >> numStrings >> stringLength;

    int totalMaxPairs = 0, totalMinPairs = 0;

    while (numStrings--)
    {
        string str;
        cin >> str;

        totalMaxPairs += calculateTotalMaxPairs(str, stringLength);
        totalMinPairs += calculateMinPairs(str, stringLength);
    }

    cout << totalMinPairs << " " << totalMaxPairs << endl;

    return 0;
}
