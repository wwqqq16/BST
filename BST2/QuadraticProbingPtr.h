        #ifndef _QUADRATIC_PROBING_PTR_H_
        #define _QUADRATIC_PROBING_PTR_H_

        #include "vector.h"
        #include "mystring.h"

        // QuadraticProbing Hash table class
        //
        // CONSTRUCTION: an initialization for ITEM_NOT_FOUND
        //               and an approximate initial size or default of 101
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // void remove( x )       --> Remove x
        // Hashable find( x )     --> Return item that matches x
        // void makeEmpty( )      --> Remove all items
        // int hash( String str, int tableSize )
        //                        --> Static method to hash strings

        template <class HashedObj>
        class QuadraticPtrHashTable
        {
          public:

            // explicit QuadraticPtrHashTable( const HashedObj & notFound, int size )
            //   : array( nextPrime( size ) ), ITEM_NOT_FOUND( notFound )
            // {
            //     makeEmpty( );
            // }

            // ~QuadraticPtrHashTable()
            // {
            //     for (int i = 0; i < array.size(); i++)
            //     {
            //         if (array[i] != NULL)
            //         {
            //             HashedObj* tmp = const_cast<HashedObj*>(array[i]);
            //             delete tmp;
            //             array[i] = NULL;
            //         }
            //     }
            // }


            // void insert( const HashedObj & x )
            // {
            //         // Insert x as active
            //     int currentPos = findPos( x );

            //     // -------------------------------------------------
            //     // if( isActive( currentPos ) )
            //     //     return;
            //     // -------------------------------------------------
            //     if (array[currentPos] != NULL)
            //         return;

            //     // -----------------------------------------------------------
            //     // array[ currentPos ] = HashEntry( x, ACTIVE );
            //     // -----------------------------------------------------------
            //     HashedObj* tmp = new HashedObj;
            //     *tmp = x;
            //     array[currentPos] = tmp;

            //         // Rehash; see Section 5.5
            //     if( ++currentSize > array.size( ) / 2 )
            //         rehash( );
            // }

            // void remove( const HashedObj & x )
            // {
            //     int currentPos = findPos( x );

            //     // ----------------------------------------------------------------
            //     // if( isActive( currentPos ) )
            //     //     array[ currentPos ].info = DELETED;
            //     // ----------------------------------------------------------------

            //     if (array[currentPos] != NULL)
            //     {
            //         if (array[currentPos] != NULL)
            //         {
            //             HashedObj* tmp = const_cast<HashedObj*>(array[currentPos]);
            //             delete tmp;
            //             array[currentPos] = NULL;
            //         }
            //     }
                    
            // }

            // const HashedObj & find( const HashedObj & x ) const
            // {
            //     int currentPos = findPos( x );
            //     // -----------------------------------------------------------------------------------
            //     // return isActive( currentPos ) ? array[ currentPos ].element : ITEM_NOT_FOUND;
            //     // -----------------------------------------------------------------------------------

            //     return (array[currentPos] != NULL) ? *(array[currentPos]) : ITEM_NOT_FOUND;
            // }

            // void makeEmpty( )
            // {
            //     currentSize = 0;
            //     for( int i = 0; i < array.size( ); i++ )
            //     // --------------------------------------------------------------------------------------
            //         // array[ i ].info = EMPTY;
            //     // --------------------------------------------------------------------------------------
            //     {
            //         array[i] = NULL;
            //     }
                    
            // }

            // const QuadraticPtrHashTable<HashedObj> & operator=( const QuadraticPtrHashTable<HashedObj> & rhs )
            // {
            //     if( this != &rhs )
            //     {
            //         array = rhs.array;
            //         currentSize = rhs.currentSize;
            //     }
            //     return *this;
            // }

            explicit QuadraticPtrHashTable( const HashedObj & notFound, int size = 101 );
            QuadraticPtrHashTable( const QuadraticPtrHashTable & rhs )
              : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ),
                array( rhs.array ), currentSize( rhs.currentSize ) { }
            
            ~QuadraticPtrHashTable();

            const HashedObj & find( const HashedObj & x ) const;

            void makeEmpty( );
            void insert( const HashedObj & x );
            void remove( const HashedObj & x );

            const QuadraticPtrHashTable & operator=( const QuadraticPtrHashTable & rhs );


// -------------------------------------------------------------------
            // enum EntryType { ACTIVE, EMPTY, DELETED };
// -------------------------------------------------------------------

          private:
          // ---------------------------------------------------------------------------------------
            // struct HashEntry
            // {
            //     HashedObj element;
            //     EntryType info;

            //     HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
            //       : element( e ), info( i ) { }
            // };
          // ----------------------------------------------------------------------------------------

            vector<const HashedObj*> array;
            int currentSize;
            const HashedObj ITEM_NOT_FOUND;
            
            // bool isPrime( int n ) const
            // {
            //     if( n == 2 || n == 3 )
            //         return true;

            //     if( n == 1 || n % 2 == 0 )
            //         return false;

            //     for( int i = 3; i * i <= n; i += 2 )
            //         if( n % i == 0 )
            //             return false;

            //     return true;
            // }

            // int nextPrime( int n ) const
            // {
            //     if( n % 2 == 0 )
            //         n++;

            //     for( ; !isPrime( n ); n += 2 )
            //         ;

            //     return n;
            // }

            // void rehash( )
            // {
            //     vector<const HashedObj*> oldArray = array;

            //         // Create new double-sized, empty table
            //     array.resize( nextPrime( 2 * oldArray.size( ) ) );
            //     for( int j = 0; j < array.size( ); j++ )
            //     // --------------------------------------------------------------------------------
            //         // array[ j ].info = EMPTY;
            //     // --------------------------------------------------------------------------------
            //         array[j] = NULL;

            //         // Copy table over
            //     currentSize = 0;
            //     for( int i = 0; i < oldArray.size( ); i++ )
            //     // --------------------------------------------------------------------------------
            //         // if( oldArray[ i ].info == ACTIVE )
            //             // insert( oldArray[ i ].element );
            //     // --------------------------------------------------------------------------------
            //         if (oldArray[i] != NULL)
            //         {
            //             insert(*oldArray[i]);
            //         }
            // }

            // int findPos( const HashedObj & x ) const
            // {
            //     int collisionNum = 0;
            //     int currentPos = hash( x, array.size( ) );

            //     // ---------------------------------------------------------------------------------
            //     // while( array[ currentPos ].info != EMPTY &&
            //     //        array[ currentPos ].element != x )
            //     // ---------------------------------------------------------------------------------
            //     while ((array[currentPos] != NULL) && (*(array[currentPos]) != x))
            //     {
            //         currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
            //         if( currentPos >= array.size( ) )
            //             currentPos -= array.size( );
            //     }

            //     return currentPos;
            // }

            // bool isActive( int currentPos ) const
            // {
            //     return array[ currentPos ].info == ACTIVE;
            // }

            // int hash( const string & key, int tableSize ) const
            // {
            //     int hashVal = 0;

            //     for( int i = 0; i < key.length( ); i++ )
            //         hashVal = 37 * hashVal + key[ i ];

            //     hashVal %= tableSize;
            //     if( hashVal < 0 )
            //         hashVal += tableSize;

            //     return hashVal;
            // }

            // int hash( int key, int tableSize ) const
            // {
            //     if( key < 0 ) key = -key;
            //     return key % tableSize;
            // }





            bool isPrime( int n ) const;
            int nextPrime( int n ) const;
            // bool isActive( int currentPos ) const;
            int findPos( const HashedObj & x ) const;
            int hash( const string & key, int tableSize ) const;
            int hash( int key, int tableSize ) const;
            void rehash( );
        };

        //#include "QuadraticProbingPtr.cpp"
        #endif
