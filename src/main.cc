#include "List.h"
#include <List>

int main(){
    // g++ List.cc && ./a.out 
    // g++ main.cc && ./a.out 
// g++ -lstdc++ -std=c++17 main.cc && ./a.out
    
    using namespace std;

    setlocale(LC_ALL, "ru");

    s21::List<int> lst(2);
    // lst.push_back(5);
    // // lst.push_back(10);
    // s21::List<int> lst2;
    // lst.push_back(22);
    s21::List<int> lst3;
    lst3.push_back(11);
    // ts.push_front(22);
    cout << lst3.front() << endl;
    // lst3.push_back(22);
    list<int> ts(3);
    // ts.push_front(22);
    // <int>ts(5);
    cout << ts.front() << endl;
    // cout << lst[0] << endl;

    // for (size_t i = 0; i < lst.GetSize(); i++)
    // {
        
    //     cout << lst[i] << endl;
    //     // cout >> lst->x >> endl;
    // }

    // cout << "show_Start" << endl;
    // lst3.show();
    cout << ts.max_size() << endl;
    

    // lst.insert (99, 1);
    // lst.removeAt(1);
    // lst.pop_back();

    // cout<< "Элементов в списке" << lst.GetSize() << endl << "Забрали первый элемент" << endl << endl;
    
    
    //                                                                                                                                                                                                                                                                                                                                                              for (size_t i = 0; i < lst.GetSize(); i++)
    // {
    //     cout << lst[i] << endl;
    // }
    // cout<< "Элементов в списке" << lst.GetSize() << endl;
    return 0;
}






