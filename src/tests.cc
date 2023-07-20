#include <gtest/gtest.h>
// #include <list>
// #include "s21_containers.h"
#include "list.h"
#include <List>

using namespace std;

TEST(List, Сonstructor_null_1) {
s21::List<int> A;
ASSERT_EQ(A.size(), 0);
}

// TEST(List, Сonstructor_throw_1) {
// s21::List<int> A (3);
// s21::List<int> A (5);
// ASSERT_EQ(A.size(), 0);
// }

TEST(List, Сonstructor_size_1) {
  s21::List<int> A (5);
  ASSERT_EQ(A.size(), 5);
}

TEST(List, Сonstructor_pushback_size_1) {
  s21::List<int> A;
  s21::List<double> B;
  s21::List<string> C;
  A.push_back(1);
  B.push_back(0.235);
  C.push_back("string_1");
  ASSERT_EQ(A.size(), 1);
  ASSERT_EQ(B.size(), 1);
  ASSERT_EQ(C.size(), 1);
  A.push_back(5);
  B.push_back(0.0002);
  C.push_back("string2");
  ASSERT_EQ(A.size(), 2);
  ASSERT_EQ(B.size(), 2);
  ASSERT_EQ(C.size(), 2);
}

TEST(List, Сonstructor_pushback_size_2) {
  s21::List<int> A {1, 2 , 3};
  s21::List<double> B { 1.1, 1.2, 1.3};
  s21::List<string> C {"string_1", "string_2", "string_3"};
  ASSERT_EQ(A.size(), 3);
  ASSERT_EQ(B.size(), 3);
  ASSERT_EQ(C.size(), 3);
  A.push_back(5);
  B.push_back(0.0002);
  C.push_back("string_4");
  ASSERT_EQ(A.size(), 4);
  ASSERT_EQ(B.size(), 4);
  ASSERT_EQ(C.size(), 4);
}

TEST(List, Create_and_size_1) {
  s21::List<int> A = {1, 2, 3};
  EXPECT_EQ(A.size(), 3);
  s21::List<double> B = {1.23, 0.45, -4.65};
  EXPECT_EQ(B.size(), 3);
  s21::List<char> C = {'F', 'O', 'X'};
  EXPECT_EQ(C.size(), 3);
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
  EXPECT_EQ(s21_List.empty(), 1);
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

// TEST(Stack, Constructor_Copy) {
//   s21::List<char> s21_stack_1 = {'f', 'o', 'x', 'y'};
//   s21::List<char> s21_stack_2 = s21_stack_1;

//   EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());

//   for (auto i = 0; i < 4; i++) {
//     EXPECT_EQ(s21_stack_1.top(), s21_stack_2.top());
//     EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());
//     s21_stack_1.pop(), s21_stack_2.pop();
//   }
// }

// TEST(Stack, Constructor_Move) {
//   s21::List<char> s21_stack_1 = {'f', 'o', 'x', 'y'};
//   s21::List<char> s21_stack_2 = std::move(s21_stack_1);
//   s21::List<char> s21_stack_3 = {'f', 'o', 'x', 'y'};

//   EXPECT_EQ(s21_stack_2.size(), s21_stack_3.size());
//   EXPECT_EQ(s21_stack_1.size(), size_t(0));
//   EXPECT_EQ(s21_stack_1.empty(), true);
//   for (auto i = 0; i < 4; i++) {
//     EXPECT_EQ(s21_stack_3.top(), s21_stack_2.top());
//     EXPECT_EQ(s21_stack_3.size(), s21_stack_2.size());
//     s21_stack_3.pop(), s21_stack_2.pop();
//   }
// }


TEST(List, Front_Back) {  // сделать такой же тест. но с вылетом исключения
  s21::List<double> A;
       list<double> B;
    A.push_back(1.2);
    A.push_back(1.1);
    B.push_back(1.2);
    B.push_back(1.1);
    ASSERT_EQ(A.front(), B.front());
    ASSERT_EQ(A.back(), B.back());
    
    s21::List<char> C;
         list<char> D;
    C.push_back('1');
    C.push_back('2');
    D.push_back('1');
    D.push_back('2');
    ASSERT_EQ(C.front(), D.front());
    ASSERT_EQ(C.back(), D.back());
    
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
       list<double> B;
    A.push_front(1.2);
    A.push_front(1.1);
    B.push_front(1.2);
    B.push_front(1.1);
    ASSERT_EQ(A.front(), B.front());
    ASSERT_EQ(A.back(), B.back());
  
    s21::List<char> C;
         list<char> D;
    C.push_front('1');
    C.push_front('2');
    D.push_front('1');
    D.push_front('2');
    ASSERT_EQ(C.front(), D.front());
    ASSERT_EQ(C.back(), D.back());
    
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

TEST(List, Copy) {
  s21::List<double> s21_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
  std::list<double> std_List {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
      list<double> std_copy(std_List);
  s21::List<double> s21_copy(s21_List);
  for (int i = 0;  i < s21_List.size(); i++)
  {
        s21_List.pop_front();
        std_List.pop_front();
        EXPECT_EQ(s21_List.front(), std_List.front());
  }
}


// {
//    При создание 0 листа должна обрабатываться ошибка при  pop и запрос на последний обхъект
// std_List.pop_back();
//         EXPECT_EQ(s21_List.back(), std_List.back()); 
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
