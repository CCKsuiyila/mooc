//��0��15��10��40��55 ����ǰ11������,����Ķ��ǳ�ʱ,���һ�����
//�����ˮд�ıȽ϶��,����д��̫ˮ��   ��������û�зֿ���һ����ԭ��
/*	2017-02-22 00:48:40	55.0/100.0	 	�ܴ���߼�����
 	2017-02-22 00:09:50	40.0/100.0	 	���������ָ��
 	2017-02-22 00:08:15	40.0/100.0	 	-3���-2
 	2017-02-21 23:17:40	10.0/100.0	 	��Щ�������ָ����ע�͵�
 	2017-02-21 22:54:01	10.0/100.0	 	>=1��Ϊ>=3
 	2017-02-21 22:15:40	15.0/100.0	 	100010��Ϊ1000100
 	2017-02-21 22:14:15	15.0/100.0	 	int main֮ǰ����
 	2017-02-21 19:33:27	0.0/100.0	 
*/
//��Ȼ�������ִ���	ϣ��û���´���
//�����ȽϺõĵط�����,��ʱ���²����ֵ�״̬�����������   ��������һ�¾�д�������
//��������������Ǹ���ʱ�临�Ӷ���   �ʵ�Ա(tsp)�Ǹ���Ҳ��.
#include<iostream>
#include<cstdio>
using namespace std;

//tree_with_list
class tree_node{
	public://�Ӵ��඼��ôд��,��Ȼ����Ҳͦ�鷳��
	tree_node();
	tree_node* leftchild;
	tree_node* rightchild;
	tree_node* father;
	tree_node* prev;
	tree_node* succ;
	int data;
};
tree_node::tree_node(){
	leftchild = NULL;
	rightchild = NULL;
	father = NULL;
	prev = NULL;
	succ = NULL;
	data = 0;
}

class tree{
	public:
	tree(int length);
	tree_node* tree_head;
	int total;
	void initialize(int value);
	tree_node* append(int value);
	private:
	int rank;
	tree_node* store;
};

tree::tree(int length){
	tree_head = NULL;
	total = 0;
	rank = 0;
	store = new tree_node[length+10];
}

void tree::initialize(int value){
	tree_head = &(store[rank++]);
	tree_head->prev=tree_head;
	tree_head->succ=tree_head;
	tree_head->data=value;
	total = 1;	
}

tree_node* tree::append(int value){
	tree_node* pnode = &(store[rank++]);
	pnode->prev = tree_head->prev;
	pnode->succ = tree_head;
	tree_head->prev = pnode;
	pnode->prev->succ = pnode;
	pnode->data = value;
	total = total + 1;
	return pnode;
}

int output(tree_node* a){
	if(a->leftchild != NULL){
		output(a->leftchild);
	}
	fprintf(stdout, "%d ", a->data);
	if(a->rightchild != NULL){
		output(a->rightchild);
	}
	return 0;
}

int main(){
	//input
	int n;
	fscanf(stdin, "%d", &n);
	//�����������
	int input;
	tree preorder_tree(1000100);
	fscanf(stdin, "%d", &(input));
	preorder_tree.initialize(input);
	for(int i = 1; i < n; ++i){
		fscanf(stdin, "%d", &(input));
		preorder_tree.append(input);
	}
	//�����������
	tree postorder_tree(1000100);
	fscanf(stdin, "%d", &(input));
	postorder_tree.initialize((input));
	for(int i = 1; i < n; ++i){
		fscanf(stdin, "%d", &(input));
		postorder_tree.append(input);
	}
	//���뻹����һ���ɵ�,��ʱ�Ҳ�����, ������������
	//process
	while(preorder_tree.total >= 3){
		int sign = 0;
		for(tree_node* i = preorder_tree.tree_head; 0 == sign; i = i->succ ){
			for(tree_node* j = postorder_tree.tree_head; 0 == sign ;j = j->succ){
				if(i->data == j->data){
					if((i->succ->data == j->prev->prev->data)&&(i->succ->succ->data == j->prev->data)){
						sign = 1;
						//����i�ĸ��ӹ�ϵ
						i->leftchild = i->succ;
						i->rightchild = i->succ->succ;
						i->leftchild->father = i;
						i->rightchild->father = i;
						//���i�Լ�i���ӵ��б��ϵ
						i->succ = i->rightchild->succ;
						i->succ->prev = i;
					
						i->leftchild->prev = NULL;
						i->rightchild->prev = NULL;
						i->leftchild->succ = NULL;
						i->rightchild->succ = NULL;
					
						//���j������ӵ��б��ϵ
						if(j->prev->prev == postorder_tree.tree_head){
							postorder_tree.tree_head = j;
						}
						tree_node* temp = j->prev;
						j->prev->prev->prev->succ = j;
						j->prev = j->prev->prev->prev;
					
						temp->prev->prev = NULL;
						temp->prev->succ = NULL;
						temp->prev = NULL;
						temp->succ = NULL;
					
						preorder_tree.total = preorder_tree.total - 2;
						postorder_tree.total = postorder_tree.total - 2;
					}
					break;
				}
			}
		}
	}
	
	//output
	output(preorder_tree.tree_head);
	return 0;
}



	
