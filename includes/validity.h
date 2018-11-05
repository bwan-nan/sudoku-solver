#ifndef VALIDITY_H
# define VALIDITY_H

int     row_is_ok(int k, char **tab, int i);
int     column_is_ok(int k, char **tab, int i);
int     nonet_is_ok(int k, char **tab, int i, int j);

#endif
