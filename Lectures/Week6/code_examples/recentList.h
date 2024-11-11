template <class T>
struct Node {
  T data;
  Node<T>* next;
  Node<T>* prev;

  Node<T>(const T& data_, Node<T>* next_ = nullptr, Node<T>* prev_ = nullptr) {
    data = data_;
    next = next_;
    prev = prev_;
  }
};

template <class T>
class RecentList {
  //The front node
  Node<T>* front;
  Node<T>* end;
  int listSize;

public:
  RecentList();
  void insert(const T&);
  bool copyToArray(T array[], int capacity);
  ~RecentList();
};

//No argument constructor, sets the object to a safe state
template <class T>
RecentList<T>::RecentList() {

  front = nullptr;
  end = nullptr;
  listSize = 0;
}

//Inserts a node at the front of the list
template <class T>
void RecentList<T>::insert(const T& data_) {

  //Check if there are any nodes to begin with
  if (front) {
    //Create a new Node and make its next pointer point to the current front node
    Node<T>* n = new Node<T>(data_, front);
    //Then set the current front's prev pointer point to the new node
    front->prev = n;
    //Now the new node is the front node
    front = n;
  }
  else {
    front = new Node<T>(data_);
    end = front;
  }
  listSize++;
}

//Copies each node's data into the array starting with the front
//If the array is large enough to hold the entire list return true, false otherwise
template <class T>
bool RecentList<T>::copyToArray(T array[], int capacity){

	Node<T>* currentNode = front;
	int count = 0;

	for (int i = 0; i < capacity && currentNode; i++){
			
		array[i] = currentNode->data;
		currentNode = currentNode->next;
		count++;
	}

	if (count == listSize)
		return true;
				
	return false;
}

//Destructor
template <class T>
RecentList<T>::~RecentList() {
  //Traverse through the list and deallocate each node
  while (front) {
    listSize--;
    Node<T>* cur = front->next;
    delete front;
    front = cur;
  }
}

