// The libMesh Finite Element Library.
// Copyright (C) 2002-2015 Benjamin S. Kirk, John W. Peterson, Roy H. Stogner

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#ifndef LIBMESH_FIRST_ORDER_UNSTEADY_SOLVER_H
#define LIBMESH_FIRST_ORDER_UNSTEADY_SOLVER_H

#include "libmesh/unsteady_solver.h"

namespace libMesh
{
/**
 * Generic class from which first order UnsteadySolvers should subclass.
 *
 * Subclasses of this class are meant to solve problems of the form
 * \f[ M(u)\dot{u} = F(u)\f]
 *
 * This class is part of the new DifferentiableSystem framework,
 * which is still experimental.  Users of this framework should
 * beware of bugs and future API changes.
 *
 * \author Paul T. Bauman
 * \date 2015
 */
class FirstOrderUnsteadySolver : public UnsteadySolver
{
public:
  /**
   * Constructor. Requires a reference to the system
   * to be solved.
   */
  explicit
  FirstOrderUnsteadySolver (sys_type& s)
    : UnsteadySolver(s) {}

  /**
   * Destructor.
   */
  virtual ~FirstOrderUnsteadySolver (){}

  virtual unsigned int time_order() const libmesh_override
  { return 1; }
};

} // end namespace libMesh

#endif // LIBMESH_FIRST_ORDER_UNSTEADY_SOLVER_H