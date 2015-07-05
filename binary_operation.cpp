#pragma once

#include "binary_operation.h"

namespace libexpr {
	binary_operation::binary_operation(const expression *lhs, const expression *rhs) :
		lhs(lhs->clone()), rhs(rhs->clone())
	{};

	binary_operation::binary_operation(const expression &lhs, const expression &rhs) :
		binary_operation(&lhs, &rhs)
	{};

	binary_operation::binary_operation(const binary_operation *binary_operation) :
		binary_operation(binary_operation->lhs, binary_operation->rhs)
	{};

	binary_operation::binary_operation(const binary_operation &binary_operation) :
		binary_operation(binary_operation.lhs, binary_operation.rhs)
	{};

	binary_operation::~binary_operation() {
		delete lhs;
		delete rhs;
	};

	double binary_operation::compute(double  arg) {
		double lhsVal = lhs->compute(arg);
		double rhsVal = rhs->compute(arg);
		double res = operation(lhsVal, rhsVal);
		return res;
	};
};