#pragma once


namespace key
{
	template<class k>
	struct  BSTreeNode
	{
		BSTreeNode<k>* _left;
		BSTreeNode<k>* _right;
		k _key;
		BSTreeNode(const k& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class k>
	class BSTree
	{
		typedef BSTreeNode<k> node;
	public:
		BSTree() = default; //强制生成默认的拷贝构造
		BSTree(BSTree<k>& t)
		{
			_root = copy(t._root);
		}

		BSTree<k>& operator = (BSTree<k> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			Destroy(_root);
		}


		bool Insert(const k& key)
		{

			if (_root == nullptr)
			{
				_root = new node(key);
				return true;
			}
			node* _cur = _root;
			node* parent = nullptr;
			while (_cur)
			{
				if (_cur->_key < key)
				{
					parent = _cur;
					_cur = _cur->_right;
				}
				else if (_cur->_key > key)
				{
					parent = _cur;
					_cur = _cur->_left;
				}
				else
				{
					return false;
				}
			}
			_cur = new node(key);
			if (_cur->_key < parent->_key)
			{
				parent->_left = _cur;
			}
			else
			{
				parent->_right = _cur;
			}
			return true;
		}

		bool InsertR(const k& key)
		{
			_InserR(_root, key);
		}
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}

		bool Erase(const k& key)
		{
			node* _cur = _root;
			node* parent = _cur;
			while (_cur)
			{
				if (_cur->_key < key)
				{
					parent = _cur;
					_cur = _cur->_right;
				}
				else if (_cur->_key > key)
				{
					parent = _cur;
					_cur = _cur->_left;
				}
				else
				{
					//左为空
					if (_cur->_left == nullptr)
					{
						if (_cur == _root)
						{
							_root = _cur->_right;
						}
						else
						{
							if (parent->_left == _cur)
							{
								parent->_left = _cur->_right;
							}
							else
							{
								parent->_right = _cur->_right;
							}
						}
						delete _cur;
					}
					//右为空
					else if (_cur->_right == nullptr)
					{
						if (_cur == _root)
						{
							_root = _cur->_left;
						}
						else
						{
							if (parent->_left == _cur)
							{
								parent->_left = _cur->_left;
							}
							else
							{
								parent->_right = _cur->_left;
							}
						}
						delete _cur;
					}
					else
					{
						//用右子树的最小节点来代替然后删除
						node* minright = _cur->_right;
						node* pminright = _cur;
						while (minright->_left)
						{
							pminright = minright;
							minright = minright->_left;
						}
						_cur->_key = minright->_key;
						if (pminright->_left == minright)
						{
							pminright->_left = minright->_right;
						}
						else
						{
							pminright->_right = minright->_right;
						}
						delete minright;
					}
					return true;
				}
			}
			return false;
		}

		bool EraseR(const k& key)
		{
			return _EraseR(_root, key);
		}

		bool FindR(const k& key)
		{
			return _FindR(_root, key);
		}
		bool Find(const k& key)
		{
			node* _cur = _root;
			while (_cur)
			{
				if (_cur->_key < key)
				{
					_cur = _cur->_right;
				}
				else if (_cur->_key > key)
				{
					_cur = _cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

	protected:
		void Destroy(node*& root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);

			delete root;
			root = nullptr;
		}
		bool _InsertR(node*& root, const k& key)
		{
			if (root == nullptr)
			{
				root = new node(key);
				return true;
			}
			if (root->_key < key)
			{
				_InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				_InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}
		void _Inorder(node* root)
		{
			if (root == nullptr) return;

			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}
		bool _EraseR(node*& root, const k& key)
		{
			node* del = root;
			if (root == nullptr) return false;
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else
				{
					node* maxleft = root->_left;
					while (maxleft->_right)
					{
						maxleft = maxleft->_right;
					}
					root->_key = maxleft->_key;
					return _EraseR(root->_left, maxleft->_key);
				}
			}
			delete del;
			return true;
		}
		bool _FindR(node* root, const k& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
			{
				_FindR(root->_right, key);
			}
			if (root->_key > key)
			{
				_FindR(root->_left, key);
			}
			else
			{
				return true;
			}
			return false;
		}
		node* copy(node*& root)
		{
			if (root == nullptr)
				return nullptr;
			node* newroot = new node(root->_key);
			newroot->_left = copy(root->_left);
			newroot->_right = copy(root->_right);
			return newroot;
		}
	private:
		node* _root = nullptr;
	};
};


namespace	kv
{
	template<class k, class v>
	struct  BSTreeNode
	{
		BSTreeNode<k, v>* _left;
		BSTreeNode<k, v>* _right;
		k _key;
		v _value;
		BSTreeNode(const k& key, const v& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}
	};

	template<class k, class v>
	class BSTree
	{
		typedef BSTreeNode<k, v> node;
	public:
		BSTree() = default; //强制生成默认的拷贝构造
		BSTree(BSTree<k, v>& t)
		{
			_root = copy(t._root);
		}

		BSTree<k, v>& operator = (BSTree<k, v> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			Destroy(_root);
		}


		bool Insert(const k& key, const v& value)
		{

			if (_root == nullptr)
			{ 
				_root = new node(key, value);
				return true;
			}
			node* _cur = _root;
			node* parent = nullptr;
			while (_cur)
			{
				if (_cur->_key < key)
				{
					parent = _cur;
					_cur = _cur->_right;
				}
				else if (_cur->_key > key)
				{
					parent = _cur;
					_cur = _cur->_left;
				}
				else
				{
					return false;
				}
			}
			_cur = new node(key, value);
			if (_cur->_key < parent->_key)
			{
				parent->_left = _cur;
			}
			else
			{
				parent->_right = _cur;
			}
			return true;
		}

		bool InsertR(const k& key, const v& value)
		{
			_InserR(_root, key, value);
		}
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}

		bool Erase(const k& key)
		{
			node* _cur = _root;
			node* parent = _cur;
			while (_cur)
			{
				if (_cur->_key < key)
				{
					parent = _cur;
					_cur = _cur->_right;
				}
				else if (_cur->_key > key)
				{
					parent = _cur;
					_cur = _cur->_left;
				}
				else
				{
					//左为空
					if (_cur->_left == nullptr)
					{
						if (_cur == _root)
						{
							_root = _cur->_right;
						}
						else
						{
							if (parent->_left == _cur)
							{
								parent->_left = _cur->_right;
							}
							else
							{
								parent->_right = _cur->_right;
							}
						}
						delete _cur;
					}
					//右为空
					else if (_cur->_right == nullptr)
					{
						if (_cur == _root)
						{
							_root = _cur->_left;
						}
						else
						{
							if (parent->_left == _cur)
							{
								parent->_left = _cur->_left;
							}
							else
							{
								parent->_right = _cur->_left;
							}
						}
						delete _cur;
					}
					else
					{
						//用右子树的最小节点来代替然后删除
						node* minright = _cur->_right;
						node* pminright = _cur;
						while (minright->_left)
						{
							pminright = minright;
							minright = minright->_left;
						}
						_cur->_key = minright->_key;
						if (pminright->_left == minright)
						{
							pminright->_left = minright->_right;
						}
						else
						{
							pminright->_right = minright->_right;
						}
						delete minright;
					}
					return true;
				}
			}
			return false;
		}

		bool EraseR(const k& key)
		{
			return _EraseR(_root, key);
		}

		bool FindR(const k& key)
		{
			return _FindR(_root, key);
		}
		node*& Find(const k& key)
		{
			node* _cur = _root;
			while (_cur)
			{
				if (_cur->_key < key)
				{
					_cur = _cur->_right;
				}
				else if (_cur->_key > key)
				{
					_cur = _cur->_left;
				}
				else
				{
					return _cur;
				}
			}
			return nullptr;
		}

	protected:
		void Destroy(node*& root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);

			delete root;
			root = nullptr;
		}
		bool _InsertR(node*& root, const k& key, const v& value)
		{
			if (root == nullptr)
			{
				root = new node(key, value);
				return true;
			}
			if (root->_key < key)
			{
				_InsertR(root->_right, key, value);
			}
			else if (root->_key > key)
			{
				_InsertR(root->_left, key, value);
			}
			else
			{
				return false;
			}
		}
		void _Inorder(node* root)
		{
			if (root == nullptr) return;

			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}
		bool _EraseR(node*& root, const k& key)
		{
			node* del = root;
			if (root == nullptr) return false;
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else
				{
					node* maxleft = root->_left;
					while (maxleft->_right)
					{
						maxleft = maxleft->_right;
					}
					root->_key = maxleft->_key;
					return _EraseR(root->_left, maxleft->_key);
				}
			}
			delete del;
			return true;
		}
		node*& _FindR(node* root, const k& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}
			return nullptr;
		}
		node* copy(node*& root)
		{
			if (root == nullptr)
				return nullptr;
			node* newroot = new node(root->_key);
			newroot->_left = copy(root->_left);
			newroot->_right = copy(root->_right);
			return newroot;
		}
	private:
		node* _root = nullptr;
	};
};