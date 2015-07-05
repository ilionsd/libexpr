#pragma once


#include "cloneable.h"

//#include "libexpr.h"

namespace libexpr {

	class expression : public cloneable {
	public:
		expression();
		expression(const expression& expression);
		expression(const expression* expression);

		virtual ~expression();

		expression* clone() const override = 0;

		virtual double compute(double arg) = 0;
		expression* derivative();

		expression& operator=(const expression& expression);

	protected:
		virtual expression* compute_derivative() = 0;

	private:
		expression* derivativeValue;
	};


};
