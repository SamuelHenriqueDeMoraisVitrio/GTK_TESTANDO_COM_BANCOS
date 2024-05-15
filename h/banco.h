#ifndef __banco_h__
#define __banco_h__

#include "doTheWorld.h"
#ifdef __linux__
#elif _win32
#error "Sistema Incompativel"
#endif  // __linux__

#include "doTheWorld.h"
extern DtwNamespace dtw;

void newuser(DtwSchema *table, const char *label1, const char *label2, const char *label3) {
  DtwResource *user_colun = dtw.schema.new_insertion(table);

  dtw.resource.set_string_in_sub_resource(user_colun, "case1", label1);
  dtw.resource.set_string_in_sub_resource(user_colun, "case2", label2);
  dtw.resource.set_string_in_sub_resource(user_colun, "case3", label3);

  dtw.schema.commit(table);
}

#endif  // __banco_h__
