#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

typedef struct state state;

struct state
{
  int value;
};

state *state_new();
int    state_set(state *, int);
int    state_get(state *);
void   state_free(state *);

#endif /* STATE_H_INCLUDED */
