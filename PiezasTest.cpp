/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
  ASSERT_TRUE(true);
}
TEST(PiezasTest, constructorCheck1)
{
  Piezas test;
  ASSERT_EQ(test.pieceAt(1,1), Blank);
}
TEST(PiezasTest, constructorCheck2)
{
  Piezas test;  
  ASSERT_EQ(test.dropPiece(0), X);
}
TEST(PiezasTest, resetCheck)
{
  Piezas test;  
  test.dropPiece(0);
  test.reset();
  ASSERT_EQ(test.pieceAt(0,0), Blank);
}
TEST(PiezasTest, dropPieceCheck1)
{
  Piezas test;  
  ASSERT_EQ(test.dropPiece(-1), Invalid);
}
TEST(PiezasTest, dropPieceCheck2)
{
  Piezas test;  
  ASSERT_EQ(test.dropPiece(4), Invalid);
}
TEST(PiezasTest, dropPieceCheck3)
{
  Piezas test;  
  test.dropPiece(1);
  ASSERT_EQ(test.dropPiece(0), O);
}
TEST(PiezasTest, dropPieceCheck4)
{
  Piezas test;  
  test.dropPiece(1);
  test.dropPiece(1);
  ASSERT_EQ(test.dropPiece(1), X);
}
TEST(PiezasTest, dropPieceCheck5)
{
  Piezas test;  
  test.dropPiece(1);
  test.dropPiece(1);
  test.dropPiece(1);
  ASSERT_EQ(test.dropPiece(1), Blank);
}
TEST(PiezasTest, pieceAtCheck1)
{
  Piezas test;  
  ASSERT_EQ(test.pieceAt(-1,0), Invalid);
}
TEST(PiezasTest, pieceAtCheck2)
{
  Piezas test;  
  ASSERT_EQ(test.pieceAt(3,0), Invalid);
}
TEST(PiezasTest, pieceAtCheck3)
{
  Piezas test;  
  ASSERT_EQ(test.pieceAt(0,-1), Invalid);
}
TEST(PiezasTest, pieceAtCheck4)
{
  Piezas test;  
  ASSERT_EQ(test.pieceAt(0,4), Invalid);
}
TEST(PiezasTest, pieceAtCheck5)
{
  Piezas test;  
  test.dropPiece(0);
  ASSERT_EQ(test.pieceAt(0,0), X);
}
TEST(PiezasTest, pieceAtCheck6)
{
  Piezas test;  
  test.dropPiece(0);
  test.dropPiece(1);
  ASSERT_EQ(test.pieceAt(0,1), O);
}
TEST(PiezasTest, XWins1)
{
  /***********
  [X][X][X][O]
  [X][O][O][X]
  [X][O][O][X]
  ***********/
  Piezas test;  
  test.dropPiece(0); // x(0,0)
  test.dropPiece(1); // o(0,1)
  test.dropPiece(0); // x(1,0)
  test.dropPiece(1); // o(1,1)
  test.dropPiece(0); // x(2,0)
  test.dropPiece(2); // o(0,2)
  test.dropPiece(1); // x(2,1)
  test.dropPiece(0); // o(blank)
  test.dropPiece(3); // x(0,3)
  test.dropPiece(2); // o(1,2)
  test.dropPiece(2); // x(2,2)
  test.dropPiece(1); // o(blank)
  test.dropPiece(3); // x(1,3)
  test.dropPiece(3); // o(2,3)
  ASSERT_EQ(test.gameState(), X);
}
TEST(PiezasTest, XWins2)
{
  /***********
  [O][X][X][0]
  [O][O][O][X]
  [X][X][X][X]
  ***********/
  Piezas test;  
  test.dropPiece(0); // x(0,0)
  test.dropPiece(0); // o(1,0)
  test.dropPiece(1); // x(0,1)
  test.dropPiece(0); // o(2,0)
  test.dropPiece(2); // x(0,2)
  test.dropPiece(1); // o(1,1)
  test.dropPiece(3); // x(0,3)
  test.dropPiece(0); // o(blank)
  test.dropPiece(1); // x(2,1)
  test.dropPiece(2); // o(1,2)
  test.dropPiece(2); // x(2,2)
  test.dropPiece(0); // o(blank)
  test.dropPiece(3); // x(1,3)
  test.dropPiece(3); // o(2,3)
  ASSERT_EQ(test.gameState(), X);
}
TEST(PiezasTest, OWins1)
{
  /***********
  [O][X][X][O]
  [X][O][O][O]
  [X][O][O][X]
  ***********/
  Piezas test;  
  test.dropPiece(0); // x(0,0)
  test.dropPiece(1); // o(0,1)
  test.dropPiece(0); // x(1,0)
  test.dropPiece(1); // o(1,1)
  test.dropPiece(5); // x(blank)
  test.dropPiece(0); // o(2,0)
  test.dropPiece(0); // x(blank)
  test.dropPiece(2); // o(0,2)
  test.dropPiece(1); // x(2,1)
  test.dropPiece(0); // o(blank)
  test.dropPiece(3); // x(0,3)
  test.dropPiece(2); // o(1,2)
  test.dropPiece(2); // x(2,2)
  test.dropPiece(3); // o(1,3)
  test.dropPiece(1); // x(blank)
  test.dropPiece(3); // o(2,3)
  ASSERT_EQ(test.gameState(), O);
}
TEST(PiezasTest, OWins2)
{
  /***********
  [O][X][X][O]
  [X][O][O][O]
  [X][O][O][O]
  ***********/
  Piezas test;  
  test.dropPiece(0); // x(0,0)
  test.dropPiece(1); // o(0,1)
  test.dropPiece(0); // x(1,0)
  test.dropPiece(1); // o(1,1)
  test.dropPiece(5); // x(blank)
  test.dropPiece(0); // o(2,0)
  test.dropPiece(0); // x(blank)
  test.dropPiece(2); // o(0,2)
  test.dropPiece(1); // x(2,1)
  test.dropPiece(0); // o(blank)
  test.dropPiece(0); // x(blank)
  test.dropPiece(3); // o(0,3)
  test.dropPiece(-1); // x(blank)
  test.dropPiece(2); // o(1,2)
  test.dropPiece(2); // x(2,2)
  test.dropPiece(3); // o(1,3)
  test.dropPiece(1); // x(blank)
  test.dropPiece(3); // o(2,3)
  ASSERT_EQ(test.gameState(), O);
}
TEST(PiezasTest, Tie)
{
  /***********
  [X][X][X][O]
  [X][O][O][O]
  [X][O][O][X]
  ***********/
  Piezas test;  
  test.dropPiece(0); // x(0,0)
  test.dropPiece(1); // o(0,1)
  test.dropPiece(0); // x(1,0)
  test.dropPiece(1); // o(1,1)
  test.dropPiece(0); // x(2,0)
  test.dropPiece(2); // o(0,2)
  test.dropPiece(1); // x(2,1)
  test.dropPiece(0); // o(blank)
  test.dropPiece(3); // x(0,3)
  test.dropPiece(2); // o(1,2)
  test.dropPiece(2); // x(2,2)
  test.dropPiece(3); // o(1,3)
  test.dropPiece(1); // x(blank)
  test.dropPiece(3); // o(2,3)
  ASSERT_EQ(test.gameState(), Blank);
}
TEST(PiezasTest, gameNotOver)
{
  /***************
  [X][X][X][Blank]
  [X][O][2][O]
  [X][O][O][X]
  ****************/
  Piezas test;  
  test.dropPiece(0); // x(0,0)
  test.dropPiece(1); // o(0,1)
  test.dropPiece(0); // x(1,0)
  test.dropPiece(1); // o(1,1)
  test.dropPiece(0); // x(2,0)
  test.dropPiece(2); // o(0,2)
  test.dropPiece(1); // x(2,1)
  test.dropPiece(0); // o(blank)
  test.dropPiece(3); // x(0,3)
  test.dropPiece(2); // o(1,2)
  test.dropPiece(2); // x(2,2)
  test.dropPiece(3); // o(1,3)
  ASSERT_EQ(test.gameState(), Invalid);
}

