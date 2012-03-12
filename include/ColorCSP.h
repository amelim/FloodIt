#pragma once

#include <gtsam2/discrete/DiscreteFactorGraph.h>
#include <gtsam2/discrete/SingleValue.h>
#include "BinaryNoDiff.h"

namespace gtsam {
    class ColorCSP : public DiscreteFactorGraph
    {

        public:
            ColorCSP(){}

            //Factor creation functions
            void addUnary(const DiscreteKey& key, size_t value,
                    const KeyOrdering& ord)
            {
                boost::shared_ptr < SingleValue
                        > factor(new SingleValue(key, value, ord));
                push_back(factor);
            }
            void addBinary(const DiscreteKey& key1, const DiscreteKey& key2,
                    const KeyOrdering& ord)
            {
                boost::shared_ptr < BinaryNoDiff
                        > factor(new BinaryNoDiff(key1, key2, ord));
                push_back(factor);
            }

            //Find the best total assignment
            sharedValues optimalAssignment() const; 

            //Arc-consistency ~ Approximate LP-Belief Propagation
            //void runArcConsistency(size_t cardinality, size_t nrIterations=10,
            //        bool print = false) const;
    };
}
