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
			//�鿴�Ƿ�ƽ��
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				//��Ҫ���¸��ڵ�
				//���ϲ鿴
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if(parent->_bf == 0)
			{
				//֤����������ƽ��Ĵ˴εĲ��벻��������ת
				break;
			}
			else if(parent->_bf == 2 || parent->_bf == -2)
			{
				//����ת����
				//��������
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				//�����ҵ���
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				//����������������
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				//���ң�������������
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				//����Ļ������쳣���
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
			//�ֱ𱣴�����������������������
			node* subR = parent->_right;
			node* subRL = subR->_left;

			//�����������������ŵ�parent���ҽڵ�
			parent->_right = subRL;
			//��������������������ڵĻ��������ĸ��ڵ�
			if (subRL)
				subRL->_parent = parent;
			//����parent�ĸ��ڵ㣬����Ҫ���ڸ����������ĸ��ڵ�
			node* ppnode = parent->_parent;
			//��parent��ֵ������������ڵ㣬���Ҹ���parent�ĸ��ڵ�
			subR->_left = parent;
			parent->_parent = subR;
			//�鿴parent�Ƿ�Ϊavl���ĸ��ڵ�
			//����Ǹ��ڵ�Ļ����������µĸ��ڵ�Ϊ������
			//���Ҹ����������ĸ��ڵ�
			if (ppnode == nullptr)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			//parent���Ǹ��ڵ�Ļ�
			//�ж�parent�ڵ����丸�ڵ������������������
			else
			{
				//��parent���丸�ڵ��������
				if (ppnode->_left == parent)
				{
					//��ô���ǽ�����������丸�ڵ��������
					ppnode->_left = subR;
				}
				//ͬ����parent���丸�ڵ��������
				else
				{
					//��ô���ǽ�����������丸�ڵ��������
					ppnode->_right = subR;
				}
				//�������������ĸ��ڵ�
				subR->_parent = ppnode;
			}
			//�����ǽ���������ʱ��
			//�����ǵ������ʱ��parent��������һ����ƽ���
			parent->_bf = subR->_bf = 0;
		}
	void RotateR(node* parent)
		{
			//��������������������������
			node* subL = parent->_left;
			node* subLR = subL->_right;

			//��parent����ڵ㻻�����������ҽڵ�
			parent->_left = subLR;
			//�������������������Ϊ�յĸ������ĸ��ڵ�
			if (subLR)
				subLR->_parent = parent;
			//����parent�ĸ��ڵ�
			node* ppnode = parent->_parent;
			//�����������ĵ��ҽڵ�Ϊparent��������parent�ĸ��ڵ�Ϊ������
			subL->_right = parent;
			parent->_parent = subL;
			//�鿴parent�Ƿ�Ϊ���ĸ��ڵ�
			if (ppnode == nullptr)
			{
				//�����ĸ��ڵ㣬��ô����Ҫ�������ĸ��ڵ�Ϊ������
				//��������ĸ��ڵ�
				_root = subL;
				_root->_parent = nullptr;
			}
			//����Ļ��鿴parent�Ǹ��ڵ������������������
			//������������ֵ��parent��Ӧ������λ�ã��������������ĸ��ڵ�
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
			//�ҵ���������һ��������֮��parent��������һ����ƽ���
			parent->_bf = subL->_bf = 0;
		}
	void RotateLR(node* parent)
		{
			//���ȱ�������������������������
			//��������������������ƽ�����ӣ��Ա��������ƽ������
			node* subL = parent->_left;
			node* subLR = subL->_right;
			int bf = subLR->_bf;
			//�ȶ�parent����������������
			RotateL(parent->_left);
			//�ٶ�parent��������
			RotateR(parent);
			//����ƽ������
			//��Ϊ���¼��������ͼ��Ϊ����
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
			//����������
			//��������������
			//��������������ƽ������
			node* subR = parent->_right;
			node* subRL = subR->_left;
			int bf = subRL->_bf;
			//����תparent��������
			RotateR(parent->_right);
			//����תparent
			RotateL(parent);
			//����ƽ������
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