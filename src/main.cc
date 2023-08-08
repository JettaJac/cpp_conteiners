#include "list.h"
#include <List>

int main(){
    // g++ List.cc && ./a.out 
    // g++ main.cc && ./a.out 
// g++ -lstdc++ -std=c++17 main.cc && ./a.out
  
    using namespace std;

    setlocale(LC_ALL, "ru");
    // const std::list<double> std_List = {1, 2, 4, 5, 5, 6, 7};
    
    std::list<double> std_List_2 = {99, 5, 6, 8, 9};
    s21::List<double> s21_List_2 = {99, 5, 6, 8, 9};
    // auto it = std_List.cbegin();
    // s21::List<double> s21_List2(5);
    // s21_List2.push_back(5);
    // s21_List2.show();
// s21::List<double> s21_List {2.2, 1.2, 2.1, 1.4, 2.2, 1.7, 1.7};
// std::list<double> std_List {2.2, 1.2, 2.1, 1.4, 2.2, 1.7, 1.7};
s21::List<double> s21_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//   std_List.sort();
//   s21_List.sort();
  
// cout  << *s21_List.end() << endl;

//   for (int i = 0;  i < s21_List.size(); i++)
//   {
//         s21_List.pop_back();
//         std_List.pop_back();
//        cout << s21_List.back() << " and " << std_List.back()<< endl;
//   }

// s21::List<double> s21_List_2;
// std::list<double> std_List_2;
// s21_List_2.push_back(1.1);
// s21_List_2.push_back(2.2);
// s21_List_2.push_back(3.3);
// std_List_2.push_back(1.1);
// std_List_2.push_back(2.2);
// std_List_2.push_back(3.3);

// std::list<double>::iterator std_it_2 = std_List_2.begin();
// s21::List<double>::iterator s21_it_2 = s21_List_2.begin();  
// while(std_it_2 != std_List_2.end()++) {
//   cout << *std_it_2 << " yyy " << *s21_it_2 << " pppp " << *s21_List_2.end()-- <<  endl;
  
//   ++std_it_2, ++s21_it_2;
// }
// s21_List_2.show();
// cout << s21_List_2.max_size() <<   endl;

//       list<double> std_copy  = std::move (std_List);
    // s21::List<double> s21_copy = move(s21_List);
    // s21_copy.show();
    // s21::List<double> s21_List;
    // s21::List<double> s21_List{1, 2, 3, 4, 5, 6, 7};
    // s21::List<double> s21_List_2{5, 6, 7, 8};
    // s21::List<double> s21_List2(-1);
    // list<double> std_List2(-1);
    // cout <<  std_List2.front() << endl;
    // list<double> std_copy(std_List);
    //      list<double> std_copy();
    // s21::List<double> s21_copy();
    // std_copy = move(std_List);
    
    
    // cout << "start function" << endl;

    // // END
    // cout << " s21_Iterators :" << "*s21_it1" << " and " << " " << endl;
    // cout << "END " << *s21_List.end() << endl;
    // cout << "END " << *std_List.end() << endl;

// ______________________
    // // Increment


    // s21::List<double> s21_List(1);
    // s21_List.push_back(6);
    // s21_List.push_back(7);
    // s21_List.push_back(9);
    //  s21_List.push_back(12);

    // // s21_List.push_front(30);
    // // s21_List.push_front(20);
    // // s21_List.push_front(10);
    
    
    // // s21_List.push_front(4);
    s21::List<double>::iterator s21_it1 = s21_List.begin();
    // s21::List<double>::const_iterator s21_it1 = s21_List.cbegin();
    // s21::List<double>::iterator s21_it1 = s21_List.end();
    // s21::List<double>::iterator s21_it2 = s21_List.begin();
    // // s21::List<double>::ListIterator s21_it2(s21_it1);

    // // s21::List<double>::iterator s21_it1 = s21_List.end();

    // s21_it1++;
    // s21_it1++;
    // s21_it1++;
    // std::list<double> std_List(1);
    // //  std_List.push_front(1);
    // std_List.push_back(6);
    // std_List.push_back(7);
    // std_List.push_back(9);
    // std_List.push_back(12);

    // // std_List.push_front(30);
    // // std_List.push_front(20);
    // // std_List.push_front(10);

    // // std_List.push_back(4);
 
    // // std::list<double>::iterator std_it2(std_it1);

    // // std::list<double>::iterator std_it1 = std_List.end();

    // std::list<double>::iterator std_it1 = std_List.end();
    std::list<double>::iterator std_it1 = std_List.begin();
    std::list<double>::const_iterator std_it2 = std_List_2.cbegin();
    s21::List<double>::const_iterator s21_it2 = s21_List_2.cbegin();
    
    // cout << " std_Iterators_s0 : " << *std_it1 << " and " << *s21_it1 << endl;
    

    
    // for (double i = 0; i < std_List.size()+3; i++){
    //     // cout << *std_it2<< " / " ;
    //     cout << *std_it1 << " * " ;
    //     --std_it1;
    // }
    // cout << endl;

    // for (double i = 0; i < s21_List.size()+3; i++){
    //     // cout << *s21_it2<< " / " ;
    //     cout << *s21_it1 << " * " ;
    //     --s21_it1;
    // }
    // cout << endl;


    // // for (double i = s21_List.size(); i > 0; i--){
    // //     // cout << *s21_it2<< " / " ;
    // //     cout << *s21_it1 << " * " ;
    // //     s21_it1--;
    // // }
    // // cout << endl;
    
    // // for (double i = 0 ; i < std_List.size()+5; i++){
    // //     // cout << *std_it2<< " / " ;
    // //     cout << *std_it1 << " * " ;
    // //     std_it1--;
    // // }
    // cout << endl;

    // cout << " std_Iterators_s: " << *std_it1 << " and " << *s21_it1 << endl;
    // // cout << " s21_Iterators: " << *s21_it1 << " and " << *s21_it2 << endl;
    // // s21_it1--;
    // // s21_it1--;
    // // // s21_it1--;
    // // // s21_it1--;
    // // // s21_it1--;
    // // // s21_it1--;
    // // // s21_it1--;
    // // // // s21_it1--;

    // // // // std_it1--;
    // // // std_it1--;
    // // // std_it1--;
    // // // std_it1--;
    // // // std_it1--;
    // // // std_it1--;
    // // std_it1--;
    // // std_it1--;


    // // std_it1--;
    // // --std_it1;
    // // // --std_it1;
    // // // // --std_it1;
    // // // // // --std_it1;
    // // // // // // --std_it1;


    // // // // // // --s21_it1;
    // // // // // --s21_it1;
    // // // // --s21_it1;
    // // // --s21_it1;
    // // --s21_it1;



    // std_it1--;
    // std_it1--;
    // // std_it1--;
    // // // std_it1--;
    // // // // std_it1--;
    // // // // // std_it1--;
    // // // // // // std_it1--;
    // // // // // // // std_it1--;


    // // // // // // // s21_it1--;
    // // // // // // s21_it1--;
    // // // // // s21_it1--;
    // // // // s21_it1--;
    // // // s21_it1--;
    // // s21_it1--;
    // s21_it1--;
    // s21_it1--;

    // // cout << " std_Iterators :" << *std_it1 << endl;
    // cout << " std_Iterators_f: " << *std_it1 << " and " << *s21_it1 << endl;
    // // cout << " s21_Iterators: " << *s21_it1 << " and " << *s21_it2 << endl;
// _____________________________



//     // 
    // std::list<double> std_List;
//     // cout << "std_List.back() " << endl; 
//     // cout << std_List.back() << endl; 
//     // cout << *std_List.begin() << endl; 

//     // s21::List<double> s21_copy(s21_List);
//     // s21::List<double> s21_copy(s21_List);
//     // std::list<double> std_copy = std::move(std_List);
//     // s21::List<double> s21_copy = move(s21_List);
//     // std::list<double> std_copy;
//     // s21::List<double> s21_copy;
//     // std_copy = std_List;  
//     // s21_copy = s21_List;
//     // std_copy = std::move(std_List);  
//     // s21_copy = move(s21_List);
//     // std_List.swap(std_List_2);
//     // s21_List.swap(s21_List_2);

    // std_List.merge(std_List_2);
    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    // s21_it1++;
    // std_it1++;
    // s21_it1++;
    // std_it1++;
    // s21_it1++;
    // std_it1++;
    
    // s21_List.splice(s21_it1, s21_List_2);
    // std_List.splice(std_it1, std_List_2);

    // cout << "std_size_l2 " << std_List_2.size() << endl;
    // cout << "s21_size_l2 " << s21_List_2.size() << endl;
    // cout << "std_begin_l2 " << *std_List_2.begin() << endl;
    // cout << "s21_begin_L2 " << *s21_List_2.begin() << endl;
    cout << "std_begin_L " << *(--std_List.begin()) << endl;
    cout << "s21_begin_L " << *(--s21_List.begin()) << endl;
    cout << endl;
    // cout << "std_end_l2 " << *std_List_2.end() << endl;
    // cout << "s21_end_L2 " << *s21_List_2.end() << endl;
    cout << "std_end_L " << *(--std_List.end()) << endl;
    cout << "s21_end_L " << *(--s21_List.end()) << endl;
    // s21_List.sort();
    // std_List.sort();
    // std_List.reverse();
    // s21_List.reverse();
    // std_List.unique();
    // s21_List.unique();
    // s21_it1++;
    // std_it1++;
    // s21_it1++;
    // std_it1++;
    // s21_it1++;
    // std_it1++;
    // s21_it1++;
    // std_it1++;
    //  s21_it1++;
    // std_it1++;
    //  s21_it1++;
    // std_it1++;
    
    // s21_it1++;
    // std_it1++;

    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    // s21_it1--;
    // std_it1--;
    
    
    // // for (int i = 0; i < 3; i++){
    //     cout << "Erase_0 " << *std_it1 << " and " << *s21_it1 << endl;
    //     // std_List.erase(std_it1);
    //     // s21_List.erase(s21_it1);

    // std::list<double>::iterator std_it = std_List.begin();
    // s21::List<double>::iterator s21_it = s21_List.begin();

    // // s21_List_1.erase(s21_it1);
    // // s21_List_1.erase(s21_it2);
    // // std_it++;
    // // s21_it++;
    // std_List.erase(std_it);
    // s21_List.erase(s21_it);
        
        
    // // for(s21::List<double>::iterator it = s21_List.begin(); it != s21_List.end(); it++){
    //     // cout << *s21_it_12<< " / " ;      
    //     // EXPECT_EQ(*s21_it, *std_it);/
         
        // s21_it1++;
        // std_it1++;
        // std_it1++;
        // s21_it1++;
    //     cout << "Erase_1 " << *std_it1 << " and " << *s21_it1 << endl;
    // }
    // s21_List.insert(--s21_it1, 21);
    // std_List.insert(--std_it1, 21);
    // cout << "Erase_f " << *std_it1 << " and " << *s21_it1 << " Size " << s21_List.size() << endl;
    // if (s21_it1 != s21_it2){
    //     cout << "Erase_ " << *std_it1 << " and " << *s21_it2 << endl;
    // }

    // cout << "Erase_ " << *std_it << " and " << *s21_it << endl;




//     // s21::List<double>::ListIterator it21  = s21_List.begin();
//     // // ++i;
//     // it21++;
// //    s21::List<double>::ListIterator *it  = 
// //    typename s21::List<double>::ListIterator *i = s21_List.begin();

//     // auto i = s21_List.begin();
//     // cout << "ttttt_" << *it21 << endl;

//     cout << "finish function" << endl;
//     // s21::List<double>                                                                                                                                                =  move(s21_List);
//     // s21_List.clear();
//     // std_List.push_back(5);
//     // s21_List.push_back(10);
//     // s21::List<double> lst2;
//     // std_List.push_back(22);
//     // s21::List<double> s21_List;
//     // s21_List.push_back(11);
//     // std_List.push_front(22);
//     // cout << s21_List.front() << endl;
//     // s21_List.push_back(22);
//     // list<double> std_List(3);
//     // std_List.push_front(22);
//     // <double>std_List(5);
//     // cout << std_List.front() << endl;
//     // cout << lst[0] << endl;
//     // s21_List.push_front(1.2);
//     // s21_List.push_front(1.3);
//     // for (size_t i = 0; i < std_List.Gestd_Listize(); i++)
//     // {
        
//     //     cout << lst[i] << endl;
//     //     // cout >> lst->x >> endl;
//     // }

//     // s21_List.back();
//     // std_List.back();
//     // std_List.back();
//     // s21_List.pop_front();
//     // s21_List.pop_front(); 

//     // s21_List.pop_back();
//     // s21_List.pop_back();
//     // cout << s21_List.back() << endl;
//     // s21_List.pop_back();
//     // s21_List.pop_back();
//     // s21_List.pop_back();
//     // s21_List.pop_back();

//     // s21_List.pop_front();
//     // s21_List.pop_front();
//     // s21_List.pop_front();
//     // s21_List.pop_front();
//     // s21_copy.pop_front();
//     // std_copy.pop_front();
   

//     // cout << s21_List.size() << endl;
//     // cout << s21_copy.back() << endl;
//     // cout << std_copy.back() << endl;

//     // cout << s21_copy.front() << endl;
//     // cout << std_copy.front() << endl;

//     // s21::List<double> s21_List;

//     // s21_List.push_back(1);
//     // s21_List.push_back(2);


//     // ________________insert_______________

//  std::list<double> std_List_in {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
//   s21::List<double> s21_List_in {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
//   std::list<double>::iterator std_it_2 = std_List_in.begin();
//   s21::List<double>::iterator s21_it_2 = s21_List_in.begin();
//   std_List_in.insert(std_it_2, 21);
//   s21_List_in.insert(s21_it_2, 21);

//   std_it_2++, s21_it_2++;
//   std_it_2++, s21_it_2++;
//   for (int i = 0; i < 5; i++){
//     cout << "____________" << endl;
//     cout << *std_it_2 << " and "<< *s21_it_2 << endl;
//     cout <<  endl;

//     std_List_in.insert(std_it_2, 22);
//     s21_List_in.insert(s21_it_2, 22);
//     std_it_2++, s21_it_2++;
//   }
//     std::list<double>::iterator std_it_b = std_List.begin();
//   while(std_it_b != std_List.end()) {
// //   while(std_it_2 != std_List.end()) {
//     cout << *std_it_2 << " and "<< *s21_it_2 << endl;
//     // EXPECT_EQ(*std_List.begin(), *s21_List.begin());
//     // EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
//    ++std_it_2, ++s21_it_2;
//    ++std_it_b;
//   }

// //   for (int i = 0;  i < std_List_in.size(); i++)
// //   {        
// //         cout << s21_List_in.front() << " and " <<  std_List_in.front() << endl;
// //         s21_List_in.pop_front();
// //         std_List_in.pop_front();        
// //   }

// //   for (int i = 0;  i < std_List_in.size(); i++)
// //   {
// //         cout << s21_List_in.back() << " and " << std_List_in.back() <<  endl;
// //         s21_List_in.pop_back();
// //         std_List_in.pop_back();        
// //   } 


// //   __________________________________________________

// ________________ERASE_______________

//  std::list<double> std_List_in {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
//   s21::List<double> s21_List_in {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
//   std::list<double>::iterator std_it_2 = std_List_in.begin();
//   s21::List<double>::iterator s21_it_2 = s21_List_in.begin();
// //   std_List_in.erase(std_it_2);
//   s21_List_in.erase(s21_it_2);
//   cout << "____________" << endl;

// //   std_it_2++;
//   s21_it_2++;
// //   std_List_in.erase(std_it_2);
// //   std_it_2++;
// //   std_List_in.erase(std_it_2);
// //   std_List_in.erase(std_it_2);


//   s21_List_in.erase(s21_it_2);
//   s21_it_2++;
//   s21_List_in.erase(s21_it_2);
// //   cout << "____________" << endl;
// //   std_it_2++, s21_it_2++;
// //   cout << "____________" << endl;
// //   for (int i = 0; i < 5; i++){
// //     cout << "f____________" << endl;
// //     cout << *std_it_2 << " and "<< *s21_it_2 << endl;
// //     cout <<  endl;

// //     std_List_in.erase(std_it_2);
// //     s21_List_in.erase(s21_it_2);
// //     cout << "f____________" << endl;
// //     std_it_2++, s21_it_2++;
// //   }
// //     std::list<double>::iterator std_it_b = std_List.begin();
// //   while(std_it_b != std_List.end()) {
// // //   while(std_it_2 != std_List.end()) {
// //     cout << *std_it_2 << " and "<< *s21_it_2 << endl;
// //     // EXPECT_EQ(*std_List.begin(), *s21_List.begin());
// //     // EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
// //    ++std_it_2, ++s21_it_2;
// //    ++std_it_b;
// //   }

// //   for (int i = 0;  i < std_List_in.size(); i++)
// //   {        
// //         cout << s21_List_in.front() << " and " <<  std_List_in.front() << endl;
// //         s21_List_in.pop_front();
// //         std_List_in.pop_front();        
// //   }

// //   for (int i = 0;  i < std_List_in.size(); i++)
// //   {
// //         cout << s21_List_in.back() << " and " << std_List_in.back() <<  endl;
// //         s21_List_in.pop_back();
// //         std_List_in.pop_back();        
// //   } 


// //   __________________________________________________

cout << "_________________________SPLICE_____________________" << endl;


  s21::List<double> s21_List_sp_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_sp_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List_sp_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_sp_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  auto std_it_sp = std_List_sp_1.cbegin();
  auto s21_it_sp = s21_List_sp_1.cbegin();
  s21_List_sp_1.splice(s21_it_sp, s21_List_sp_2);
  std_List_sp_1.splice(std_it_sp, std_List_sp_2);

  cout << s21_List_sp_1.size() << " and " << std_List_sp_1.size() << endl;
  cout << s21_List_sp_2.size() << " and " << std_List_sp_2.size() << endl;
  
  auto std_it_b = std_List_sp_1.begin();
  while(std_it_b != std_List_sp_1.end()) {
//   while(std_it_sp != std_List_sp_1.end()) {
    // cout << *std_it_sp << " and " << *s21_it_sp << endl;
    // cout << std_List_sp_1.size() << " and " << s21_List_sp_1.size()<< endl;
    // cout << *std_List_sp_1.begin() << " and " << *s21_List_sp_1.begin()<< endl;
    // cout << *(--std_List_sp_1.end()) << " and " <<  *(--s21_List_sp_1.end())<< endl;

    // cout << std_List_sp_2.size() << " and " <<  s21_List_sp_2.size()<< endl;
    cout << *std_List_sp_2.begin() << " and " <<   *s21_List_sp_2.begin()<< endl;
    cout << *(--std_List_sp_2.end()) << " and " <<   *(--s21_List_sp_2.end())<< endl;

    ++std_it_sp, ++s21_it_sp;
    std_it_b++;
  }

    // ___________________________________________

    cout << "show_Start_List" << endl;
    s21_List_sp_1.show();

    cout << "std: show_Start_List_move" << endl;
    for (const auto& element : std_List_sp_1) {
        
        cout << element << " x ";
    }
    cout << endl;
    cout << "SIZE " << std_List_sp_1.size()  << endl;
    cout << endl;

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



    // cout << "std_" << std_List.max_size() << endl;
    // cout << "s21_" << s21_List.max_size() << endl;
    //  s21::List<double> s21_List = {1, 2, 3};

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


    
    // list<double> sourceList = {1, 2, 3, 4, 5};
    
    // list<double> destinationList;

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






