#pragma once

#include "multiplication.h"

namespace libexpr {

	multiplication::multiplication(const expression *lhs, const expression *rhs) :
		binary_operation(lhs, rhs)
	{};

	multiplication::multiplication(const expression &lhs, const expression &rhs) :
		binary_operation(lhs, rhs)
	{};

	multiplication::multiplication(const multiplication *multiplication) :
		binary_operation(multiplication)
	{};

	multiplication::multiplication(const multiplication &multiplication) :
		binary_operation(multiplication)
	{};

	multiplication* multiplication::clone() const {
		multiplication* clone = new multiplication(this);
		return clone;
	};

	expression* multiplication::compute_derivative() {
		expression& lhsMul = multiplication(lhs->derivative(), rhs);
		expression& rhsMul = multiplication(lhs, rhs->derivative());
		expression* res = (expression*) new sum(lhsMul, rhsMul);
		return res;
	};

	double multiplication::operation(double lhsVal, double rhsVal) {
		return lhsVal * rhsVal;
	};

};