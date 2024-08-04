#include "editor_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions about ll_text...
// append a line: add to the end of the linked list
ll_text *append_text(ll_text *list, char *text) {
	ll_text *new_node = malloc(sizeof(ll_text));
        
	new_node->text = strdup(text);
	
	new_node->next = NULL;

	if(list == NULL){
		return new_node;
	}
	
	ll_text *current = list;
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = new_node;
	
	return list;	
}

void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) {
	int count = 0;

	while(list != NULL){
		count++;
		list = list->next;
	}

	return count;
}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line
ll_text *insert_text(ll_text *list, char *text, int position) {
	ll_text *new_node = malloc(sizeof(ll_text));
	new_node->text = strdup(text);
	new_node->next = NULL;

	if(position == 0){
		new_node->next = list;
		return new_node;
	}

	ll_text *current = list;
	for(int i = 0; i < position - 1 && current != NULL; i++){
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;


	return list;
}

// delete a specific line: delete the ith entry in the linked list and return
// the new front of the linked list.
ll_text *delete_text(ll_text *list, int position) {
	if(list == NULL) {
		return NULL;
	}

	ll_text *current = list;
	if(position == 0){
		list = list->next;
		free(current->text);
		free(current);
		return list;
	}

	for(int i = 0; i < position - 1 && current->next != NULL; i++){
		current = current->next;
	}

	ll_text *temp = current ->next;
	current->next = temp->next;
	free(temp->text);
	free(temp);

	return list;
}

// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.
ll_text *replace_text(ll_text *list, char *text, int position) {
	ll_text *current = list;
	for(int i = 0; i < position && current != NULL; i++){
		current = current->next;
	}

	free(current->text);

	current->text = strdup(text);

	return list;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {
	if(list == NULL){
		return NULL;
	}

	ll_text *copy = NULL, *current_copy = NULL;

	for(ll_text *current = list; current != NULL; current = current->next){
		if(copy == NULL){
			copy = malloc(sizeof(ll_text));
			if(!copy) return NULL;
			copy->text = strdup(current->text);
			if(!copy->text){
				free(copy);
				return NULL;
			}
			copy->next = NULL;
			current_copy = copy; 
		} else {
			current_copy->next = malloc(sizeof(ll_text));
			if(!current_copy->next){
				ll_text *temp = copy; 
				while(temp) {
					ll_text *next = temp->next;
					free(temp->next);
					free(temp);
					temp = next;
				}
				return NULL;
			}
			current_copy = current_copy->next;
			current_copy->text = strdup(current->text);
			current_copy->next = NULL;
		}
	}
	return copy;

}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}

ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}

// Push a new state onto the stack that's an exact copy of the state currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack) {
	if(stack == NULL || stack ->lines == NULL){
		return stack;
	}

	ll_text *duplicate_text = duplicate_ll_text(stack->lines);

	ll_text_stack *new_node = malloc(sizeof(ll_text_stack));
	new_node->lines = duplicate_text;
	new_node->next = stack;

	return new_node;
}

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack) {
	ll_text_stack *new_node = malloc(sizeof(ll_text_stack));
	new_node->lines = NULL;
	new_node->next = stack;

	return new_node;
}

// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {
	if(stack == NULL){
		return NULL;
	}

	ll_text_stack *next = stack->next;


	ll_text *current = stack->lines;
	while(current != NULL){
		ll_text *next_text = current->next;
		free(current->text);
		free(current);
		current = next_text;
	}
	free(stack);

	return next;

}

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
