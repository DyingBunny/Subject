//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//
//using namespace std;
//
//
///*������������������ʵ����ĿҪ��Ĺ���
//��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
//******************************��ʼд����******************************/
//int schedule(int m, vector < int > array) {
//
//
//}
///******************************����д����******************************/
//
//
//int main() {
//	int res;
//
//	int _array_size = 0;
//	int m;
//	cin >> m;
//	cin >> _array_size;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	vector<int> _array;
//	int _array_item;
//	for (int _array_i = 0; _array_i<_array_size; _array_i++) {
//		cin >> _array_item;
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		_array.push_back(_array_item);
//	}
//
//
//
//	res = schedule(m, _array);
//	cout << res << endl;
//
//	return 0;
//
//}

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
int main()
{
	int computer;
	int num;
	std::cin >> computer;
	std::cin >> num;
	int tmp = num;
	std::vector<int> v;
	while (tmp)
	{
		int input;
		std::cin >> input;
		v.push_back(input);
		tmp--;
	}
	
	int count = num / computer;
	std::vector<int> v1;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (!std::count(v1.begin(), v1.end(), v[i] + v[j]))
			{			
				v1.push_back(v[i] + v[j]);
			}		
		}
	}
	std::sort(v1.begin(), v1.end());
	std::cout << v1[v1.size() / 2];
	return 0;
}