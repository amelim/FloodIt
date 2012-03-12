/*
 * A constraint which requires two variables to be the same
 * Adapted from Frank Dellaert's BinaryAllDiff Factor 
 */

#pragma once

#include <gtsam2/discrete/DecisionTreeFactor.h>

namespace gtsam
{
    
    class BinaryNoDiff: public DiscreteFactor
    {
        DiscreteKey key1_, key2_;
        public:
            const DiscreteKey& key1() const { return key1_;}
            const DiscreteKey& key2() const { return key2_;}

            BinaryNoDiff(const DiscreteKey& key1, const DiscreteKey& key2,
                    const KeyOrdering& ord):
                        DiscreteFactor(ord.at(key1), ord.at(key2)), key1_(key1), key2_(key2) {}

            //print
            virtual void print(const std::string& s = " ") const
            {
                std::cout << s << ": BinaryNoDiff on " << key1() << " and " << key2() << std::endl;
            }

            //Calculate Value
            //Returns 1 if values for key1 and key 2 are the same, 0 otherwise
            virtual double operator()(const Values& values) const
            {
                return (double) (values.at(key1()) == values.at(key2()));
            }

		    /// Convert into a decisiontree
		    virtual operator DecisionTreeFactor() const {
			    DiscreteKeys keys = key1() & key2();
			    // It is important we reconstruct the mappping from DiscreteKey
			    // to Index here, or the resulting DecisionTreeFactor will be wrong.
			    // This is not an issue of the DecisionTree, but of Factors and Conditionals
			    // needing to play nice with gtsam/inference, which only handles Index :-(
			    KeyOrdering ordering;
			    insert(ordering)(key1(), keys_[0])(key2(), keys_[1]);
			    std::vector<double> table;
			    for (size_t i1 = 0; i1 < key1().cardinality(); i1++)
				    for (size_t i2 = 0; i2 < key2().cardinality(); i2++)
					    table.push_back(i1 != i2);
			    DecisionTreeFactor converted(keys, ordering, table);
			    return converted;
		    }

		    /// Multiply into a decisiontree
		    virtual DecisionTreeFactor operator*(const DecisionTreeFactor& f) const {
			    // TODO: can we do this more efficiently?
			    return DecisionTreeFactor(*this) * f;
		    }

		    /*
		    * Ensure Arc-consistency
		    * @param j domain to be checked
		    * @param domains all other domains
		    */
		    ///
		    bool ensureArcConsistency(size_t j, std::vector<Domain>& domains) const {
			    throw std::runtime_error("BinaryAllDiff::ensureArcConsistency not implemented");
		    }

		    /// Partially apply known values
		    virtual DiscreteFactor::shared_ptr partiallyApply(const Values&) const {
			    throw std::runtime_error("partiallyApply not implemented");
		    }
    
		    /// Partially apply known values, domain version
		    virtual DiscreteFactor::shared_ptr partiallyApply(const std::vector<Domain>&) const {
			    throw std::runtime_error("partiallyApply not implemented");
		    }
	};

} // namespace gtsam
