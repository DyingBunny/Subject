//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//
//using namespace std;
//
//class ListNode {
//public:
//	int val;
//	ListNode* next;
//	ListNode(int val){
//		this->val = val;
//		this->next = NULL;
//	};
//};
//
///*������������������ʵ����ĿҪ��Ĺ���
//******************************��ʼд����******************************/
//ListNode* partition(ListNode* head, int m) {
//
//}
///******************************����д����******************************/
//
//
//int main() {
//	ListNode* head = NULL;
//	ListNode* node = NULL;
//	int m;
//	cin >> m;
//	int v;
//	while (cin >> v){
//		if (head == NULL){
//			node = new ListNode(v);
//			head = node;
//		}
//		else{
//			node->next = new ListNode(v);
//			node = node->next;
//		}
//	}
//	head = partition(head, m);
//	if (head != NULL){
//		cout << head->val;
//		node = head->next;
//		delete head;
//		head = node;
//		while (head != NULL){
//			cout << "," << head->val;
//			node = head->next;
//			delete head;
//			head = node;
//		}
//	}
//	cout << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>


int main()
{
	int input;
	std::cin >> input;
	std::vector<int> tmp;
	int x = 3;
	int a;
	while (x)
	{
		std::cin >> a;
		tmp.push_back(a);
		x--;
	}
	std::vector<int> result;
	for (auto it:tmp)
	{
		if (it <= input)
		{
			result.push_back(it);
		}
	}
	for (auto it : tmp)
	{
		if (it>input)
		{
			result.push_back(it);
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (i != result.size() - 1)
		{
			std::cout << result[i] << ",";
		}
		else
		{
			std::cout << result[i];
		}
	}
}
