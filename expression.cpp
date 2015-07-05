#pragma once

#include "expression.h"


namespace libexpr {
	expression::expression() :
		derivativeValue(nullptr) {};

	expression::expression(const expression& expression) :
		derivativeValue(expression.derivativeValue->clone())
	{};

	expression::expression(const expression* expression) :
		derivativeValue(expression->derivativeValue->clone())
	{};

	expression::~expression() {
		delete derivativeValue;
	};

	expression* expression::derivative() {
		if (derivativeValue == nullptr) {
			derivativeValue = compute_derivative();
		}
		return derivativeValue;
	};

	expression& expression::operator=(const expression& other) {
		if (this != &other) {
			delete derivativeValue;
			derivativeValue = other.derivativeValue->clone();
		}
		return *this;
	};
};