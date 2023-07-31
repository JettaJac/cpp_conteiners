#include <gtest/gtest.h>
// #include <list>
// #include "s21_containers.h"
#include "list.h"
#include <List>

using namespace std;


//  std::list<int> std_List;     // обработать случай
//     cout << "std_List.back() " << endl; 
//     cout << std_List.back() << endl; 

TEST(List, Сonstructor_null_1) {
s21::List<int> s21_List;
std::list<int> std_List;
ASSERT_EQ(s21_List.size(), std_List.size());
}

// TEST(List, Сonstructor_throw_1) {
// s21::List<int> A (3);
// s21::List<int> A (5);
// ASSERT_EQ(A.size(), 0);
// }

TEST(List, Сonstructor_size_1) {
  s21::List<int> s21_List (5);
  ASSERT_EQ(s21_List.size(), 5);
}

TEST(List, Сonstructor_pushback_size_1) {
  s21::List<int> s21_List_1;
  s21::List<double> s21_List_2;
  s21::List<string> s21_List_3;
  s21_List_1.push_back(1);
  s21_List_2.push_back(0.235);
  s21_List_3.push_back("string_1");
  ASSERT_EQ(s21_List_1.size(), 1);
  ASSERT_EQ(s21_List_2.size(), 1);
  ASSERT_EQ(s21_List_3.size(), 1);
  s21_List_1.push_back(5);
  s21_List_2.push_back(0.0002);
  s21_List_3.push_back("string2");
  ASSERT_EQ(s21_List_1.size(), 2);
  ASSERT_EQ(s21_List_2.size(), 2);
  ASSERT_EQ(s21_List_3.size(), 2);
}

TEST(List, Сonstructor_pushback_size_2) {
  s21::List<int> A {1, 2 , 3};
  s21::List<double> s21_List_2 { 1.1, 1.2, 1.3};
  s21::List<string> s21_List_3 {"string_1", "string_2", "string_3"};
  ASSERT_EQ(A.size(), 3);
  ASSERT_EQ(s21_List_2.size(), 3);
  ASSERT_EQ(s21_List_3.size(), 3);
  A.push_back(5);
  s21_List_2.push_back(0.0002);
  s21_List_3.push_back("string_4");
  ASSERT_EQ(A.size(), 4);
  ASSERT_EQ(s21_List_2.size(), 4);
  ASSERT_EQ(s21_List_3.size(), 4);
}

TEST(List, Create_and_size_1) {
  s21::List<int> A = {1, 2, 3};
  EXPECT_EQ(A.size(), 3);
  s21::List<double> s21_List_2 = {1.23, 0.45, -4.65};
  EXPECT_EQ(s21_List_2.size(), 3);
  s21::List<char> s21_List_3 = {'F', 'O', 'X'};
  EXPECT_EQ(s21_List_3.size(), 3);
}

TEST(List, Constructor_Default) {
  s21::List<int> s21_List;
  std::list<int> std_List;
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_List.empty(), std_List.empty());
}

TEST(List, Clear) {
  s21::List<int> s21_List(3);
  std::list<int> std_List(3);
  s21_List.clear();
  EXPECT_EQ(s21_List.empty(), true);
}

TEST(List, Initializer_list) { 
  s21::List<int> s21_List {1, 2, 3};
  std::list<int> std_List {1, 2, 3};
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_List.front(), std_List.front());
  EXPECT_EQ(s21_List.back(), std_List.back());
}

TEST(List, Constructor_Initializer_List) { 
  s21::List<int> s21_List = {1, 2, 3, 4};
  EXPECT_EQ(s21_List.back(), 4);
  EXPECT_EQ(s21_List.size(), size_t(4));
  EXPECT_EQ(s21_List.empty(), false);
}

TEST(List, Front_s21_List_2ack) {  // сделать такой же тест. но с вылетом исключения
  s21::List<double> A;
       list<double> s21_List_2;
    A.push_back(1.2);
    A.push_back(1.1);
    s21_List_2.push_back(1.2);
    s21_List_2.push_back(1.1);
    ASSERT_EQ(A.front(), s21_List_2.front());
    ASSERT_EQ(A.back(), s21_List_2.back());
    
    s21::List<char> s21_List_3;
         list<char> D;
    s21_List_3.push_back('1');
    s21_List_3.push_back('2');
    D.push_back('1');
    D.push_back('2');
    ASSERT_EQ(s21_List_3.front(), D.front());
    ASSERT_EQ(s21_List_3.back(), D.back());
    
    s21::List<string> E;
         list<string> F;
    E.push_back("string_1");
    E.push_back("string_2");
    F.push_back("string_1");
    F.push_back("string_2");
    ASSERT_EQ(E.front(), F.front());
    ASSERT_EQ(E.back(), F.back());
}

TEST(List, Push_front) {  // сделать такой же тест. но с вылетом исключения (преднамеренная ошибка)
  s21::List<double> A;
       list<double> s21_List_2;
    A.push_front(1.2);
    A.push_front(1.1);
    s21_List_2.push_front(1.2);
    s21_List_2.push_front(1.1);
    ASSERT_EQ(A.front(), s21_List_2.front());
    ASSERT_EQ(A.back(), s21_List_2.back());
  
    s21::List<char> s21_List_3;
         list<char> D;
    s21_List_3.push_front('1');
    s21_List_3.push_front('2');
    D.push_front('1');
    D.push_front('2');
    ASSERT_EQ(s21_List_3.front(), D.front());
    ASSERT_EQ(s21_List_3.back(), D.back());
    
    s21::List<string> E;
         list<string> F;
    E.push_front("string_1");
    E.push_front("string_2");
    F.push_front("string_1");
    F.push_front("string_2");
    ASSERT_EQ(E.front(), F.front());
    ASSERT_EQ(E.back(), F.back());
}

TEST(List, Pop_back) {
  s21::List<double> s21_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  std::list<double> std_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  for (int i = 0;  i < s21_List.size(); i++)
  {
        s21_List.pop_back();
        std_List.pop_back();
        EXPECT_EQ(s21_List.back(), std_List.back());
  }
}

// TEST(List, Pop_back_empty) {
//   s21::List<double> s21_List;
//   std::list<double> std_List;
//         // s21_List.pop_back();
//         std_List.pop_back();
// }

TEST(List, Pop_front) {
  s21::List<double> s21_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  std::list<double> std_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  for (int i = 0;  i < s21_List.size(); i++)
  {
        s21_List.pop_front();
        std_List.pop_front();
        EXPECT_EQ(s21_List.front(), std_List.front());
  }
}

// TEST(List, Pop_front_empty) {
//   s21::List<double> s21_List;
//   std::list<double> std_List;
//         // s21_List.pop_front();
//         // std_List.pop_front();
//         EXPECT_EQ(s21_List.front(), std_List.front());
// }

TEST(List, Copy_list) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
      list<double> std_copy(std_List);
  s21::List<double> s21_copy(s21_List);
  EXPECT_EQ(s21_List.size(), 7);
  EXPECT_EQ(s21_copy.size(), 7);
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  for (int i = 0;  i < std_List.size(); i++)
  {        
        EXPECT_EQ(s21_copy.front(), std_copy.front());
        s21_copy.pop_front();
        std_copy.pop_front();
        
  }
  for (int i = 0;  i < std_copy.size(); i++)
  {
      // cout << "hh" << endl;
        EXPECT_EQ(s21_copy.back(), std_copy.back());
        s21_copy.pop_back();
        std_copy.pop_back();        
  } 
}

TEST(Stack, Copy_char) {
  s21::List<char> s21_stack_1 = {'f', 'o', 'x', 'y'};
  s21::List<char> s21_stack_2 = s21_stack_1;

  EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());

  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_1.back(), s21_stack_2.back());
    EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());
    s21_stack_1.pop_back(), s21_stack_2.pop_back();
  }
}

TEST(List, Copy_op) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_copy;
  s21::List<double> s21_copy;
  std_copy = std_List;  
  s21_copy = s21_List;
  
  EXPECT_EQ(s21_List.size(), 7);
  EXPECT_EQ(s21_copy.size(), 7);
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  
  for (int i = 0;  i < std_List.size(); i++)
  {
        EXPECT_EQ(s21_copy.front(), std_copy.front());
        s21_copy.pop_front();
        std_copy.pop_front();
  }

  for (int i = 0;  i < std_copy.size(); i++)
  {
      // cout << "hh" << endl;
        EXPECT_EQ(s21_copy.back(), std_copy.back());
        s21_copy.pop_back();
        std_copy.pop_back();        
  }
  // s21_List.show();

}

TEST(List, Move_list) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
      list<double> std_copy  = std::move (std_List);
  s21::List<double> s21_copy = move(s21_List);
  EXPECT_EQ(s21_List.size(), 0);
  EXPECT_EQ(s21_copy.size(), 7);
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_List.empty(), true);
  // s21_copy.show();
  for (int i = 0;  i < std_List.size(); i++)
  {
        EXPECT_EQ(s21_copy.front(), std_copy.front());
        s21_copy.pop_front();
        std_copy.pop_front();
  }

  for (int i = 0;  i < std_copy.size(); i++)
  {
      // cout << "hh" << endl;
        EXPECT_EQ(s21_copy.back(), std_copy.back());
        s21_copy.pop_back();
        std_copy.pop_back();        
  }
}

TEST(Stack, Move_char) {
  s21::List<char> s21_List_1 = {'f', 'o', 'x', 'y'};
  s21::List<char> s21_List_2 = std::move(s21_List_1);
  s21::List<char> s21_List_3 = {'f', 'o', 'x', 'y'};

  EXPECT_EQ(s21_List_2.size(), s21_List_3.size());
  EXPECT_EQ(s21_List_1.size(), size_t(0));
  EXPECT_EQ(s21_List_1.empty(), true);
  for (auto i = 0; i < s21_List_3.size(); i++) {
    EXPECT_EQ(s21_List_3.back(), s21_List_2.back());
    EXPECT_EQ(s21_List_3.size(), s21_List_2.size());
    s21_List_3.pop_back(), s21_List_2.pop_back();
  }
}

TEST(List, Move_op) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_copy;
  s21::List<double> s21_copy;
  std_copy = std::move(std_List);  
  s21_copy = move(s21_List);
  EXPECT_EQ(s21_List.size(), 0);
  EXPECT_EQ(s21_copy.size(), 7);
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  //// EXPECT_EQ(*s21_List.(), *std_List.());
  // // EXPECT_EQ(s21_copy.tail(), std_copy.tail());
  //// cout << std_List.size() << endl;
  //// cout << std_copy.size() << endl;
  //// cout << s21_List.size() << endl;
  //// cout << s21_copy.size() << endl;
  for (int i = 0;  i < std_copy.size(); i++)
  {
        EXPECT_EQ(s21_copy.front(), std_copy.front());
        s21_copy.pop_front();
        std_copy.pop_front();        
  }

  for (int i = 0;  i < std_copy.size(); i++)
  {
        EXPECT_EQ(s21_copy.back(), std_copy.back());
        s21_copy.pop_back();
        std_copy.pop_back();        
  }

}


TEST(List, Swap) { // Перепроверить тесты
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std_List_1.swap(std_List_2);
  s21_List_1.swap(s21_List_2);
  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  for (int i = 0;  i < std_List_1.size(); i++)
  {
        EXPECT_EQ(s21_List_1.front(), std_List_1.front());
        s21_List_1.pop_front();
        std_List_1.pop_front();        
  }
  for (int i = 0;  i < std_List_2.size(); i++)
  {
        EXPECT_EQ(s21_List_2.back(), std_List_2.back());
        s21_List_2.pop_back();
        std_List_2.pop_back();        
  }
}

// TEST(List, Unique) { // разбить на несколько тестов
//   s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.3, 1.3, 1.6, 7.7};
//   std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.3, 1.3, 1.6, 7.7};
//   s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 5.5};
//   std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 5.5};
//   s21::List<string> s21_List_3 {"str_1", "str_2", "str_3", "str_4", "str_5"};
//   std::list<string> std_List_3 {"str_1", "str_2", "str_3", "str_4", "str_5"};
//   s21::List<string> s21_List_4 {"str_1", "str_1", "str_3", "str_4", "str_3"};
//   std::list<string> std_List_4 {"str_1", "str_1", "str_3", "str_4", "str_3"};
//  //  swap(std_List_1, std_List_2);  
//   std_List_1.unique();
//   s21_List_1.unique();
//   std_List_2.unique();
//   s21_List_2.unique();
//   std_List_3.unique();
//   s21_List_3.unique();
//   std_List_4.unique();
//   s21_List_4.unique();
//   EXPECT_EQ(s21_List_1.size(), std_List_1.size());
//   EXPECT_EQ(s21_List_2.size(), std_List_2.size());
//   EXPECT_EQ(s21_List_3.size(), std_List_3.size());
//   EXPECT_EQ(s21_List_4.size(), std_List_4.size());

//   for (int i = 0;  i < std_List_1.size(); i++)
//   {
//         EXPECT_EQ(s21_List_1.front(), std_List_1.front());
//         s21_List_1.pop_front();
//         std_List_1.pop_front();        

//         EXPECT_EQ(s21_List_2.front(), std_List_2.front());
//         s21_List_1.pop_front();
//         std_List_1.pop_front();   

//         EXPECT_EQ(s21_List_3.front(), std_List_3.front());
//         s21_List_1.pop_front();
//         std_List_1.pop_front();   

//         EXPECT_EQ(s21_List_4.front(), std_List_4.front());
//         s21_List_1.pop_front();
//         std_List_1.pop_front();        
//   }

//   for (int i = 0;  i < std_List_2.size(); i++)
//   {
//         EXPECT_EQ(s21_List_2.back(), std_List_2.back());
//         s21_List_2.pop_back();
//         std_List_2.pop_back();        
//   }
// }


// TEST(List, Max_size) {
//   s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//   std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//   // EXPECT_EQ(s21_List.max_size(), std_List.max_size());
//   cout << std_List.max_size() << endl;
//   // cout << s21_List.max_size() << endl;
// }


// {
//    При создание 0 листа должна обрабатываться ошибка при  pop и запрос на последний обхъект
// std_List.pop_back();
//         EXPECT_EQ(s21_List.back(), std_List.back()); 
// }


// ----------------iterators----------------
// TEST(Stack, Iterator_Constr) {
//   s21::List<char> s21_stack_1 = {'f', 'o', 'x', 'y'};
//   std::list<char> std_stack_1 = {'f', 'o', 'x', 'y'};
//   s21::List<char> s21_stack_2 = s21_stack_1;

//   EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());

//   std_stack_1.begin();



//   for (auto i = 0; i < 4; i++) {
//     EXPECT_EQ(s21_stack_1.back(), s21_stack_2.back());
//     EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());
//     s21_stack_1.pop_back(), s21_stack_2.pop_back();
//   }
// }



TEST(ListIteratorTest, Begin) { // Переименновать тест ljgjkybnm dfhbfwbzvb
  s21::List<int> s21_List;
  
  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);

  std::list<int> std_List;
  std_List.push_back(1);
  std_List.push_back(2);
  std_List.push_back(3);

  // auto it = s21_List.begin();
  // s21::List<int>::ListIterator *it = s21_List.begin();
  EXPECT_EQ(*s21_List.begin(), *std_List.begin());

  // EXPECT_EQ(1, 1);
}

TEST(ListIteratorTest, End) { // Переименновать тест +add
  s21::List<int> s21_List;
  std::list<int> std_List;
  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);

  std_List.push_back(1);
  std_List.push_back(2);
  std_List.push_back(3);

  // auto it = s21_List.end();
  s21::List<int>::ListIterator it = s21_List.end();
  EXPECT_EQ(*it, *std_List.end());

  // EXPECT_EQ(1, 1);
}

// // TEST(ListIteratorTest, Increment) {
// //   s21::List<int> list;
// //   list.push_back(1);
// //   list.push_back(2);
// //   list.push_back(3);
// //   s21::ListIterator<int> it = list.begin();
// //   EXPECT_EQ(*it, 1);
// //   ++it;
// //   EXPECT_EQ(*it, 2);
// //   ++it;
// //   EXPECT_EQ(*it, 3);
// //   ++it;
// //   EXPECT_EQ(it, nullptr);
// // }

// // TEST(ListIteratorTest, Decrement) {
// //   s21::List<int> list;
// //   list.push_back(1);
// //   list.push_back(2);
// //   list.push_back(3);
// //   s21::ListIterator<int> it = list.end();
// //   --it;
// //   EXPECT_EQ(*it, 3);
// //   --it;
// //   EXPECT_EQ(*it, 2);
// //   --it;
// //   EXPECT_EQ(*it, 1);
// //   --it;
// //   EXPECT_EQ(it, nullptr);
// // }

// // // TEST(ListIteratorTest, ArrowOperator) {
// // //   s21::List<std::string> list;
// // //   list.push_back("hello");
// // //   list.push_back("world");
// // //   s21::ListIterator<std::string> it = list.begin();
// // //   EXPECT_EQ(it->size(), 5);
// // //   ++it;
// // //   EXPECT_EQ(it->size(), 5);
// // // }

// // TEST(ListIteratorTest, Equality) {
// //   s21::List<int> list;
// //   list.push_back(1);
// //   list.push_back(2);
// //   list.push_back(3);
// //   s21::ListIterator<int> it1 = list.begin();
// //   s21::ListIterator<int> it2 = list.begin();
// //   EXPECT_EQ(it1, it2);
// //   ++it1;
// //   EXPECT_NE(it1, it2);
// //   ++it2;
// //   EXPECT_EQ(it1, it2);
// // }

TEST(ListIteratorTest, CopyConstructor) {  //trow создаем 0, пытаемся сдвинуться
  s21::List<int> s21_List;
  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);
  s21::List<int>::iterator s21_it1 = s21_List.begin();
  s21::List<int>::ListIterator s21_it2(s21_it1);
  EXPECT_EQ(*s21_it1, *s21_it2);
  EXPECT_EQ(1, *s21_it2);
  ++s21_it1;
  EXPECT_NE(*s21_it1, *s21_it2); 


  std::list<int> std_List;
  std_List.push_back(1);
  std_List.push_back(2);
  std_List.push_back(3);
  std::list<int>::iterator std_it1 = std_List.begin();
  std::list<int>::iterator std_it2(std_it1);
  EXPECT_EQ(*std_it1, *std_it2);
  EXPECT_EQ(1, *std_it2);
  ++std_it1;
  EXPECT_NE(*std_it1, *std_it2); // тут NE
  EXPECT_EQ(1, *std_it2);
  EXPECT_EQ(*std_it1, 2);
  ++std_it2;
  EXPECT_EQ(*std_it1, *std_it2);
  EXPECT_EQ(2, *std_it2);


EXPECT_EQ(*std_it1, *std_it2);


}
TEST(ListIteratorTest, Increment) { // сделать исключение
  s21::List<int> s21_List;
  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);
  s21_List.push_back(4);
  s21::List<int>::iterator s21_it = s21_List.begin();

  std::list<int> std_List;
  std_List.push_back(1);
  std_List.push_back(2);
  std_List.push_back(3);
  std_List.push_back(4);
  std::list<int>::iterator std_it = std_List.begin();

  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  s21_it++;
  std_it++;
  // s21_it++;
  std_it++;
  EXPECT_EQ(*s21_it, *std_it);
  // ++s21_it;  //  не работает
  // ++std_it;
  // ++s21_it;
  // ++std_it;
  // EXPECT_EQ(1, *std_it);
}

// // TEST(ListIteratorTest, Decrement) { // сделать исключение
// //   s21::List<int> s21_List;
// //   s21_List.push_back(1);
// //   s21_List.push_back(2);
// //   s21_List.push_back(3);
// //   s21_List.push_back(4);
// //   s21::List<int>::iterator s21_it = s21_List.begin();

// //   std::list<int> std_List;
// //   std_List.push_back(1);
// //   std_List.push_back(2);
// //   std_List.push_back(3);
// //   std_List.push_back(4);
// //   std::list<int>::iterator std_it = std_List.begin();

// //   EXPECT_EQ(*s21_it, *std_it);
// //   --s21_it;
// //   --std_it;
// //   --s21_it;
// //   --std_it;
// //   EXPECT_EQ(*s21_it, *std_it);
// //   s21_it--;
// //   std_it--;
// //   s21_it--;
// //   std_it--;
// //   EXPECT_EQ(*s21_it, *std_it);
// //   // --s21_it;
// //   // --std_it;
// //   // --s21_it;
// //   // --std_it;
// //   // EXPECT_EQ(1, *std_it);
// // }


// // TEST(ListIteratorTest, AssignmentOperator) {
// //   s21::List<int> list;
// //   list.push_back(1);
// //   list.push_back(2);
// //   list.push_back(3);
// //   s21::ListIterator<int> it1 = list.begin();
// //   s21::ListIterator<int> it2;
// //   it2 = it1;
// //   EXPECT_EQ(it1, it2);
// //   ++it1;
// //   EXPECT_NE(it1, it2);
// //   ++it2;
// //   EXPECT_EQ(it1, it2);
// // }














int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}




// // //  std::list<int> c1(3, 100);
// // //     print(1, c1);
 
// // //     auto it = c1.begin();
// // //     it = c1.insert(it, 200);
// // //     print(2, c1);
 
// // //     c1.insert(it, 2, 300);
// // //     print(3, c1);
 
// // //     // reset `it` to the begin:
// // //     it = c1.begin();
 
// // //     std::list<int> c2(2, 400);
// // //     c1.insert(std::next(it, 2), c2.begin(), c2.end());
// // //     print(4, c1);
 
// // //     int arr[] = {501, 502, 503};
// // //     c1.insert(c1.begin(), arr, arr + std::size(arr));
// // //     print(5, c1);
 
// // //     c1.insert(c1.end(), {601, 602, 603});
// // //     print(6, c1);