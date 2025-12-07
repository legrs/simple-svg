
/*******************************************************************************
*  The "New BSD License" : http://www.opensource.org/licenses/bsd-license.php  *
********************************************************************************

Copyright (c) 2010, Mark Turney
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include "simple_svg_1.0.0.hpp"
#include <iostream>

using namespace std;
using namespace svg;

int main(){
    cout << "hoge " << endl;
    Defs d1(Layout(Dimensions(0,0), Layout::BottomLeft));
    Group g1("g1", Layout(Dimensions(0,0), Layout::BottomLeft));
    Document doc("test.svg", Layout(Dimensions(100,100), Layout::BottomLeft));
    g1 << Circle("c1",Point(0,0), 80, Fill(Color::Red), Stroke(1, Color::Black));
    d1 << g1;
    doc << d1;
    doc << Use("g1",Point(50,50));
    doc.save();
    return 0;
}
