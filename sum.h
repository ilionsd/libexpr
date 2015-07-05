#pragma once

//#include "libexpr.h"
#include "expression.h"
#include "binary_operation.h"

namespace libexpr {
	class sum : public binary_operation
	{
	public:
		sum(const expression *lhs, const expression *rhs);
		sum(const expression &lhs, const expression &rhs);
		sum(const sum *sum);
		sum(const sum &sum);
		~sum() override = default;

		sum *clone() const override;

	protected:
		expression *compute_derivative() override;
		virtual double operation(double lhsVal, double rhsVal) override;
	};

	


};


