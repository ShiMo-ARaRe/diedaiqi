//迭代器
//迭代器是访问容器中元素的通用方法。
//如果使用迭代器，不同的容器，访问元素的方法是相同的。
//迭代器支持的基本操作：赋值（=）、解引用（*）、比较（==和!=）、从左向右遍历（++）。
//一般情况下，迭代器是指针和移动指针的方法。
//
//迭代器有五种分类：
//1）正向迭代器
//只能使用++运算符从左向右遍历容器，每次沿容器向右移动一个元素。
//容器名<元素类型>::iterator 迭代器名;        // 正向迭代器。
//容器名<元素类型>::const_iterator 迭代器名;  // 常正向迭代器。
//相关的成员函数：
//iterator begin();
//const_iterator begin();
//const_iterator cbegin();  // 配合auto使用。
//iterator end();
//const_iterator end();
//const_iterator cend();
//2）双向迭代器
//具备正向迭代器的功能，还可以反向（从右到左）遍历容器（也是用++），不管是正向还是反向遍历，都可以用--让迭代器后退一个元素。
//容器名<元素类型>:: reverse_iterator 迭代器名;        // 反向迭代器。
//容器名<元素类型>:: const_reverse_iterator 迭代器名;  // 常反向迭代器。
//相关的成员函数：
//reverse_iterator rbegin();
//const_reverse_iterator crbegin();
//reverse_iterator rend();
//const_reverse_iterator crend();
//3）随机访问迭代器
//具备双向迭代器的功能，还支持以下操作：
//?	用于比较两个迭代器相对位置的关系运算（<、<=、>、>=）。
//?	迭代器和一个整数值的加减法运算（+、+=、-、-=）。
//?	支持下标运算（iter[n]）。
//数组的指针是纯天然的随机访问迭代器。
//4）输入和输出迭代器
//这两种迭代器比较特殊，它们不是把容器当做操作对象，而是把输入/输出流作为操作对象。
//
//
//示例：


#include <iostream>
#include <vector>
#include <list>
using  namespace std;

struct Node


{
	// 单链表的结点。
	int item;
	Node* next;
};

int* find_(int* arr, int n, const int& val)


{
	// 在整型数组arr中查找值为val的元素。
	for (int ii = 0; ii < n; ii++)                     // 遍历数组。
		if (arr[ii] == val)
			return &arr[ii];       // 如果找到了，返回数组中元素的地址。

	return nullptr;
}

int* find_(int* begin, int* end, const int& val)


{
	// 在整型数组的区间中查找值为val的元素。
	for (int* iter = begin; iter != end; iter++)      // 遍历查找区间。
		if (*iter == val)
			return iter;                         // 如果找到了元素，返回区间中的位置。

	return nullptr;
}

Node* find_(Node* begin, Node* end, const Node& val)


{
	// 在单链表中查找值为val的元素。
	for (Node* iter = begin; iter != end; iter = iter->next)      // 遍历链表。
		if (iter->item == val.item)
			return iter;           // 如果找到了，返回链表中结点的地址。

	return nullptr;
}

// 查找元素的算法。
template<typename T1, typename T2>

// begin-查找区间开始的位置；end-查找区间结束的位置；val-待查找的值。
T1 find_(T1 begin, T1 end, const T2& val)


{
	for (T1 iter = begin; iter != end; iter++)     // 遍历查找区间。         //现在明白为什么endl是末元素后一个位置了
		if (*iter == val)
			return iter;                       // 如果找到了元素，返回区间中的位置。

	return end;
}



int main()


{
	// 在vector容器中查找元素。

	vector<int> vv = { 1, 2, 3, 4, 5 };  // 初始化vector容器。
	vector<int>::iterator it2 = find_(vv.begin(), vv.end(), 3);


	if (it2 != vv.end())
		cout << "查找成功。\n";
	else
		cout << "查找失败。\n";




	// 在list容器中查找元素。
	list<int> ll = { 1, 2, 3, 4, 5 };           // 初始化vector容器。
	list<int>::iterator it3 = find_(ll.begin(), ll.end(), 3);

	if (it3 != ll.end())
		cout << "查找成功。\n";
	else
		cout << "查找失败。\n";
}









//#include <iostream>
//#include <vector>
//using  namespace std;
//
//class AA
//
//
//{
//	public:
//		string m_name;
//
//		AA()
//
//		{
//			cout << "默认构造函数AA()。\n";
//		}
//
//		AA(const string &name) : m_name(name)
//
//		{
//			cout << "构造函数，name=" << m_name << "。\n";
//		}
//
//		AA(const AA &a) : m_name(a.m_name)
//
//		{
//			cout << "拷贝构造函数，name=" << m_name << "。\n";
//		}
//
//		AA &operator=(const AA &a)
//
//		{
//			m_name = a.m_name;
//			cout << "赋值函数，name=" << m_name << "。\n";
//			return *this;
//		}
//
//		~AA()
//
//		{
//			cout << "析构函数，name=" << m_name << "。\n";
//		}
//};
//
//int main()
//
//
//{
//	vector<int> vv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	//for (auto it = vv.begin(); it != vv.end(); it++)     // 用迭代器遍历容器vv。
//	//{
//	//	cout << *it << " ";
//	//}
//	//cout << endl;
//
//	for (auto val : vv)
//
//	{
//		// 用基于范围的for循环遍历数组vv。
//		cout << val << " ";
//		vv.push_back(10);
//	}
//	cout << endl;
//
//	/*vector<AA> v;
//	cout << "1111，v.capacity()=" << v.capacity() << "\n";
//	v.emplace_back("西施");
//	cout << "2222，v.capacity()=" << v.capacity() << "\n";
//	v.emplace_back("冰冰");
//	cout << "3333，v.capacity()=" << v.capacity() << "\n";
//	v.emplace_back("幂幂");
//	cout << "4444，v.capacity()=" << v.capacity() << "\n";
//
//	for (const auto &a : v)
//		cout << a.m_name << " ";
//	cout << endl;*/
//}
