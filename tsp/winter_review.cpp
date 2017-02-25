//������ԭ���Ľ���һ��˼·,���������ƹ�����������ķ���,�����Ǻ�ԭ��һ���ķ���,60    ����ĺö೬ʱ
//Ȼ����취����,����һ�����˵Ĵ���,ѧϰ�������ڽӱ�,����Щquicksort,binary_searchȥ��  
//Ȼ���70����    ���泬ʱ����   ����˴���
//��ʱ�ȵ�����   �п�����

#include<iostream>
#include<cstdio>
using namespace std;

class QUEUE{
	public:
		QUEUE(int length);//���캯��
		int current_size;//������Ԫ�ظ���
		bool enqueue(int value);//���
		int dequeue();//����
	private:
		int max_size;//������󳤶�
		int head;//��ͷ�±�
		int tail;//��β�±�
		int * array;//����Ԫ�ص�����
};

QUEUE::QUEUE(int length){
	current_size = 0;
	max_size = length;
	head = 0;
	tail = 0;
	array = new int[length+10];
}
bool QUEUE::enqueue(int value){
	if(current_size <= max_size){//�˴�ӦΪ<=������<
		array[head] = value;
		if((max_size -1) == head){
			head = 0;
		}else{
			++head;
		}
		++current_size;
		return true;
	}
	return false;
}
int QUEUE::dequeue(){
	if(current_size > 0){
		int temp = array[tail];
		if((max_size -1) == tail){
			tail = 0;
		}else{
			++tail;
		}
		--current_size;
		return temp;
	}
}



//�����˼ҵĴ���,�о�д���ڽӱ������ٺܶ�,�Ǿ�д����
//Adjacency_list

class Node{
	public:
		Node();
		Node* succ;
		int city_name;
};
Node::Node(){
	succ = NULL;
	city_name = 0;
}

Node* array = new Node[3000010];//��������60��Ϊ70(2)
int array_index = 0;

class City{
	public:
		City();
		int number;
		Node* the_head;
		Node* current;
		void insertbehind(int value);
};

City::City(){
	number = 0;
	the_head = &(array[array_index]);
	++array_index;
	current = the_head;
}

void City::insertbehind(int value){
	Node *temp = &(array[array_index]);
	++array_index;
	temp->city_name = value;
	current->succ = temp;
	current = temp;
}

int main(){
	//����
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	City* city = new City[2000010];//��������60��Ϊ70(1)
	int *find_origin=new int[2000010];
	for(int i = 0; i < 2000010; ++i){
		find_origin[i] = 0;
	}
	for (int i = 0; i < m; ++i){
		int x, y;   
		fscanf(stdin, "%d %d", &x, &y);
		find_origin[y]=y;//
		city[x].insertbehind(y);
	}
	//�ҳ�����û�б�ָ��ĵ�,Ҳ���ǿ�����Ϊ���ĵ�(����ֱ�Ӹ��ƹ�����,�����޸�,���ǲ������Ǹ�origin����������,ֱ�����)
	QUEUE queue(2000010);
	for(int i=1 ;i<=n;++i){
		if(i!=find_origin[i]){
			queue.enqueue(i);
		}
	}
	//��ʼ��������,Ҳ�����ڹ����������
	int count = 0;
	while(queue.current_size > 0){
		++count;
		for(int i = 0, j = queue.current_size; i < j; ++i){
			int from = queue.dequeue();
			Node* a = city[from].the_head;
			for(; a->succ != NULL;){//
				a = a->succ;
				queue.enqueue(a->city_name);
			}
		}
	}
	fprintf(stdout,"%d", count);
	return 0;
}

