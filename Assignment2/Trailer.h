#pragma once

namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);
		Trailer(Trailer& trailer);
		~Trailer();

		unsigned int GetWeight() const;
		Trailer& operator=(Trailer& trailer);

	private:
		unsigned int mTrailerWeight;
	};
}