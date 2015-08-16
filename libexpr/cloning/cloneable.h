#pragma once

#include <memory>
#include <type_traits>

namespace expression {
	namespace cloning {
		template<typename base>
		class cloneable
		{
		public:
			cloneable() = default;
			~cloneable() = default;

			virtual std::unique_ptr<base> clone() const = 0;

		private:
			cloneable &operator=(const cloneable &);
		};
	}
}