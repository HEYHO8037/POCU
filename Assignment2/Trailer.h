#pragma once

namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);
		Trailer(const Trailer& trailer);
		~Trailer();

		unsigned int GetWeight() const;
		Trailer& operator=(const Trailer& trailer);

	private:
		unsigned int mTrailerWeight = 0;
	};
}