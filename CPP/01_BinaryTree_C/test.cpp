// 이진트리의 순회

// 전위 순회(Preorder Traversal)	: P-L-R
// 중위 순회(Inorder Traversal)		: L-P-R
// 후위 순회(Postorder Traversal)	: L-R-P

#include <iostream>

#define CAPACITY	15	// node의 총수

using namespace std;

// 노드 구조체
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}NODE, * LPNODE;

// 전위 순회
void preorder(LPNODE ptr)
{
	if (ptr)
	{
		cout << char(ptr->data) << ' ';
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

// 중위 순회
void inorder(LPNODE ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		cout << char(ptr->data) << ' ';
		inorder(ptr->right);
	}
}

// 후위 순회
void postorder(LPNODE ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << char(ptr->data) << ' ';
	}
}

int main()
{
	NODE nodes[CAPACITY + 1];
	for (int i = 1; i <= CAPACITY; i++)
	{
		nodes[i].data = 'A' + i - 1;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}
	for (int i = 2; i <= CAPACITY; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].left = &nodes[i];
		}
		else
		{
			nodes[i / 2].right = &nodes[i];
		}
	}
	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;
}