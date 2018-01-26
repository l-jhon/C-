template <typename T>
class Node{
public:
	T x;
	Node<T>* Prox;
	Node(T p) : x(p){};
};