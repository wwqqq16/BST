#include "QuadraticProbingPtr.h"

template <class HashedObj>
QuadraticPtrHashTable<HashObj>::QuadraticPtrHashTable( const HashedObj & notFound, int size )
  : array( nextPrime( size ) ), ITEM_NOT_FOUND( notFound )
{
    makeEmpty( );
}

template <class HashedObj>
QuadraticPtrHashTable<HashObj>::~QuadraticPtrHashTable()
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != NULL)
        {
            HashedObj* tmp = const_cast<HashedObj*>(array[i]);
            delete tmp;
            array[i] = NULL;
        }
    }
}

template <class HashedObj>
void QuadraticPtrHashTable<HashObj>::insert( const HashedObj & x )
{
        // Insert x as active
    int currentPos = findPos( x );

    // -------------------------------------------------
    // if( isActive( currentPos ) )
    //     return;
    // -------------------------------------------------
    if (array[currentPos] != NULL)
        return;

    // -----------------------------------------------------------
    // array[ currentPos ] = HashEntry( x, ACTIVE );
    // -----------------------------------------------------------
    HashedObj* tmp = new HashedObj;
    *tmp = x;
    array[currentPos] = tmp;

        // Rehash; see Section 5.5
    if( ++currentSize > array.size( ) / 2 )
        rehash( );
}

template <class HashedObj>
void QuadraticPtrHashTable<HashObj>::remove( const HashedObj & x )
{
    int currentPos = findPos( x );
    // ----------------------------------------------------------------
    // if( isActive( currentPos ) )
    //     array[ currentPos ].info = DELETED;
    // ----------------------------------------------------------------
    if (array[currentPos] != NULL)
    {
        if (array[currentPos] != NULL)
        {
            HashedObj* tmp = const_cast<HashedObj*>(array[currentPos]);
            delete tmp;
            array[currentPos] = NULL;
        }
    }
                
}

template <class HashedObj>
const HashedObj & QuadraticPtrHashTable<HashObj>::find( const HashedObj & x ) const
{
    int currentPos = findPos( x );
    // -----------------------------------------------------------------------------------
    // return isActive( currentPos ) ? array[ currentPos ].element : ITEM_NOT_FOUND;
    // -----------------------------------------------------------------------------------
    return (array[currentPos] != NULL) ? *(array[currentPos]) : ITEM_NOT_FOUND;
}

template <class HashedObj>
void QuadraticPtrHashTable<HashObj>::makeEmpty( )
{
    currentSize = 0;
    for( int i = 0; i < array.size( ); i++ )
    // --------------------------------------------------------------------------------------
        // array[ i ].info = EMPTY;
    // --------------------------------------------------------------------------------------
    {
        array[i] = NULL;
    }
        
}

template <class HashedObj>
const QuadraticPtrHashTable<HashObj>::QuadraticPtrHashTable<HashedObj> & operator=( const QuadraticPtrHashTable<HashedObj> & rhs )
{
    if( this != &rhs )
    {
        array = rhs.array;
        currentSize = rhs.currentSize;
    }
    return *this;
}

template <class HashedObj>
bool QuadraticPtrHashTable<HashObj>::isPrime( int n ) const
{
    if( n == 2 || n == 3 )
        return tru
    if( n == 1 || n % 2 == 0 )
        return fals
    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return fals
    return true;
}

template <class HashedObj>
int QuadraticPtrHashTable<HashObj>::nextPrime( int n ) const
{
    if( n % 2 == 0 )
        n+
    for( ; !isPrime( n ); n += 2 )
    
    return n;
}

template <class HashedObj>
void QuadraticPtrHashTable<HashObj>::rehash( )
{
    vector<const HashedObj*> oldArray = arra
        // Create new double-sized, empty table
    array.resize( nextPrime( 2 * oldArray.size( ) ) );
    for( int j = 0; j < array.size( ); j++ )
    // --------------------------------------------------------------------------------
        // array[ j ].info = EMPTY;
    // --------------------------------------------------------------------------------
        array[j] = NUL
        // Copy table over
    currentSize = 0;
    for( int i = 0; i < oldArray.size( ); i++ )
    // --------------------------------------------------------------------------------
        // if( oldArray[ i ].info == ACTIVE )
            // insert( oldArray[ i ].element );
    // --------------------------------------------------------------------------------
        if (oldArray[i] != NULL)
        {
            insert(*oldArray[i]);
        }
}

template <class HashedObj>
int QuadraticPtrHashTable<HashObj>::findPos( const HashedObj & x ) const
{
    int collisionNum = 0;
    int currentPos = hash( x, array.size( ) 
    // ---------------------------------------------------------------------------------
    // while( array[ currentPos ].info != EMPTY &&
    //        array[ currentPos ].element != x )
    // ---------------------------------------------------------------------------------
    while ((array[currentPos] != NULL) && (*(array[currentPos]) != x))
    {
        currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
        if( currentPos >= array.size( ) )
            currentPos -= array.size( );
    }

    return currentPos;
}

template <class HashedObj>
int QuadraticPtrHashTable<HashedObj>::hash( const string & key, int tableSize ) const
{
    int hashVal = 
    for( int i = 0; i < key.length( ); i++ )
        hashVal = 37 * hashVal + key[ i 
    hashVal %= tableSize;
    if( hashVal < 0 )
        hashVal += tableSiz
    return hashVal;
}

template <class HashedObj>
int QuadraticPtrHashTable<HashObj>::hash( int key, int tableSize ) const
{
    if( key < 0 ) key = -key;
    return key % tableSize;
}

