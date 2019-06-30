template<typename T>

class List {

    template<typename Z>
    struct Node {
        Node* next; 
        Z value;
        Node(Z value = Z(),Node* node = nullptr):value(value),next(node) { }
    };
    
    int size;
    Node<T>* head;
    Node<T>* tail;
    
    public:
    
    List();

    List(int size,T value = T());
    
    List(List& copy);
    
    ~List();
    
    int get_size() const;
    
    void clear();
    
    List<T> operator+(const List<T>& lst1);
    
    void operator=(const List<T>& lst1);

    const bool operator==(const List<T>& right);
    
    const bool operator!=(const List<T>& right);
    
    T& operator[](const int index);
    
    void insert_at_index(T value,int index);
    
    T get_at_index(int index);

    void set_at_index(T value,int index);

    void remove_at_index(int index );

    void push_back(T value);
    
    void push_front(T value);
    
    void pop_back();
    
    void pop_front();
    
    T list_max() const;
    
    T list_min() const;
    
    void reverse();
    
    void print() const;
};
