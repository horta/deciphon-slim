#ifndef DB_READER_H
#define DB_READER_H

#include "lite_pack.h"
#include "model_prof.h"
#include "model_prof_typeid.h"

struct db_reader
{
  unsigned nprofiles;
  uint32_t *profile_sizes;
  enum prof_typeid prof_typeid;
  struct lip_file file;
};

enum rc db_reader_open(struct db_reader *db, FILE *fp);
void db_reader_close(struct db_reader *db);

enum rc db_reader_unpack_magic_number(struct db_reader *);
enum rc db_reader_unpack_prof_typeid(struct db_reader *,
                                     enum prof_typeid typeid);
enum rc db_reader_unpack_float_size(struct db_reader *);
enum rc db_reader_unpack_prof_sizes(struct db_reader *db);

#endif
