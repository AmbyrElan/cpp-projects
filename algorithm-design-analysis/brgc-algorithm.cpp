#include <iostream>
#include <string>
#include <vector>
using namespace std;

// generate gray code and subsets 
void generateGrayCodeSubsets(int n)
{
    // base case
    if (n <= 0)
        return;

    vector<string> arr;

    // start gray code at 1
    arr.push_back("0");
    arr.push_back("1");

    // loop through gray code
    int i, j;
    for (i = 2; i < (1 * pow(2,n)); i = (i * pow(2,1)))
    {
        // reverse every grayc code in the array currently
        for (j = i - 1; j >= 0; j--)
            arr.push_back(arr[j]);

        // append 0 to the first half of the array
        for (j = 0; j < i; j++)
            arr[j] = "0" + arr[j];

        // append 1 to the second half of the array
        for (j = i; j < 2 * i; j++)
            arr[j] = "1" + arr[j];
    }

    // print array
    cout << "Subsets: " << endl;
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
}

int inputNumItems()
{
    int n = 0;

    cout << "How many items? " << endl;
    cin >> n;

    return n;
}

int main()
{
    generateGrayCodeSubsets(inputNumItems());

    return 0;
}
