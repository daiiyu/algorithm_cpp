#include <iostream>

using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
class List
{
public:

    List(){init();}
    void init(){
        //头部不存放数据
        head_ = new Node<T>;
        tail_ = head_;
        tail_->next = head_;
    }

    inline void push_back(const T &data){
        auto *tmp =new Node<T>{data, head_};
        tail_->next = tmp;
        tail_ = tmp;
        ++size;
    }
    inline void insert(int pos, const T& data){
        if(pos > size||pos <0)
        return;
        Node<T>* iter=head_;
        for(int i=0; i<pos -1 ; ++i){
            
            iter = iter->next;
        }
        Node<T>* tmp = new Node<T>{data, iter->next};
        iter->next = tmp;
        ++size;

    }
    Node<T>* begin(){
        return head_->next;
    }
    Node<T>* end(){
        return head_;
    }

private:
    Node<T>* head_;
    Node<T> * tail_;
    size_t size = 0;;
};



int main()
{
    List<int> list;
    
    for(int i = 0 ; i< 100; ++i){
        list.insert(0, i);
    }
    for(auto iter = list.begin(); iter != list.end(); iter = iter->next){
        cout<<iter->data<<"\t";
    }
    cout<<endl;
}