#include"alg.h"
#include<iostream>
#include<vector>
#include<string>
#include "mdeque.h"
#include "mheap.h"


template <class T>
inline std::ostream & operator << (std::ostream & o, const std::vector<T> & mvect){
    o << '(';
    if (mvect.size() != 0){
        int i = 0;
        for (; i < mvect.size()-1; ++i)
            o << mvect[i] << ", ";
        o << mvect[i];
    }
    o << ')';
    return o;
}

template <class T>
inline std::ostream & operator << (std::ostream & o, const mvector<T> & mvect){
    o << '[';
    if (mvect.size() != 0){
        int i = 0;
        for (; i < mvect.size()-1; ++i)
            o << mvect[i] << ", ";
        o << mvect[i];
    }
    o << ']';
    return o;
}
template <class T>
inline std::ostream & operator << (std::ostream & o, const mdeque<T> & mvect){
    o << '[';
    if (mvect.size() != 0){
        int i = 0;
        for (; i < mvect.size()-1; ++i)
            o << mvect[i] << ", ";
        o << mvect[i];
    }
    o << ']';
    return o;
}


void test_factorial() {
    for (int i = 0; i < 60; i++)
        std::cout << i << " -> " << fact(i) << std::endl;

}
void test_linsearch() {
    std::vector<int> vec = { 1,-2,3,4,333,-34,0 };
    std::cout << lin_search(vec, 333) << std::endl;
    std::cout << lin_search(vec, 9999999) << std::endl;
    std::cout << lin_search(vec, -2) << std::endl;

    std::vector<std::string> stvec = {"assa","ds","sds","s s "};
    std::cout << lin_search<std::string>(stvec, "ds") << std::endl;

    std::vector<double> fv = {1.222,0.2332,322,9.23};
    std::cout << lin_search(fv, 1.222) << std::endl;
    std::cout << lin_search(fv, 9.23) << std::endl;


}
void test_binsearch() {
    std::vector<int> vec = {-10,-8,3,4,10};
    //std::cout << bin_search(vec, 4) << "  " << bin_search_req(vec, 4) <<"  "<<bin_search_req_lambda(vec,4)<< std::endl;
    for(int val:{4,10,-10,0,-11,15})
        std::cout <<val<<"   "<< bin_search(vec, val) << "  " << bin_search_rec(vec, val) <<"  "<<bin_search_rec_lambda(vec,val)<< std::endl;
}

void test_mvector(){
    mvector<int> mvect;
    mvect.push_back(-10);
    mvect.push_back(-8);
    mvect.push_back(3);
    mvect.push_back(4);
    std::cout << mvect << std::endl;
    mvect.pop_back();
    mvect.pop_back();
    std::cout << mvect << std::endl;
    mvect.push_back(8);
    std::cout << mvect << std::endl;
    mvector<std::vector<int>> mvect1;
    mvect1.push_back({1,2,3});
    mvect1.push_back({2,3});
    std::cout << mvect1 << std::endl;
    mvector<float> mvect2(3);
    mvect2[2] = 4.0f;
    std::cout << mvect2 << std::endl;
    mvector<mvector<int>> mvect3{{1,2,3},{4,5,6},{},{2}};
    std::cout << mvect3 << std::endl;
    mvect3[1] = {10,9,11};
    std::cout << mvect3 << std::endl;
    std::vector<int> vect = {100,200,300};
    mvect3[2] = vect;
    std::cout << mvect3 << std::endl;
    mvector<std::vector<mvector<int>>> mvect4{{{1,2,3},{4,5,6}},{{555,666},{777}}};
    std::cout << mvect4 << std::endl;

    for (auto & val: mvect4){
        std::cout << val << std::endl;
    }
}

void test_mdeque(){
    mdeque<int> md;
    md.reserve(8);
    std::cout << md.test_mem() << std::endl;
    md.push_back(1);
    std::cout << md.test_mem() << std::endl;
    md.push_back(2);
    std::cout << md.test_mem() << std::endl;
    md.push_back(3);
    std::cout << md.test_mem() << std::endl;
    md.push_back(4);
    std::cout << md.test_mem() << std::endl;
    md.pop_front();
    std::cout << md.test_mem() << std::endl;
    md.pop_front();
    std::cout << md.test_mem() << std::endl;
    md.push_back(5);
    std::cout << md.test_mem() << std::endl;
    md.push_back(6);
    std::cout << md.test_mem() << std::endl;
    md.push_back(7);
    std::cout << md.test_mem() << std::endl;
    md.pop_front();
    std::cout << md.test_mem() << std::endl;
    md.pop_front();
    std::cout << md.test_mem() << std::endl;
    md.pop_front();
    std::cout << md.test_mem() << std::endl;
    md.push_back(8);
    std::cout << md.test_mem() << std::endl;
    md.push_back(9);
    std::cout << md.test_mem() << std::endl;
    md.push_back(10);
    std::cout << md.test_mem() << ' ' << md <<std::endl;
    md.push_front(11);
    std::cout << md.test_mem() << ' ' << md <<std::endl;
    md.pop_back();
    std::cout << md.test_mem() << ' ' << md <<std::endl;
    md.pop_back();
    std::cout << md.test_mem() << ' ' << md <<std::endl;
    md.pop_back();
    std::cout << md.test_mem() << ' ' << md <<std::endl;

    mdeque<int> mvect;
    mvect.push_back(-10);
    mvect.push_front(-8);
    mvect.push_back(3);
    mvect.push_back(4);
    std::cout << mvect << std::endl;
    mvect.pop_back();
    mvect.pop_back();
    std::cout << mvect << std::endl;
    mvect.push_back(8);
    std::cout << mvect << std::endl;
    mdeque<std::vector<int>> mvect1;
    mvect1.push_back({1,2,3});
    mvect1.push_back({2,3});
    std::cout << mvect1 << std::endl;
    mdeque<float> mvect2(3);
    mvect2[2] = 4.0f;
    std::cout << mvect2 << std::endl;
    mdeque<mdeque<int>> mvect3{{1,2,3},{4,5,6},{},{2}};
    std::cout << mvect3 << std::endl;
    mvect3[1] = {10,9,11};
    std::cout << mvect3 << std::endl;
    std::vector<int> vect = {100,200,300};
    mvect3[2] = vect;
    std::cout << mvect3 << std::endl;
    mdeque<std::vector<mdeque<int>>> mvect4{{{1,2,3},{4,5,6}},{{555,666},{777}}};
    std::cout << mvect4 << std::endl;
    mdeque<mvector<mdeque<int>>> mvect5{{{1,2,3},{4,5,6}},{{555,666},{777}}};
    std::cout << mvect5 << std::endl;
    mdeque<mdeque<mdeque<int>>> mvect6{{{1,2,3},{4,5,6}},{{555,666},{777}}};
    std::cout << mvect6 << std::endl;
    mvect6.push_back({{555, 2048}});
    mvect6.push_back({{}});
    mvect6.push_back({{}});
    mvect6.push_front({{10}, {100}});
    std::cout <<mvect6.test_mem() << std::endl;

    std::cout << std::endl;
    for (const auto & val: mvect6){
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
    for (auto & val: mvect6){
        val.push_front({-1, -2, -3});
    }
    std::cout << mvect6 << std::endl;

    std::cout << std::endl;
    for (auto & val: mvect6){
        for(auto & val1: val){
            std::cout << val1 << std::endl;
        }
    }
}
void test_heapi() {
    std::vector<int> heap{ 16, 8, 8, 7, 1, 0, 1, 3, 20};
    sift_upi(heap, heap.size(), heap.size() - 1);
    std::cout << heap<<std::endl;
    for (int i = heap.size() - 1; i > 0; --i) {
        std::swap(heap[0], heap[i]);
        sift_downi(heap, i, 0);
        std::cout << heap << std::endl;
    }
    build_heapi(heap);
    std::cout << heap << std::endl;
    build_heapi(heap, std::greater<int>());
    std::cout << heap << std::endl;
    std::vector<int> m{ -10, 5, 90, 51, -18, 29, 0, 4, 5, 6, 8};
    heap_sorti(m);
    std::cout << m << std::endl;
    heap_sorti(m, [](int a, int b) {return a > b; });
    std::cout << m << std::endl;
    heap_sorti(m, std::greater<int>());
    std::cout << m << std::endl;
}
void test_heap() {
    {
        std::vector<int> heap{ 16, 8, 8, 7, 1, 0, 1, 3, 20 };
        sift_up(heap, heap.size(), heap.size() - 1);
        std::cout << heap << std::endl;
        for (int i = heap.size() - 1; i > 0; --i) {
            std::swap(heap[0], heap[i]);
            sift_down(heap, i, 0);
            std::cout << heap << std::endl;
        }
        build_heap(heap);
        std::cout << heap << std::endl;
        build_heap(heap, std::greater<int>());
        std::cout << heap << std::endl;
        std::vector<int> m{ -10, 5, 90, 51, -18, 29, 0, 4, 5, 6, 8 };
        heap_sort(m);
        std::cout << m << std::endl;
        heap_sort(m, [](int a, int b) {return a > b; });
        std::cout << m << std::endl;
        heap_sort(m, std::greater<int>());
        std::cout << m << std::endl;
    }

    std::cout << std::endl;

    {
        std::vector<double> heap{ 16.5, 8.3, 8.0, 7.0, 1.0, 0.0, 1.0, 3.0, 20.0 };
        sift_up(heap, heap.size(), heap.size() - 1);
        std::cout << heap << std::endl;
        for (int i = heap.size() - 1; i > 0; --i) {
            std::swap(heap[0], heap[i]);
            sift_down(heap, i, 0);
            std::cout << heap << std::endl;
        }
        build_heap(heap);
        std::cout << heap << std::endl;
        build_heap(heap, std::greater<double>());
        std::cout << heap << std::endl;
        std::vector<double> m{ -10, 5, 90, 51, -18, 29, 0, 4, 5, 6, 8 };
        heap_sort(m);
        std::cout << m << std::endl;
        heap_sort(m, [](double a, double b) {return a > b; });
        std::cout << m << std::endl;
        heap_sort(m, std::greater<double>());
        std::cout << m << std::endl;
    }

    std::cout << std::endl;

    {
        mdeque<double> heap{ 16.5, 8.3, 8.0, 7.0, 1.0, 0.0, 1.0, 3.0, 20.0 };
        sift_up(heap, heap.size(), heap.size() - 1);
        std::cout << heap << std::endl;
        for (int i = heap.size() - 1; i > 0; --i) {
            std::swap(heap[0], heap[i]);
            sift_down(heap, i, 0);
            std::cout << heap << std::endl;
        }
        build_heap(heap);
        std::cout << heap << std::endl;
        build_heap(heap, std::greater<double>());
        std::cout << heap << std::endl;
        mdeque<double> m{ -10, 5, 90, 51, -18, 29, 0, 4, 5, 6, 8 };
        heap_sort(m);
        std::cout << m << std::endl;
        heap_sort(m, [](double a, double b) {return a > b; });
        std::cout << m << std::endl;
        heap_sort(m, std::greater<double>());
        std::cout << m << std::endl;
    }

    std::cout << std::endl;

    {
        mvector<int> heap{ 16, 8, 8, 7, 1, 0, 1, 3, 20 };
        sift_up(heap, heap.size(), heap.size() - 1);
        std::cout << heap << std::endl;
        for (int i = heap.size() - 1; i > 0; --i) {
            std::swap(heap[0], heap[i]);
            sift_down(heap, i, 0);
            std::cout << heap << std::endl;
        }
        build_heap(heap);
        std::cout << heap << std::endl;
        build_heap(heap, std::greater<int>());
        std::cout << heap << std::endl;
        mvector<int> m{ -10, 5, 90, 51, -18, 29, 0, 4, 5, 6, 8 };
        heap_sort(m);
        std::cout << m << std::endl;
        heap_sort(m, [](int a, int b) {return a > b; });
        std::cout << m << std::endl;
        heap_sort(m, std::greater<int>());
        std::cout << m << std::endl;
    }
}
void test_priorety_queue() {
    mpriority_queue <std::pair<int, int>> q;
    q.push({ 1,2 });
    q.push({ 3,4 });
    q.push({ 12,18 });
    std::cout << q.top().first << " " << q.top().second << std::endl;
    q.push({ 13,12 });
    std::cout << q.top().first << " " << q.top().second << std::endl;
    q.pop();
    std::cout << q.top().first << " " << q.top().second << std::endl;
    mpriority_queue <int> iq;
    iq.push(-10);
    iq.push(-10);
    iq.push(15);
    iq.push(10);
    iq.push(-8);
   
    std::cout << iq.top() << std::endl;

    mpriority_queue <int, std::greater<int>> ql;
    ql.push(-10);
    ql.push(-10);
    ql.push(15);
    ql .push(10);
    ql.push(-8);

    std::cout << ql.top() << std::endl;

    mpriority_queue <int, std::function<bool(int, int)>> qf([](int a, int b) {return abs(a) > abs(b); });
    qf.push(-10);
    qf.push(-10);
    qf.push(15);
    qf.push(10);
    qf.push(-8);

    std::cout << qf.top() << std::endl;

    struct A {
        int key = 0;
        char data[4096] = { 0 };
    }; 
    std::vector <A> qa = { {10, "abc"},{20, "def"}, {0, "ghi"}, {8, "l"}, {15, "x"}};
    mpriority_queue <int, std::function<bool(int, int)>> q_index([&qa](int a, int b) {return qa[a].data[0] < qa[b].data[0]; });
    q_index.push(1);
    q_index.push(4);
    q_index.push(2);
    q_index.push(0);
    std::cout << qa[q_index.top()].data << std::endl;
    /*for (int i = 'a'; i <= 'z'; ++i) {
        std::cout << i << " " << char(i) << std::endl;
    }*/
    std::cout << sizeof(A) << std::endl;
    q_index.pop();

    std::cout << qa[q_index.top()].data << std::endl;
    q_index.push(3);
    std::cout << qa[q_index.top()].data << std::endl;
}

int main(){
    //std::vector<int>::value_type x;
    //test_factorial();
    //test_linsearch();
    //test_binsearch();
    //test_mvector();
    //test_mdeque();
    //test_heap();
    test_priorety_queue();
    return 0;
}
