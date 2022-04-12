#include<iostream>
#include<queue>
using namespace std;

//�����
template<class T>
class BinaryTreeNode {
	//��Ԫ������
	template<class T>
	friend class BinaryTree;
private:
	T data;
	BinaryTreeNode<T>* leftchild;
	BinaryTreeNode<T>* rightchild;
public:
	//���캯��
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
	//��������
	~BinaryTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	//���ʽ��
	void VisitNode() {
		cout << data << " ";
	}
	//ȡ����
	BinaryTreeNode<T>* getLeft() {
		return leftchild;
	}
	//ȡ�ҽ��
	BinaryTreeNode<T>* getRight() {
		return rightchild;
	}
};

//��������
template<class T>
class BinaryTree {
private:
	BinaryTreeNode<T>* root;
public:
	//���캯��
	BinaryTree() {
		root = NULL;
		cout << "Now start to construct the BinaryTree" << endl;
		CreateNode(root);
	}
	//��������
	~BinaryTree() {
		root = NULL;
	}
	//ǰ�򹹽�������
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
	//ȡ���ڵ�
	BinaryTreeNode<T>* getRoot() {
		return root;
	}
	//�ݹ��㷨����������
	int CaculateTreeDepth1(BinaryTreeNode<T>* treeNode) {
		if (treeNode == NULL) {
			return 0;
		}
		int depth = 0;
		int leftDepth = CaculateTreeDepth1(treeNode->getLeft());//�������������		
		int rightDepth = CaculateTreeDepth1(treeNode->getRight());//�������������
		depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//������������
		return depth;
	}
	//�ǵݹ��㷨����������
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
	//ǰ�򹹽�������
	BinaryTree<char> test;
	//����������
	cout << endl << "�ݹ������ȣ�";
	cout << test.CaculateTreeDepth1(test.getRoot());
	cout << endl << "�ǵݹ������ȣ�";
	cout << test.CaculateTreeDepth2(test.getRoot());
}