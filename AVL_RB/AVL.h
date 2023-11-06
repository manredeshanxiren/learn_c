#pragma once

template<class k, class v>
struct AVLNode
{
	AVLNode<k, v>* _left;
	AVLNode<k, v>* _right;
	AVLNode<k, v>* _parent;
	pair<k, v> _kv;
	int _bf; //balance factor

	AVLNode(const pair<k, v>& kv)
	:_left(nullptr)
	,_right(nullptr)
	,_parent(nullptr)
	,_kv(kv)
	,_bf(0)
	{}
 };


template<class k, class v>
class AVLTree
{
	typedef AVLNode<k, v> node;
public:
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
		cur->_parent = parent;
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			//查看是否平衡
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				//需要更新父节点
				//向上查看
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if(parent->_bf == 0)
			{
				//证明该子树是平衡的此次的插入不会引起旋转
				break;
			}
			else if(parent->_bf == 2 || parent->_bf == -2)
			{
				//得旋转调整
				//右右左单旋
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				//左左右单旋
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				//右左，先右旋再左旋
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				//左右，先左旋再右旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				//否则的话属于异常情况
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	int Height()
	{
		return _Height(_root);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}


	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

private:
	void RotateL(node* parent)
		{
			//分别保存右子树和右子树的左子树
			node* subR = parent->_right;
			node* subRL = subR->_left;

			//将右子树的左子树放到parent的右节点
			parent->_right = subRL;
			//如果右子树的左子树存在的话更新他的父节点
			if (subRL)
				subRL->_parent = parent;
			//保存parent的父节点，后面要用于更新右子树的父节点
			node* ppnode = parent->_parent;
			//将parent赋值给右子树的左节点，并且更新parent的父节点
			subR->_left = parent;
			parent->_parent = subR;
			//查看parent是否为avl树的根节点
			//如果是根节点的话更新树的新的根节点为右子树
			//并且更新右子树的父节点
			if (ppnode == nullptr)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			//parent不是根节点的话
			//判断parent节点是其父节点的左子树还是右子树
			else
			{
				//若parent是其父节点的左子树
				if (ppnode->_left == parent)
				{
					//那么我们将右子树变成其父节点的左子树
					ppnode->_left = subR;
				}
				//同样若parent是其父节点的右子树
				else
				{
					//那么我们将右子树变成其父节点的右子树
					ppnode->_right = subR;
				}
				//最后更新右子树的父节点
				subR->_parent = ppnode;
			}
			//当我们进行左单旋的时候
			//当我们调整完成时，parent和右子树一定是平衡的
			parent->_bf = subR->_bf = 0;
		}
	void RotateR(node* parent)
		{
			//保存左子树和左子树的右子树
			node* subL = parent->_left;
			node* subLR = subL->_right;

			//将parent的左节点换成左子树的右节点
			parent->_left = subLR;
			//如果左子树的右子树不为空的更新他的父节点
			if (subLR)
				subLR->_parent = parent;
			//保存parent的父节点
			node* ppnode = parent->_parent;
			//更新左子树的的右节点为parent，并更新parent的父节点为左子树
			subL->_right = parent;
			parent->_parent = subL;
			//查看parent是否为树的根节点
			if (ppnode == nullptr)
			{
				//是树的根节点，那么我们要更新树的根节点为左子树
				//并更新其的父节点
				_root = subL;
				_root->_parent = nullptr;
			}
			//否则的话查看parent是父节点的左子树还是右子树
			//并将左子树赋值给parent对应的子树位置，并更新左子树的父节点
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
			//右单旋和左单旋一样操作完之后parent和左子树一定是平衡的
			parent->_bf = subL->_bf = 0;
		}
	void RotateLR(node* parent)
		{
			//首先保存左子树和右子树的左子树
			//保存左子树的右子树的平衡因子，以便后续调整平衡因子
			node* subL = parent->_left;
			node* subLR = subL->_right;
			int bf = subLR->_bf;
			//先对parent的左子树进行左旋
			RotateL(parent->_left);
			//再对parent进行右旋
			RotateR(parent);
			//调整平衡因子
			//分为以下几个情况画图最为清晰
			if (bf == 1)
			{
				parent->_bf = 0;
				subLR->_bf = 0;
				subL->_bf = -1;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subLR->_bf = 0;
				subL->_bf = 0;
			}
			else if (bf == 0)
			{
				parent->_bf = 0;
				subLR->_bf = 0;
				subL->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
	void RotateRL(node* parent)
	{
			//保存右子树
			//右子树的左子树
			//右子树左子树的平衡因子
			node* subR = parent->_right;
			node* subRL = subR->_left;
			int bf = subRL->_bf;
			//右旋转parent的右子树
			RotateR(parent->_right);
			//左旋转parent
			RotateL(parent);
			//更新平衡因子
			if (bf == 1)
			{
				parent->_bf = -1;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 0)
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else
			{
				assert(false);
			}
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

	bool _IsBalance(node* root)
	{
		if (root == nullptr)
			return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return abs(leftH - rightH) < 2 
			&& _IsBalance(root->_left) 
			&& _IsBalance(root->_right);
	}
private:
	node* _root = nullptr;
};