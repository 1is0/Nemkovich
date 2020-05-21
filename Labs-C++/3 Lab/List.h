#ifndef ListH
#define ListH

// ---------------------------------------------------------------------------
template<typename U>
class List {
public:
	List();
	~List();
	void push_back(U data);
	void delfirst();
	void clear();
	void deleteindex(int index);

	int GetSize() {
		return size;
	}

	U& operator[](const int index);

private:

	template<class T>
	class Node {
	public:
		Node* next;
		T data;

		Node(T data = T(), Node *Next = nullptr) {
			this->data = data;
			this->next = Next;
		}
	};

	int size;
	Node<U> *head;
};

// ---------------------------------------------------------------------------

template<typename U>
List<U>::List() {
	size = 0;
	head = nullptr;
}

template<typename U>
List<U>::~List() {
	clear();
}

template<typename U>
void List<U>::push_back(U data) {
	if (head == nullptr) {
		head = new Node<U>(data);

	}
	else {
		Node<U> *current = this->head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node<U>(data);

	}
	size++;
}

template<typename U>
void List<U>::delfirst() {
	Node<U> *tmp = head;
	head = head->next;
	delete tmp;
	size--;
}

template<typename U>
void List<U>::deleteindex(int index) {
	if (!head) {
		return;
	}
	if (index == 0) {
		delfirst();
	}
	else {
		Node<U> *previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}

		Node<U> *toDelete = previous->next;

		previous->next = toDelete->next;

		delete toDelete;

		size--;
	}
}

template<typename U>
void List<U>::clear() {
	while (size) {
		delfirst();
	}
}

template<typename U>
U& List<U>:: operator[](const int index) {
	int counter = 0;
	Node<U> *current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->next;
		counter++;
	}

};

#endif
