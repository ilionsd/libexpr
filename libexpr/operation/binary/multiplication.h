#pragma once

#include <memory>

#include "../../cloning/cloner.h"
#include "../../expression/expression.h"
#include "binary_operation.h"
#include "sum.h"

namespace expression {
	namespace operation {
		namespace binary {
			class multiplication : public binary_operation, public cloning::cloner<expression, multiplication> {
			public:
				multiplication::multiplication(const expression &lhs, const expression &rhs) :
					binary_operation(lhs, rhs)
				{};
				multiplication::multiplication(const std::unique_ptr<const expression> &lhs, const std::unique_ptr<const expression> &rhs) :
					binary_operation(lhs, rhs)
				{};
				multiplication::multiplication(const multiplication &multiplication) :
					binary_operation(multiplication)
				{};
				multiplication::multiplication(const std::unique_ptr<const multiplication> &multiplication) :
					binary_operation(*multiplication)
				{};

				~multiplication() override = default;

			protected:
				std::unique_ptr<expression> compute_derivative() override;
				virtual double do_operation(double lhsVal, double rhsVal) override;
			};
		};
	};
};