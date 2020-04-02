#include "ecole/reward/nlpiterations.hpp"

namespace ecole {
namespace reward {

auto NLPIterations::clone() const -> std::unique_ptr<RewardFunction> {
	return std::make_unique<NLPIterations>(*this);
}

void NLPIterations::reset(environment::State const& initial_state) {
	counter = SCIPgetNLPIterations(initial_state.model.get_scip_ptr());
}

Reward NLPIterations::get(environment::State const& state, bool done) {
	(void)done;
	auto reward = SCIPgetNLPIterations(state.model.get_scip_ptr()) - counter;
	counter += reward;
	return static_cast<double>(reward);
}

}  // namespace reward
}  // namespace ecole