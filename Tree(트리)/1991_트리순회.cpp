//이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다.둘째 줄부터 N개의 줄에 걸쳐 
//각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 
//항상 A가 루트 노드가 된다.자식 노드가 없는 경우에는.으로 표현된다.
//
//출력
//첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다.각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
	char left;
	char right;
};

struct node arr[100];

void print_preorder(char root)
{
	if (root == '.')
		return ;
	cout << root;
	print_preorder(arr[root].left);
	print_preorder(arr[root].right);
}

void print_inorder(char root)
{
	if (root == '.')
		return;
	
	print_inorder(arr[root].left);
	cout << root;
	print_inorder(arr[root].right);
}

void print_postorder(char root)
{
	if (root == '.')
		return;
	
	print_postorder(arr[root].left);
	print_postorder(arr[root].right);
	cout << root;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		arr[t1].left = t2;
		arr[t1].right = t3;
	}

	print_preorder('A');
	cout << endl;
	print_inorder('A');
	cout << endl;
	print_postorder('A');
	cout << endl;

}
