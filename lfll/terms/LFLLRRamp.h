/*
The MIT License (MIT)

Copyright (c) 2013 Nicolas Pauss

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef LFLLRRAMP_H
#define LFLLRRAMP_H

#include <lfll/engine/LFLLDefinitions.h>
#include <lfll/engine/LFLLMath.h>
#include <lfll/terms/LFLLBoundedTerm.h>


LFLL_BEGIN_NAMESPACE

/**
  * R Ramp term
  *
  * @f[
\renewcommand{\arraystretch}{2.25}
x:R \rightarrow  f(x) = \left \{
   \begin{array}{cc}
     1, & x \leq minLim \\
     \frac{\displaystyle x - minLim}{\displaystyle maxLim-minLim}, & minLim < x < maxLim \\
     0, & x \geq maxLim \\
   \end{array}
\right \}
  * @f]
  *
  @verbatim
           ------
          /
         /
        /
   -----
  @endverbatim
  */
class LFLLRRamp : public LFLLBoundedTerm
{
public:
    LFLLRRamp(scalar minLimit, scalar maxLimit)
        : LFLLBoundedTerm(minLimit, maxLimit)
        , m_invDifference(ONE_SCALAR / (maxLimit - minLimit))
    {}

    inline dom membership(scalar val) const
    {
        if (math::isLessOrEqualTo(val, m_minLimit)) {
            return MIN_DOM;
        } else if (math::isGreaterOrEqualTo(val, m_maxLimit)) {
            return MAX_DOM;
        }

        return math::scalarToDom((val - m_minLimit) * m_invDifference);
    }

private:
    scalar m_invDifference;
};

LFLL_END_NAMESPACE

#endif //LFLLRRAMP_H