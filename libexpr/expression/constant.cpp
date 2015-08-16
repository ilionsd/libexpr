#pragma once

#include "constant.h"

namespace expression {
	const constant constant::zero = 0;

	std::unique_ptr<expression> constant::compute_derivative() {
		std::unique_ptr<expression> derivative = constant::zero.clone();
		return derivative;
	};

	
};