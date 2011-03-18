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


#include "PlainTextContainer.hpp"
#include <fstream>

namespace kiwi{
namespace text{	

PlainTextContainer::PlainTextContainer()
{
}


bool PlainTextContainer::loadFromFile(const kiwi::string& path){
  std::ifstream file( path.c_str() );
  if( file.is_open() ) {
    init( file );
    file.close();
    return true;
  }else{
    return false;
  }
}

bool PlainTextContainer::saveToFile(const kiwi::string& path){
  std::ofstream file( path.c_str() );
  if( file.is_open() ) {
    for(kiwi::uint32_t i = 0; i < nbLines(); ++i){
      file << line(i).str() << "\n"; // TODO
    }
    return true;
  }else{
    return false;
  }
}

Line& PlainTextContainer::line(kiwi::int32_t linePos)
{
//	ScopedBlockMacro( "PlainTextContainer::line" )
	// out of bounds...
	if(linePos >= nbLines() ) return *_lines.begin(); // TODO modulo
	//general case
	std::list<kiwi::text::PlainTextLine>::iterator it = _lines.begin();
	while( linePos-- > 0 ){ ++it; }
	return (*it);
}


const Line& PlainTextContainer::line(kiwi::int32_t lineNumber) const
{
//	ScopedBlockMacro( "PlainTextContainer::line" )
	// out of bounds...
	if(lineNumber >= nbLines() ) return *_lines.begin();
	//general case
	std::list<kiwi::text::PlainTextLine>::const_iterator it = _lines.begin();
	while( lineNumber-- > 0 ){ ++it; }
	return (*it);
}

void PlainTextContainer::insertLine(const PlainTextLine& toInsert
	, kiwi::int32_t linePos )
{
//	ScopedBlockMacro( "PlainTextContainer::insertLine" )
  if(nbLines() == 0) linePos = 0;
  if(linePos < 0){
    linePos = nbLines() + linePos;
  }
  if(linePos > nbLines() ){
		DEBUG_ONLY(
			Debug::error() << "required position is out of the container.\n"
				<< "( " << linePos << " > " << nbLines() << " )\n" 
				<< " Nothing is inserted.\n";
		)
		return;
	}
  
	//general case
	std::list<kiwi::text::PlainTextLine>::iterator it = _lines.begin();
	while( linePos > 0 ){
		++it;
		--linePos;
	}
	_lines.insert(it, toInsert);
}

void PlainTextContainer::insertLine(const Line& toInsert, kiwi::int32_t linePos)
{
	insertLine(PlainTextLine(toInsert.str()), linePos );
}

void PlainTextContainer::clear()
{
	_lines.clear();
}

void PlainTextContainer::append(std::istream& inputStream)
{
	while( !inputStream.eof() )
	{
		kiwi::string line;
		std::getline(inputStream, line);
		insertLine( PlainTextLine(line), nbLines() );
	}
}

void PlainTextContainer::append(const TextContainerInterface& toAppend)
{
	for(kiwi::uint32_t i = 0; i < toAppend.nbLines(); ++i)
	{
		insertLine( toAppend.line(i), nbLines() );
	}
}

void PlainTextContainer::init(std::istream& inputStream)
{
	clear();
	append(inputStream);
}

void PlainTextContainer::removeLine(kiwi::int32_t linePos)
{
//	ScopedBlockMacro( "PlainTextContainer::removeLine" )
	// out of bounds...
	if(linePos >= nbLines() ) return;
	
	//general case
	std::list<kiwi::text::PlainTextLine>::iterator it = _lines.begin();
	while( linePos > 1 ){
		++it;
		--linePos;
	}
	_lines.erase(it);
}

void PlainTextContainer::removeLines(kiwi::uint32_t firstLine, kiwi::uint32_t lastLine)
{
//	ScopedBlockMacro( "PlainTextContainer::removeLines" )
//	Debug::print()<<firstLine << " -> " << lastLine << endl();
	// out of bounds...
	if(firstLine >= nbLines() ) return;
	if(lastLine >= nbLines() ) lastLine = nbLines() - 1;

	int i = 0;
	std::list<kiwi::text::PlainTextLine>::iterator itf = _lines.begin();
	while( i++ < firstLine ){ ++itf;}
	std::list<kiwi::text::PlainTextLine>::iterator itl = itf;
	while( i++ < lastLine + 1 ){ ++itl; }
	++itl;
	_lines.erase(itf,itl);
}

/*
PlainTextContainer::lock_t PlainTextContainer::lock(kiwi::uint32_t firstLinePos
		, kiwi::uint32_t lastLinePos )
{

}			

void PlainTextContainer::unlock( PlainTextContainer::lock_t id )
{
	
}

bool PlainTextContainer::isLocked(kiwi::uint32_t firstLinePos, kiwi::uint32_t lastLinePos) const
{

}
*/

}// namespace
}// namespace
