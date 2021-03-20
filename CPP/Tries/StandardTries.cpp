#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 10000
using namespace std; 
//
//class Node {
//private:
//	char alpha;
//	Node* next;
//public:
//
//};
//class Root {
//private:
//	Node* root[26];
//};
#include <cstdio>
#include <cstring>

#define ALPHABETS 26

// Convert char to array index
// All are base on capital
int char_to_index(char c) {
	return c - 'A';
}
struct Trie {
	bool finish;
	Trie* next[26];
	Trie() : finish(0) {
		memset(next, 0, sizeof(next));//next로 시작하는 메모리 주소부터 next개의 바이트를 0값으로 채운다.
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
	Trie* find(const char* key) {
		if (*key == '\0') return this;
		int curr = *key - 'a';
		if (next[curr] == NULL)return NULL;
		return next[curr]->find(key + 1);
	}
	//bool is_terminal; // this represents end of string
	//Trie* children[ALPHABETS];

	//// Constructor
	//Trie() : is_terminal(false) {
	//	memset(children, 0, sizeof(children));
	//}

	//// Delete all children
	//~Trie() {
	//	for (int i = 0; i < ALPHABETS; ++i) {
	//		if (children[i])
	//			delete children[i];
	//	}
	//}

	//void insert(const char* key) {
	//	if (*key == '\0') {
	//		is_terminal = true;
	//	}
	//	else {
	//		int index = char_to_index(*key);

	//		if (children[index] == 0)
	//			children[index] = new Trie();
	//		children[index]->insert(key + 1);
	//	}
	//}

	//Trie* find(const char* key) {
	//	if (*key == 0) {
	//		return this;
	//	}

	//	int index = char_to_index(*key);
	//	if (children[index] == 0) {
	//		return NULL;
	//	}

	//	return children[index]->find(key + 1);
	//}

	//bool string_exist(const char* key) {
	//	if (*key == 0 && is_terminal) {
	//		return true;
	//	}

	//	int index = char_to_index(*key);
	//	if (children[index] == 0) {
	//		return false;
	//	}
	//	return children[index]->string_exist(key + 1);
	//}


};

int main()
{
	/*int t, n, r;
	char a[MAX_N][11];

	cin >> t;
	while (t--) {
		cin >> n;
		getchar();
		for (int i = 0; i < n; i++)
			cin >> a[i];
		Trie* root = new Trie;
		r = 0;
		for (int i = 0; i < n; i++)
			root->insert(a[i]);
		for (int i = 0; i < n; i++) {
			if (root->find(a[i])) {
				r = 1;
			}
		}
		printf("%s\n", r ? "NO": "YES");
	}
	return 0;*/
	Trie* root = new Trie();

	const char* words[5] = { "be", "bee", "can", "cat", "cd" };

	for (int i = 0; i < 5; ++i) {
		printf("insert : %s\n", words[i]);
		root->insert(words[i]);
	}

	printf("\n");

	printf("%s : be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

	printf("\n");

	/*printf("%s : c\n", root->string_exist("c") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : be\n", root->string_exist("be") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : bee\n", root->string_exist("bee") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : candy\n", root->string_exist("candy") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : cd\n", root->string_exist("cd") != 0 ? "String Exist" : "String Not Exist");
	*/
	delete root;

	return 0;
}