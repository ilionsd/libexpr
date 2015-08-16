#pragma once

#include <memory>

#include "../cloning/cloner.h"
#include "expression.h"


namespace expression {
	class constant : public expression, public virtual cloning::cloner<expression, constant> {
	public:
		static const constant zero;

		constant(int value) :
			value(value)
		{};
		constant(long long value) :
			value(value)
		{};
		constant(const constant &constant) :
			expression(constant),
			value(constant.value)
		{};
		constant(const std::unique_ptr<const constant> &constant) :
			expression(*constant),
			value(constant->value)
		{};

		operator long long();

		virtual double compute(double arg) override;

	protected:
		virtual std::unique_ptr<expression> compute_derivative() override;

	private:
		long long value;
	};
};