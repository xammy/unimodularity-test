#ifndef TU_SERIES_PARALLEL_H
#define TU_SERIES_PARALLEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <tu/element.h>
#include <tu/matrix.h>

typedef struct
{
  TU_ELEMENT element;   /**< Element that is removed. */
  TU_ELEMENT mate;      /**< Element is parallel to or in series with \ref element, or 0 for a zero row/column. */
} TU_SERIES_PARALLEL;

/**
 * \brief Finds all series or parallel elements of the ternary \p matrix.
 *
 * If \p isSorted is \c true, then the running time is linear in the number of rows + number of columns + number of
 * nonzeros of \p matrix.
 */

TU_EXPORT
TU_ERROR TUfindSeriesParallel(
  TU* tu,                           /**< \ref TU environment. */
  TU_CHRMAT* matrix,                /**< Sparse char matrix. */
  TU_SERIES_PARALLEL* operations,   /**< Array for storing the operations. Must be sufficiently large. */
  size_t* pnumOperations,           /**< Pointer for storing the number of operations. */  
  TU_SUBMAT** premainingSubmatrix,  /**< Pointer for storing the submatrix that remains. */
//   TU_SUBMAT** pwheelSubmatrix,      /**< Pointer for storing a submatrix representing a wheel. */
  bool isSorted                     /**< Whether the entries of \p matrix are sorted. */
);

#ifdef __cplusplus
}
#endif

#endif /* TU_SERIES_PARALLEL_H */
