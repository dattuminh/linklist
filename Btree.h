#ifndef __BTREE__
#define __BTREE__
class Btree{
public:
	//Left node = l
	Btree *l;
	//Right node = r
	Btree *r;
	char data;
	Btree();	
};

#endif

