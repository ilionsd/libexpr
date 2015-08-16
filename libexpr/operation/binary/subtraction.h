#pragma once

#include "../../cloning/cloner.h"
#include "../../expression/expression.h"
#include "binary_operation.h"

namespace expression {
	namespace operation {
		namespace binary {
			class subtraction:	public binary_operation, cloning::cloner<expression, subtraction>
			{
			public:
				subtraction::subtraction(const expression &lhs, const expression &rhs) :
					binary_operation(lhs, rhs)
				{};
				subtraction::subtraction(const std::unique_ptr<const expression> &lhs, const std::unique_ptr<const expression> &rhs) :
					binary_operation(lhs, rhs)
				{};
				subtraction::subtraction(const subtraction &subtraction) :
					binary_operation(subtraction)
				{};
				subtraction::subtraction(const std::unique_ptr<const subtraction> &subtraction) :
					binary_operation(*subtraction)
				{};

				~subtraction() override = default;

			protected:
				std::unique_ptr<expression> compute_derivative() override;
				virtual double do_operation(double lhsVal, double rhsVal) override;
			};
		};
	};
};

