//思路：不断选取S的开头和结尾中较小的一个字符放到T的末尾
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    char arr[2000];
    //cin>>n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int a = 0, b = n - 1, num;
        while (a <= b)
        {
            //将从左起和从有起的字符串比较
            bool left = false;
            for (int i = 0; a + i <= b; i++)
            {
                if (arr[a + i] < arr[b - i])
                {
                    left = true;
                    break;
                }
                else if (arr[a + i] > arr[b - i])
                {
                    left = false;
                    break;
                }
            }
            if (left)
                cout << arr[a++];
            else
                cout << arr[b--];
            ans++;
            if (ans == 80)
            {
                cout<<"\n";
                ans = 0;
            }
        }
        cout << endl;
    }
    return 0;
}