#define SIZEone 10010
#define SIZEtwo 20010
#include <cstdio>
#include <cstdlib>
#include<iostream>
using namespace std;

static char peral[SIZEtwo];//��������	
static int place[SIZEone];//λ������
static char colour[SIZEone];//��ɫ����
int n;
int i;//ѭ�����Ʊ���
int j;//ѭ�����Ʊ���
int x;//��ʱ��
int I;//ģ��i(�������е�λ��,�����д���0)
int length;//������Ԫ�ص�����
	
int main(){
	int eliminate(int y);
	int eliminateagain(int y);
	int count(char*peral);
	
	gets(peral);//��һ��  ��������
	
	scanf("%d",&n);//�ڶ���   ����n

    for (i=0;i<n;i++) {
        scanf("%d %c",&(place[i]),&(colour[i]));//n��,������β���
    }
	
	count(peral);
	
    for(i=0;i<n;i++){
		I=place[i];
	    eliminate(I);
		if(length==0){
			printf("-\n");
			continue;
		}
		for(j=0;j<length;j++){
			if(peral[j]!=0){
				printf("%c",peral[j]);
			}
			else{
				break;
			}
        }
		printf("\n");
    }
	return 0;
}

	 
	 
int eliminate(int y){
		
	int eliminateagain(int y);
		
	if(y>=2&&y<=length&&peral[y-2]==peral[y-1]&&peral[y-1]==colour[i]){
		for(j=y-2,x=y;j<length-2;j++){
			peral[j]=peral[x++];
		}
		I=y-2;
		length=length-2;
		eliminateagain(I);
		return 0;
	}
	
	else if(y>=1&&y<=length-1&&peral[y-1]==peral[y]&&peral[y]==colour[i]){
		for(j=y-1,x=y+1;j<length-2;j++){
			    
			peral[j]=peral[x++];
		}
		I=y-1;
		length=length-2;
		eliminateagain(I);
		return 0;
	}
	
	else if(y>=0&&y<=length-2&&peral[y]==peral[y+1]&&peral[y+1]==colour[i]){
		for(j=y,x=y+2;j<length-2;j++){
			    
			peral[j]=peral[x++];
		}
		I=y;
		length=length-2;
		eliminateagain(I);
		return 0;
	}
		
	else{
		int transfer=length;
		for(transfer;transfer>I;transfer--){
			peral[transfer]=peral[transfer-1];
	    }
		peral[I]=colour[i];
		length=length+1;
		return 0;
	}	
}
	
	
int eliminateagain(int y){
		
	if(y>=2&&y<=length-2&&peral[y-2]==peral[y-1]&&peral[y-1]==peral[y]&&peral[y]==peral[y+1]){
		for(j=y-2,x=y+2;j<length-4;j++){
			    
			peral[j]=peral[x++];
		}
		I=y-2;
		length=length-4;
		eliminateagain(I);
	}
		
	else if(y>=2&&y<=length-1&&peral[y-2]==peral[y-1]&&peral[y-1]==peral[y]){
		for(j=y-2,x=y+1;j<length-3;j++){
			    
			peral[j]=peral[x++];
		}
		I=y-2;
		length=length-3;
		eliminateagain(I);
	}
	
	else if(y>=1&&y<=length-2&&peral[y-1]==peral[y]&&peral[y]==peral[y+1]){
		for(j=y-1,x=y+2;j<length-3;j++){
			    
			peral[j]=peral[x++];
		}
		I=y-1;
		length=length-3;
		eliminateagain(I);
	}
	else{ 
	}
	return 0;
}
	
int count(char*peral){
	for(i=0;i<SIZEone;i++){
		if(0==peral[i]){
			length=i;
			return 0;
		}				
	}
}

