#include "astl\container\vector.hpp"
#include <algorithm>
#include <exception>


namespace anotherSTL
{
	template<typename T>
	void vector<T>::construct(size_type capacity)
	{
		_capacity_ = capacity;
		_data_ = new T[_capacity_];
		_size_ = 0;
	}

	// ctor.
	template<typename T>
	vector<T>::vector()
	{		
		construct(DEFAULT_VECTOR_SIZE);
	}

	template<typename T>
	vector<T>::vector(size_type n, const value_type& val)
	{ 
		construct(n);

		for (size_type i = 0; i < _size_; ++i)
		{
			_data_[i] = val;
		}
		this->_size_ = n;
	}

	template<typename T>
	vector<T>::vector(size_type capacity)
	{
		construct(capacity);
	}

	template<typename T>
	vector<T>::vector(const vector& v)
	{		
		construct(v._capacity_;);

		for (size_type i = 0; i < _size_; ++i)
		{
			_data_[i] = v[i];
		}	
		_size_ = v._size_;
	}

	// TODO: this can definitely be improved depending on InputIterator type. Do it later after ite is created. 
	template<typename T>
	template<typename InputIterator>
	vector<T>::vector(InputIterator first, InputIterator second)
	{
		// calculater size between the pair;
		size_type s =  distance(first, second);
		
		construct(s);		
		
		for (InputIterator curr = first, size_type i = 0; i < s; ++i, ++curr )
		{
			_data_[i] = *curr;			
			++this->_size_;
		}
	}

	template<typename T>
	void vector<T>::swap(vector& x)
	{
		size_type t_size = x._size_;
		size_type t_cap = x._capacity_;
		size_type t_data = x._data_;

		x._size_ = this->_size_;
		x._capacity_ = this->_capacity_;
		x._data_ = this->_data_;

		this->_size_ = t_size;
		this->_capacity_ = t_cap;
		this->_data_ = t_data;
	}

	template<typename T>
	vector<T>& vector<T>::operator= (const vector& x)
	{
		vector<T> t(x);
		this->swap(t);
		return *this;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::begin()
	{
		return &_data_[0];
	}

	template<typename T>
	typename vector<T>::const_iterator vector<T>::begin() const
	{
		return &_data_[0];
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::end()
	{
		return &_data_[this->_size_-1];
	}

	template<typename T>
	typename vector<T>::const_iterator vector<T>::end() const
	{
		return &_data_[this->_size_-1];
	}


	template<typename T>
	void vector<T>::destruct()
	{
		_capacity_ = 0;
		_size_ = 0;
		delete _data_;
		// TODO: this is in fact incorrect, should use the allocator's destructor
		// delete _data_;
	}

	template<typename T>
	vector<T>::~vector()
	{
		destruct();
	}


	//capacity
	template<typename T>
	typename vector<T>::size_type vector<T>::size() const
	{
		return _size_;
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::capacity() const
	{
		return _capacity_;
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::max_size() const
	{
		//TODO: not sure "This is the maximum potential size the container can reach due to known system or library implementation limitations"
		return 1073741823;
	}

	template<typename T>
	void vector<T>::resize(size_type n, value_type val)
	{		
		size_type c = this->capacity;
		this->_size_ = n;
		if (n <= c)
		{			
			for (size_type i = 0; i < n; ++i)
			{
				this->_data_[i] = val;
			}
		}
		else
		{			
			vecotr x(n, val);
			this->swap(x);
		}
	}

	template<typename T>
	bool vector<T>::empty() const
	{
		return this->_size_ == 0;
	}

	template<typename T>
	void vector<T>::reserve(size_type n)
	{
		if (this->_capacity_ < n)
		{		
			vector x(n);
			for (size_type i = 0 < i < this->_size_; ++i)
			{
				x._data_[i] = this->_data_[i];
			}
			this->swap(x);
		}
	}

	template<typename T>
	typename vector<T>::reference vector<T>::operator[] (size_type n)
	{
		return const_cast<reference>((static_cast<const vector<T>&>(this)).operator[](n));
	}

	template<typename T>
	typename vector<T>::const_reference vector<T>::operator[] (size_type n) const
	{
		return this->_data_[n];
	}
	
	template<typename T>
	typename vector<T>::reference vector<T>::at(size_type n)
	{
		return const_cast<reference>(static_cast<const vector<T>&>(this).at(n));
	}

	template<typename T>
	typename vector<T>::const_reference vector<T>::at(size_type n) const
	{
		if (n >= this->_size_)
		{
			throw std::out_of_range("index out of range ");
		}
		else
		{
			return this->operator[](n);
		}
	}

	template<typename T>
	typename vector<T>::reference vector<T>::back()
	{
		return const_cast<reference>(static_cast<const vector<T>&>(this).back());
	}

	template<typename T>
	typename vector<T>::const_reference vector<T>::back() const
	{
		return this->_data_[size() - 1];
	}

	template<typename T>
	void vector<T>::assign(size_type n, const value_type& val)
	{
		destruct();
		construct(n);
		vector v(n, val);
		this->swap(v);
	}

	template<typename T>
	template<typename InputItereator> 
	void vector<T>::assign(InputItereator first, InputItereator last)
	{
		destruct();
		construct(n);
		vector v(first, last);
		this->swap(v);
	}

	template<typename T>
	typename vector<T>::size_type vector<T>::available_space() const
	{
		return this->_capacity_ - this->_size_;
	}

	template<typename T>
	bool vector<T>::has_space(size_type n )
	{
		return available_space() >= n;
	}

	template<typename T>
	bool vector<T>::has_space(size_type n) const
	{
		return available_space() >= n;
	}

	template<typename T>
	int vector<T>::last_elem_index()
	{
		return size-1;
	}

	template<typename T>
	int vector<T>::last_elem_index() const
	{
		return size - 1;
	}

	template<typename T>
	void vector<T>::reallocate(size_type n) const
	{
		destruct();
		construct(n);
	}

	template<typename T>
	void vector<T>::ensure_enough_more_space(size_type n ) const
	{
		if (!has_space(n))
		{
			vector v(size()*DEFAULT_VECTOR_INCREMENTAL_RATIO);
			v.assign(this->begin(), this->end());
			this->swap(v);
		}
	}

	template<typename T>
	void vector<T>::push_back(const value_type& val)
	{
		ensure_enough_more_space(1);
		this->_data_[last_elem_index()] = val;		
	}

	template<typename T>
	void vector<T>::pop_back()
	{
		// undefine behaviour: if size is empty, behaviour is undefined
		-- this->_size_;
	}


	template<typename T>
	void vector<T>::move_tail(iterator from, size_type steps)
	{
		for (iterator i = this->end(); i != from; --i)
		{
			*(i + steps) = *i;
		}
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::insert(iterator position, const value_type& val)
	{
		ensure_enough_more_space(1);
		move_tail(position, 1);
		*(position )= value;
		++_size_£»
	}

	template<typename T>
	void vector<T>::insert(iterator postion, size_type n, const value_type& val)
	{
		ensure_enough_more_space(n);
		move_tail(position, n);
		// TODO: refactor to commond code wtih the constructor
		for (size_type i = 0; i < n; ++i)
		{
			*(position + i) = val;
		}
	}

	template<typename T>
	template<typename InputIterator>
	void vector<T>::insert(iterator position, InputIterator first, InputIterator last)
	{
		size_type n = distance(first, last);
		ensure_enough_more_space(n);
		move_tail(position, n);
		// TODO: refactor to commond code wtih the constructor
		for (InputIterator curr = first, size_type i = 0; i < n; ++i, ++first)
		{
			*(position+i) = *curr;
		}
	}
}