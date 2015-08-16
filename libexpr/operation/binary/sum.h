#pragma once

#include <memory>

#include "../../cloning/cloner.h"
#include "../../expression/expression.h"
#include "binary_operation.h"

namespace expression {
	namespace operation {
		namespace binary {
			class sum : public binary_operation, public cloning::cloner<expression, sum>
			{
			public:
				sum(const expression &lhs, const expression &rhs) :
					binary_operation(lhs, rhs)
				{};
				sum(const std::unique_ptr<const expression> &lhs, const std::unique_ptr<const expression> &rhs) :
					binary_operation(lhs, rhs)
				{};
				sum(const sum &sum) :
					binary_operation(sum)
				{};
				sum(const std::unique_ptr<const sum> &sum) :
					binary_operation(*sum)
				{};
				
				~sum() override = default;

			protected:
				std::unique_ptr<expression> compute_derivative() override;
				virtual double do_operation(double lhsVal, double rhsVal) override;
			};
		};
	};
};


