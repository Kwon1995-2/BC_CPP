#include <stdio.h> 
#include <stdlib.h> 
#include <stack>
#include <iterator>

using namespace std;

// 이진 탐색 트리

typedef struct node {   // 노드 구조체
    int key;
    struct node* left;  // 왼쪽 자식 포인터
    struct node* right; // 오른쪽 자식 포인터
} NODE;

int cnt = 0;    // 노드를 방문하는 회수 저장
NODE* search(NODE* root, int key) {
    cnt++;
    if (root == NULL) return NULL;

    if (root->key == key) return root; //key가 자기 자신인 경우 찾았으므로 리턴
    else if (root->key < key) return search(root->right, key); //현재키<찾으려는 키면 오른쪽 트리로(큰수로)
    else return search(root->left, key); //아니면 왼쪽 트리로
}

NODE* newNode(int item) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(NODE* root) { //중위 순회로 출력
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

NODE* insert(NODE* node, int key) {
    if (node == NULL) return newNode(key); //트리가 비었다면 새로 노드를 만듦

    if (key < node->key) node->left = insert(node->left, key); //찾는키<노드키면 왼쪽
    else if (key > node->key) node->right = insert(node->right, key); //반대면 오르쪽

    return node; //노드 포인터 반환
}

void appendStack(std::stack<NODE*>& st, NODE* node)
{
    st.push(node);
    if (node->left != NULL) appendStack(st, node->left);
    if (node->right != NULL) appendStack(st, node->right);
}

void deleteNodes(NODE* root)
{
    std::stack<NODE*> st;

    st.push(root);
    if (root->left != NULL) appendStack(st, root->left);
    if (root->right != NULL) appendStack(st, root->right);

    while (1)
    {
        NODE* node = st.top();
        printf("delete : %d\n", node->key);
        delete node;
        st.pop();

        if (st.size() == 0) break;
    }
}

// 이진 탐색 트리 
int main()
{
    NODE* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 40);
    insert(root, 20);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);

    cnt = 0;    // 노드 방문 횟수 초기화
    search(root, 40);

    printf("찾는 데 몇 번 순회?: %d\n", cnt);

    inorder(root); //출력

    deleteNodes(root);

    return 0;
}