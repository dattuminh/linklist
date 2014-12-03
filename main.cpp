#include<iostream>
#include"LinkNode.h"
#include"Btree.h"
#include<stack>
using namespace std;

LinkNode *root = NULL;
stack<Btree*> s;

LinkNode * createLinkNode(Btree *node){
	Btree *pre = node;
	Btree *greg = node;
	return root;
}
void throughBitreeOrder(Btree* node){
//	Btree *pre = node;
	if(node == NULL)
		return;
	Btree *temp;
	Btree *p = node;
	while(p->l!=NULL){
		s.push(p);
		p = p->l;
	}
	cout<<p->data<<endl;
	while(!s.empty()){
		temp = s.top();
		s.pop();
		cout<<temp->data<<endl;
		throughBitreeOrder(temp->r);
		cout<<temp->r->data<<endl;
	}
}
//while(s.empty()==false)s.pop();
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
			s.pop();
			btree_root->l = s.top();
			s.pop();
			btree_root->data = *p;
			s.push(btree_root);
		}else{
			btree_root = new Btree();
			btree_root->data = *p;
			s.push(btree_root);
		}	
		p++;
	}	
	return s.top();
}


int main(int argc,char *argv[]) {
	root  = new LinkNode();
	const char* p = "ab-c/de+*";
    	Btree *btree = createBtree(p);
	throughBitreeOrder(btree);
	return 0;
}
