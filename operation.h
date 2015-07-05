#pragma once

#include <type_traits>
#include "binary_operation.h"

namespace libexpr {
	namespace operation {
		template<class T>
		static class binary
		{
		public:
			typedef std::enable_if<std::is_base_of<binary_operation, T>::value, T>::type binary_operation_class;

			static binary_operation_class apply(const expression *lhs, const expression *rhs);
			static double evaluate(double lhs, double rhs);
		};

		/*
		template<sum> sum operation::binary::apply(const expression *lhs, const expression *rhs) {
			sum res(lhs, rhs);
			return res;
		};
		
		template<multiplication> multiplication binary::apply(const expression *lhs, const expression *rhs) {
			multiplication res(lhs, rhs);
			return res;
		};
		*/

	};
};