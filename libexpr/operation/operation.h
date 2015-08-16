#pragma once

#include <type_traits>


#include "../expression/expression.h"
#include "../cloning/cloner.h"

namespace expression {
	namespace operation {
		class operation : public expression, public virtual cloning::cloneable<expression>  {
		public:
			operation() = default;
			~operation() = default;
		};
	};
};