#pragma once

#include "binary_operation.h"

namespace expression {
	namespace operation {
		namespace binary {
			double binary_operation::compute(double  arg) {
				double lhsVal = lhs->compute(arg);
				double rhsVal = rhs->compute(arg);
				double res = do_operation(lhsVal, rhsVal);
				return res;
			};
		};
	};
};