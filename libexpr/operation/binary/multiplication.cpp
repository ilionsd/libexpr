#pragma once

#include "multiplication.h"

namespace expression {
	namespace operation {
		namespace binary {
			

			std::unique_ptr<expression> multiplication::compute_derivative() {
				expression& lhsMul = multiplication(lhs->derivative(), *rhs);
				expression& rhsMul = multiplication(*lhs, rhs->derivative());
				std::unique_ptr<expression> res(new sum(lhsMul, rhsMul));
				return res;
			};

			double multiplication::do_operation(double lhsVal, double rhsVal) {
				return lhsVal * rhsVal;
			};
		};
	};
};