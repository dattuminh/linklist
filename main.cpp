#include<iostream>
#include"LinkNode.h"
#include"Btree.h"
#include<stack>
using namespace std;

LinkNode *root = NULL;
stack<Btree*> s;
LinkNode * createNode(LinkNode *root,char* p1,char* p2,char* q1,char* q2){
	//先构造二叉树
	/*if(mid_c[0]!=back_c[0]){
		cout<<"input data error"<<endl;
		return NULL;
	}*/
/////p1、p1是中缀表达式，q1、q2是后缀表达式
	
//	root.data = mid_c[0];
/*	
	while(a!='\0'){
		
	}*/
	return root;
}

Btree * createBtree(const char* p){
	while(*p!='\0'){
		Btree *btree_root;
		if(*p=='+'||*p=='-'||*p=='*'||*p=='/'){
			if(s.empty()){
				cout<<"stack is empty"<<endl;
				return NULL;
			}		
     		btree_root = new Btree();
			btree_root->r = s.top();
			btree_root->l = s.top();
			btree_root->data = *p;
			s.push(btree_root);
		}
		btree_root = new Btree();
		btree_root->data = *p;
		s.push(btree_root);
		p++;
	}	
	return s.top();
}


int main(int argc,char *argv[]) {
	root  = new LinkNode();
	const char* p = "ab-c/de+x";
    Btree *btree = createBtree(p);
	cout<<btree->l->data<<endl;
	return 0;
}
