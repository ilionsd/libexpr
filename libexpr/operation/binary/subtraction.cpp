
#include "subtraction.h"

namespace expression {
	namespace operation {
		namespace binary {
			

			std::unique_ptr<expression> subtraction::compute_derivative() {
				std::unique_ptr<expression> res(new subtraction(lhs->derivative(), rhs->derivative()));
				return res;
			};

			double subtraction::do_operation(double lhsVal, double rhsVal) {
				return lhsVal - rhsVal;
			};
		};
	};
};
