#include <iostream>   
#include <string>  
using namespace std;  
int main()  
{  
	int T; 
	int num[21][21];  
	cin >> T;  
	while(T--) 
	{  
		for(int i = 0; i < 21; i++)  
			for(int j = 0; j < 21; j++)  
				num[i][j] = 0;  
		int n;  
		string flag;  
		cin >> n;  
		cin >> flag;  
		for(int i = 0; i < n; i++)  
			for(int j = 0; j < n; j++)  
				cin >> num[i][j];  
		if(flag == "up")  
		{  
			for(int j = 0; j < n; j++)  
			{  
				for(int i = 0; i < n; i++)  
				{  
					if(num[i][j] != 0)  
					{  
						int tmp_i = i;  
						while(num[++i][j] == 0)  
						{;}  
						if(i < n && num[tmp_i][j] == num[i][j])  
						{  
							num[tmp_i][j] = num[tmp_i][j] * 2;  
							num[i][j] = 0;  
						}  
						i--;  
					}  
				}  
			}  
			for(int j = 0; j < n; j++)  
			{  
				int index = 0;  
				for(int i = 0; i < n; i++)  
					if(num[i][j] != 0)  
					{  
						int tmp = num[index][j];  
						num[index][j] = num[i][j];  
						num[i][j] = tmp;  
						index++;  
					}  
			}  
		}  
		else if(flag == "down")  
			{  
			for(int j = 0; j < n; j++)  
			{  
				for(int i = n - 1; i > -1; i--)  
				{  
					if(num[i][j] != 0)  
					{  
						int tmp_i = i;  
						while(num[--i][j] == 0)  
						{}  
						if(i >= 0 && num[tmp_i][j] == num[i][j])  
						{  
							num[tmp_i][j] = num[tmp_i][j] * 2;  
							num[i][j] = 0;  
						}  
						i++;  
					}  
				}  
			}  
			for(int j = 0; j < n; j++)  
			{  
				int index = n - 1;  
				for(int i = n - 1; i >= 0; i--)  
					if(num[i][j] != 0)  
					{  
						int tmp = num[index][j];  
						num[index][j] = num[i][j];  
						num[i][j] = tmp;  
						index--;  
					}  
			}     
		}  
		else if(flag == "left")  
			{  
			for(int i = 0; i < n; i++)  
			{  
				for(int j = 0; j < n; j++)  
				{  
					if(num[i][j] != 0)  
					{  
						int tmp_j = j;  
						while(num[i][++j] == 0)  
						{}  
						if(j < n && num[i][tmp_j] == num[i][j])  
						{  
							num[i][tmp_j] = num[i][tmp_j] * 2;  
							num[i][j] = 0;  
						}  
						j--;  
					}  
				}  
			}  
			for(int i = 0; i < n; i++)  
			{  
				int index = 0;  
				for(int j = 0; j < n; j++)  
					if(num[i][j] != 0)  
					{  
						int tmp = num[i][index];  
						num[i][index] = num[i][j];  
						num[i][j] = tmp;  
						index++;  
					}  
			}    
		}  
		else  
		{  
			for(int i = 0; i < n; i++)  
			{  
				for(int j = n - 1; j >= 0; j--)  
				{  
					if(num[i][j] != 0)  
					{  
						int tmp_j = j;  
						while(num[i][--j] == 0)  
						{}  
						if(j  >= 0 && num[i][tmp_j] == num[i][j])  
						{  
							num[i][tmp_j] = num[i][tmp_j] * 2;  
							num[i][j] = 0;  
						}  
						j++;  
					}  
				}  
			}  
			for(int i = 0; i < n; i++)  
			{  
				int index = n - 1;  
				for(int j = n - 1; j >= 0; j--)  
					if(num[i][j] != 0)  
					{  
						int tmp = num[i][index];  
						num[i][index] = num[i][j];  
						num[i][j] = tmp;  
						index--;  
					}  
			}  
		}
		for(int i = 0; i < n; i++)  
		{  
			for(int j = 0; j < n; j++)  
			{  
				cout << num[i][j];  
				if(j != n - 1)  
					cout << " ";  
			}  
			cout << endl;  
		}  
	}  
}  