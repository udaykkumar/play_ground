#pragma once
#include <iostream>
namespace  ds 
{

	bool is_subsequence( std::string subseq, std::string seq, size_t subseq_len, size_t seq_len)
	{

		/// if there is no subsequence then its part of everything
		if ( subseq_len == 0 )
			return true;

		/// if there is no sequence it can not include any subseq
		if ( seq_len == 0 )
			return false;

		if ( subseq[ subseq_len-1 ] == seq[ seq_len-1 ] )
			return is_subsequence( subseq, seq, subseq_len-1, seq_len-1);
		else
			return is_subsequence( subseq, seq, subseq_len, seq_len-1  );
	}

	bool is_subsequence( std::string subseq, std::string seq )
	{
		return is_subsequence( subseq, seq, subseq.size(), seq.size() );
	}
} //  ds
