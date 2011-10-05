/**
 * @file
 *
 * @author Oliver Merkel
 *
 * @ingroup gtest sample hello world
 *
 * @brief Small implementation testing a Greeting class holding a text for a hello world.
 */

/*
 * Copyright (c) <2011> <Oliver Merkel, Merkel dot Oliver at web dot de>.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * $Id$
 */

#include <string>

using namespace std;

#include "../helloworld/greeting.h"
#include "gtest/gtest.h"

TEST(HelloWorldTest, Equality) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE( 1 == 1 );
}

TEST(HelloWorldTest, SomeTest) {
  EXPECT_TRUE( 2 == 1+1 );
}

TEST(SampleTest, SomeTestThatFails) {
  EXPECT_TRUE( 2 == 10+1 );
}

TEST(HelloWorldTest, GreetingGetText) {
  string hw_us ("Hello World!");
  string hw_de ("Hallo Welt!");
  Greeting* g = new Greeting();
  EXPECT_TRUE( hw_us.compare(g->getText())==0 );
  EXPECT_FALSE( hw_de.compare(g->getText())==0 );
}

