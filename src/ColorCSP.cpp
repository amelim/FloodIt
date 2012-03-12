/*
 * ColorCSP.cpp
 * CSP class for FloodIt
 * Andrew Melim
 */

#include "ColorCSP.h"
#include <gtsam2/discrete/DiscreteSequentialSolver.h>

namespace gtsam
{
    
    ColorCSP::sharedValues ColorCSP::optimalAssignment() const
    {
       	DiscreteSequentialSolver solver(*this);
		DiscreteBayesNet::shared_ptr chordal = solver.eliminate();
		sharedValues mpe = optimize(*chordal);
		return mpe; 
    }
}
