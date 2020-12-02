#include "gtest/gtest.h"

#include "op.hpp"

#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include "list_container_test.hpp"
#include "VectorContainer_test.hpp"
#include "iterator_test.hpp"
#include "visitor.hpp"
#include "visitor_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
