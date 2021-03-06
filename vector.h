#ifndef _CVECTOR_H_
#define _CVECTOR_H_

#include <string.h>
#include <stdlib.h>

#define VECTOR_DEFAULT_CAPACITY 32
#define VECTOR_RESIZE_FACTOR 2

#define vector_t(Ty) vector_##Ty

#define vector_template(Ty)						\
									\
	typedef Ty vector_##Ty##_value_type;				\
									\
	typedef struct s_vector_##Ty##_internal vector_##Ty;		\
	typedef struct s_vector_##Ty##_members vector_##Ty##_members_t;	\
									\
	struct s_vector_##Ty##_members					\
	{								\
	    void	(*assign)(vector_##Ty*, size_t, Ty);		\
		Ty*	(*at)(vector_##Ty*, size_t);			\
	    	Ty*	(*front)(vector_##Ty*);				\
		Ty*	(*back)(vector_##Ty*);				\
		Ty*	(*data)(vector_##Ty*);				\
		Ty*	(*begin)(vector_##Ty*);				\
		const Ty* (*cbegin)(vector_##Ty*);			\
		Ty*	(*end)(vector_##Ty*);				\
		const Ty* (*cend)(vector_##Ty*);			\
		int	(*empty)(vector_##Ty*);				\
		size_t	(*size)(vector_##Ty*);				\
		size_t	(*max_size)(vector_##Ty*);			\
		void	(*reserve)(vector_##Ty*, size_t);		\
		size_t	(*capacity)(vector_##Ty*);			\
		void	(*shrink_to_fit)(vector_##Ty*);			\
		void	(*clear)(vector_##Ty*);				\
		void	(*erase)(vector_##Ty*, Ty*);			\
		void    (*push_back)(vector_##Ty*, Ty);			\
		void	(*pop_back)(vector_##Ty*);			\
		void    (*resize)(vector_##Ty*, size_t);		\
		void	(*swap)(vector_##Ty*, vector_##Ty*);		\
		void	(*_delete)(vector_##Ty*);			\
	};								\
									\
	struct s_vector_##Ty##_internal					\
	{								\
		Ty *data;						\
		size_t size, capacity;					\
		const vector_##Ty##_members_t *members;			\
	};								\
									\
	void	assign_##Ty(vector_##Ty*, size_t, Ty);			\
	Ty*	at_##Ty(vector_##Ty*, size_t);				\
	Ty*	front_##Ty(vector_##Ty*);				\
	Ty*	back_##Ty(vector_##Ty*);				\
	Ty*	data_##Ty(vector_##Ty*);				\
	Ty*	begin_##Ty(vector_##Ty*);				\
	const Ty* cbegin_##Ty(vector_##Ty*);				\
	Ty*	end_##Ty(vector_##Ty*);					\
	const Ty* cend_##Ty(vector_##Ty*);				\
	int	empty_##Ty(vector_##Ty*);				\
	size_t	size_##Ty(vector_##Ty*);				\
	size_t	max_size_##Ty(vector_##Ty*);				\
	void	reserve_##Ty(vector_##Ty*, size_t);			\
	size_t	capacity_##Ty(vector_##Ty*);				\
	void	shrink_to_fit_##Ty(vector_##Ty*);			\
	void	clear_##Ty(vector_##Ty*);				\
	void	erase_##Ty(vector_##Ty*, Ty*);				\
	void    push_back_##Ty(vector_##Ty*, Ty);			\
	void	pop_back_##Ty(vector_##Ty*);				\
	void    resize_##Ty(vector_##Ty*, size_t);			\
	void	swap_##Ty(vector_##Ty*, vector_##Ty*);			\
	void	delete_##Ty(vector_##Ty*);				\
									\
	static const vector_##Ty##_members_t				\
	vector_##Ty##_member_functions =				\
	{								\
		&assign_##Ty,						\
		&at_##Ty,						\
		&front_##Ty,						\
		&back_##Ty,						\
		&data_##Ty,						\
		&begin_##Ty,						\
		&cbegin_##Ty,						\
		&end_##Ty,						\
		&cend_##Ty,						\
		&empty_##Ty,						\
		&size_##Ty,						\
		&max_size_##Ty,						\
		&reserve_##Ty,						\
		&capacity_##Ty,						\
		&shrink_to_fit_##Ty,					\
		&clear_##Ty,						\
		&erase_##Ty,						\
		&push_back_##Ty,					\
		&pop_back_##Ty,						\
		&resize_##Ty,						\
		&swap_##Ty,						\
		&delete_##Ty				\
	};								\
									\
	void assign_##Ty(vector_##Ty *_this, size_t count, Ty value)	\
	{								\
	        resize_##Ty(_this, count);				\
									\
		for (int i = 0; i < count; i++)				\
			_this->data[i] = value;				\
	}								\
									\
	Ty* at_##Ty(vector_##Ty *_this, size_t index)			\
	{								\
		return &_this->data[index];				\
	}								\
									\
	Ty* front_##Ty(vector_##Ty *_this)				\
	{								\
		return _this->data;					\
	}								\
									\
	Ty* back_##Ty(vector_##Ty *_this)				\
	{								\
		return _this->data + _this->size - 1;			\
	}								\
									\
	Ty* data_##Ty(vector_##Ty *_this)				\
	{								\
		return _this->data;					\
	}								\
									\
	Ty* begin_##Ty(vector_##Ty *_this)				\
	{								\
		return _this->data;					\
	}								\
									\
	const Ty* cbegin_##Ty(vector_##Ty *_this)			\
	{								\
		return (const Ty*)(_this->data);			\
	}								\
									\
	Ty* end_##Ty(vector_##Ty *_this)				\
	{								\
		return _this->data + _this->size;			\
	}								\
									\
	const Ty* cend_##Ty(vector_##Ty *_this)				\
	{								\
		return (const Ty*)(_this->data + _this->size);		\
	}								\
									\
	int empty_##Ty(vector_##Ty *_this)				\
	{								\
		return _this->size == 0;				\
	}								\
									\
	size_t size_##Ty(vector_##Ty *_this)				\
	{								\
		return _this ? _this->size : 0;				\
	}								\
									\
	size_t max_size_##Ty(vector_##Ty *_this)			\
	{								\
		return (unsigned int)(-1) / sizeof(Ty);			\
	}								\
									\
	void reserve_##Ty(vector_##Ty *_this, size_t new_cap)		\
	{								\
		if (_this && _this->capacity < new_cap)			\
		{							\
			Ty *tmp = (Ty*)realloc(				\
				_this->data, 				\
				new_cap*sizeof(Ty));			\
			if (!tmp) 					\
				return; 				\
			_this->data = tmp; 				\
			_this->capacity = new_cap;			\
		}							\
	}								\
									\
	size_t capacity_##Ty(vector_##Ty *_this)			\
	{								\
		return _this ? _this->capacity : 0;			\
	}								\
									\
	void shrink_to_fit_##Ty(vector_##Ty *_this)			\
	{								\
		if (_this && _this->capacity > _this->size)		\
		{							\
			Ty *tmp = (Ty*)realloc(				\
				_this->data,				\
				_this->size*sizeof(Ty));		\
			if (!tmp) 					\
				return; 				\
			_this->data = tmp; 				\
			_this->capacity = _this->size;			\
		}							\
	}								\
									\
	void clear_##Ty(vector_##Ty *_this)				\
	{								\
		_this->size = 0;					\
	}								\
									\
	void erase_##Ty(vector_##Ty *_this, Ty *it)			\
	{								\
		if (!_this || !*it) return; 				\
		if (it >= _this->data &&				\
		    it < _this->data + _this->size)			\
		{							\
			memmove(					\
				it, (Ty*)(it+1),			\
				_this->data + _this->size - it);  	\
			_this->size--;					\
		}							\
	}								\
									\
	void push_back_##Ty(vector_##Ty *_this, Ty value)		\
	{								\
		if (!_this) return; 					\
		if (_this->capacity <= _this->size)			\
		{							\
			reserve_##Ty(					\
				_this,					\
				_this->capacity*VECTOR_RESIZE_FACTOR);	\
		}							\
		_this->data[_this->size] = value;			\
		_this->size++;						\
	}								\
									\
	void pop_back_##Ty(vector_##Ty *_this)				\
	{								\
		if (_this && _this->size) _this->size--;		\
	}								\
									\
	void resize_##Ty(vector_##Ty *_this, size_t new_size)		\
	{								\
		if (!_this) return; 					\
		if (_this->capacity < new_size)				\
			reserve_##Ty(_this, new_size);			\
		_this->size = new_size;					\
	} 								\
									\
	void swap_##Ty(vector_##Ty *_this, vector_##Ty *other)		\
	{								\
		if (!_this || !other) return;				\
	 								\
		void *tmp_data	= (void*)(_this->data);			\
		size_t tmp_size = _this->size;				\
		size_t tmp_cap	= _this->capacity;			\
									\
		_this->data	= (Ty*)(other->data);			\
		_this->size	= other->size;				\
		_this->capacity = other->capacity;			\
									\
		other->data	= (Ty*)tmp_data;			\
		other->size	= tmp_size;				\
		other->capacity = tmp_cap;				\
	}								\
									\
	vector_##Ty *new_vector_##Ty()					\
	{								\
		vector_##Ty *vec = 					\
			(vector_##Ty*)malloc(sizeof(vector_##Ty));	\
		if (vec == 0)						\
			return 0; 					\
		vec->size	= 0;					\
		vec->capacity	= VECTOR_DEFAULT_CAPACITY;		\
		vec->members	= &vector_##Ty##_member_functions;	\
		vec->data	= (Ty*)malloc(VECTOR_DEFAULT_CAPACITY *	\
					sizeof(Ty));			\
									\
		return vec;						\
	}								\
									\
	void delete_##Ty(vector_##Ty *_this)				\
	{								\
		if (_this)						\
		{							\
			if (_this->data) 				\
				free(_this->data);			\
			free(_this);					\
		}							\
	}								\

#define concat(a,b)        a ## b

#define vec_new(_Ty)           concat(new_, _Ty)()
#define vec_delete(v)          v->members->_delete(v);v=0

#define vec_at(a,b)            a->members->at(a,b)
#define vec_get(a,b)           *at(a,b)
#define vec_assign(a,b,c)      a->members->assign(a,b,c)
#define vec_push_back(a,b)     a->members->push_back(a,b)
#define vec_pop_back(a)        a->members->push_back(a)
#define vec_clear(a)           a->members->clear(a)
#define vec_resize(a,b)        a->members->resize(a,b)
#define vec_size(a)            a->members->size(a)
#define vec_capacity(a)        a->members->capacity(a)
#define vec_max_size(a)        a->members->max_size(a)
#define vec_reserve(a,b)       a->members->reserve(a,b)
#define vec_resize(a,b)        a->members->resize(a,b)
#define vec_front(a)           a->members->front(a)
#define vec_back(a)            a->members->back(a)	
#define vec_shrink_to_fit(a)   a->members->shrink_to_fit(a);
#define vec_empty(a)           a->members->empty(a)
#define vec_swap(a,b)          a->members->swap(a,b)
#define vec_erase(a,b)         a->members->erase(a,b)
#define vec_begin(a)           a->members->begin(a)
#define vec_cbegin(a)          a->members->cbegin(a)
#define vec_end(a)             a->members->end(a)
#define vec_cend(a)            a->members->cend(a)

#define vec_iterator(T)        concat(T, _value_type*)

#endif /* _CVECTOR_H_ */
