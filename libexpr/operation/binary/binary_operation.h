#pragma once

#include <memory>

#include "../operation.h"

namespace expression {
	namespace operation {
		namespace binary {
			class binary_operation : public operation, public virtual cloning::cloneable<expression> {
			public:
				binary_operation(const expression &lhs, const expression &rhs) :
					lhs(lhs.clone()), rhs(rhs.clone())
				{};
				binary_operation(const std::unique_ptr<const expression> &lhs, const std::unique_ptr<const expression> &rhs) :
					lhs(lhs->clone()), rhs(rhs->clone())
				{};
				binary_operation(const binary_operation &binaty_operation) :
					lhs(binaty_operation.lhs->clone()), rhs(binaty_operation.rhs->clone())
				{};
				binary_operation(const binary_operation *binary_operation);
				
				~binary_operation() override = default;

				double compute(double arg) override;

			protected:
				std::unique_ptr<expression> lhs, rhs;
				virtual double do_operation(double lhsVal, double rhsVal) = 0;
			};
		};
	};
};



