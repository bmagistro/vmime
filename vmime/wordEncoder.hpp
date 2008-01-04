//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002-2008 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#ifndef VMIME_WORDENCODER_HPP_INCLUDED
#define VMIME_WORDENCODER_HPP_INCLUDED


#include "vmime/charset.hpp"


namespace vmime
{


class encoder;


/** Encodes words following RFC-2047.
  */

class wordEncoder
{
public:

	/** Available encodings for RFC-2047. */
	enum Encoding
	{
		ENCODING_AUTO,
		ENCODING_QP,
		ENCODING_B64
	};


	wordEncoder(const string& buffer, const charset& charset, const Encoding encoding = ENCODING_AUTO);


	/** Return the next chunk in the word.
	  *
	  * @param maxLength maximal length of the chunk
	  * @return next chunk, of maximal length 'maxLength' if possible
	  */
	const string getNextChunk(const string::size_type maxLength);

	/** Return the encoding used.
	  *
	  * @return encoding
	  */
	const Encoding getEncoding() const;

private:

	static const Encoding guessBestEncoding(const string& buffer, const charset& charset);

	void guessBestEncoding();


	string m_buffer;
	string::size_type m_pos;
	string::size_type m_length;

	bool m_simple;

	charset m_charset;
	Encoding m_encoding;

	ref <encoder> m_encoder;
};


} // vmime


#endif // VMIME_WORDENCODER_HPP_INCLUDED

