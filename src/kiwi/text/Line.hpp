// Copyright (c) 2010 Nicolas Silva
// All rights reserved.
//      Redistribution and use in source and binary forms, with or without
//      modification, are permitted provided that the following conditions are
//      met:
//      
//      * Redistributions of source code must retain the above copyright
//        notice, this list of conditions and the following disclaimer.
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following disclaimer
//        in the documentation and/or other materials provided with the
//        distribution.
//      * Neither the name of the  nor the names of its
//        contributors may be used to endorse or promote products derived from
//        this software without specific prior written permission.
//      
//      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//      "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//      LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//      A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//      OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//      SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//      LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//      DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//      THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//      OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#pragma once

#ifndef KIWI_TEXT_LINE_HPP
#define KIWI_TEXT_LINE_HPP

namespace kiwi{
namespace text{


	
class Line
{
public:
	virtual kiwi::int8_t operator[]( kiwi::int32_t pos ) const = 0;
	virtual kiwi::int8_t& operator[]( kiwi::int32_t pos ) = 0;
	inline kiwi::int8_t getChar(kiwi::int32_t pos) const { return (*this)[pos]; }
	inline kiwi::int8_t& getChar(kiwi::int32_t pos) { return (*this)[pos]; }
	virtual uint32_t size() const = 0;
	virtual kiwi::string str() const = 0;
	virtual void operator+=( char txt ) = 0;
	virtual void operator+=( char const* txt ) = 0;
	virtual void operator+=( kiwi::string txt ) = 0;
	virtual ~Line(){}

	bool operator==( const kiwi::text::Line& toComp) const
	{
		if( size() != toComp.size() ) return false;
		for(int i = 0; i < size(); ++i)
		{
			if( (*this)[i] != toComp[i] ) return false;
		}
		return true;
	}

};


}//namespace
}//namespace

#endif
