#pragma once

#include "sum.h"

namespace libexpr {

	sum::sum(const expression *lhs, const expression *rhs) :
		binary_operation(lhs, rhs)
	{};

	sum::sum(const expression &lhs, const expression &rhs) :
		binary_operation(lhs, rhs)
	{};

	sum::sum(const sum *sum) :
		binary_operation(sum)
	{};

	sum::sum(const sum &sum) :
		binary_operation(sum)
	{};

	sum* sum::clone() const {
		sum* clone = new sum(this);
		return clone;
	};

	expression* sum::compute_derivative() {
		expression* res = (expression*)new sum(lhs->derivative(), rhs->derivative());
		return res;
	};

	double sum::operation(double lhsVal, double rhsVal) {
		return lhsVal + rhsVal;
	};


};