#pragma once

enum colour
{
	RED,
	BLACK,
};

template<class k, class v>
struct RBTreeNode
{
	RBTreeNode<k, v>* _left;
	RBTreeNode<k, v>* _right;
	RBTreeNode<k, v>* _parent;
	pair<k, v> _kv;
	colour _col;

	RBTreeNode(const pair<k, v>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class k, class v>
class RBTree
{
	typedef RBTreeNode<k, v> node;
public:
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

public:

	node* Find(const k& key)
	{
		node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
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

	bool Insert(const pair<k, v>& kv)
	{
		if (_root == nullptr)
		{
			_root = new node(kv);
			return true;
		}

		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new node(kv);
		if (parent->_kv.first > cur->_kv.first)
		{
			parent->_left = cur;

		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent->_parent;

		while (parent && parent->_col == RED)
		{
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
					parent = cur = parent;
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
		return true;
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