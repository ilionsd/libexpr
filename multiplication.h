#pragma once

//#include "libexpr.h"
#include "expression.h"
#include "binary_operation.h"
#include "sum.h"

namespace libexpr {
	class multiplication : public binary_operation {
	public:
		multiplication(const expression *lhs, const expression *rhs);
		multiplication(const expression &lhs, const expression &rhs);
		multiplication(const multiplication *multiplication);
		multiplication(const multiplication &multiplication);

		multiplication* clone() const override;

		~multiplication() override = default;

	protected:
		expression *compute_derivative() override;
		virtual double operation(double lhsVal, double rhsVal) override;
	};

};