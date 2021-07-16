/////////////////////////////////////////////////////////////////////////////
//
// BSD 3-Clause License
//
// Copyright (c) 2019, The Regents of the University of California
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "flute.h"
#include "pdrev.h"
#include "opendb/db.h"

namespace ord {
class OpenRoad;
}

namespace stt {

using utl::Logger;

class SteinerTreeBuilder
{
 public:
  SteinerTreeBuilder();
  ~SteinerTreeBuilder() = default;

  void init(odb::dbDatabase* db, Logger* logger);

  Tree buildSteinerTree(std::vector<int> x,
                       std::vector<int> y,
                       int flute_accuracy,
                       int drvr_index);
  Tree buildSteinerTree(odb::dbNet* net,
                       std::vector<int> x,
                       std::vector<int> y,
                       int flute_accuracy,
                       int drvr_index);
  void freeTree(Tree tree);
  float getAlpha() const { return alpha_; }
  void setAlpha(float alpha) { alpha_ = alpha; }
  float getNetAlpha(odb::dbNet* net) const;
  void addAlphaForNet(odb::dbNet* net, float alpha) { net_alpha_map_[net] = alpha; }

 private:
  float alpha_;
  std::map<odb::dbNet*, float> net_alpha_map_;

  Logger* logger_;
  odb::dbDatabase* db_;
};

}  // namespace stt
