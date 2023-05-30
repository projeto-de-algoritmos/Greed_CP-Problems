#include <iostream>
#include <vector>

std::vector<int> readNumbers(int size)
{
    std::vector<int> numbers(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> numbers[i];
    }
    return numbers;
}

std::vector<int> getDistinctNumbers(const std::vector<int> &numbers)
{
    int size = numbers.size();
    std::vector<int> distinctNumbers = {numbers[0]};
    for (int i = 1; i < size - 1; i++)
    {
        if ((distinctNumbers.back() <= numbers[i] && numbers[i] <= numbers[i + 1]) ||
            (distinctNumbers.back() >= numbers[i] && numbers[i] >= numbers[i + 1]))
        {
            continue;
        }
        distinctNumbers.push_back(numbers[i]);
    }
    distinctNumbers.push_back(numbers[size - 1]);
    return distinctNumbers;
}

int countDistinctElements(const std::vector<int> &distinctNumbers)
{
    if (distinctNumbers.size() == 2 && distinctNumbers[0] == distinctNumbers[1])
    {
        return 1;
    }
    else
    {
        return distinctNumbers.size();
    }
}

void solveTestCases()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int size;
        std::cin >> size;
        std::vector<int> numbers = readNumbers(size);
        std::vector<int> distinctNumbers = getDistinctNumbers(numbers);
        int count = countDistinctElements(distinctNumbers);
        std::cout << count << "\n";
    }
}

int main()
{
    solveTestCases();
    return 0;
}
