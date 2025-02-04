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

/**
 * @file Contrast.hpp
 * @brief Header file for a Nd contrast Filter.
 * @author Nicolas Silva (email: nical.silva@gmail.com  twitter: @nicalsilva)
 * @version 0.1
 */


#pragma once
#ifndef KIWI_IMAGE_CONTRAST_HPP
#define KIWI_IMAGE_CONTRAST_HPP

#include "kiwi/generic/IterativeFilter.hpp"
#include "kiwi/generic/ArrayIterator.hpp"
#include "kiwi/core/Tags.hpp"

namespace kiwi{
namespace image{

template<typename TValueType, unsigned int TDimension>
class Contrast : public IterativeFilter< AbstractArrayContainer< TValueType, TDimension > >
{
public:
// -----------------------------------------------------------------------------
	typedef TValueType ValueType;
	typedef AbstractArrayContainer<TValueType, TDimension> InputType;
// -----------------------------------------------------------------------------
	Contrast();
	
	void preProcess();
	
	void processFragment(
		kiwi::generic::ArrayConstIterator<TValueType>* in
		, kiwi::generic::ArrayIterator<TValueType>* out  );
		
	kiwi::Tags readerInputTags(portIndex_t index);
	kiwi::Tags writerInputTags(portIndex_t index);
	kiwi::string readerInputName(portIndex_t index);
	
protected:
	TValueType _pivot;
	TValueType _strength;
	
};


}// namespace
}// namespace

#include "Contrast.ih"

#endif
