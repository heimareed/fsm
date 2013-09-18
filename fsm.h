#ifndef _FSM_H
#define _FSM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct fsm_branch {
	int event;
	int new_state;
	void *(*func)(void *);
	void *(*callback)(void *);
};

struct fsm_state {
	int state;
	int event_num;
	struct fsm_branch *branck;
};

struct fsm_t {
	int state_num;
	struct fsm_state *state_list;
	int init_state;
	int curr_state;
	int stop;
};

struct fsm_t *fsm_init(struct fsm_t *fsm, int state_num, int event_num, int init_state, int curr_state);
struct fsm_t *fsm_init_with_state(struct fsm_t *fsm, struct fsm_state *state, int state_num, int event_num, int init_state);
void fsm_release(struct fsm_t *fsm);
int fsm_run(struct fsm_t *fsm, int (*get_event)(void *), void *para, void *func_para, void *cb_para);
#endif
