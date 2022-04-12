#include <iostream>

using namespace std;

template<typename T>
class binaryNode {
	template<typename T>
	friend class binaryTree;

public:
	binaryNode() {
		this->lchild = NULL;
		this->rchild = NULL;
	}

	binaryNode(const T &val) {
		this->data = val;
		this->lchild = NULL;
		this->rchild = NULL;
	}

	binaryNode(const T& val, binaryNode<T>* lval, binaryNode<T>* rval) {
		this->data = val;
		this->lchild = lval;
		this->rchild = rval;
	}

	~binaryNode() {
		this->lchild = NULL;
		this->rchild = NULL;
	}

	void visit() {
		cout << "访问的节点：" << this->data << endl;
	}

	binaryNode<T>* getLchild() {
		return this->lchild;
	}

	binaryNode<T>* getRchild() {
		return this->rchild;
	}
	
private:
	T data;
	binaryNode* lchild;
	binaryNode* rchild;
};

template <typename T>
class binaryTree {
public:
	binaryTree() {
		root = NULL;
		cout << "创建树" << endl;
		create_binaryTree(root);
	}

	~binaryTree() {
		root = NULL;
	}

	void create_binaryTree(binaryNode<T>*&treeNode) {
		cout << "输入节点中的值：" << endl;
		T val;
		cin >> val;

		treeNode = new binaryNode<T>(val);
		if (val == '#') {
			delete treeNode;
			treeNode = NULL;
		}
		
		else {
			create_binaryTree(treeNode->lchild);
			create_binaryTree(treeNode->rchild);
		}
	}

	binaryNode<T>* getRoot() {
		return root;
	}

	int getDeep(binaryNode<T>* treeNode) {
		if (treeNode == NULL) {
			return 0;
		}

		int deepth = 0;
		int rdeep = getDeep(treeNode->getLchild());
		int ldeep = getDeep(treeNode->getRchild());
		deepth = rdeep > ldeep ? rdeep + 1 : ldeep + 1;
	}
private:
	binaryNode<T>* root;
};

void test() {
	binaryTree<char>treeNode;
	
	cout << "二叉树的深度为：";
	cout<< treeNode.create_binaryTree(treeNode.getRoot()) << endl;
}

int main() {
	test();
}