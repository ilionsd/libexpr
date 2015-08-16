#pragma once

#include <memory>
#include <type_traits>

#include "cloneable.h"

namespace expression {
	namespace cloning {
		template<typename base, typename derived>
		class cloner : public virtual cloneable<base>
		{
		public:
			virtual std::unique_ptr<base> clone() const override;
		};
	}
}