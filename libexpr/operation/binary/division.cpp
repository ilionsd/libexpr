#pragma once

#include "division.h"
#include "subtraction.h"
#include "multiplication.h"

namespace expression {
	namespace operation {
		namespace binary {


			std::unique_ptr<expression> division::compute_derivative() {
				expression& minuend = multiplication(lhs->derivative(), *rhs);
				expression& subtrahend = multiplication(*lhs, rhs->derivative());
				expression& numerator = subtraction(minuend, subtrahend);
				//-- Добавить знаменатель --
				std::unique_ptr<expression> res(new division(lhs->derivative(), rhs->derivative()));
				return res;
			};

			double division::do_operation(double lhsVal, double rhsVal) {
				return lhsVal / rhsVal;
			};
		};
	};
};