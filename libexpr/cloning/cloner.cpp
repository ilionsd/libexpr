#include "cloner.h"

namespace expression {
	namespace cloning {
		template<typename base, typename derived>
		std::unique_ptr<base> cloner<base, derived>::clone() const
		{
			return std::unique_ptr<base>(new derived(static_cast<const derived &>(*this)));
		};
	}
}