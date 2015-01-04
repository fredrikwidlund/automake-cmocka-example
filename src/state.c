#include <stdlib.h>
#include "state.h"

state *state_new()
{
  state *s;

  s = malloc(sizeof *s);
  if (!s)
    return NULL;

  s->value = 0;

  return s;
}

int state_set(state *s, int value)
{
  if (value < 1 || value > 10)
    return -1;

  s->value = value;

  return 0;
}

int state_get(state *s)
{
  return s->value;
}

void state_free(state *s)
{
  free(s);
}
