#include <stdio.h>

#include "h/doTheWorld.h"
DtwNamespace dtw;

void insert(DtwSchema *tab, const char *col1, const char *col2, const char *col3, const char *col4,
            const char *col5) {
  DtwResource *tabtab = dtw.schema.new_insertion(tab);

  dtw.resource.get_string_from_sub_resource(tabtab, "col1", col1);
  dtw.resource.get_string_from_sub_resource(tabtab, "col2", col2);
  dtw.resource.get_string_from_sub_resource(tabtab, "col3", col3);
  dtw.resource.get_string_from_sub_resource(tabtab, "col4", col4);
  dtw.resource.get_string_from_sub_resource(tabtab, "col5", col5);

  dtw.schema.commit(tab);
}

int main() {
  dtw = newDtwNamespace();

  DtwResource *banco = dtw.resource.newResource("Banco");

  if (banco == NULL) {
    printf("\n\tErro\n");
    return 1;
  }

  DtwSchema *table1 = dtw.resource.sub_schema(banco, "table1");

  dtw.schema.add_primary_key(table1, "col1");
  dtw.schema.add_primary_key(table1, "col2");
  dtw.schema.add_primary_key(table1, "col3");

  insert(table1, "Coluna1", "Coluna2", "Coluna3", "Coluna4", "Coluna5");

  //dtw.resource.free(banco);
}
