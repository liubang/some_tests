//=====================================================================
//
// block_builder.h -
//
// Created by liubang on 2023/05/29 19:36
// Last Modified: 2023/05/29 19:36
//
//=====================================================================

#pragma once

#include "cpp/misc/sst/comparator.h"
#include "cpp/tools/binary.h"

#include <string>
#include <vector>

namespace playground::cpp::misc::sst {

/**
 * data block and index block builder
 */
class BlockBuilder {
public:
  BlockBuilder(const Comparator* comparator, int block_restart_interval);

  BlockBuilder(const BlockBuilder&) = delete;
  BlockBuilder& operator=(const BlockBuilder&) = delete;

  void add(const tools::Binary& key, const tools::Binary& val);

  tools::Binary finish();

  [[nodiscard]] std::size_t size() const;

  [[nodiscard]] bool empty() const { return buffer_.empty(); }

  void reset();

private:
  const Comparator* comparator_;
  bool finished_{false};
  int counter_;
  std::string buffer_;
  std::string last_key_;
  int block_restart_interval_;
  std::vector<uint32_t> restarts_;
};

}  // namespace playground::cpp::misc::sst
