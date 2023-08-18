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
EXPECT_EQ(s21_List.size(), std_List.size());
EXPECT_EQ(std_List.empty(), s21_List.empty());
}

// TEST(List, Сonstructor_throw_1) {
// s21::List<int> A (3);
// s21::List<int> A (5);
// EXPECT_EQ(A.size(), 0);
// }
TEST(List, Сonstructor_size_0) {
  std::list<int> std_List (0);
  s21::List<int> s21_List (0);
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(std_List.empty(), s21_List.empty());
}

TEST(List, Сonstructor_size_1) {
  std::list<int> std_List (5);
  s21::List<int> s21_List (5);
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(std_List.empty(), s21_List.empty());
}

TEST(List, Сonstructor_pushback_size_1) {
  s21::List<int> s21_List_1;
  s21::List<double> s21_List_2;
  s21::List<string> s21_List_3;
  s21_List_1.push_back(1);
  s21_List_2.push_back(0.235);
  s21_List_3.push_back("string_1");
  EXPECT_EQ(s21_List_1.size(), 1);
  EXPECT_EQ(s21_List_2.size(), 1);
  EXPECT_EQ(s21_List_3.size(), 1);
  s21_List_1.push_back(5);
  s21_List_2.push_back(0.0002);
  s21_List_3.push_back("string2");
  EXPECT_EQ(s21_List_1.size(), 2);
  EXPECT_EQ(s21_List_2.size(), 2);
  EXPECT_EQ(s21_List_3.size(), 2);
}

TEST(List, Сonstructor_pushback_size_2) {
  s21::List<int> s21_List_1 {1, 2, 3};
  s21::List<double> s21_List_2 { 1.1, 1.2, 1.3};
  s21::List<string> s21_List_3 {"string_1", "string_2", "string_3"};
  EXPECT_EQ(s21_List_1.size(), 3);
  EXPECT_EQ(s21_List_2.size(), 3);
  EXPECT_EQ(s21_List_3.size(), 3);
  s21_List_1.push_back(5);
  s21_List_2.push_back(0.0002);
  s21_List_3.push_back("string_4");
  EXPECT_EQ(s21_List_1.size(), 4);
  EXPECT_EQ(s21_List_2.size(), 4);
  EXPECT_EQ(s21_List_3.size(), 4);
}

TEST(List, Create_and_size_1) {
  std::list<int> s21_List_1 = {1, 2, 3};
  s21::List<int> std_List_1 = {1, 2, 3};
  EXPECT_EQ(std_List_1.size(), s21_List_1.size());
  std::list<double> std_List_2 = {1.23, 0.45, -4.65};
  s21::List<double> s21_List_2 = {1.23, 0.45, -4.65};
  EXPECT_EQ(std_List_2.size(), s21_List_2.size());
  std::list<char> std_List_3 = {'F', 'O', 'X'};
  s21::List<char> s21_List_3 = {'F', 'O', 'X'};
  EXPECT_EQ(std_List_3.size(), s21_List_3.size());
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
  std_List.clear();
  EXPECT_EQ(std_List.empty(), s21_List.empty());
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  EXPECT_EQ(*(std_List.end()), *(s21_List.end()));
}

TEST(List, Initializer_list) { 
  s21::List<int> s21_List {1, 2, 3};
  std::list<int> std_List {1, 2, 3};
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(std_List.front(), s21_List.front());
  EXPECT_EQ(std_List.back(), s21_List.back());
}

TEST(List, Constructor_Initializer_List) { 
  s21::List<int> s21_List = {1, 2, 3, 4};
  std::list<int> std_List = {1, 2, 3, 4};
  EXPECT_EQ(std_List.front(), s21_List.front());
  EXPECT_EQ(std_List.back(), s21_List.back());
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(std_List.empty(), s21_List.empty());
}

TEST(List, Front_s21_List_back) {  // сделать такой же тест, но с вылетом исключения
  std::list<double> std_List_1;
  s21::List<double> s21_List_1;
  std_List_1.push_back(1.2);
  std_List_1.push_back(1.1);
  s21_List_1.push_back(1.2);
  s21_List_1.push_back(1.1);
  EXPECT_EQ(std_List_1.front(), s21_List_1.front());
  EXPECT_EQ(std_List_1.back(), s21_List_1.back());
  EXPECT_EQ(std_List_1.size(), s21_List_1.size());
  
  std::list<char> std_List_2;
  s21::List<char> s21_List_2;
  std_List_2.push_back('1');
  std_List_2.push_back('2');
  s21_List_2.push_back('1');
  s21_List_2.push_back('2');
  EXPECT_EQ(std_List_2.front(), s21_List_2.front());
  EXPECT_EQ(std_List_2.back(), s21_List_2.back());
  EXPECT_EQ(std_List_2.size(), s21_List_2.size());
  
  std::list<string> std_List_3;
  s21::List<string> s21_List_3;
  std_List_3.push_back("string_1");
  std_List_3.push_back("string_2");
  s21_List_3.push_back("string_1");
  s21_List_3.push_back("string_2");
  EXPECT_EQ(std_List_3.front(), s21_List_3.front());
  EXPECT_EQ(std_List_3.back(), s21_List_3.back());
  EXPECT_EQ(std_List_3.size(), s21_List_3.size());
}


TEST(List, Push_back) { 
  s21::List<double> s21_List;
  std::list<double> std_List;
  s21_List.push_back(1.1);
  s21_List.push_back(2.2);
  s21_List.push_back(3.3);
  std_List.push_back(1.1);
  std_List.push_back(2.2);
  std_List.push_back(3.3);

  std::list<double>::iterator std_it = std_List.begin();
  s21::List<double>::iterator s21_it = s21_List.begin();  
  while(std_it != std_List.end()) {
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(std_List.front(), s21_List.front());
    EXPECT_EQ(std_List.back(), s21_List.back());
    EXPECT_EQ(std_List.size(), s21_List.size());
    ++std_it, ++s21_it;
  }
}


TEST(List, Push_front) {  // сделать такой же тест. но с вылетом исключения (преднамеренная ошибка)
  std::list<double> std_List_1;
  s21::List<double> s21_List_1;
    std_List_1.push_front(1.2);
    std_List_1.push_front(1.1);
    s21_List_1.push_front(1.2);
    s21_List_1.push_front(1.1);
    EXPECT_EQ(std_List_1.front(), s21_List_1.front());
    EXPECT_EQ(std_List_1.back(), s21_List_1.back());
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
  
    s21::List<char> std_List_2;
    std::list<char> s21_List_2;
    std_List_2.push_front('1');
    std_List_2.push_front('2');
    s21_List_2.push_front('1');
    s21_List_2.push_front('2');
    EXPECT_EQ(std_List_2.front(), s21_List_2.front());
    EXPECT_EQ(std_List_2.back(), s21_List_2.back());
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    
    s21::List<string> std_List_3;
    std::list<string> s21_List_3;
    std_List_3.push_front("string_1");
    std_List_3.push_front("string_2");
    s21_List_3.push_front("string_1");
    s21_List_3.push_front("string_2");
    EXPECT_EQ(std_List_3.front(), s21_List_3.front());
    EXPECT_EQ(std_List_3.back(), s21_List_3.back());
    EXPECT_EQ(std_List_3.size(), s21_List_3.size());
}

TEST(List, Pop_back) { 
  std::list<double> std_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  s21::List<double> s21_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  
  for (int i = 0;  i < s21_List.size(); i++)
  {
    s21_List.pop_back();
    std_List.pop_back();
    EXPECT_EQ(s21_List.front(), std_List.front());
    EXPECT_EQ(s21_List.back(), std_List.back());
    EXPECT_EQ(std_List.size(), s21_List.size()); 
  }
}

TEST(List, Pop_back_empty) { // сделать вылеты на исключения
  s21::List<double> s21_List;
  std::list<double> std_List;
        // s21_List.pop_back();
        // std_List.pop_back();
  EXPECT_EQ(s21_List.front(), std_List.front()); 
  EXPECT_EQ(s21_List.back(), std_List.back());     
  EXPECT_EQ(std_List.size(), s21_List.size());
}

TEST(List, Pop_front) {
std::list<double> std_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
s21::List<double> s21_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  
  for (int i = 0;  i < s21_List.size(); i++)
  {
        s21_List.pop_front();
        std_List.pop_front();
        EXPECT_EQ(s21_List.front(), std_List.front());
        EXPECT_EQ(s21_List.back(), std_List.back()); 
        EXPECT_EQ(std_List.size(), s21_List.size()); 
  }

}

TEST(List, Pop_front_empty) { // сделать вылеты на исключения
  s21::List<double> s21_List;
  std::list<double> std_List;
        // s21_List.pop_front();
        // std_List.pop_front();
  EXPECT_EQ(s21_List.front(), std_List.front());
  EXPECT_EQ(s21_List.back(), std_List.back()); 
  EXPECT_EQ(std_List.size(), s21_List.size());
}

TEST(List, Copy_list) {
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_copy(std_List);
  s21::List<double> s21_copy(s21_List);
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());

  for (int i = 0;  i < std_List.size(); i++)
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

  std::list<double> std_copy_2(std_List);
  s21::List<double> s21_copy_2(s21_List);

  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(s21_copy_2.size(), std_copy_2.size());

  std::list<double>::iterator std_it_e = std_List.end();
  std::list<double>::iterator std_it_1 = --std_List.end();
  s21::List<double>::iterator s21_it_1 = --s21_List.end();
  std::list<double>::iterator std_it_c1 = --std_copy_2.end();
  s21::List<double>::iterator s21_it_c1= --s21_copy_2.end();

  while(std_it_e != std_List.begin()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    EXPECT_EQ(*std_it_c1, *s21_it_c1);
    EXPECT_EQ(*std_copy_2.begin(), *s21_copy_2.begin());
    EXPECT_EQ(*(--std_copy_2.end()), *(--s21_copy_2.end()));
   --std_it_1, --s21_it_1;
   --std_it_c1, --s21_it_c1;
   std_it_e--;
  }

  std::list<double>::iterator std_it_b = std_List.begin();
  std::list<double>::iterator std_it_2 = std_List.begin();
  s21::List<double>::iterator s21_it_2 = s21_List.begin();
  std::list<double>::iterator std_it_c2 = std_copy_2.begin();
  s21::List<double>::iterator s21_it_c2= s21_copy_2.begin();

  while(std_it_b != std_List.end()) {
    EXPECT_EQ(*std_it_2, *s21_it_2);
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    EXPECT_EQ(*std_it_c2, *s21_it_c2);
    EXPECT_EQ(*std_copy_2.begin(), *s21_copy_2.begin()); 
    EXPECT_EQ(*(--std_copy_2.end()), *(--s21_copy_2.end()));
    ++std_it_2, ++s21_it_2;
    ++std_it_c2, ++s21_it_c2;
    std_it_b++;
  }
}

TEST(List, Copy_char) { 
  std::list<char> std_List_1 = {'f', 'o', 'x', 'y'};
  std::list<char> std_List_2 = std_List_1;
  s21::List<char> s21_List_1 = {'f', 'o', 'x', 'y'};
  s21::List<char> s21_List_2 = s21_List_1;

  for (auto i = 0; i < std_List_1.size(); i++) {
    EXPECT_EQ(std_List_1.back(), s21_List_1.back());
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    std_List_1.pop_back(), s21_List_1.pop_back();

    EXPECT_EQ(std_List_2.back(), s21_List_2.back());
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    std_List_2.pop_back(), s21_List_2.pop_back();
  }

  std::list<char> std_copy(std_List_1);
  s21::List<char> s21_copy(s21_List_1);

  EXPECT_EQ(std_List_1.size(), s21_List_1.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());

  std::list<char>::iterator std_it_e = std_List_1.end();
  std::list<char>::iterator std_it_1 = --std_List_1.end();
  s21::List<char>::iterator s21_it_1 = --s21_List_1.end();
  std::list<char>::iterator std_it_c1 = --std_copy.end();
  s21::List<char>::iterator s21_it_c1= --s21_copy.end();

  while(std_it_e != std_List_1.begin()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));

    EXPECT_EQ(*std_it_c1, *s21_it_c1);
    EXPECT_EQ(*std_copy.begin(), *s21_copy.begin());
    EXPECT_EQ(*(--std_copy.end()), *(--s21_copy.end()));
   --std_it_1, --s21_it_1;
   --std_it_c1, --s21_it_c1;
   std_it_e--;
  }
}

TEST(List, Copy_op) {
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_copy;
  s21::List<double> s21_copy;
  std_copy = std_List;  
  s21_copy = s21_List;
  
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  
  for (int i = 0;  i < std_List.size(); i++)
  {
    EXPECT_EQ(s21_copy.front(), std_copy.front());
    
    s21_copy.pop_front(), std_copy.pop_front();
  }

  for (int i = 0;  i < std_copy.size(); i++)
  {
    EXPECT_EQ(s21_copy.back(), std_copy.back());
    EXPECT_EQ(std_List.size(), s21_List.size());
    s21_copy.pop_back(), std_copy.pop_back();        
  }

  std::list<double> std_copy_2;
  s21::List<double> s21_copy_2;
  std_copy_2 = std_List;  
  s21_copy_2 = s21_List;

  std::list<double>::iterator std_it_e = std_copy_2.end();

  std::list<double>::iterator std_it_c0 = --std_List.end();
  s21::List<double>::iterator s21_it_c0 = --s21_List.end();
  std::list<double>::iterator std_it_c1 = --std_copy_2.end();
  s21::List<double>::iterator s21_it_c1 = --s21_copy_2.end();

  while(std_it_e != std_copy_2.begin()) {
    EXPECT_EQ(*std_it_c1, *s21_it_c1);
    EXPECT_EQ(*std_copy_2.begin(), *s21_copy_2.begin());
    EXPECT_EQ(*(--std_copy_2.end()), *(--s21_copy_2.end()));

    EXPECT_EQ(*std_it_c0, *s21_it_c0);
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    ++std_it_c0, ++s21_it_c0;
    ++std_it_c1, ++s21_it_c1;
    std_it_e++;
  }

  std::list<double>::iterator std_it_b = std_copy_2.begin();
  std::list<double>::iterator std_it_c2 = std_copy_2.begin();
  s21::List<double>::iterator s21_it_c2 = s21_copy_2.begin();

  while(std_it_b != std_copy_2.end()) {
    EXPECT_EQ(*std_it_c2, *s21_it_c2);
    EXPECT_EQ(*std_copy_2.begin(), *s21_copy_2.begin());
    EXPECT_EQ(*(--std_copy_2.end()), *(--s21_copy_2.end()));
   ++std_it_c2, ++s21_it_c2;
   std_it_b++;
  }
}

TEST(List, Move_list) { // возможно разбить на 2 теста как и остальные
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_move  = std::move (std_List);
  s21::List<double> s21_move = move(s21_List);
  
  EXPECT_EQ(s21_List.size(), 0);
  EXPECT_EQ(s21_move.size(), 7);
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_List.empty(), true);
  
  for (int i = 0;  i < std_List.size(); i++)
  {
    EXPECT_EQ(s21_move.front(), std_move.front());
    s21_move.pop_front();
    std_move.pop_front();
  }

  for (int i = 0;  i < std_move.size(); i++)
  {
    EXPECT_EQ(s21_move.back(), std_move.back());
    s21_move.pop_back();
    std_move.pop_back();        
  }

  std::list<double>::iterator std_it = std_List.end();
  s21::List<double>::iterator s21_it = s21_List.end();
  while(std_it != std_List.begin()) {
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(s21_List.size(), std_List.size());
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
   ++std_it, ++s21_it;
  }

  std::list<double> std_move_2  = std::move (std_List);
  s21::List<double> s21_move_2 = move(s21_List);
  
  std::list<double>::iterator std_it_e = std_move_2.end();
  std::list<double>::iterator std_it_c1 = std_move_2.end();
  s21::List<double>::iterator s21_it_c1 = s21_move_2.end();
  
  while(std_it_e != std_move_2.begin()) {
    EXPECT_EQ(*std_it_c1, *s21_it_c1);
    EXPECT_EQ(s21_move_2.size(), std_move_2.size());
    EXPECT_EQ(*std_move_2.begin(), *s21_move_2.begin());
    EXPECT_EQ(*(std_move_2.end()), *(s21_move_2.end()));
    --std_it_c1, --s21_it_c1;
    std_it_e--;
  }

  std::list<double>::iterator std_it_b = std_move_2.begin();
  std::list<double>::iterator std_it_c2 = std_move_2.begin();
  s21::List<double>::iterator s21_it_c2 = s21_move_2.begin();

  while(std_it_b != std_move_2.end()) {
    EXPECT_EQ(*std_it_c2, *s21_it_c2);
    EXPECT_EQ(s21_move_2.size(), std_move_2.size());
    EXPECT_EQ(*std_move_2.begin(), *s21_move_2.begin());
    EXPECT_EQ(*(--std_move_2.end()), *(--s21_move_2.end()));
   ++std_it_c2, ++s21_it_c2;
   std_it_b++;
  }  
}

TEST(List, Move_char) {
  std::list<char> std_List_1 = {'f', 'o', 'x', 'y'};
  s21::List<char> s21_List_1 = {'f', 'o', 'x', 'y'};  
  std::list<char> std_List_2 = move(std_List_1);
  s21::List<char> s21_List_2 = move(s21_List_1);
  
  EXPECT_EQ(std_List_1.size(), s21_List_1.size()); 
  EXPECT_EQ(std_List_1.empty(), s21_List_1.empty());
  EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
  EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));

  for (auto i = 0; i < s21_List_2.size(); i++) {
    EXPECT_EQ(std_List_2.back(), s21_List_2.back());
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    s21_List_2.pop_back(), std_List_2.pop_back();
  }

  std::list<char> std_move = move(std_List_2);
  s21::List<char> s21_move = move(s21_List_2);

  std::list<char>::iterator std_it_b = std_move.begin();
  std::list<char>::iterator std_it = std_move.begin();
  s21::List<char>::iterator s21_it = s21_move.begin();

  while(std_it_b != --std_move.end()) { 
  // while(std_it != std_move.end()) { 
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(*std_move.begin(), *s21_move.begin());
    EXPECT_EQ(*(--std_move.end()), *(--s21_move.end()));
   ++std_it, ++s21_it;
   ++std_it_b;
  }

  std::list<char>::iterator std_it_2 = --std_move.end();
  s21::List<char>::iterator s21_it_2 = --s21_move.end();
  while(std_it_2 != std_move.begin()) { 
    EXPECT_EQ(*std_it_2, *s21_it_2);
    EXPECT_EQ(*std_move.begin(), *s21_move.begin());
    EXPECT_EQ(*(--std_move.end()), *(--s21_move.end()));
   --std_it_2, --s21_it_2;
  }
}

TEST(List, Move_op) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_move_1;
  s21::List<double> s21_move_1;

  std_move_1 = std::move(std_List);  
  s21_move_1 = move(s21_List);

  EXPECT_EQ(s21_List.size(), 0);
  EXPECT_EQ(s21_move_1.size(), 7);
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_move_1.size(), std_move_1.size());

  for (int i = 0;  i < std_move_1.size(); i++)
  {
    EXPECT_EQ(s21_move_1.front(), std_move_1.front());
    s21_move_1.pop_front();
    std_move_1.pop_front();        
  }

  for (int i = 0;  i < std_move_1.size(); i++)
  {
    EXPECT_EQ(s21_move_1.back(), std_move_1.back());
    s21_move_1.pop_back();
    std_move_1.pop_back();        
  }

  // std::list<double>::iterator std_it = std_List.end();
  // s21::List<double>::iterator s21_it = s21_List.end();
  // while(std_it != std_List.begin()) {
  //   EXPECT_EQ(*std_it, *s21_it);
  //   EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  //   EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
  //   EXPECT_EQ(s21_List.size(), std_List.size());
  //   EXPECT_EQ(s21_move_1.size(), std_move_1.size());
  //  ++std_it, ++s21_it;
  // }

  // std::list<double>::iterator std_it_2 = std_move_1.begin();
  // s21::List<double>::iterator s21_it_2 = s21_move_1.begin();
  // while(std_it_2 != std_move_1.end()) {
  //   EXPECT_EQ(*std_it_2, *s21_it_2);
  //   EXPECT_EQ(*std_move_1.begin(), *s21_move_1.begin());
  //   // EXPECT_EQ(*(--std_move_1.end()), *(--s21_move_1.end()));
  //   EXPECT_EQ(s21_move_1.size(), std_move_1.size());
  //  ++std_it_2, ++s21_it_2;
  // }

  std::list<double>::iterator std_it = std_List.end();
  s21::List<double>::iterator s21_it = s21_List.end();

  while(std_it != std_List.begin()) {
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(s21_List.size(), std_List.size());
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    ++std_it, ++s21_it;
  }

  std::list<double> std_move_2;
  s21::List<double> s21_move_2;

  std_move_2 = std::move(std_move_1);  
  s21_move_2 = move(s21_move_1);

  std::list<double>::iterator std_it_1 = std_move_2.begin();
  s21::List<double>::iterator s21_it_1 = s21_move_2.begin();

  while(std_it_1 != std_move_2.end()) { 
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(*std_move_2.begin(), *s21_move_2.begin());
    EXPECT_EQ(*(--std_move_2.end()), *(--s21_move_2.end()));
   ++std_it_1, ++s21_it_1;
  }

  std::list<double>::iterator std_it_2 = --std_move_2.end();
  s21::List<double>::iterator s21_it_2 = --s21_move_2.end();
  while(std_it_2 != std_move_2.begin()) { 
    EXPECT_EQ(*std_it_2, *s21_it_2);
    EXPECT_EQ(*std_move_2.begin(), *s21_move_2.begin());
    EXPECT_EQ(*(--std_move_2.end()), *(--s21_move_2.end()));
   --std_it_2, --s21_it_2;
  }
}

// TEST(List, Operator_) { // не все работает корректно
//   std::list<double> std_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};
//   s21::List<double> s21_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};

//   std::list<double>::iterator std_it = std_List.end();
//   s21::List<double>::iterator s21_it = s21_List.end();
//   s21::List<double>::iterator s21_it_b = s21_List.begin();

//   std_it = std_List.begin();
//   s21_it = s21_List.begin();
//   EXPECT_EQ(*s21_it_b, *s21_it);

//   while(std_it != std_List.end()) {
// //     // EXPECT_NEAR(*std_it, *s21_it, 0.00000001);
//     EXPECT_EQ(*std_it, *s21_it);
//     ++std_it, ++s21_it;
//   }
// }*

// ////___
TEST(List, Insert_1) { 
  std::list<double> std_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};

  std::list<double>::iterator std_it = std_List.begin();
  s21::List<double>::iterator s21_it = s21_List.begin();
     
  std_List.insert(std_it, 20);
  s21_List.insert(s21_it, 20);

  std_it++;
  s21_it++;
  std_it++;
  s21_it++;
  std_it++;
  s21_it++;
 
  std_List.insert(std_it, 21);
  s21_List.insert(s21_it, 21);

  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_List.front(), std_List.front()); 
  EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  EXPECT_EQ(*(--std_List.end()), *(--s21_List.end())); 
 
  std::list<double>::iterator std_it_b = std_List.begin();
  s21::List<double>::iterator s21_it_b = s21_List.begin();
  std_it_b++;
  s21_it_b++;
  while(std_it_b != std_List.end()) { 
    EXPECT_EQ(*std_it_b, *s21_it_b);
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    ++std_it_b, ++s21_it_b;
  }

  std::list<double>::iterator std_it_e = --std_List.end();
  s21::List<double>::iterator s21_it_e = --s21_List.end();
  while(std_it_e != std_List.begin()) {
    EXPECT_EQ(*std_it_e, *s21_it_e);
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
   --std_it_e, --s21_it_e;
  }
  EXPECT_EQ(std_List.size(), s21_List.size());
}

TEST(List, Insert_2) { // не все работает корректно
  std::list<double> std_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};
  std::list<double>::iterator std_it = std_List.begin();
  s21::List<double>::iterator s21_it = s21_List.begin();

  std::list<double>::iterator std_it_b = std_List.begin();
  s21::List<double>::iterator s21_it_b = s21_List.begin();

  std_List.insert(std_it, 22);
  s21_List.insert(s21_it, 22);
  std_it++, s21_it++;

  for (int i = 0; i < 10; i++){ // фиксируем, где i - это количество вставок
    
    if (std_it_b == std_List.end() || s21_it_b == s21_List.end() ) {
      std_it_b++, s21_it_b++;
    }
    if (std_it == std_List.end() || s21_it == s21_List.end() ) {
      std_it++, s21_it++;
    }
    std_List.insert(std_it, 21);
    s21_List.insert(s21_it, 21);
    std_it++, s21_it++;
    std_List.insert(std_it, 23);
    s21_List.insert(s21_it, 23);
    EXPECT_EQ(std_List.size(), s21_List.size());
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(*std_it_b, *s21_it_b); 
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    std_it_b++, s21_it_b++; 
    std_it++, s21_it++;
  }

  for (int i = 0;  i < std_List.size(); i++)
  {        
    EXPECT_EQ(s21_List.front(), std_List.front());
    EXPECT_EQ(s21_List.back(), std_List.back());
    EXPECT_EQ(std_List.size(), s21_List.size());
    s21_List.pop_front(), std_List.pop_front();        
  }

  for (int i = 0;  i < std_List.size(); i++)
  {
    EXPECT_EQ(s21_List.front(), std_List.front());
    EXPECT_EQ(s21_List.back(), std_List.back());
    s21_List.pop_back();
    std_List.pop_back();        
  }     
}

TEST(List, Erase_1) { // Добавиь тест на удаление последнего элемента и соот. tail_
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};

  std::list<double>::iterator std_it_b = std_List.begin();
  s21::List<double>::iterator s21_it_b = s21_List.begin();
  std::list<double>::iterator std_it_e = std_List.end(); 
  s21::List<double>::iterator s21_it_e = s21_List.end();
  std::list<double>::iterator std_it = std_List.begin();
  s21::List<double>::iterator s21_it = s21_List.begin();

  std_List.erase(std_it);
  s21_List.erase(s21_it);
  // std_it++;
  // s21_it++;
  std_List.erase(--std_it_e);
  s21_List.erase(--s21_it_e);
  EXPECT_EQ(std_List.size(), s21_List.size());
  EXPECT_EQ(s21_List.front(), std_List.front()); 
  EXPECT_EQ(s21_List.back(), std_List.back()); 
  EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  EXPECT_EQ(*(--std_List.end()), *(--s21_List.end())); 

    
  for (int i = 0;  i < std_List.size(); i++)
  {        
    EXPECT_EQ(s21_List.front(), std_List.front());
    EXPECT_EQ(s21_List.size(), std_List.size());
    s21_List.pop_front(), std_List.pop_front();        
  }

  for (int i = 0;  i < std_List.size(); i++)
  {
    EXPECT_EQ(s21_List.back(), std_List.back());
    EXPECT_EQ(s21_List.size(), std_List.size()); 
    s21_List.pop_back(), std_List.pop_back();       
  }      
}


TEST(List, Erase_2) { // Добавиь тест на удаление последнего элемента и соот. tail_
   
  std::list<double> std_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7};
  std::list<double>::iterator std_it = std_List.begin();
  s21::List<double>::iterator s21_it = s21_List.begin();

  auto it1 = s21_List.begin();
  auto it2 = s21_List.begin();
  while (it1 != s21_List.end()) {
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }

  // std::list<double>::iterator std_it_b = std_List.begin();

  while(std_it != std_List.end()) {
    // while(std_it != std_List_2.end()) {
    EXPECT_EQ(*std_it, *s21_it);
    // EXPECT_NEAR(*std_it, *s21_it, 0.00000001);
    EXPECT_EQ(std_List.size(), s21_List.size());
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    ++std_it, ++s21_it;
    // ++std_it_b;
  }
  
  std::list<double>::iterator std_it_e = --std_List.end();
  while(std_it_e != std_List.begin()) {
    EXPECT_EQ(*std_it, *std_it);
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
    EXPECT_EQ(std_List.size(), s21_List.size());  
   --std_it, --std_it;
   --std_it_e;
  }
}

// TEST(List, Erase_3) { // не все работает корректно
//   std::list<double> std_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7, 6, 4, 2, 6, 5};
//   s21::List<double> s21_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7, 6, 4, 2, 6, 5};
//   std::list<double>::iterator std_it = std_List.begin();
//   s21::List<double>::iterator s21_it = s21_List.begin();

//   // std::list<double>::iterator std_it_b = std_List.begin();
//   // s21::List<double>::iterator s21_it_b = s21_List.begin();

//   // std_List.insert(std_it, 22);
//   // s21_List.insert(s21_it, 22);
//   // std_it++, s21_it++;

 
//   std::list<double>::iterator std_it_b = std_List.begin();
//   while(std_it_b != std_List.end() && std_it_b++ != std_List.end()) {
//     EXPECT_EQ(*std_it, *std_it);
//     std_List.erase(std_it);
//     s21_List.erase(s21_it);
//     EXPECT_EQ(*std_it, *std_it);

//     ++std_it, ++std_it;
//     EXPECT_EQ(*std_it, *std_it);

//     // std_List.erase(std_it);
//     // s21_List.erase(s21_it);
//     EXPECT_EQ(*std_it, *std_it);

//     EXPECT_EQ(*std_List.begin(), *s21_List.begin());
//     EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
//     EXPECT_EQ(std_List.size(), s21_List.size());  
//   //  ++std_it, ++std_it;
//    ++std_it_b;
//   }

//   std::list<double>::iterator std_it1 = std_List.begin();
//   s21::List<double>::iterator s21_it1 = s21_List.begin();
//   std::list<double>::iterator std_it_e = --std_List.end();
//   while(std_it_e != std_List.begin() && std_it_e != ++std_List.begin()) {
//     EXPECT_EQ(*std_it1, *std_it1);
//     std_List.erase(std_it1);
//     s21_List.erase(s21_it1);
//     EXPECT_EQ(*std_it1, *std_it1);
//     EXPECT_EQ(*std_it1, *std_it1);

//     // std_List.erase(std_it);
//     // s21_List.erase(s21_it);
//     EXPECT_EQ(*std_it1, *std_it1);

//     EXPECT_EQ(*std_List.begin(), *s21_List.begin());
//     EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
//     EXPECT_EQ(std_List.size(), s21_List.size());  
//   //  --std_it, --std_it;
//    --std_it_e;
//   }

//   // std::list<double>::iterator std_it_e = --std_List.end();
//   // while(std_it_e != std_List.begin()) {
//   //   EXPECT_EQ(*std_it, *std_it);
//   //   EXPECT_EQ(*std_List.begin(), *s21_List.begin());
//   //   EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
//   //   EXPECT_EQ(std_List.size(), s21_List.size());  
//   //  --std_it, --std_it;
//   //  --std_it_e;
//   // }
//   }

  // TEST(List, Erase_4) { // не все работает корректно
  // std::list<double> std_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7, 6, 4, 2, 6, 5};
  // s21::List<double> s21_List {1.1, 2.2, 2.2, 1.4, 1.5, 1.6, 7.7, 6, 4, 2, 6, 5};
  // std::list<double>::iterator std_it = std_List.begin();
  // s21::List<double>::iterator s21_it = s21_List.begin();
 
  // // std::list<double>::iterator std_it_b = std_List.begin();
  // // while(std_it_b != std_List.end() && std_it_b++ != std_List.end()) {
  // //   EXPECT_EQ(*std_it, *std_it);
  // //   std_List.erase(std_it);
  // //   s21_List.erase(s21_it);
  // //   EXPECT_EQ(*std_it, *std_it);

  // //   ++std_it, ++std_it;
  // //   EXPECT_EQ(*std_it, *std_it);

  // //   // std_List.erase(std_it);
  // //   // s21_List.erase(s21_it);
  // //   EXPECT_EQ(*std_it, *std_it);

  // //   EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  // //   EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
  // //   EXPECT_EQ(std_List.size(), s21_List.size());  
  // // //  ++std_it, ++std_it;
  // //  ++std_it_b;
  // // }

  // // std::list<double>::iterator std_it = std_List.begin();
  // // s21::List<double>::iterator s21_it = s21_List.begin();
  // std::list<double>::iterator std_it_e = --std_List.end();
  // while(std_it_e != std_List.begin() && std_it_e != ++std_List.begin()) {
  //   EXPECT_EQ(*std_it, *std_it);
  //   std_List.erase(std_it);
  //   s21_List.erase(s21_it);
  //   EXPECT_EQ(*std_it, *std_it);

  //   // std_List.erase(std_it);
  //   // s21_List.erase(s21_it);
  //   EXPECT_EQ(*std_it, *std_it);

  //   EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  //   EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));
  //   EXPECT_EQ(std_List.size(), s21_List.size());  
  //  --std_it, --s21_it;
  //  --std_it_e;
  // }
  
  // }

TEST(List, Swap) { // Перепроверить тесты
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};

  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};

  std_List_1.swap(std_List_2);
  s21_List_1.swap(s21_List_2);
  EXPECT_EQ(std_List_1.size(), s21_List_1.size());
  EXPECT_EQ(std_List_2.size(), s21_List_2.size());
  
  for (int i = 0;  i < std_List_1.size(); i++)
  {
    EXPECT_EQ(std_List_1.front(), s21_List_1.front());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
    EXPECT_EQ(std_List_1.size(), s21_List_1.size()); 
    std_List_1.pop_front(), s21_List_1.pop_front();        
  }

  for (int i = 0;  i < s21_List_2.size(); i++)
  {
    EXPECT_EQ(std_List_2.back(), s21_List_2.back());
    EXPECT_EQ(std_List_2.front(), s21_List_2.front());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    std_List_2.pop_back(), s21_List_2.pop_back();        
  }

  std::list<double>::iterator std_it_2 = std_List_2.begin();
  s21::List<double>::iterator s21_it_2 = s21_List_2.begin();
  std::list<double>::iterator std_it_b = std_List_1.begin();
  
    while(std_it_b != std_List_1.end()) {

    EXPECT_EQ(*std_it_2, *s21_it_2);
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));

    ++std_it_2, ++s21_it_2;
    ++std_it_b;
  }
}


// TEST(List, Merge_1) { // Перепроверить тесты, течет // сделать с пустыми списками
//   s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//   std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
//   s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
//   std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
//   auto std_it = std_List_1.cbegin();
//   auto s21_it = s21_List_1.cbegin();
//   std_List_1.sort();
//   std_List_2.sort();
//   s21_List_1.sort();
//   s21_List_2.sort();

//   s21_List_1.merge(s21_List_2);
//   std_List_1.merge(std_List_2);

//   EXPECT_EQ(s21_List_1.size(), std_List_1.size());
//   EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  
//   auto std_it_b = std_List_1.cbegin();
//   while(std_it_b != std_List_1.end()) {
//     EXPECT_EQ(*std_it, *s21_it);
//     EXPECT_EQ(std_List_1.size(), s21_List_1.size());
//     EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
//     EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
//     ++std_it, ++s21_it;
//     std_it_b++;
//   }

//   auto std_it_e = --std_List_2.end();
//   while(std_it_e != std_List_2.begin()) {
//     // EXPECT_EQ(*std_it, *s21_it);
//     EXPECT_EQ(std_List_2.size(), s21_List_2.size());
//     EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
//     EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
//     --std_it, --s21_it;
//     --std_it_e;
//   }
// }

TEST(List, Merge_2) { // Перепроверить тесты
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List_2 {1.0, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {1.0, 8.8, 5.5, 4.4, 3.3};
  
  std_List_1.sort();
  std_List_2.sort();
  s21_List_1.sort();
  s21_List_2.sort();

  s21_List_1.merge(s21_List_2);
  std_List_1.merge(std_List_2);

  auto std_it = std_List_1.cbegin();
  auto s21_it = s21_List_1.cbegin();

  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  
  auto std_it_b = std_List_1.cbegin();
  
  while(std_it_b != std_List_1.end()) {
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));

    ++std_it, ++s21_it;
    std_it_b++;
  }

  auto std_it_e = --std_List_2.end();
  while(std_it_e != std_List_2.begin()) {
    EXPECT_EQ(*std_it, *s21_it);
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
    --std_it, --s21_it;
    --std_it_e;
  }
}

TEST(List, Splice_0) { // Перепроверить тесты, течет
  s21::List<double> s21_List_1;
  std::list<double> std_List_1;
  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};

  auto std_it = std_List_1.cbegin();
  auto s21_it = s21_List_1.cbegin();
  s21_List_1.splice(s21_it, s21_List_2);
  std_List_1.splice(std_it, std_List_2);

  // EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  
  auto std_it_b = std_List_1.cbegin();
  auto std_it_1 = std_List_1.cbegin();
  auto s21_it_1 = s21_List_1.cbegin();
  while(std_it_b != std_List_1.end()) {
  // // while(std_it1 != std_List_1.end()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
    ++std_it_1, ++s21_it_1;
    ++std_it_b;
  }

  auto std_it_e = --std_List_2.end();
  while(std_it_e != std_List_2.begin()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
    --std_it_1, --s21_it_1;
    --std_it_e;
  }
}

TEST(List, Splice_1) { // Перепроверить тесты, течет
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};

  auto std_it = std_List_1.cbegin();
  auto s21_it = s21_List_1.cbegin();
  s21_List_1.splice(s21_it, s21_List_2);
  std_List_1.splice(std_it, std_List_2);

  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  
  auto std_it_b = std_List_1.cbegin();
  auto std_it_1 = std_List_1.cbegin();
  auto s21_it_1 = s21_List_1.cbegin();
  while(std_it_b != std_List_1.end()) {
  // // while(std_it1 != std_List_1.end()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
    ++std_it_1, ++s21_it_1;
    ++std_it_b;
  }

  auto std_it_e = --std_List_2.end();
  while(std_it_e != std_List_2.begin()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
    --std_it_1, --s21_it_1;
    --std_it_e;
  }
}

TEST(List, Splice_2) { // Перепроверить тесты, течет
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};

  auto std_it = std_List_1.cend();
  auto s21_it = s21_List_1.cend();
  s21_List_1.splice(s21_it, s21_List_2);
  std_List_1.splice(std_it, std_List_2);

  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  
  auto std_it_b = std_List_1.cbegin();
  auto std_it_1 = std_List_1.cbegin();
  auto s21_it_1 = s21_List_1.cbegin();
  while(std_it_b != std_List_1.end()) {
  // // while(std_it1 != std_List_1.end()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
    ++std_it_1, ++s21_it_1;
    ++std_it_b;
  }

  auto std_it_e = --std_List_2.end();
  while(std_it_e != std_List_2.begin()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
    --std_it_1, --s21_it_1;
    --std_it_e;
  }
}

TEST(List, Splice_3) { // Перепроверить тесты, течет
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 3.3};

  auto std_it = std_List_1.cbegin();
  auto s21_it = s21_List_1.cbegin();
  std_it++, s21_it++;
  std_it++, s21_it++;
  s21_List_1.splice(s21_it, s21_List_2);
  std_List_1.splice(std_it, std_List_2);

  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  
  auto std_it_b = std_List_1.cbegin();
  auto std_it_1 = std_List_1.cbegin();
  auto s21_it_1 = s21_List_1.cbegin();
  while(std_it_b != std_List_1.end()) {
  // // while(std_it1 != std_List_1.end()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    
    EXPECT_EQ(std_List_1.size(), s21_List_1.size());
    EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
    EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));
    ++std_it_1, ++s21_it_1;
    ++std_it_b;
  }

  auto std_it_e = --std_List_2.end();
  while(std_it_e != std_List_2.begin()) {
    EXPECT_EQ(*std_it_1, *s21_it_1);
    EXPECT_EQ(std_List_2.size(), s21_List_2.size());
    EXPECT_EQ(*std_List_2.begin(), *s21_List_2.begin());
    EXPECT_EQ(*(--std_List_2.end()), *(--s21_List_2.end()));
    --std_it_1, --s21_it_1;
    --std_it_e;
  }
}

TEST(List, Reverse) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std_List.reverse();
  s21_List.reverse();  

  s21::List<double>::iterator s21_it = s21_List.begin();
  std::list<double>::iterator std_it = std_List.begin();
  while (std_it != std_List.end()){
    EXPECT_EQ(*s21_it, *std_it);
    s21_it++;
    std_it++;
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end())); 
    EXPECT_EQ(s21_List.size(), std_List.size());
  }   
}

TEST(List, Unique_0) { // разбить на несколько тестов
  std::list<double> std_List_1 {1.1};
  s21::List<double> s21_List_1 {1.1};
  std::list<double> std_List_2 {};
  s21::List<double> s21_List_2 {};
  std::list<string> std_List_3 (0);
  s21::List<string> s21_List_3 (0);
  std::list<string> std_List_4 (1);
  s21::List<string> s21_List_4 (1);

  // std_List_1.unique();
  // s21_List_1.unique();
  // std_List_2.unique();
  // s21_List_2.unique();
  // std_List_3.unique();
  // s21_List_3.unique();
  // std_List_4.unique();
  // s21_List_4.unique();
  

  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  EXPECT_EQ(s21_List_3.size(), std_List_3.size());
  EXPECT_EQ(s21_List_4.size(), std_List_4.size());

  std::list<double>::iterator std_it1 = std_List_1.begin();
  s21::List<double>::iterator s21_it1 = s21_List_1.begin();
  std::list<double>::iterator std_it2 = std_List_2.begin();
  s21::List<double>::iterator s21_it2 = s21_List_2.begin();
  std::list<string>::iterator std_it3 = std_List_3.begin();
  s21::List<string>::iterator s21_it3 = s21_List_3.begin();
  std::list<string>::iterator std_it4 = std_List_4.begin();
  s21::List<string>::iterator s21_it4 = s21_List_4.begin();

  // while (std_it1 != std_List_1.end())
  // {     
  //       EXPECT_EQ(*std_it1, *s21_it1);
  //       std_it1++, s21_it1++; 
  //       EXPECT_EQ(*std_it2, *s21_it2);
  //       std_it2++, s21_it2++; 
  //       EXPECT_EQ(*std_it3, *s21_it3);
  //       std_it3++, s21_it3++; 
  //       EXPECT_EQ(*std_it4, *s21_it4);
  //       std_it4++, s21_it4++; 

  //       EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  //       EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
  //       EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));            
  // }  
}

TEST(List, Unique) { // разбить на несколько тестов
  std::list<double> std_List_1 {1.1, 2.2, 1.3, 1.3, 1.3, 1.6, 7.7};
  s21::List<double> s21_List_1 {1.1, 2.2, 1.3, 1.3, 1.3, 1.6, 7.7};
  std::list<double> std_List_2 {9.9, 8.8, 5.5, 4.4, 5.5, 5.5};
  s21::List<double> s21_List_2 {9.9, 8.8, 5.5, 4.4, 5.5, 5.5};
  std::list<string> std_List_3 {"str_1", "str_2", "str_3", "str_4", "str_5"};
  s21::List<string> s21_List_3 {"str_1", "str_2", "str_3", "str_4", "str_5"};
  std::list<string> std_List_4 {"str_1", "str_1", "str_3", "str_4", "str_3", "str_1"};
  s21::List<string> s21_List_4 {"str_1", "str_1", "str_3", "str_4", "str_3", "str_1"};

  // std_List_1.unique();
  // s21_List_1.unique();
  // std_List_2.unique();
  // s21_List_2.unique();
  // std_List_3.unique();
  // s21_List_3.unique();
  // std_List_4.unique();
  // s21_List_4.unique();
  
  //  EXPECT_EQ(std_List_1.size(), 5);


  EXPECT_EQ(s21_List_1.size(), std_List_1.size());
  EXPECT_EQ(s21_List_2.size(), std_List_2.size());
  EXPECT_EQ(s21_List_3.size(), std_List_3.size());
  EXPECT_EQ(s21_List_4.size(), std_List_4.size());

  std::list<double>::iterator std_it1 = std_List_1.begin();
  s21::List<double>::iterator s21_it1 = s21_List_1.begin();
  std::list<double>::iterator std_it2 = std_List_2.begin();
  s21::List<double>::iterator s21_it2 = s21_List_2.begin();
  std::list<string>::iterator std_it3 = std_List_3.begin();
  s21::List<string>::iterator s21_it3 = s21_List_3.begin();
  std::list<string>::iterator std_it4 = std_List_4.begin();
  s21::List<string>::iterator s21_it4 = s21_List_4.begin();

  while (std_it1 != std_List_1.end())
  {     
        // EXPECT_EQ(*std_it1, *s21_it1);
        std_it1++, s21_it1++; 
        // EXPECT_EQ(*std_it2, *s21_it2);
        // std_it2++, s21_it2++; 
        // EXPECT_EQ(*std_it3, *s21_it3);
        // std_it3++, s21_it3++; 
        // EXPECT_EQ(*std_it4, *s21_it4);
        // std_it4++, s21_it4++; 

        EXPECT_EQ(s21_List_1.size(), std_List_1.size());
        // EXPECT_EQ(*std_List_1.begin(), *s21_List_1.begin());
        EXPECT_EQ(*(--std_List_1.end()), *(--s21_List_1.end()));            
  }  
}


TEST(List, Sort) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};

  std_List.sort();
  s21_List.sort();
  
  s21::List<double>::iterator s21_it = s21_List.begin();
  std::list<double>::iterator std_it = std_List.begin();

  while (std_it != std_List.end()){        
    EXPECT_EQ(*s21_it, *std_it);
    s21_it++;
    std_it++;
    EXPECT_EQ(s21_List.size(), std_List.size());
    EXPECT_EQ(*std_List.begin(), *s21_List.begin());
    EXPECT_EQ(*(--std_List.end()), *(--s21_List.end())); 
  }

  EXPECT_EQ(*std_List.begin(), *s21_List.begin());
  EXPECT_EQ(*(--std_List.end()), *(--s21_List.end()));       
}

TEST(List, Max_size) {
  s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  EXPECT_EQ(s21_List.max_size(), std_List.max_size());
}


// // // {
// // //    При создание 0 листа должна обрабатываться ошибка при  pop и запрос на последний обхъект
// // // std_List.pop_back();
// // //         EXPECT_EQ(s21_List.back(), std_List.back()); 
// // // }

TEST(List, Begin) { 
  s21::List<int> s21_List;  
  s21_List.push_front(1);
  s21_List.push_front(2);
  s21_List.push_front(3);

  std::list<int> std_List;
  std_List.push_front(1);
  std_List.push_front(2);
  std_List.push_front(3);

  s21::List<int>::iterator s21_it = s21_List.begin();
  std::list<int>::iterator std_it = std_List.begin();
  int i = 1;

  while (std_it != std_List.end()){   
    s21_List.push_front(i);  
    std_List.push_front(i);   

    EXPECT_EQ(*s21_it, *std_it);
    s21_it++;
    std_it++;
    EXPECT_EQ(*(--s21_List.end()), * (--std_List.end()));
    EXPECT_EQ(s21_List.size(), std_List.size());
  }

  EXPECT_EQ(*s21_List.cbegin(), *std_List.cbegin());
  EXPECT_EQ(*s21_List.begin(), *std_List.begin());
  EXPECT_EQ(*s21_List.end(), *std_List.end());
}

TEST(List, End) { 
  s21::List<int> s21_List;
  std::list<int> std_List;

  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);

  std_List.push_back(1);
  std_List.push_back(2);
  std_List.push_back(3);

  EXPECT_EQ(*s21_List.begin(), *std_List.begin());
  EXPECT_EQ(*s21_List.end(), *std_List.end());

  s21::List<int>::iterator s21_it = s21_List.end();
  std::list<int>::iterator std_it = std_List.end();
  int i = 1;

  while (std_it != std_List.begin()){   
    s21_List.push_back(i);  
    std_List.push_back(i);   

    EXPECT_EQ(*s21_it, *std_it);
    s21_it--;
    std_it--;
    EXPECT_EQ(*(--s21_List.end()), * (--std_List.end()));
    EXPECT_EQ(s21_List.size(), std_List.size());
  }

  EXPECT_EQ(*s21_List.cbegin(), *std_List.cbegin());
  EXPECT_EQ(*s21_List.begin(), *std_List.begin());
  EXPECT_EQ(*s21_List.end(), *std_List.end());
  EXPECT_EQ(*s21_List.cend(), *std_List.cend());

}

// // // TEST(ListIteratorTest, Increment_1) {
// //   // s21::List<int> list;
// //   // list.push_back(1);
// //   // list.push_back(2);
// //   // list.push_back(3);
// //   // // s21::List<int>::iterator it = list.begin();
// //   // // EXPECT_EQ(*it, 1);
// //   // // ++it;
// //   // // EXPECT_EQ(*it, 2);
// //   // // ++it;
// //   // // // EXPECT_EQ(*it, 3);
// //   // // // ++it;
// //   // // // EXPECT_EQ(it, nullptr);
//  // // }

// // // // TEST(ListIteratorTest, Decrement) {
// // // //   s21::List<int> list;
// // // //   list.push_back(1);
// // // //   list.push_back(2);
// // // //   list.push_back(3);
// // // //   s21::ListIterator<int> it = list.end();
// // // //   --it;
// // // //   EXPECT_EQ(*it, 3);
// // // //   --it;
// // // //   EXPECT_EQ(*it, 2);
// // // //   --it;
// // // //   EXPECT_EQ(*it, 1);
// // // //   --it;
// // // //   EXPECT_EQ(it, nullptr);
// // // // }

// // // // // // TEST(ListIteratorTest, ArrowOperator) {
// // // // // //   s21::List<std::string> list;
// // // // // //   list.push_back("hello");
// // // // // //   list.push_back("world");
// // // // // //   s21::ListIterator<std::string> it = list.begin();
// // // // // //   EXPECT_EQ(it->size(), 5);
// // // // // //   ++it;
// // // // // //   EXPECT_EQ(it->size(), 5);
// // // // // // }

TEST(ListIteratorTest, Equality) {
  s21::List<int> s21_List;
  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);
  s21::List<int>::iterator it1 = s21_List.begin();
  s21::List<int>::iterator it2 = s21_List.begin();
  EXPECT_EQ(*it1, *it2);
  ++it1;
  EXPECT_NE(*it1, *it2);
  ++it2;
  EXPECT_EQ(*it1, *it2);
}


// // // TEST(ListIterator, Constructor){  // перепроверить, не работает? индекса нет, без него нет смысла теста
// // //   std::list<int> std_List;
// // //   std_List.push_back(11);
// // //   s21::List<int> s21_List;
// // //   s21_List.push_back(11);
// // //   std::list<int>::iterator std_it[1];
// // //   s21::List<int>::iterator s21_it[1];
// // //   std::list<int>::iterator std_it1 = std_List.begin();
// // //   s21::List<int>::iterator s21_it1 = s21_List.begin();
// // //   // EXPECT_EQ(*s21_it, *std_it);
// // //   EXPECT_EQ(*s21_it1, *std_it1);
// // // }


TEST(ListIteratorTest, CopyConstructor) {  //trow создаем 0, пытаемся сдвинуться
  s21::List<int> s21_List;
  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);
  s21::List<int>::iterator s21_it1 = s21_List.begin();
  s21::List<int>::iterator s21_it2(s21_it1);
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

TEST(ListIteratorTest, Increment) { // сделать исключение... Сделать проверку через итераторы
  s21::List<int> s21_List;
  // s21_List.push_front(4);
  // s21_List.push_front(3);
  // s21_List.push_front(2);
  // s21_List.push_front(1);

  s21_List.push_back(1);
  s21_List.push_back(2);
  s21_List.push_back(3);
  s21_List.push_back(4);

  std::list<int> std_List;
  std_List.push_front(4);
  std_List.push_front(3);
  std_List.push_front(2);
  std_List.push_front(1);

  s21::List<int>::iterator s21_it_1 = s21_List.begin();
  std::list<int>::iterator std_it_1 = std_List.begin();
  for (int i = 0; i < s21_List.size() + 10; i++){     
    EXPECT_EQ(*s21_it_1, *std_it_1);
    ++s21_it_1;
    ++std_it_1;
    EXPECT_EQ(*s21_List.cbegin(), *std_List.cbegin());
    EXPECT_EQ(*s21_List.begin(), *std_List.begin());
    EXPECT_EQ(*s21_List.end(), *std_List.end());
  }

  s21::List<int>::iterator s21_it_2 = s21_List.end();
  std::list<int>::iterator std_it_2 = std_List.end();
  for (int i = 0; i < s21_List.size() + 10; i++){
    EXPECT_EQ(*s21_it_2, *std_it_2);
    s21_it_2++;
    std_it_2++;
    EXPECT_EQ(*s21_List.cbegin(), *std_List.cbegin());
    EXPECT_EQ(*s21_List.begin(), *std_List.begin());
    EXPECT_EQ(*s21_List.end(), *std_List.end());
  }
}

TEST(ListIteratorTest, Decrement) { // сделать исключение нет проверки на исключение 
  s21::List<int> s21_List;
  s21_List.push_front(4);
  s21_List.push_front(3);
  s21_List.push_front(2);
  s21_List.push_front(1);

  // s21_List.push_back(1);
  // s21_List.push_back(2);
  // s21_List.push_back(3);
  // s21_List.push_back(4);

  std::list<int> std_List;
  std_List.push_back(1);
  std_List.push_back(2);
  std_List.push_back(3);
  std_List.push_back(4);
 
  s21::List<int>::iterator s21_it_1 = s21_List.begin();
  std::list<int>::iterator std_it_1 = std_List.begin();
  for (int i = 0; i < s21_List.size() + 10; i++){    
    EXPECT_EQ(*s21_it_1, *std_it_1);
    --s21_it_1;
    --std_it_1;
    EXPECT_EQ(*s21_List.cbegin(), *std_List.cbegin());
    EXPECT_EQ(*s21_List.begin(), *std_List.begin());
    EXPECT_EQ(*s21_List.end(), *std_List.end());
  }

  s21::List<int>::iterator s21_it_2 = s21_List.end();
  std::list<int>::iterator std_it_2 = std_List.end();
  for (int i = 0; i < s21_List.size() + 10; i++){  
    EXPECT_EQ(*s21_it_2, *std_it_2);
    s21_it_2--;
    std_it_2--;
    EXPECT_EQ(*s21_List.cbegin(), *std_List.cbegin());
    EXPECT_EQ(*s21_List.begin(), *std_List.begin());
    EXPECT_EQ(*s21_List.end(), *std_List.end());
  }  
}

// // // TEST(ListIteratorTest, Index) {
// // //   s21::List<double> s21_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
// // //   std::list<double> std_List {1.1, 2.2, 1.3, 1.4, 1.5, 1.6, 7.7};
  
// // //   s21::List<double>::iterator s21_it = s21_List.begin();
// // //   std::list<double>::iterator std_it = std_List.begin();
// // //   std_it++;
// // //   s21_it[1];
// // //   EXPECT_EQ(*std_it, *s21_it);
// // // }

// // // // TEST(ListIteratorTest, AssignmentOperator) {
// // // //   s21::List<int> list;
// // // //   list.push_back(1);
// // // //   list.push_back(2);
// // // //   list.push_back(3);
// // // //   s21::ListIterator<int> it1 = list.begin();
// // // //   s21::ListIterator<int> it2;
// // // //   it2 = it1;
// // // //   EXPECT_EQ(it1, it2);
// // // //   ++it1;
// // // //   EXPECT_NE(it1, it2);
// // // //   ++it2;
// // // //   EXPECT_EQ(it1, it2);
// // // // }

// // // // TEST(ListIteratorTest, AssignmentOperator) {
// // // //   // std::list<int> std_List;
// // // //   s21::List<int> s21_List;

// // // //   // std_List.push_back(1);
// // // //   // std_List.push_back(2);
// // // //   // std_List.push_back(3);
// // // //   s21_List.push_back(1);
// // // //   s21_List.push_back(2);
// // // //   s21_List.push_back(3);

// // // //   s21::List<int>::iterator s21_it_1 = s21_List.begin();
// // // //   s21::List<int>::iterator s21_it_2;
// // // //   // std::list<int>::iterator std_it_2 = std_List.begin();

// // // //   // std::list<int>::iterator std_it1 = s21_List.begin();

// // // //   s21::List<int>::iterator it2;
// // // //   // s21_it_1 = s21_it_2;
// // // //   EXPECT_EQ(s21_it_1, s21_it_2);
// // // //   ++s21_it_1;
// // // //   EXPECT_NE(s21_it_1, s21_it_2);
// // // //   ++s21_it_2;
// // // //   EXPECT_EQ(s21_it_1, s21_it_2);
// // // // }



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

