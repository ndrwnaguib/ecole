#pragma once

#include <ecole/scip/model.hpp>

namespace ecole {
namespace environment {

/**
 * A minimal state class that contains only a @ref scip::Model.
 *
 * Represent the state of an Markov Decision Process, and is passed along to extract
 * observations, rewards, etc.
 * Can safely be inherited from to defined mode specialized states.
 */
class DefaultState {
public:
	scip::Model model;

	virtual ~DefaultState() = default;
};

}  // namespace environment
}  // namespace ecole
