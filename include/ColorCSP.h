#pragma once

#include <gtsam2/discrete/DiscreteFactorGraph.h>
#include <gtsam2/discrete/SingleValue.h>

namespace gtsam {
    class ColorCSP : public DiscreteFactorGraph
    {

        public:
            ColorCSP(){}

            //Factor creation functions
            void addUnary(const DiscreteKey& key, size_t value,
                    const KeyOrdering& ord);
            void addBinary(const DiscreteKey& key1, const DiscreteKey& key2,
                    const KeyOrdering& ord);


            //Find the best total assignment
            sharedValues optimalAssignment() const; 

            //Arc-consistency ~ Approximate LP-Belief Propagation
            //void runArcConsistency(size_t cardinality, size_t nrIterations=10,
            //        bool print = false) const;
    };
}
