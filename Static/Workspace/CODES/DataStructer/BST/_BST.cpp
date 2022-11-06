#include <cstdio>
using namespace std;
template <class T>
class BST{
private:
	signed int BST_signedint_size;
	node*BST_nodepointer_gen;
	static node*BST_nodepointer_usnode;
	node*BST_nodepointerfunction_findbyvalue(T);
	node*BST_nodepointerfunction_findbyrank(signed int);
public:
	class node{
	private:
	public:
		node*node_nodepointer_lc;
		node*node_nodepointer_rc;
		T node_signedint_data;
		signed int node_signedint_count;
		signed int node_signedint_weight;
	};
	void BST_voidfunction_add(T);
	void BST_voidfunction_remove(T);
	void BST_voidfunction_erase(T);
	bool BST_voidfunction_count(T);
	T BST_templatefunction_ranker(signed int);
	signed int BST_signedintfunction_rank(T);
	signed int BST_signedintfunction_size(void);
};
BST::node*BST::BST_nodepointerfunction_findbyvalue(T x){
	