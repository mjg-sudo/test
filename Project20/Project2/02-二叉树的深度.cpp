#include<iostream>
#include<queue>
using namespace std;

//结点类
template<class T>
class BinaryTreeNode {
	//友元类声明
	template<class T>
	friend class BinaryTree;
private:
	T data;
	BinaryTreeNode<T>* leftchild;
	BinaryTreeNode<T>* rightchild;
public:
	//构造函数
	BinaryTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	BinaryTreeNode(const T& dataValue) {
		data = dataValue;
		leftchild = NULL;
		rightchild = NULL;
	}
	BinaryTreeNode(const T& dataValue, BinaryTreeNode<T>* leftchildValue, BinaryTreeNode<T>* rightchildValue) {
		data = dataValue;
		leftchild = leftchildValue;
		rightchild = rightchildValue;
	}
	//析构函数
	~BinaryTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	//访问结点
	void VisitNode() {
		cout << data << " ";
	}
	//取左结点
	BinaryTreeNode<T>* getLeft() {
		return leftchild;
	}
	//取右结点
	BinaryTreeNode<T>* getRight() {
		return rightchild;
	}
};

//二叉树类
template<class T>
class BinaryTree {
private:
	BinaryTreeNode<T>* root;
public:
	//构造函数
	BinaryTree() {
		root = NULL;
		cout << "Now start to construct the BinaryTree" << endl;
		CreateNode(root);
	}
	//析构函数
	~BinaryTree() {
		root = NULL;
	}
	//前序构建二叉树
	void CreateNode(BinaryTreeNode<T>*& treeNode) {
		cout << "Please enter a value or '#' to stop:";
		T dataValue;
		cin >> dataValue;
		treeNode = new BinaryTreeNode<T>(dataValue);
		if (treeNode->data == '#') {
			delete treeNode;
			treeNode = NULL;
		}
		else {
			CreateNode(treeNode->leftchild);
			CreateNode(treeNode->rightchild);
		}
	}
	//取根节点
	BinaryTreeNode<T>* getRoot() {
		return root;
	}
	//递归算法求二叉树深度
	int CaculateTreeDepth1(BinaryTreeNode<T>* treeNode) {
		if (treeNode == NULL) {
			return 0;
		}
		int depth = 0;
		int leftDepth = CaculateTreeDepth1(treeNode->getLeft());//求左子树的深度		
		int rightDepth = CaculateTreeDepth1(treeNode->getRight());//求右子树的深度
		depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//求二叉树的深度
		return depth;
	}
	//非递归算法求二叉树深度
	int CaculateTreeDepth2(BinaryTreeNode<T>* treeNode) {
		queue<BinaryTreeNode<T>*> q;
		if (treeNode == NULL) {
			return 0;
		}
		q.push(treeNode);
		int depth = 0;
		while (!q.empty()) {
			depth++;
			for (int size = q.size(); size > 0; size--) {
				BinaryTreeNode<T>* p = q.front();
				q.pop();
				if (p->getLeft()) {
					q.push(p->getLeft());
				}
				if (p->getRight()) {
					q.push(p->getRight());
				}
			}
		}
		return depth;
	}
};
int main() {
	//前序构建二叉树
	BinaryTree<char> test;
	//求二叉树深度
	cout << endl << "递归求得深度：";
	cout << test.CaculateTreeDepth1(test.getRoot());
	cout << endl << "非递归求得深度：";
	cout << test.CaculateTreeDepth2(test.getRoot());
}