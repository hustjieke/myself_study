// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
//
// WriteBatch holds a collection of updates to apply atomically to a DB.
//
// The updates are applied in the order in which they are added
// to the WriteBatch.  For example, the value of "key" will be "v3"
// after the following batch is written:
//
//    batch.Put("key", "v1");
//    batch.Delete("key");
//    batch.Put("key", "v2");
//    batch.Put("key", "v3");
//
// Multiple threads can invoke const methods on a WriteBatch without
// external synchronization, but if any of the threads may call a
// non-const method, all threads accessing the same WriteBatch must use
// external synchronization.

#ifndef STORAGE_LEVELDB_INCLUDE_WRITE_BATCH_H_
#define STORAGE_LEVELDB_INCLUDE_WRITE_BATCH_H_

#include <string>
#include "leveldb/status.h"

namespace leveldb {

class Slice;

// 原子更新(事务)leveldb提供了原子更新的功能.通过使用WriteBatch,
// 可以将多个操作绑定,使得多个操作在一个batch内完成.类似于关系型数据库中的事务.
// 同步写
// 默认情况下,leveldb的写是异步写(asynchronous).即其调用了write交给内核之后就直接返回.
// 由于磁盘速度很慢,内核会对write做一定的缓冲,在合适的时候存到磁盘中.
// 通常来说这种方式执行的效果很好.不过如果在数据存到磁盘前,主机掉电了,那数据就丢失了.
// 所以如果对数据很敏感,可以设置sync标志,强制操作系统写入磁盘中.(在write返回前,调用fsync或者fdatasync或msync)
// leveldb::WriteOptions write_options;write_options.sync = true;db->Put(write_options, ...);
// 由于磁盘的限制,同步是一个很慢的过程(参考上面的表格).考虑到效率,可以将多个写操作放在一个
// writebatch中,然后执行同步写.这样同步的cost就可以被分担到多个写操作中.
//
// (淘宝文)对若干数目key的write操作(put/delete)封装成WriteBatch.它会将userkey连同
// SequnceNumber和ValueType先做encode,然后做decode,将数据insert到指定的Handler
// (memtable)上面.上层的处理逻辑简洁,但encode/decode略有冗余. 
// WriteBatch encode之后,内部保存的数据格式:
// SequnceNumber(uint64)  count(uint32)  record0 ...... recordN 
// record组成: ValueType(char) key_len(varint32) key_data(key_len) value_len(varint32) value_data(value_len)
// 1) SequnceNumber: WriteBatch中开始使用的SequnceNumber.
// 2) count: 批量处理的record数量
// 3) record: 封装在WriteBatch内的数据.如果ValueType是kTypeValue,则后面有key和
//    value如果ValueType是kTypeDeletion,则后面只有key.
// 有关record的说明参见.cc文件中头部的注释
class WriteBatch {
 public:
  WriteBatch();
  ~WriteBatch();

  // Store the mapping "key->value" in the database.
  void Put(const Slice& key, const Slice& value);

  // If the database contains a mapping for "key", erase it.  Else do nothing.
  void Delete(const Slice& key);

  // Clear all updates buffered in this batch.
  void Clear();

  // Support for iterating over the contents of a batch.
  class Handler {
   public:
    virtual ~Handler();
    virtual void Put(const Slice& key, const Slice& value) = 0;
    virtual void Delete(const Slice& key) = 0;
  };
  Status Iterate(Handler* handler) const;

 private:
  friend class WriteBatchInternal;

  std::string rep_;  // See comment in write_batch.cc for the format of rep_

  // Intentionally copyable
};

}  // namespace leveldb

#endif  // STORAGE_LEVELDB_INCLUDE_WRITE_BATCH_H_
