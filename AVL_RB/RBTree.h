#pragma once

enum colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	//���һ��������������ͨ����������ת����const�����������
	//1.��ʱ��const������������������ͨ����
	//2.��ͨ���������������ǿ�������
	__RBTreeIterator(const __RBTreeIterator<T, T&, T*>& it)
		:_node(it._node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator !=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			//�Ҳ�Ϊ����������������ڵ�
			Node* subleft = _node->_right;
			while (subleft->_left)
			{
				subleft = subleft->_left;
			}
			_node = subleft;
		}
		else
		{
			//��Ϊ�����Ÿ���·�����ҵ������Ǹ�������Ǹ�����
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent != nullptr && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			//������������ô�����ҵ������������ҽڵ�
			Node* subright = _node->_left;
			while (subright->_right)
			{
				subright = subright->_right;
			}
			_node = subright;
		}
		else
		{
			//�����������������ô�����ҵ������Ǹ��ڵ������������Ƚڵ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}


};

template<class k, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> node;
public:
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;


	node* Find(const k& key)
	{
		node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return false; 
	}

	pair<iterator, bool> Insert(const T& data)
	{
		//��Ϊ�յĻ���ֱ�Ӳ���
		//���ҽ�����Ľڵ㸳ֵΪ��ɫ
		if (_root == nullptr)
		{
			_root = new node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		//����Ļ��ֱ𱣴浱ǰ�ڵ�
		//�͵�ǰ�ڵ�ĸ��ڵ�
		node* parent = nullptr;
		node* cur = _root;
		KeyOfT kot;
		//Ѱ�Һ��ʵĲ���λ��
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}
		//�ҵ�λ�ú�
		cur = new node(data);
		//�жϽ����������������������
		if (kot(parent->_data) > kot(cur->_data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		//��������ĸ��ڵ�
		cur->_parent = parent;
		//�鿴�Ƿ���Ҫ����
		while (parent && parent->_col == RED)
		{
			//�����游�ڵ�
			node* GrandFather = parent->_parent;
			if (GrandFather->_left == parent)
			{
				node* uncle = GrandFather->_right;
				//���1 �� u������Ϊ�죬��ɫ�����������ϵ���
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					GrandFather->_col = RED;

					//�������ϵ���
					cur = GrandFather;
					parent = cur->_parent;
				} 
				else // ���2 + 3��u������/u������Ϊ�ڣ���ת+��ɫ
				{
					//     g
					//   p   u
					// c 
					if (cur == parent->_left)
					{
						RotateR(GrandFather);
						parent->_col = BLACK;
						GrandFather->_col = RED;
					}
					else
					{
						//    g
						//  p   u
						//		c 
						RotateL(parent);
						RotateR(GrandFather);

						cur->_col = BLACK;
						GrandFather->_col = RED;
					}
					break;
				}
			}
			else
			{
				//    g
				//u       p
				//               c
				node* uncle = GrandFather->_left;
				//���1 �� u������Ϊ�죬��ɫ�����������ϵ���
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					GrandFather->_col = RED;

					//�������ϵ���
					cur = GrandFather;
					parent = cur = parent;
				}
				else//���2 + 3
				{
					//    g
					//u       p
					//               c
					if (parent->_right == cur)
					{
						RotateL(GrandFather);
						parent->_col = BLACK;
						GrandFather->_col = RED;
					}
					//     g
					//u         p
					//     c
					else
					{
						RotateR(parent);
						RotateL(GrandFather);
						cur->_col = BLACK;
						GrandFather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(_root), true);
	}

	int Height()
	{
		return _Height(_root);
	}

	bool IsBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}

		if (_root&& _root->_col = RED)
		{
			cout << "���ڵ��Ǻ�ɫ��" << endl;
		}
		
		int benchmark = 0;
		node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				benchmark++;
			cur = cur->_left;
		}

		return _check(_root, 0, benchmark);
	}
	
	void _Inorder(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	iterator begin()
	{
		node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

private:
	void _Destroy(node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
	void RotateR(node* parent)
	{
		node* subL = parent->_left;
		node* subLR = subL->_right;


		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		node* ppnode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (ppnode == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
	}
	void RotateL(node* parent)
	{
		node* subR = parent->_right;
		node* subRL = subR->_left;


		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (ppnode == nullptr)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
	}
	bool _check(node* root, int BlackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark != BlackNum)
			{
				cout << "��ɫ�ڵ���������ͬ" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == BLACK)
		{
			BlackNum++;
		}

		if (root->_col == RED && root->parent && root->parent->_col == RED)
		{
			cout << "�����������ĺ�ɫ" << endl;
		}

		return _check(root->_left, BlackNum, benchmark) &&
			_check(root->_right, BlackNum, benchmark);

	}
	int _Height(node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);
		return leftH > rightH ? leftH + 1 : rightH + 1;
	}
private:
	node* _root;
};