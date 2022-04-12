#include <iostream>

using namespace std;

template <typename T>
class BinaryNode {
	template <typename T>
	friend class BinaryTree;
private:
	T data;
	BinaryNode* lchild;
	BinaryNode* rchild;
public:
	BinaryNode() {
		this->lchild = NULL;
		this->rchild = NULL;
	}

	BinaryNode(const T& val) {
		this->data = val;
		this->lchild = NULL;
		this->rchild = NULL;
	}

	BinaryNode(const T& val, BinaryNode<T>* ldata, BinaryNode<T>* rdata) {
		this->data = val;
		this->lchild = ldata;
		this->rchild = rdata;
	}

	~BinaryNode() {
		this->lchild = NULL;
		this->rchild = NULL;
	}

	void visit() {
		cout << this->data << " ";
	}

	BinaryNode<T>* getLchild() {
		return this->lchild;
	}

	BinaryNode<T>* getRchild() {
		return this->rchild;
	}
};


template <typename T>
class BinaryTree {
private:
	BinaryNode<T>* root;
public:
	BinaryTree() {
		cout << "创建二叉树" << endl;
		root = NULL;
		create_BinaryTree(root);
	}

	~BinaryTree() {
		root = NULL;
	}

	void create_BinaryTree(BinaryTree<T>*& treeNode) {
		cout << "输入节点值：" << endl;
		T val;
		cin >> val;
		treeNode = BinaryNode<T>(val);
		if (treeNode->data == '#'){
			delete treeNode;
			treeNode=NULL;
		}
		else {
			create_BinaryTree(treeNode->lchild);
			create_BinaryTree(treeNode->rchild);
		}
	}

	BinaryNode<T>* getRoot() {
		return this->root;
	}

	int caculater_deep(BinaryNode<T>* treeNode) {
		int deepth = 0;
		int rdeep = caculater_deep(treeNode->getLchild());
		int ldeep = caculater_deep(treeNode->getRchild());
		deepth = rdeep > ldeep ? rdeep + 1 : ldeep + 1;
		return deepth;
	}
};

void test() {
	BinaryTree<char>treeNode;
	cout << "二叉树的深度：" << treeNode.caculater_deep(treeNode.getRoot()) << endl;
}
int main() {
	test();
	return 0;
}