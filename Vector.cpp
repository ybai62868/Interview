#include<iostream>
"https://github.com/fookwood/fkcode/network"
template<class Object>
class Vector{
private:
	int theSize; //元素的个数
	int theCapacity; //容量
	Object *objects; //指向new分配的资源
public:
	explicit Vector( int initSize = 0 ):
		theSize( initSize ),theCapacity( initSize + SPACE_CAPACITY ){
		objects = new Object[ theCapacity ];
	}//用explicit避免隐式类型转换
	Vector( const Vector & rhs ):objects( NULL ){
		operator=( rhs );
	}//copy constructor
	~Vector(){
		delete [] objects;
	}

	const Vector & operator= ( const Vector & rhs ){
		if( this != &rhs ){//如果是本身的话就不用再操作了
			delete [] objects;
			theSize = rhs.size();
			theCapacity = rhs.capacity();

			objects = new Object[ capacity() ];
			for( int k = 0; k < theSize; k++ )//拷贝元素 				 			objects[k] = rhs.objects[k]; 		 		} 		 		return *this; 	 	}// above,the "big three" 	 	void resize( int newSize ){ 		 		if( newSize > theCapacity )
			reserve( newSize*2 + 1 ); //
		theSize = newSize;
	}//每次空间不够的时候,就重新获得2倍于当前容量的空间,+1是为了防止0的情况

	void reserve( int newCapacity ){
		if( newCapacity < theSize ) return;

		Object *oldArray = objects;
		objects = new Object[ newCapacity ];
		for( int k = 0; k < theSize; k++ )
			objects[k] = oldArray[k];
		theCapacity = newCapacity;
		delete [] oldArray;
	}//获取新的空间,拷贝,释放旧的
//[]操作符,non-const和const版的..
	Object & operator[] ( int index ) { return objects[ index ]; }
	const Object & operator[] ( int index ) const { return objects[ index ]; }

	bool empty() const { return size() == 0; }
	int size() const { return theSize; }
	int capacity() const { return theCapacity; }

	void push_back( const Object & x ){
		if( theSize == theCapacity )
			reserve( 2*theCapacity + 1 );
		objects[ theSize++ ] = x;
	}//插入元素

	void pop_back() { theSize--; }
	const Object & back() const { return objects[ theSize-1 ]; }

	typedef Object * iterator;//用原生指针替代迭代器
	typedef const Object * const_iterator;

	iterator begin() { return &objects[0]; }
	const_iterator begin() const { return &objects[0]; }
	iterator end()	 { return &objects[ theSize ]; }
	const_iterator end()   const { return &objects[ theSize ]; }

	enum{ SPACE_CAPACITY = 4 };//初始容量
};

int main() {
//进行简单的测试
	Vector V;
	for( int i = 0; i < 100; i++ )
		V.push_back( i );

	for( Vector::iterator it = V.begin(); it != V.end(); it++ )
		std::cout << *it << std::endl;

	const Vector v( V );
	for( Vector::const_iterator it = V.begin();
			it != V.end(); it++ )
		std::cout << *it << std::endl;

	return 0;
}
