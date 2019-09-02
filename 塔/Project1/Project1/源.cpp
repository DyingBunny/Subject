#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;
	int tmp = n;
	int sum = k;
	std::vector<int> input;
	std::vector<int> result;
	while (tmp){
		int height;
		std::cin >> height;
		input.push_back(height);
		tmp--;
	}
	while (k){
		int max = 0;
		int max_index = 0;
		int min = 0;
		int min_index = 0;
		for (int i = 0; i < n; i++){
			if (input[i]>max){
				max = input[i];
				max_index = i;
			}
		}
		min = max;
		for (int i = 0; i < n; i++){
			if (input[i]<min){
				min = input[i];
				min_index = i;
			}
		}
		if (max == min){
			break;
		}
		input[max_index]--;
		input[min_index]++;
		result.push_back(max_index+1);
		result.push_back(min_index+1);
		k--;
	}
	int count = sum - k;
	int unstable = 0;
	unstable = *std::max_element(input.begin(), input.end()) - *std::min_element(input.begin(), input.end());
	std::cout << unstable <<" "<<count << std::endl;
	int num = 1;
	for (auto it : result){
		if (num == 2){		
			std::cout << it;
			std::cout << "\n";		
			num = 0;
		}
		else{
			std::cout << it<<" ";
			num++;
		}
	}
	return 0;
}

//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//int tur[111];
//int ansx[1111];
//int ansy[1111];
//int main()
//{
//	int n, k;
//	while (scanf("%d%d", &n, &k) != EOF)
//	{
//		int i;
//		int minn = 11111, maxx = 0;
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &tur[i]);
//			maxx = max(maxx, tur[i]);
//			minn = min(minn, tur[i]);
//		}
//		int s = maxx - minn;
//		int cont = 0;
//		for (i = 1; i <= k; i++)
//		{
//			minn = 11111; maxx = 0;
//			int maxid, minid;
//			for (int j = 1; j <= n; j++)
//			{
//				if (maxx<tur[j])
//				{
//					maxx = tur[j];
//					maxid = j;
//				}
//				if (minn>tur[j])
//				{
//					minn = tur[j];
//					minid = j;
//				}
//
//			}
//			if (minn + 1 >= maxx)
//				break;
//			else
//			{
//				tur[minid] += 1;
//				tur[maxid] -= 1;
//				ansx[i] = maxid;
//				ansy[i] = minid;
//				cont++;
//			}
//		}
//		minn = 11111; maxx = 0;
//		for (int j = 1; j <= n; j++)
//		{
//			//printf("%d\n",tur[i]);
//			maxx = max(maxx, tur[j]);
//			minn = min(minn, tur[j]);
//		}
//		int b = maxx - minn;
//
//		printf("%d %d\n", b, cont);
//		for (i = 1; i <= cont; i++)
//			printf("%d %d\n", ansx[i], ansy[i]);
//	}
//}
