#pragma once

#include <memory>

#include "../../cloning/cloner.h"
#include "../../expression/expression.h"
#include "binary_operation.h"


namespace expression {
	namespace operation {
		namespace binary {
			class division : public binary_operation, public cloning::cloner<expression, division> {
			public:
				division::division(const expression &lhs, const expression &rhs) :
					binary_operation(lhs, rhs)
				{};
				division::division(const std::unique_ptr<const expression> &lhs, const std::unique_ptr<const expression> &rhs) :
					binary_operation(lhs, rhs)
				{};
				division::division(const division &division) :
					binary_operation(division)
				{};
				division::division(const std::unique_ptr<const division> &division) :
					binary_operation(*division)
				{};

				~division() override = default;

			protected:
				std::unique_ptr<expression> compute_derivative() override;
				virtual double do_operation(double lhsVal, double rhsVal) override;
			};
		};
	};
};