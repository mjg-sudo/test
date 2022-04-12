#include <iostream>

using namespace std;

template <typename T>
class treeNode {
public:
	T data;
	treeNode* lchild;
	treeNode* rchild;

	treeNode() {
		this->data = NULL;
		this->lchild = NULL;
		this->rchild = NULL;
	}

	static int deep_treeNode(treeNode<T>* node) {
		int count = 1;
		if (node == NULL) {
			return 0;
		}
		
		int right=deep_treeNode(node->rchild)
		return count;
	}

};

template <typename T>
void create_treeNode(treeNode<T>**node) {
	cout << "添加节点中的数值：";
	T val;
	cin >> val;
	if (val == '#') {
		node = NULL;
		cout << "此节点结束添加" << endl;
		return;
	}

	treeNode<T> *newNode = new treeNode<T>();
	*node = newNode;
	(*node)->data = val;
	cout << "添加左孩子" << endl;
	create_treeNode(&(*node)->lchild);
	cout << "添加右孩子" << endl;
	create_treeNode(&(*node)->rchild);

}

template <typename T>
void print_treeNode(treeNode<T>** node) {
	cout << &(*node)->data << endl;
	print_treeNode(&(*node)->lchild);
	print_treeNode(&(*node)->rchild);
}


void test() {
	treeNode<char> *node = new treeNode<char>();
	create_treeNode(&node);
	print_treeNode(&node);
}
int main() {
	test();
}