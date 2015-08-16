#pragma once

#include <memory>

#include "../cloning/cloneable.h"
#include "../cloning/cloner.h"

namespace expression {
	class expression : public virtual cloning::cloneable<expression> {
	public:
		expression();
		expression(const expression &_expression);
		expression(const std::unique_ptr<const expression> &_expression);

		virtual ~expression();

		virtual double compute(double arg) = 0;
		expression &derivative();

		expression &operator=(const expression &expression);

	protected:
		virtual std::unique_ptr<expression> compute_derivative() = 0;

	private:
		std::unique_ptr<expression> derivativeValue;
	};
};
