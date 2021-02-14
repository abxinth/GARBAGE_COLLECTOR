#include<assert.h>
#define STACK_MAX 256
enum ObjectType{
	OBJ_INT,
	OBJ_PAIR
};
typedef struct sObject{
	enum ObjectType type;
	union{
	int value;
	struct{
		struct sObject* head;
		struct sObject* tail;
	};
	};
}Object;
typedef struct{
	enum Object* stack[STACK_MAX];
	int stackSize;
}VM;
VM *newVM(){
	VM* vm = malloc(sizeof(VM));
	vm->stackSize = 0;
	return vm;

}
void push(VM* vm,enum Object* value){
	assert(vm->stackSize < STACK_MAX);
	vm->stack[vm->stackSize++] = value;
}
Object* pop(VM *vm){
	assert(vm->stackSize >0);
	return vm->stack[--vm->stackSize];
}
Object* newObject(VM* vm,enum ObjectType type){
	Object* object = malloc(sizeof(Object));
	object->type = type;
	return object;
}
void pushInt(VM* vm,int intValue){
	Object* object = newObject(vm,OBJ_INT);
	object->value = intValue;
	push(vm,object);
}
Object* pushPair(VM* vm){
	Object* objet = newObject(vm, OBJ_PAIR);
	object->tail = pop(vm);
	object->head = pop(vm);
	push(vm,object);
	return object;
}

int main(){


return 0;
}
