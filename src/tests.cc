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
  ASSERT_EQ(A.size(), 1);
  ASSERT_EQ(C.size(), 1);
  A.push_back(5);
  B.push_back(0.0002);
  C.push_back("string2");
  ASSERT_EQ(A.size(), 2);
  ASSERT_EQ(A.size(), 2);
  ASSERT_EQ(C.size(), 2);
}


// TEST(List, Create_and_size_1) {
//   s21::List<int> A = {1, 2, 3};
//   EXPECT_EQ(A.size(), 0);
//   s21::List<double> B = {1.23, 0.45, -4.65};
//   EXPECT_EQ(B.size(), 3);
//   s21::List<char> C = {'F', 'O', 'X'};
//   EXPECT_EQ(C.size(), 3);
// }

TEST(List, Constructor_Default) {
  s21::List<int> s21_List;
  std::list<int> std_List;
  EXPECT_EQ(s21_List.size(), std_List.size());
  EXPECT_EQ(s21_List.empty(), std_List.empty());
}


// TEST(Stack, Constructor_Initializer_stack) {
//   s21::List<int> s21_stack = {1, 2, 3, 4};
//   EXPECT_EQ(s21_stack.top(), 4);
//   EXPECT_EQ(s21_stack.size(), size_t(4));
//   EXPECT_EQ(s21_stack.empty(), false);
// }

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
    ASSERT_EQ(C.front(), D.front());
    ASSERT_EQ(E.back(), F.back());
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
