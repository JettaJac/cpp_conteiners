#include "List.h"
#include <List>

int main(){
    // g++ List.cc && ./a.out 
    // g++ main.cc && ./a.out 
// g++ -lstdc++ -std=c++17 main.cc && ./a.out
  
    using namespace std;

    setlocale(LC_ALL, "ru");
    // const std::list<int> std_List = {1, 2, 4, 5, 5, 6, 7};
    // std::list<int> std_List_2 = {5, 6, 8, 9};
    // auto it = std_List.cbegin();
    // s21::List<int> s21_List_5(5);

s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//   std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//       list<double> std_copy  = std::move (std_List);
    s21::List<double> s21_copy = move(s21_List);
    s21_copy.show();
    // s21::List<int> s21_List;
    // s21::List<int> s21_List{1, 2, 3, 4, 5, 6, 7};
    // s21::List<int> s21_List_2{5, 6, 7, 8};
    // s21::List<int> s21_List2(-1);
    // list<int> std_List2(-1);
    // cout <<  std_List2.front() << endl;
    // list<int> std_copy(std_List);
    //      list<int> std_copy();
    // s21::List<int> s21_copy();
    // std_copy = move(std_List);
    
    
    cout << "start function" << endl;

    // // Increment
    // s21::List<int> s21_List;
    // s21_List.push_back(1);
    // s21_List.push_back(2);
    // s21_List.push_back(3);
    // s21::List<int>::iterator s21_it1 = s21_List.begin();
    // s21::List<int>::ListIterator s21_it2(s21_it1);

    // std::list<int> std_List;
    // std_List.push_back(1);
    // std_List.push_back(2);
    // std_List.push_back(3);
    // std::list<int>::iterator std_it1 = std_List.begin();
    // std::list<int>::iterator std_it2(std_it1);

    // cout << " std_Iterators :" << *std_it1 << " and " << *std_it2 << endl;
    // cout << " s21_Iterators :" << *s21_it1 << " and " << *s21_it2 << endl;
    // ++s21_it1;
    // s21_it1++;
    // s21_it1++;
    // s21_it1++;
    // s21_it1++;
    // ++std_it1;
    // // std_it1++;
    // ++s21_it1;
    // s21_it1++;
    // ++std_it1;
    // std_it1++;
    // ++std_it1;
    // ++std_it1;
    // ++std_it1;
    // ++std_it1;
    // std_it1++;
    // std_it1++;
    // std_it1++;
    // std_it1++;
    // std_it1++;
    // // std_it1++;

    // s21_it1++;
    // s21_it1++;
    // s21_it1++;
    // s21_it1++;
    // // s21_it1++;
    // s21_it1++; 
    // // cout << " std_Iterators :" << *std_it1 << endl;
    // cout << " std_Iterators :" << *std_it1 << " and " << *s21_it1 << endl;
    // // cout << " s21_Iterators :" << *s21_it1 << " and " << *s21_it2 << endl;


    // 
    // std::list<int> std_List;
    // cout << "std_List.back() " << endl; 
    // cout << std_List.back() << endl; 
    // cout << *std_List.begin() << endl; 

    // s21::List<int> s21_copy(s21_List);
    // s21::List<int> s21_copy(s21_List);
    // std::list<int> std_copy = std::move(std_List);
    // s21::List<int> s21_copy = move(s21_List);
    // std::list<int> std_copy;
    // s21::List<int> s21_copy;
    // std_copy = std_List;  
    // s21_copy = s21_List;
    // std_copy = std::move(std_List);  
    // s21_copy = move(s21_List);
    // std_List.swap(std_List_2);
    // s21_List.swap(s21_List_2);

    // std_List.merge(std_List_2);

    // std_List.reverse();
    // std_List.unique();
    // s21_List.unique();

    // std_List.sort();
    // s21::List<int>::ListIterator it21  = s21_List.begin();
    // // ++i;
    // it21++;
//    s21::List<int>::ListIterator *it  = 
//    typename s21::List<int>::ListIterator *i = s21_List.begin();

    // auto i = s21_List.begin();
    // cout << "ttttt_" << *it21 << endl;

    cout << "finish function" << endl;
    // s21::List<int>                                                                                                                                                =  move(s21_List);
    // s21_List.clear();
    // std_List.push_back(5);
    // s21_List.push_back(10);
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

    // s21_List.back();
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
    // s21_copy.pop_front();
    // std_copy.pop_front();
   

    // cout << s21_List.size() << endl;
    // cout << s21_copy.back() << endl;
    // cout << std_copy.back() << endl;

    // cout << s21_copy.front() << endl;
    // cout << std_copy.front() << endl;

    // s21::List<int> s21_List;

    // s21_List.push_back(1);
    // s21_List.push_back(2);
    
    // cout << "show_Start_List" << endl;
    // s21_List.show();

    // cout << "std: show_Start_List_move" << endl;
    // for (const auto& element : std_List) {
        
    //     cout << element << " x ";
    // }
    // cout << endl;

    // cout << "SIZE s21: " << s21_List.size() << endl;
    // cout << "SIZE std: " << std_List.size() << endl;
    // cout << endl;

    // cout << "show_Start_copy_move" << endl;
    // s21_List_2.show();

    // cout << "std: show_Start_copy_move" << endl;
    // for (const auto& element : std_List_2) {
        
    //     cout << element << " x ";
    // }
    // cout << endl;

    // // cout << "SIZE s21: " << s21_copy.size() << endl;
    // // cout << "SIZE std: " << std_copy.size() << endl;

    // cout << "SIZE s21: " << s21_List_2.size() << endl;
    // cout << "SIZE std: " << std_List_2.size() << endl;
    
    

 
     
// 
    //  for (const auto& element : std_List) {
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;



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


cout << "Finish_Main" << endl;
cout << endl;


// s21_List.


    
    // list<int> sourceList = {1, 2, 3, 4, 5};
    
    // list<int> destinationList;

    // // Копируем элементы из sourceList в destinationList
    // destinationList = sourceList;

    // // Выводим скопированные элементы на экран
    // for (const auto& element : destinationList) {
        
    //     cout << element << " ";
    // }
    
    // cout << 
    // endl;

    return 0;











}






