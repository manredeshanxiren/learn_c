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

	//添加一个拷贝构造解决普通迭代器不能转换成const迭代器的情况
	//1.这时候const迭代器传过来就是普通构造
	//2.普通迭代器传过来就是拷贝构造
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
			//右不为空找右子树的最左节点
			Node* subleft = _node->_right;
			while (subleft->_left)
			{
				subleft = subleft->_left;
			}
			_node = subleft;
		}
		else
		{
			//右为空沿着根的路径，找到孩子是父亲左的那个祖先
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
			//左子树存在那么我们找到左子树的最右节点
			Node* subright = _node->_left;
			while (subright->_right)
			{
				subright = subright->_right;
			}
			_node = subright;
		}
		else
		{
			//如果左子树不存在那么我们找到孩子是父节点右子树的祖先节点
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
		//树为空的话则直接插入
		//并且将插入的节点赋值为黑色
		if (_root == nullptr)
		{
			_root = new node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		//否则的话分别保存当前节点
		//和当前节点的父节点
		node* parent = nullptr;
		node* cur = _root;
		KeyOfT kot;
		//寻找合适的插入位置
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
		//找到位置后
		cur = new node(data);
		//判断将其放在右子树还是左子树
		if (kot(parent->_data) > kot(cur->_data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		//并更新其的父节点
		cur->_parent = parent;
		//查看是否需要调整
		while (parent && parent->_col == RED)
		{
			//保存祖父节点
			node* GrandFather = parent->_parent;
			if (GrandFather->_left == parent)
			{
				node* uncle = GrandFather->_right;
				//情况1 ： u存在且为红，变色处理，并且向上调整
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					GrandFather->_col = RED;

					//继续往上调整
					cur = GrandFather;
					parent = cur->_parent;
				} 
				else // 情况2 + 3：u不存在/u存在且为黑，旋转+变色
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
				//情况1 ： u存在且为红，变色处理，并且向上调整
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					GrandFather->_col = RED;

					//继续往上调整
					cur = GrandFather;
					parent = cur = parent;
				}
				else//情况2 + 3
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
			cout << "根节点是红色的" << endl;
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
				cout << "黑色节点数量不相同" << endl;
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
			cout << "出现了连续的红色" << endl;
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