//=================================================================================================
/*!
//  \file src/mathtest/densecolumn/ClassTest.cpp
//  \brief Source file for the DenseColumn class test
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/CompressedVector.h>
#include <blaze/math/DynamicVector.h>
#include <blaze/math/Views.h>
#include <blazetest/mathtest/densecolumn/ClassTest.h>


namespace blazetest {

namespace mathtest {

namespace densecolumn {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the DenseColumn class test.
//
// \exception std::runtime_error Operation error detected.
*/
ClassTest::ClassTest()
   : mat_ ( 4UL, 5UL )
   , tmat_( 4UL, 5UL )
{
   testConstructors();
   testAssignment();
   testAddAssign();
   testSubAssign();
   testMultAssign();
   testScaling();
   testSubscript();
   testIterator();
   testNonZeros();
   testReset();
   testIsDefault();
   testIsNan();
   testIsSame();
   testMinimum();
   testMaximum();
   testSubvector();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the DenseColumn constructors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all constructors of the DenseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testConstructors()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn constructor";

      initialize();

      // 0th matrix column
      {
         CT col0 = column( mat_, 0UL );

         checkSize    ( col0, 4UL );
         checkCapacity( col0, 4UL );
         checkNonZeros( col0, 0UL );

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 0th dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 1st matrix column
      {
         CT col1 = column( mat_, 1UL );

         checkSize    ( col1, 4UL );
         checkCapacity( col1, 4UL );
         checkNonZeros( col1, 1UL );

         if( col1[0] != 0 || col1[1] != 1 || col1[2] != 0 || col1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 1st dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 2nd matrix column
      {
         CT col2 = column( mat_, 2UL );

         checkSize    ( col2, 4UL );
         checkCapacity( col2, 4UL );
         checkNonZeros( col2, 2UL );

         if( col2[0] != -2 || col2[1] != 0 || col2[2] != -3 || col2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 2nd dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( -2 0 -3 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 3rd matrix column
      {
         CT col3 = column( mat_, 3UL );

         checkSize    ( col3, 4UL );
         checkCapacity( col3, 4UL );
         checkNonZeros( col3, 3UL );

         if( col3[0] != 0 || col3[1] != 4 || col3[2] != 5 || col3[3] != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 3rd dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 4 5 -6 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 4th matrix column
      {
         CT col4 = column( mat_, 4UL );

         checkSize    ( col4, 4UL );
         checkCapacity( col4, 4UL );
         checkNonZeros( col4, 4UL );

         if( col4[0] != 7 || col4[1] != -8 || col4[2] != 9 || col4[3] != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 4th dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col4 << "\n"
                << "   Expected result:\n( 7 -8 9 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn constructor";

      initialize();

      // 0th matrix column
      {
         TCT col0 = column( tmat_, 0UL );

         checkSize    ( col0, 4UL );
         checkCapacity( col0, 4UL );
         checkNonZeros( col0, 0UL );

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 0th dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 1st matrix column
      {
         TCT col1 = column( tmat_, 1UL );

         checkSize    ( col1, 4UL );
         checkCapacity( col1, 4UL );
         checkNonZeros( col1, 1UL );

         if( col1[0] != 0 || col1[1] != 1 || col1[2] != 0 || col1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 1st dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 2nd matrix column
      {
         TCT col2 = column( tmat_, 2UL );

         checkSize    ( col2, 4UL );
         checkCapacity( col2, 4UL );
         checkNonZeros( col2, 2UL );

         if( col2[0] != -2 || col2[1] != 0 || col2[2] != -3 || col2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 2nd dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( -2 0 -3 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 3rd matrix column
      {
         TCT col3 = column( tmat_, 3UL );

         checkSize    ( col3, 4UL );
         checkCapacity( col3, 4UL );
         checkNonZeros( col3, 3UL );

         if( col3[0] != 0 || col3[1] != 4 || col3[2] != 5 || col3[3] != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 3rd dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 4 5 -6 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 4th matrix column
      {
         TCT col4 = column( tmat_, 4UL );

         checkSize    ( col4, 4UL );
         checkCapacity( col4, 4UL );
         checkNonZeros( col4, 4UL );

         if( col4[0] != 7 || col4[1] != -8 || col4[2] != 9 || col4[3] != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 4th dense column failed\n"
                << " Details:\n"
                << "   Result:\n" << col4 << "\n"
                << "   Expected result:\n( 7 -8 9 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the DenseColumn assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all assignment operators of the DenseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testAssignment()
{
   //=====================================================================================
   // Row-major homogeneous assignment
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn homogeneous assignment";

      initialize();

      CT col1 = column( mat_, 1UL );
      col1 = 8;

      checkSize    ( col1,  4UL );
      checkCapacity( col1,  4UL );
      checkNonZeros( col1,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 13UL );

      if( col1[0] != 8 || col1[1] != 8 || col1[2] != 8 || col1[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 8 8 8 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 8 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 8 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 8 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 8 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  8 -2  0  7 )\n"
                                     "( 0  8  0  4 -8 )\n"
                                     "( 0  8 -3  5  9 )\n"
                                     "( 0  8  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major copy assignment
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn copy assignment";

      initialize();

      CT col1 = column( mat_, 1UL );
      col1 = column( mat_, 2UL );

      checkSize    ( col1,  4UL );
      checkCapacity( col1,  4UL );
      checkNonZeros( col1,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 11UL );

      if( col1[0] != -2 || col1[1] != 0 || col1[2] != -3 || col1[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( -2 0 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != -2 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) !=  0 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != -3 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) !=  0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0 -2 -2  0  7 )\n"
                                     "( 0  0  0  4 -8 )\n"
                                     "( 0 -3 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector assignment";

      initialize();

      CT col1 = column( mat_, 1UL );

      blaze::DynamicVector<int,blaze::columnVector> vec1( 4UL, 0 );
      vec1[1] = 8;
      vec1[3] = 9;

      col1 = vec1;

      checkSize    ( col1,  4UL );
      checkCapacity( col1,  4UL );
      checkNonZeros( col1,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 11UL );

      if( col1[0] != 0 || col1[1] != 8 || col1[2] != 0 || col1[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 8 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 8 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 9 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  8  0  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  9  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector assignment";

      initialize();

      CT col4 = column( mat_, 4UL );

      blaze::CompressedVector<int,blaze::columnVector> vec1( 4UL );
      vec1[3] = 9;

      col4 = vec1;

      checkSize    ( col4, 4UL );
      checkCapacity( col4, 4UL );
      checkNonZeros( col4, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 5UL );
      checkNonZeros( mat_, 7UL );

      if( col4[0] != 0 || col4[1] != 0 || col4[2] != 0 || col4[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col4 << "\n"
             << "   Expected result:\n( 0 0 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != 0 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) != 0 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  0 )\n"
                                     "( 0  1  0  4  0 )\n"
                                     "( 0  0 -3  5  0 )\n"
                                     "( 0  0  0 -6  9 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major homogeneous assignment
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn homogeneous assignment";

      initialize();

      TCT col1 = column( tmat_, 1UL );
      col1 = 8;

      checkSize    ( col1 ,  4UL );
      checkCapacity( col1 ,  4UL );
      checkNonZeros( col1 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 13UL );

      if( col1[0] != 8 || col1[1] != 8 || col1[2] != 8 || col1[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 8 8 8 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 8 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 8 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 8 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 8 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  8 -2  0  7 )\n"
                                     "( 0  8  0  4 -8 )\n"
                                     "( 0  8 -3  5  9 )\n"
                                     "( 0  8  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major copy assignment
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn copy assignment";

      initialize();

      TCT col1 = column( tmat_, 1UL );
      col1 = column( tmat_, 2UL );

      checkSize    ( col1 ,  4UL );
      checkCapacity( col1 ,  4UL );
      checkNonZeros( col1 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 11UL );

      if( col1[0] != -2 || col1[1] != 0 || col1[2] != -3 || col1[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( -2 0 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != -2 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  0 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != -3 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) !=  0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0 -2 -2  0  7 )\n"
                                     "( 0  0  0  4 -8 )\n"
                                     "( 0 -3 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector assignment";

      initialize();

      TCT col1 = column( tmat_, 1UL );

      blaze::DynamicVector<int,blaze::columnVector> vec1( 4UL, 0 );
      vec1[1] = 8;
      vec1[3] = 9;

      col1 = vec1;

      checkSize    ( col1 ,  4UL );
      checkCapacity( col1 ,  4UL );
      checkNonZeros( col1 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 11UL );

      if( col1[0] != 0 || col1[1] != 8 || col1[2] != 0 || col1[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( 0 8 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 8 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 9 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  8  0  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  9  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector assignment";

      initialize();

      TCT col4 = column( tmat_, 4UL );

      blaze::CompressedVector<int,blaze::columnVector> vec1( 4UL );
      vec1[3] = 9;

      col4 = vec1;

      checkSize    ( col4 , 4UL );
      checkCapacity( col4 , 4UL );
      checkNonZeros( col4 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 5UL );
      checkNonZeros( tmat_, 7UL );

      if( col4[0] != 0 || col4[1] != 0 || col4[2] != 0 || col4[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col4 << "\n"
             << "   Expected result:\n( 0 0 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != 0 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) != 0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  0 )\n"
                                     "( 0  1  0  4  0 )\n"
                                     "( 0  0 -3  5  0 )\n"
                                     "( 0  0  0 -6  9 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the DenseColumn addition assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the addition assignment operators of the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testAddAssign()
{
   //=====================================================================================
   // Row-major DenseColumn addition assignment
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn addition assignment";

      initialize();

      CT col2 = column( mat_, 2UL );
      col2 += column( mat_, 3UL );

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 12UL );

      if( col2[0] != -2 || col2[1] != 4 || col2[2] != 2 || col2[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 4 2 -6 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  4 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  2 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) != -6 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  4  4 -8 )\n"
                                     "( 0  0  2  5  9 )\n"
                                     "( 0  0 -6 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector addition assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector addition assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != 0 || col2[1] != -4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 -4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != -4 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0  7 )\n"
                                     "( 0  1 -4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector addition assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector addition assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != 0 || col2[1] != -4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 -4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != -4 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0  7 )\n"
                                     "( 0  1 -4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major DenseColumn addition assignment
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn addition assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );
      col2 += column( tmat_, 3UL );

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 12UL );

      if( col2[0] != -2 || col2[1] != 4 || col2[2] != 2 || col2[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 4 2 -6 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  4 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  2 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) != -6 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  4  4 -8 )\n"
                                     "( 0  0  2  5  9 )\n"
                                     "( 0  0 -6 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector addition assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector addition assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != 0 || col2[1] != -4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 -4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != -4 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0  7 )\n"
                                     "( 0  1 -4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector addition assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector addition assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 += vec;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != 0 || col2[1] != -4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 -4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != -4 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0  7 )\n"
                                     "( 0  1 -4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the DenseColumn subtraction assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the subtraction assignment operators of the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testSubAssign()
{
   //=====================================================================================
   // Row-major DenseColumn subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn subtraction assignment";

      initialize();

      CT col2 = column( mat_, 2UL );
      col2 -= column( mat_, 3UL );

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 12UL );

      if( col2[0] != -2 || col2[1] != -4 || col2[2] != -8 || col2[3] != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 -4 -8 6 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != -4 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -8 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  6 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1 -4  4 -8 )\n"
                                     "( 0  0 -8  5  9 )\n"
                                     "( 0  0  6 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector subtraction assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  3UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 11UL );

      if( col2[0] != -4 || col2[1] != 4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -4 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  4 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector subtraction assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  3UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 11UL );

      if( col2[0] != -4 || col2[1] != 4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -4 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  4 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major DenseColumn subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn subtraction assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );
      col2 -= column( tmat_, 3UL );

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 12UL );

      if( col2[0] != -2 || col2[1] != -4 || col2[2] != -8 || col2[3] != 6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 -4 -8 6 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != -4 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -8 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  6 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1 -4  4 -8 )\n"
                                     "( 0  0 -8  5  9 )\n"
                                     "( 0  0  6 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector subtraction assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  3UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 11UL );

      if( col2[0] != -4 || col2[1] != 4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -4 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  4 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector subtraction assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 -= vec;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  3UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 11UL );

      if( col2[0] != -4 || col2[1] != 4 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 4 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -4 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  4 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  4  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the DenseColumn multiplication assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the multiplication assignment operators of the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testMultAssign()
{
   //=====================================================================================
   // Row-major DenseColumn multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn multiplication assignment";

      initialize();

      CT col2 = column( mat_, 2UL );
      col2 *= column( mat_, 3UL );

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 5UL );
      checkNonZeros( mat_, 9UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != -15 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 -15 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=   0 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=   0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -15 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=   0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0   0  0  7 )\n"
                                     "( 0  1   0  4 -8 )\n"
                                     "( 0  0 -15  5  9 )\n"
                                     "( 0  0   0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector multiplication assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 *= vec;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 5UL );
      checkNonZeros( mat_, 9UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -4 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  0 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector multiplication assignment";

      initialize();

      CT col2 = column( mat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 *= vec;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 5UL );
      checkNonZeros( mat_, 9UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -4 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  0 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major DenseColumn multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn multiplication assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );
      col2 *= column( tmat_, 3UL );

      checkSize    ( col2 , 4UL );
      checkCapacity( col2 , 4UL );
      checkNonZeros( col2 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 5UL );
      checkNonZeros( tmat_, 9UL );

      if( col2[0] != 0 || col2[1] != 0 || col2[2] != -15 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( 0 0 -15 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=   0 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=   0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -15 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=   0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0   0  0  7 )\n"
                                     "( 0  1   0  4 -8 )\n"
                                     "( 0  0 -15  5  9 )\n"
                                     "( 0  0   0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector multiplication assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::columnVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      col2 *= vec;

      checkSize    ( col2 , 4UL );
      checkCapacity( col2 , 4UL );
      checkNonZeros( col2 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 5UL );
      checkNonZeros( tmat_, 9UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -4 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  0 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector multiplication assignment";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::columnVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      col2 *= vec;

      checkSize    ( col2 , 4UL );
      checkCapacity( col2 , 4UL );
      checkNonZeros( col2 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 5UL );
      checkNonZeros( tmat_, 9UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -4 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  0 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of all DenseColumn (self-)scaling operations.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all available ways to scale an instance of the DenseColumn
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testScaling()
{
   //=====================================================================================
   // Row-major self-scaling (v*=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v*=s)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 *= 3;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != -6 || col2[1] != 0 || col2[2] != -9 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -6 0 -9 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -6 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -9 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -6  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -9  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=v*s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=v*s)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 = col2 * 3;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != -6 || col2[1] != 0 || col2[2] != -9 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -6 0 -9 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -6 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -9 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -6  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -9  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=s*v)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=s*v)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 = 3 * col2;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != -6 || col2[1] != 0 || col2[2] != -9 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -6 0 -9 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -6 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -9 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -6  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -9  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v/=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v/=s)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 /= 0.5;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != -6 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 -6 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -4 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -6 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -6  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=v/s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=v/s)";

      initialize();

      CT col2 = column( mat_, 2UL );

      col2 = col2 / 0.5;

      checkSize    ( col2,  4UL );
      checkCapacity( col2,  4UL );
      checkNonZeros( col2,  2UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  5UL );
      checkNonZeros( mat_, 10UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != -6 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 -6 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -4 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -6 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -6  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major DenseColumn::scale()
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn::scale()";

      initialize();

      // Integral scaling the 3rd column
      {
         CT col3 = column( mat_, 3UL );
         col3.scale( 3 );

         checkSize    ( col3,  4UL );
         checkCapacity( col3,  4UL );
         checkNonZeros( col3,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  5UL );
         checkNonZeros( mat_, 10UL );

         if( col3[0] != 0 || col3[1] != 12 || col3[2] != 15 || col3[3] != -18 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 12 15 -18 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=   0 || mat_(0,4) !=  7 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  12 || mat_(1,4) != -8 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  15 || mat_(2,4) !=  9 ||
             mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -18 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0 -2  0   7 )\n"
                                        "( 0  1  0  12 -8 )\n"
                                        "( 0  0 -3  15  9 )\n"
                                        "( 0  0  0 -18 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Floating point scaling the 3rd column
      {
         CT col3 = column( mat_, 3UL );
         col3.scale( 0.5 );

         checkSize    ( col3,  4UL );
         checkCapacity( col3,  4UL );
         checkNonZeros( col3,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  5UL );
         checkNonZeros( mat_, 10UL );

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 7 || col3[3] != -9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 7 -9 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  6 || mat_(1,4) != -8 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  7 || mat_(2,4) !=  9 ||
             mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -9 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                        "( 0  1  0  6 -8 )\n"
                                        "( 0  0 -3  7  9 )\n"
                                        "( 0  0  0 -9 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v*=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v*=s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 *= 3;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != -6 || col2[1] != 0 || col2[2] != -9 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -6 0 -9 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -6 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -9 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -6  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -9  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=v*s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=v*s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 = col2 * 3;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != -6 || col2[1] != 0 || col2[2] != -9 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -6 0 -9 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -6 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -9 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -6  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -9  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=s*v)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=s*v)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 = 3 * col2;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != -6 || col2[1] != 0 || col2[2] != -9 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -6 0 -9 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -6 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -9 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -6  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -9  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v/=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v/=s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 /= 0.5;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != -6 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 -6 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -4 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -6 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -6  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=v/s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=v/s)";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      col2 = col2 / 0.5;

      checkSize    ( col2 ,  4UL );
      checkCapacity( col2 ,  4UL );
      checkNonZeros( col2 ,  2UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  5UL );
      checkNonZeros( tmat_, 10UL );

      if( col2[0] != -4 || col2[1] != 0 || col2[2] != -6 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -4 0 -6 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -4 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -6 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -4  0  7 )\n"
                                     "( 0  1  0  4 -8 )\n"
                                     "( 0  0 -6  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major DenseColumn::scale()
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn::scale()";

      initialize();

      // Integral scaling the 3rd column
      {
         TCT col3 = column( tmat_, 3UL );
         col3.scale( 3 );

         checkSize    ( col3 ,  4UL );
         checkCapacity( col3 ,  4UL );
         checkNonZeros( col3 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  5UL );
         checkNonZeros( tmat_, 10UL );

         if( col3[0] != 0 || col3[1] != 12 || col3[2] != 15 || col3[3] != -18 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 12 15 -18 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=   0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  12 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  15 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -18 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0 -2  0   7 )\n"
                                        "( 0  1  0  12 -8 )\n"
                                        "( 0  0 -3  15  9 )\n"
                                        "( 0  0  0 -18 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Floating point scaling the 3rd column
      {
         TCT col3 = column( tmat_, 3UL );
         col3.scale( 0.5 );

         checkSize    ( col3 ,  4UL );
         checkCapacity( col3 ,  4UL );
         checkNonZeros( col3 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  5UL );
         checkNonZeros( tmat_, 10UL );

         if( col3[0] != 0 || col3[1] != 6 || col3[2] != 7 || col3[3] != -9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 6 7 -9 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  6 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  7 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -9 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                        "( 0  1  0  6 -8 )\n"
                                        "( 0  0 -3  7  9 )\n"
                                        "( 0  0  0 -9 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the DenseColumn subscript operator.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of adding and accessing elements via the subscript operator
// of the DenseColumn class template. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
void ClassTest::testSubscript()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn::operator[]";

      initialize();

      CT col2 = column( mat_, 2UL );

      // Writing the first element
      col2[1] = 9;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -2 || col2[1] != 9 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 9 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  9 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  9  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Writing the second element
      col2[2] = 0;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 2UL );

      if( col2[0] != -2 || col2[1] != 9 || col2[2] != 0 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 9 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  9 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  0 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  9  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Writing the third element
      col2[3] = -8;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -2 || col2[1] != 9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
          mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  9 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  0 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != 0 || mat_(3,2) != -8 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  9  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0 -8 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn::operator[]";

      initialize();

      TCT col2 = column( tmat_, 2UL );

      // Writing the first element
      col2[1] = 9;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -2 || col2[1] != 9 || col2[2] != -3 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 9 -3 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  9 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  9  4 -8 )\n"
                                     "( 0  0 -3  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Writing the second element
      col2[2] = 0;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 2UL );

      if( col2[0] != -2 || col2[1] != 9 || col2[2] != 0 || col2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 9 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  9 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  0 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  9  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0  0 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Writing the third element
      col2[3] = -8;

      checkSize    ( col2, 4UL );
      checkCapacity( col2, 4UL );
      checkNonZeros( col2, 3UL );

      if( col2[0] != -2 || col2[1] != 9 || col2[2] != 0 || col2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col2 << "\n"
             << "   Expected result:\n( -2 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  9 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  0 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) != -8 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0 -2  0  7 )\n"
                                     "( 0  1  9  4 -8 )\n"
                                     "( 0  0  0  5  9 )\n"
                                     "( 0  0 -8 -6 10 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the DenseColumn iterator implementation.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the iterator implementation of the DenseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testIterator()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      initialize();

      // Counting the number of elements in 0th column
      {
         test_ = "Row-major iterator subtraction";

         CT col0 = column( mat_, 0UL );
         const size_t number( col0.end() - col0.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st column
      {
         test_ = "Row-major iterator subtraction";

         CT col1 = column( mat_, 1UL );
         const size_t number( col1.end() - col1.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 2nd column
      {
         test_ = "Row-major iterator subtraction";

         CT col2 = column( mat_, 2UL );
         const size_t number( col2.end() - col2.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 3rd column
      {
         test_ = "Row-major iterator subtraction";

         CT col3 = column( mat_, 3UL );
         const size_t number( col3.end() - col3.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 4th column
      {
         test_ = "Row-major iterator subtraction";

         CT col4 = column( mat_, 4UL );
         const size_t number( col4.end() - col4.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Row-major read-only access via ConstIterator";

         CT col3 = column( mat_, 3UL );
         CT::ConstIterator it ( col3.cbegin() );
         CT::ConstIterator end( col3.cend() );

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || *it != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         --it;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it == end || *it != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it--;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it += 2UL;

         if( it == end || *it != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator addition assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it -= 2UL;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator subtraction assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it + 3UL;

         if( it == end || *it != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar addition failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it - 3UL;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar subtraction failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = 4UL + it;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Scalar/iterator addition failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Row-major assignment via Iterator";

         CT col0 = column( mat_, 0UL );
         int value = 6;

         for( CT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it = value++;
         }

         if( col0[0] != 6 || col0[1] != 7 || col0[2] != 8 || col0[3] != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 6 7 8 9 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 6 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
             mat_(1,0) != 7 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
             mat_(2,0) != 8 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
             mat_(3,0) != 9 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 6  0 -2  0  7 )\n"
                                        "( 7  1  0  4 -8 )\n"
                                        "( 8  0 -3  5  9 )\n"
                                        "( 9  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Row-major addition assignment via Iterator";

         CT col0 = column( mat_, 0UL );
         int value = 2;

         for( CT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it += value++;
         }

         if( col0[0] != 8 || col0[1] != 10 || col0[2] != 12 || col0[3] != 14 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 8 10 12 14 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) !=  8 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
             mat_(1,0) != 10 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
             mat_(2,0) != 12 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
             mat_(3,0) != 14 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n(  8  0 -2  0  7 )\n"
                                        "( 10  1  0  4 -8 )\n"
                                        "( 12  0 -3  5  9 )\n"
                                        "( 14  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Row-major subtraction assignment via Iterator";

         CT col0 = column( mat_, 0UL );
         int value = 2;

         for( CT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it -= value++;
         }

         if( col0[0] != 6 || col0[1] != 7 || col0[2] != 8 || col0[3] != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Subtraction assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 6 7 8 9 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 6 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
             mat_(1,0) != 7 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
             mat_(2,0) != 8 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
             mat_(3,0) != 9 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 6  0 -2  0  7 )\n"
                                        "( 7  1  0  4 -8 )\n"
                                        "( 8  0 -3  5  9 )\n"
                                        "( 9  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Row-major multiplication assignment via Iterator";

         CT col0 = column( mat_, 0UL );
         int value = 1;

         for( CT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it *= value++;
         }

         if( col0[0] != 6 || col0[1] != 14 || col0[2] != 24 || col0[3] != 36 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Multiplication assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 6 14 24 36 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) !=  6 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
             mat_(1,0) != 14 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
             mat_(2,0) != 24 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
             mat_(3,0) != 36 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n(  6  0 -2  0  7 )\n"
                                        "( 14  1  0  4 -8 )\n"
                                        "( 24  0 -3  5  9 )\n"
                                        "( 36  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Row-major division assignment via Iterator";

         CT col0 = column( mat_, 0UL );

         for( CT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it /= 2;
         }

         if( col0[0] != 3 || col0[1] != 7 || col0[2] != 12 || col0[3] != 18 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Division assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 3 7 12 18 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) !=  3 || mat_(0,1) != 0 || mat_(0,2) != -2 || mat_(0,3) !=  0 || mat_(0,4) !=  7 ||
             mat_(1,0) !=  7 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  4 || mat_(1,4) != -8 ||
             mat_(2,0) != 12 || mat_(2,1) != 0 || mat_(2,2) != -3 || mat_(2,3) !=  5 || mat_(2,4) !=  9 ||
             mat_(3,0) != 18 || mat_(3,1) != 0 || mat_(3,2) !=  0 || mat_(3,3) != -6 || mat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n(  3  0 -2  0  7 )\n"
                                        "(  7  1  0  4 -8 )\n"
                                        "( 12  0 -3  5  9 )\n"
                                        "( 18  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      initialize();

      // Counting the number of elements in 0th column
      {
         test_ = "Row-major iterator subtraction";

         TCT col0 = column( tmat_, 0UL );
         const size_t number( col0.end() - col0.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st column
      {
         test_ = "Row-major iterator subtraction";

         TCT col1 = column( tmat_, 1UL );
         const size_t number( col1.end() - col1.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 2nd column
      {
         test_ = "Row-major iterator subtraction";

         TCT col2 = column( tmat_, 2UL );
         const size_t number( col2.end() - col2.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 3rd column
      {
         test_ = "Row-major iterator subtraction";

         TCT col3 = column( tmat_, 3UL );
         const size_t number( col3.end() - col3.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 4th column
      {
         test_ = "Row-major iterator subtraction";

         TCT col4 = column( tmat_, 4UL );
         const size_t number( col4.end() - col4.begin() );

         if( number != 4UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Column-major read-only access via ConstIterator";

         TCT col3 = column( tmat_, 3UL );
         TCT::ConstIterator it ( col3.cbegin() );
         TCT::ConstIterator end( col3.cend() );

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || *it != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         --it;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it == end || *it != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it--;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it += 2UL;

         if( it == end || *it != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator addition assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it -= 2UL;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator subtraction assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it + 3UL;

         if( it == end || *it != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar addition failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it - 3UL;

         if( it == end || *it != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar subtraction failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = 4UL + it;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Scalar/iterator addition failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Column-major assignment via Iterator";

         TCT col0 = column( tmat_, 0UL );
         int value = 6;

         for( TCT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it = value++;
         }

         if( col0[0] != 6 || col0[1] != 7 || col0[2] != 8 || col0[3] != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 6 7 8 9 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 6 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) != 7 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 8 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 9 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 6  0 -2  0  7 )\n"
                                        "( 7  1  0  4 -8 )\n"
                                        "( 8  0 -3  5  9 )\n"
                                        "( 9  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Column-major addition assignment via Iterator";

         TCT col0 = column( tmat_, 0UL );
         int value = 2;

         for( TCT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it += value++;
         }

         if( col0[0] != 8 || col0[1] != 10 || col0[2] != 12 || col0[3] != 14 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 8 10 12 14 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) !=  8 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) != 10 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 12 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 14 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n(  8  0 -2  0  7 )\n"
                                        "( 10  1  0  4 -8 )\n"
                                        "( 12  0 -3  5  9 )\n"
                                        "( 14  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Column-major subtraction assignment via Iterator";

         TCT col0 = column( tmat_, 0UL );
         int value = 2;

         for( TCT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it -= value++;
         }

         if( col0[0] != 6 || col0[1] != 7 || col0[2] != 8 || col0[3] != 9 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Subtraction assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 6 7 8 9 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 6 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) != 7 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 8 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 9 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 6  0 -2  0  7 )\n"
                                        "( 7  1  0  4 -8 )\n"
                                        "( 8  0 -3  5  9 )\n"
                                        "( 9  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Column-major multiplication assignment via Iterator";

         TCT col0 = column( tmat_, 0UL );
         int value = 1;

         for( TCT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it *= value++;
         }

         if( col0[0] != 6 || col0[1] != 14 || col0[2] != 24 || col0[3] != 36 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Multiplication assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 6 14 24 36 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) !=  6 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) != 14 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 24 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 36 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n(  6  0 -2  0  7 )\n"
                                        "( 14  1  0  4 -8 )\n"
                                        "( 24  0 -3  5  9 )\n"
                                        "( 36  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Column-major division assignment via Iterator";

         TCT col0 = column( tmat_, 0UL );

         for( TCT::Iterator it=col0.begin(); it!=col0.end(); ++it ) {
            *it /= 2;
         }

         if( col0[0] != 3 || col0[1] != 7 || col0[2] != 12 || col0[3] != 18 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Division assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 3 7 12 18 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) !=  3 || tmat_(0,1) != 0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 || tmat_(0,4) !=  7 ||
             tmat_(1,0) !=  7 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  4 || tmat_(1,4) != -8 ||
             tmat_(2,0) != 12 || tmat_(2,1) != 0 || tmat_(2,2) != -3 || tmat_(2,3) !=  5 || tmat_(2,4) !=  9 ||
             tmat_(3,0) != 18 || tmat_(3,1) != 0 || tmat_(3,2) !=  0 || tmat_(3,3) != -6 || tmat_(3,4) != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n(  3  0 -2  0  7 )\n"
                                        "(  7  1  0  4 -8 )\n"
                                        "( 12  0 -3  5  9 )\n"
                                        "( 18  0  0 -6 10 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c nonZeros() member function of the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c nonZeros() member function of the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testNonZeros()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn::nonZeros()";

      initialize();

      // Initialization check
      CT col3 = column( mat_, 3UL );

      checkSize    ( col3, 4UL );
      checkCapacity( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 0 || col3[1] != 4 || col3[2] != 5 || col3[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 4 5 -6 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the dense column
      col3[2] = 0;

      checkSize    ( col3, 4UL );
      checkCapacity( col3, 4UL );
      checkNonZeros( col3, 2UL );

      if( col3[0] != 0 || col3[1] != 4 || col3[2] != 0 || col3[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 4 0 -6 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the dense matrix
      mat_(0,3) = 5;

      checkSize    ( col3, 4UL );
      checkCapacity( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 5 || col3[1] != 4 || col3[2] != 0 || col3[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 5 4 0 -6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn::nonZeros()";

      initialize();

      // Initialization check
      TCT col3 = column( tmat_, 3UL );

      checkSize    ( col3, 4UL );
      checkCapacity( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 0 || col3[1] != 4 || col3[2] != 5 || col3[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 4 5 -6 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the dense column
      col3[2] = 0;

      checkSize    ( col3, 4UL );
      checkCapacity( col3, 4UL );
      checkNonZeros( col3, 2UL );

      if( col3[0] != 0 || col3[1] != 4 || col3[2] != 0 || col3[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 0 4 0 -6 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the dense matrix
      tmat_(0,3) = 5;

      checkSize    ( col3, 4UL );
      checkCapacity( col3, 4UL );
      checkNonZeros( col3, 3UL );

      if( col3[0] != 5 || col3[1] != 4 || col3[2] != 0 || col3[3] != -6 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << col3 << "\n"
             << "   Expected result:\n( 5 4 0 -6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reset() member function of the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reset() member function of the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testReset()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major DenseColumn::reset()";

      initialize();

      // Resetting the 0th column
      {
         CT col0 = column( mat_, 0UL );
         col0.reset();

         checkSize    ( col0,  4UL );
         checkCapacity( col0,  4UL );
         checkNonZeros( col0,  0UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  5UL );
         checkNonZeros( mat_, 10UL );

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 0th column failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 1st column
      {
         CT col1 = column( mat_, 1UL );
         col1.reset();

         checkSize    ( col1, 4UL );
         checkCapacity( col1, 4UL );
         checkNonZeros( col1, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 5UL );
         checkNonZeros( mat_, 9UL );

         if( col1[0] != 0 || col1[1] != 0 || col1[2] != 0 || col1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 1st column failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 2nd column
      {
         CT col2 = column( mat_, 2UL );
         col2.reset();

         checkSize    ( col2, 4UL );
         checkCapacity( col2, 4UL );
         checkNonZeros( col2, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 5UL );
         checkNonZeros( mat_, 7UL );

         if( col2[0] != 0 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 2nd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 3rd column
      {
         CT col3 = column( mat_, 3UL );
         col3.reset();

         checkSize    ( col3, 4UL );
         checkCapacity( col3, 4UL );
         checkNonZeros( col3, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 5UL );
         checkNonZeros( mat_, 4UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 4th column
      {
         CT col4 = column( mat_, 4UL );
         col4.reset();

         checkSize    ( col4, 4UL );
         checkCapacity( col4, 4UL );
         checkNonZeros( col4, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 5UL );
         checkNonZeros( mat_, 0UL );

         if( col4[0] != 0 || col4[1] != 0 || col4[2] != 0 || col4[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 4th column failed\n"
                << " Details:\n"
                << "   Result:\n" << col4 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major DenseColumn::reset()";

      initialize();

      // Resetting the 0th column
      {
         TCT col0 = column( tmat_, 0UL );
         col0.reset();

         checkSize    ( col0,  4UL );
         checkCapacity( col0,  4UL );
         checkNonZeros( col0,  0UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  5UL );
         checkNonZeros( tmat_, 10UL );

         if( col0[0] != 0 || col0[1] != 0 || col0[2] != 0 || col0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 0th column failed\n"
                << " Details:\n"
                << "   Result:\n" << col0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 1st column
      {
         TCT col1 = column( tmat_, 1UL );
         col1.reset();

         checkSize    ( col1, 4UL );
         checkCapacity( col1, 4UL );
         checkNonZeros( col1, 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 5UL );
         checkNonZeros( tmat_, 9UL );

         if( col1[0] != 0 || col1[1] != 0 || col1[2] != 0 || col1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 1st column failed\n"
                << " Details:\n"
                << "   Result:\n" << col1 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 2nd column
      {
         TCT col2 = column( tmat_, 2UL );
         col2.reset();

         checkSize    ( col2, 4UL );
         checkCapacity( col2, 4UL );
         checkNonZeros( col2, 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 5UL );
         checkNonZeros( tmat_, 7UL );

         if( col2[0] != 0 || col2[1] != 0 || col2[2] != 0 || col2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 2nd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col2 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 3rd column
      {
         TCT col3 = column( tmat_, 3UL );
         col3.reset();

         checkSize    ( col3, 4UL );
         checkCapacity( col3, 4UL );
         checkNonZeros( col3, 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 5UL );
         checkNonZeros( tmat_, 4UL );

         if( col3[0] != 0 || col3[1] != 0 || col3[2] != 0 || col3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 3rd column failed\n"
                << " Details:\n"
                << "   Result:\n" << col3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 4th column
      {
         TCT col4 = column( tmat_, 4UL );
         col4.reset();

         checkSize    ( col4, 4UL );
         checkCapacity( col4, 4UL );
         checkNonZeros( col4, 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 5UL );
         checkNonZeros( tmat_, 0UL );

         if( col4[0] != 0 || col4[1] != 0 || col4[2] != 0 || col4[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 4th column failed\n"
                << " Details:\n"
                << "   Result:\n" << col4 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isDefault() function with the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isDefault() function with the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testIsDefault()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDefault() function";

      initialize();

      // isDefault with default column
      {
         CT col0 = column( mat_, 0UL );

         if( isDefault( col0 ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default column
      {
         CT col1 = column( mat_, 1UL );

         if( isDefault( col1 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDefault() function";

      initialize();

      // isDefault with default column
      {
         TCT col0 = column( tmat_, 0UL );

         if( isDefault( col0 ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default column
      {
         TCT col1 = column( tmat_, 1UL );

         if( isDefault( col1 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isnan() function with the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isnan() function with the DenseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testIsNan()
{
   initialize();


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isnan() function";

      typedef blaze::DynamicMatrix<float,blaze::rowMajor>  MatrixType;
      typedef blaze::DenseColumn<MatrixType>               ColumnType;

      MatrixType mat( mat_ );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  5UL );
      checkNonZeros( mat, 10UL );

      // isnan with empty column
      {
         ColumnType col0 = column( mat, 0UL );

         checkSize    ( col0, 4UL );
         checkNonZeros( col0, 0UL );

         if( blaze::isnan( col0 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with partially filled column
      {
         ColumnType col2 = column( mat, 2UL );

         checkSize    ( col2, 4UL );
         checkNonZeros( col2, 2UL );

         if( blaze::isnan( col2 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with fully filled column
      {
         ColumnType col4 = column( mat, 4UL );

         checkSize    ( col4, 4UL );
         checkNonZeros( col4, 4UL );

         if( blaze::isnan( col4 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col4 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isnan() function";

      typedef blaze::DynamicMatrix<float,blaze::columnMajor>  MatrixType;
      typedef blaze::DenseColumn<MatrixType>                  ColumnType;

      MatrixType mat( mat_ );

      checkRows    ( mat,  4UL );
      checkColumns ( mat,  5UL );
      checkNonZeros( mat, 10UL );

      // isnan with empty column
      {
         ColumnType col0 = column( mat, 0UL );

         checkSize    ( col0, 4UL );
         checkNonZeros( col0, 0UL );

         if( blaze::isnan( col0 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with partially filled column
      {
         ColumnType col2 = column( mat, 2UL );

         checkSize    ( col2, 4UL );
         checkNonZeros( col2, 2UL );

         if( blaze::isnan( col2 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with fully filled column
      {
         ColumnType col4 = column( mat, 4UL );

         checkSize    ( col4, 4UL );
         checkNonZeros( col4, 4UL );

         if( blaze::isnan( col4 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Column:\n" << col4 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isSame() function with the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isSame() function with the DenseColumn class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testIsSame()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSame() function";

      // isSame with matching columns
      {
         CT col1 = column( mat_, 1UL );
         CT col2 = column( mat_, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns
      {
         CT col1 = column( mat_, 1UL );
         CT col2 = column( mat_, 2UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and matching subvector
      {
         typedef blaze::DenseSubvector<CT>  SubvectorType;

         CT col1 = column( mat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 4UL );

         if( blaze::isSame( col1, sv ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different size)
      {
         typedef blaze::DenseSubvector<CT>  SubvectorType;

         CT col1 = column( mat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different offset)
      {
         typedef blaze::DenseSubvector<CT>  SubvectorType;

         CT col1 = column( mat_, 1UL );
         SubvectorType sv = subvector( col1, 1UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching columns on submatrices
      {
         typedef blaze::DenseSubmatrix<MT>          SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns on submatrices
      {
         typedef blaze::DenseSubmatrix<MT>          SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 0UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching column subvectors on submatrices
      {
         typedef blaze::DenseSubmatrix<MT>          SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;
         typedef blaze::DenseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different size)
      {
         typedef blaze::DenseSubmatrix<MT>          SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;
         typedef blaze::DenseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different offset)
      {
         typedef blaze::DenseSubmatrix<MT>          SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;
         typedef blaze::DenseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 1UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSame() function";

      // isSame with matching columns
      {
         TCT col1 = column( tmat_, 1UL );
         TCT col2 = column( tmat_, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns
      {
         TCT col1 = column( tmat_, 1UL );
         TCT col2 = column( tmat_, 2UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and matching subvector
      {
         typedef blaze::DenseSubvector<TCT>  SubvectorType;

         TCT col1 = column( tmat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 4UL );

         if( blaze::isSame( col1, sv ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different size)
      {
         typedef blaze::DenseSubvector<TCT>  SubvectorType;

         TCT col1 = column( tmat_, 1UL );
         SubvectorType sv = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with column and non-matching subvector (different offset)
      {
         typedef blaze::DenseSubvector<TCT>  SubvectorType;

         TCT col1 = column( tmat_, 1UL );
         SubvectorType sv = subvector( col1, 1UL, 3UL );

         if( blaze::isSame( col1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, col1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Dense column:\n" << col1 << "\n"
                << "   Dense subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching columns on submatrices
      {
         typedef blaze::DenseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching columns on submatrices
      {
         typedef blaze::DenseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 0UL );
         ColumnType col2 = column( sm, 1UL );

         if( blaze::isSame( col1, col2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First column:\n" << col1 << "\n"
                << "   Second column:\n" << col2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching column subvectors on submatrices
      {
         typedef blaze::DenseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;
         typedef blaze::DenseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different size)
      {
         typedef blaze::DenseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;
         typedef blaze::DenseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 0UL, 3UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching column subvectors on submatrices (different offset)
      {
         typedef blaze::DenseSubmatrix<TMT>         SubmatrixType;
         typedef blaze::DenseColumn<SubmatrixType>  ColumnType;
         typedef blaze::DenseSubvector<ColumnType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 3UL, 2UL );
         ColumnType col1 = column( sm, 1UL );
         SubvectorType sv1 = subvector( col1, 0UL, 2UL );
         SubvectorType sv2 = subvector( col1, 1UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c min() function with the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c min() function used with the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testMinimum()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major min() function";

      initialize();

      // Computing the minimum of the 0th column
      {
         const int minimum = min( column( mat_, 0UL ) );

         if( minimum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 0th column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 1st column
      {
         const int minimum = min( column( mat_, 1UL ) );

         if( minimum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 1st column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 2nd column
      {
         const int minimum = min( column( mat_, 2UL ) );

         if( minimum != -3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 2nd column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -3\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 3rd column
      {
         const int minimum = min( column( mat_, 3UL ) );

         if( minimum != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 3rd column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -6\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 4th column
      {
         const int minimum = min( column( mat_, 4UL ) );

         if( minimum != -8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 4th column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -8\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major min() function";

      initialize();

      // Computing the minimum of the 0th column
      {
         const int minimum = min( column( tmat_, 0UL ) );

         if( minimum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 0th column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 1st column
      {
         const int minimum = min( column( tmat_, 1UL ) );

         if( minimum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 1st column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 2nd column
      {
         const int minimum = min( column( tmat_, 2UL ) );

         if( minimum != -3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 2nd column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -3\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 3rd column
      {
         const int minimum = min( column( tmat_, 3UL ) );

         if( minimum != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 3rd column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -6\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the minimum of the 4th column
      {
         const int minimum = min( column( tmat_, 4UL ) );

         if( minimum != -8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Minimum computation for 4th column failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -8\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c max() function with the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c max() function used with the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testMaximum()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major max() function";

      initialize();

      // Computing the maximum of the 0th column
      {
         const int maximum = max( column( mat_, 0UL ) );

         if( maximum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 0th column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 1st column
      {
         const int maximum = max( column( mat_, 1UL ) );

         if( maximum != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 1st column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 2nd column
      {
         const int maximum = max( column( mat_, 2UL ) );

         if( maximum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 2nd column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 3rd column
      {
         const int maximum = max( column( mat_, 3UL ) );

         if( maximum != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 3rd column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 4th column
      {
         const int maximum = max( column( mat_, 4UL ) );

         if( maximum != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 4th column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 10\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major max() function";

      initialize();

      // Computing the maximum of the 0th column
      {
         const int maximum = max( column( tmat_, 0UL ) );

         if( maximum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 0th column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 1st column
      {
         const int maximum = max( column( tmat_, 1UL ) );

         if( maximum != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 1st column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 2nd column
      {
         const int maximum = max( column( tmat_, 2UL ) );

         if( maximum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 2nd column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 3rd column
      {
         const int maximum = max( column( tmat_, 3UL ) );

         if( maximum != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 3rd column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Computing the maximum of the 4th column
      {
         const int maximum = max( column( tmat_, 4UL ) );

         if( maximum != 10 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Maximum computation for 4th column failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 10\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c subvector() function with the DenseColumn class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c subvector() function used with the DenseColumn class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void ClassTest::testSubvector()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major subvector() function";

      initialize();

      typedef blaze::DenseSubvector<CT>  SubvectorType;

      CT col1 = column( mat_, 1UL );
      SubvectorType sv = subvector( col1, 0UL, 4UL );

      if( sv[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator access failed\n"
             << " Details:\n"
             << "   Result: " << sv[1] << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }

      if( *sv.begin() != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *sv.begin() << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major subvector() function";

      initialize();

      typedef blaze::DenseSubvector<TCT>  SubvectorType;

      TCT col1 = column( tmat_, 1UL );
      SubvectorType sv = subvector( col1, 0UL, 4UL );

      if( sv[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator access failed\n"
             << " Details:\n"
             << "   Result: " << sv[1] << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }

      if( *sv.begin() != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *sv.begin() << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Initialization of all member matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function initializes all member matrices to specific predetermined values.
*/
void ClassTest::initialize()
{
   // Initializing the row-major dynamic matrix
   mat_.reset();
   mat_(1,1) =  1;
   mat_(0,2) = -2;
   mat_(2,2) = -3;
   mat_(1,3) =  4;
   mat_(2,3) =  5;
   mat_(3,3) = -6;
   mat_(0,4) =  7;
   mat_(1,4) = -8;
   mat_(2,4) =  9;
   mat_(3,4) = 10;

   // Initializing the column-major dynamic matrix
   tmat_.reset();
   tmat_(1,1) =  1;
   tmat_(0,2) = -2;
   tmat_(2,2) = -3;
   tmat_(1,3) =  4;
   tmat_(2,3) =  5;
   tmat_(3,3) = -6;
   tmat_(0,4) =  7;
   tmat_(1,4) = -8;
   tmat_(2,4) =  9;
   tmat_(3,4) = 10;
}
//*************************************************************************************************

} // namespace densecolumn

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running DenseColumn class test..." << std::endl;

   try
   {
      RUN_DENSECOLUMN_CLASS_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during DenseColumn class test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
