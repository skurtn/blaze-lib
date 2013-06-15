//=================================================================================================
/*!
//  \file blaze/math/expressions/VecAbsExpr.h
//  \brief Header file for the VecAbsExpr base class
//
//  Copyright (C) 2011 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. This library is free software; you can redistribute
//  it and/or modify it under the terms of the GNU General Public License as published by the
//  Free Software Foundation; either version 3, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with a special
//  exception for linking and compiling against the Blaze library, the so-called "runtime
//  exception"; see the file COPYING. If not, see http://www.gnu.org/licenses/.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_EXPRESSIONS_VECABSEXPR_H_
#define _BLAZE_MATH_EXPRESSIONS_VECABSEXPR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/AbsExpr.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Base class for all vector absolute value expression templates.
// \ingroup math
//
// The VecAbsExpr class serves as a tag for all expression templates that implement a vector
// absolute value operation. All classes, that represent a vector absolute value operation
// and that are used within the expression template environment of the Blaze library have to
// derive from this class in order to qualify as vector absolute value expression template.
// Only in case a class is derived from the VecAbsExpr base class, the IsVecAbsExpr type
// trait recognizes the class as valid vector absolute value expression template.
*/
struct VecAbsExpr : private AbsExpr
{};
//*************************************************************************************************

} // namespace blaze

#endif
