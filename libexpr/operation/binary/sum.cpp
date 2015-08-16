#pragma once

#include "sum.h"

namespace expression {
	namespace operation {
		namespace binary {
			std::unique_ptr<expression> sum::compute_derivative() {
				std::unique_ptr<expression> res(new sum(lhs->derivative(), rhs->derivative()));
				return res;
			};

			double sum::do_operation(double lhsVal, double rhsVal) {
				return lhsVal + rhsVal;
			};
		};
	};
};