#pragma once

#include <optional>

#include <xtensor/xtensor.hpp>

#include "ecole/observation/abstract.hpp"
#include "ecole/utility/sparse-matrix.hpp"
#include "ecole/scip/model.hpp"

namespace ecole::observation {

class MilpBipartiteObs {
public:
	using value_type = double;

	static inline std::size_t constexpr n_variable_features = 5;
	enum struct VariableFeatures : std::size_t {
		objective = 0,
		is_type_binary,            // One hot encoded
		is_type_integer,           // One hot encoded
		is_type_implicit_integer,  // One hot encoded
		is_type_continuous,        // One hot encoded
	};
	static inline std::size_t constexpr n_constraint_features = 1;
    enum struct ConstraintFeatures : std::size_t {
		/** Static features */
		bias = 0,
	};

	xt::xtensor<value_type, 2> variable_features;
	xt::xtensor<value_type, 2> constraint_features;
	utility::coo_matrix<value_type> edge_features;
};

class MilpBipartite : public ObservationFunction<std::optional<MilpBipartiteObs>> {
public:
	MilpBipartite(bool use_normalization = false) : normalize{use_normalization}  {}

	std::optional<MilpBipartiteObs> extract(scip::Model& model, bool done) override;
    
private:
    bool normalize = true;
};

}  // namespace ecole::observation