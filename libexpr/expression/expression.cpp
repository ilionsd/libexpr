#pragma once

#include "expression.h"

namespace expression {
	expression::expression() :
		derivativeValue(nullptr) {};

	expression::expression(const expression& _expression) :
		derivativeValue(_expression.clone())
	{};

	expression::expression(const std::unique_ptr<const expression> &_expression) :
		expression(*_expression)
	{};

	expression::~expression() {
	};

	expression& expression::derivative() {
		if (derivativeValue == nullptr) {
			derivativeValue = compute_derivative();
		}
		return (*derivativeValue);
	};

	expression& expression::operator=(const expression& other) {
		if (this != &other) {
			derivativeValue = other.derivativeValue->clone();
		}
		return (*this);
	};
};