#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//int maxN = 200;
	//int maxD = 100;
	//int maxV = maxN + maxD + 1;
	int n, k, d, max, finish, z, foodid;
	int lim[100], a[3001][300], ka[3001], c[301][301], f[301][301];
	char ch;

	ifstream f1;
	f1.open("input.txt");
	if (!f1.is_open())
	{
		cout << "input not founded" << endl;
	}
	else
	{
		string buff, x, y;

		getline(f1, buff);
		int pos = 0;
		pos = buff.find(" ");
		x = buff.substr(0, pos);
		y = buff.substr(pos, buff.length());
		n = atoi(x.c_str());
		k = atoi(y.c_str());
		buff.clear();

		getline(f1, buff); 
		d = atoi(buff.c_str());
		buff.clear();

		finish = n + d + 1;

		//�������-�����
		ka[0] = n;                                //�� ������ - n ��� � ������ ������
		for (int i = 0; i < n; i++)
		{
			a[0][i] = i;                          //����� �������, ����������� � �������
			c[0][i] = k;                          //�� ��� - ���� ���-�� ���� ������
		}

		for (int i = 0; i < d; i++)               //������� ���� ������� ����
		{
			
			f1.get(ch);
			lim[i] = static_cast<int>(ch);

		}
		
		//�������-����
		for (int i = 0; i < n; i++) 
		{
			ka[i] = 1;
			a[i][1] = finish;                      //���� ���� �� ������� ����� � �����
			c[i][finish] = lim[i - n];             //�� ��� - ������ ����� ���� ������� ����
		}
	
		//������� �� ����� � ������
		for (int i = 0; i < n; i++)
		{            
			getline(f1, buff);
			z = buff.size() / 2 + 1;
			ka[i] = z;                            //���������� ����, ������� ��� �������
			//��� ������� ������ �����
			for (int j = 0; j < z; j++)
			{
				string asd = buff.substr((j + 1) * 2 - 2, (j + 1) * 2 - 2);   //������ ��� �����
				foodid = atoi(asd.c_str());
				a[i][j] = n + foodid;             //��������� ���� �� ������ � �����
				c[i][a[i][i]] = 1;                //��� ����� ���� - 1
			}
		}

		//�����, �������� � �������-����, � ������� maxV
		max = 0;
		for (int i = n; i < n + d; i++)
		{
			max = max + f[i][finish];
		}

		ofstream f2;
		f2.open("output.txt");
		f2 << max;
		f2.close();
	}
	f1.close();
	
}