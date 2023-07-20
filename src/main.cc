#include "List.h"
#include <List>

int main(){
    // g++ List.cc && ./a.out 
    // g++ main.cc && ./a.out 
// g++ -lstdc++ -std=c++17 main.cc && ./a.out
    
    using namespace std;

    setlocale(LC_ALL, "ru");
    list<int> std_List{1, 2, 3, 4, 5, 6, 7};
    list<int> std_copy(std_List);
    std_copy = move(std_List);

    s21::List<int> s21_List{1, 2, 3, 4, 5, 6, 7};
    list<int> s21_copy(10);
    // std_copy = move(s21_List);
    // std_List.push_back(5);
    // // std_List.push_back(10);
    // s21::List<int> lst2;
    // std_List.push_back(22);
    // s21::List<int> s21_List;
    // s21_List.push_back(11);
    // std_List.push_front(22);
    // cout << s21_List.front() << endl;
    // s21_List.push_back(22);
    // list<int> std_List(3);
    // std_List.push_front(22);
    // <int>std_List(5);
    // cout << std_List.front() << endl;
    // cout << lst[0] << endl;
    // s21_List.push_front(1.2);
    // s21_List.push_front(1.3);
    // for (size_t i = 0; i < std_List.Gestd_Listize(); i++)
    // {
        
    //     cout << lst[i] << endl;
    //     // cout >> lst->x >> endl;
    // }

    // std_List.back();
    // std_List.back();
    // std_List.back();
    // s21_List.pop_front();
    // s21_List.pop_front(); 

    // s21_List.pop_back();
    // s21_List.pop_back();
    // cout << s21_List.back() << endl;
    // s21_List.pop_back();
    // s21_List.pop_back();
    // s21_List.pop_back();
    // s21_List.pop_back();

    // s21_List.pop_front();
    // s21_List.pop_front();
    // s21_List.pop_front();
    // s21_List.pop_front();
    // s21_List.pop_front();
   

    // cout << s21_List.size() << endl;
    // cout << s21_List.back() << endl;
    // cout << std_List.back() << endl;

    // cout << s21_List.front() << endl;
    // cout << std_List.front() << endl;
    
    // cout << "show_Start" << endl;
    // s21_List.show();
    // cout << "show_Start_3" << endl;
    cout << "SIZE s21: " << s21_copy.size() << endl;
    cout << "SIZE std: " << std_copy.size() << endl;
    // s21_List.show();
    // cout << std_List.max_size() << endl;
    //  s21::List<int> s21_List = {1, 2, 3};

    // std_List.insert (99, 1);
    // std_List.removeAt(1);
    // std_List.pop_back();

    // cout<< "Элементов в списке" << std_List.Gestd_Listize() << endl << "Забрали первый элемент" << endl << endl;
    
    
//                                                                                                                                                                                                                                                                                                                                                                  for (size_t i = 0; i < std_List.size(); i++)
//     {
//         cout << std_List[i] << endl;
//     }
//     cout<< "Элементов в списке" << std_List.size() << endl;
//     return 0;
}






