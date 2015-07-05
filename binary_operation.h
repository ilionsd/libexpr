#pragma once

#include <type_traits>

//#include "libexpr.h"
#include "expression.h"

namespace libexpr {

	class binary_operation : public expression {
	public:
		binary_operation(const expression *lhs, const expression *rhs);
		binary_operation(const expression &lhs, const expression &rhs);
		binary_operation(const binary_operation *binary_operation);
		binary_operation(const binary_operation &binaty_operation);

		binary_operation* clone() const override = 0;

		~binary_operation() override;

		double compute(double arg) override;

	protected:
		expression *lhs, *rhs;

		virtual double operation(double lhsVal, double rhsVal) = 0;
	};

	
};




