#pragma once

namespace libexpr {
	class cloneable
	{
	public:
		cloneable() = default;
		~cloneable() = default;

		virtual cloneable* clone() const = 0;

	private:

	};
}