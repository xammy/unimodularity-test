#ifndef TU_MATROID_H
#define TU_MATROID_H

#ifdef __cplusplus
extern "C" {
#endif

#include <tu/matrix.h>
#include <tu/graph.h>

typedef enum
{
  TU_DEC_ONE_SUM = 1,
  TU_DEC_TWO_SUM = 2,
  TU_DEC_THREE_SUM = 3,
  TU_DEC_R10 = 4,
  TU_DEC_TYPE_MASK = 7,
  TU_DEC_GRAPHIC = 8,
  TU_DEC_COGRAPHIC = 16,
  TU_DEC_REGULAR = 32
} TU_DEC_FLAGS;

typedef struct _TU_DEC
{
  TU_DEC_FLAGS flags; /**< Flags for this tree node. */
  int numChildren; /**< Number of children of this tree node. */
  struct _TU_DEC** children; /**< Array with pointers to children of this tree node. */
  TU_GRAPH *graph; /**< Graph corresponding to this tree node, or \c NULL.  */
  TU_GRAPH *cograph; /**< Cograph corresponding to this tree node, or \c NULL.  */
  TU_CHAR_MATRIX* matrix; /**< Binary matrix representing this tree node's matroid. */
  TU_CHAR_MATRIX* transpose; /**< Transpose of matrix representing this tree node's matroid. */
  int* rowLabels; /**< Array with row labels. */
  int* columnLabels; /**< Array with column labels. */
} TU_DEC;

/**
 * \brief Frees a decomposition tree (including the data of all its nodes.
 */
TU_EXPORT
void TUfreeDec(
  TU* tu,       /**< TU environment. */
  TU_DEC** dec  /**< Pointer to decomposition tree. */
);

/**
 * \brief Returns \c true iff this node is a leaf of the tree.
 */
TU_EXPORT
bool TUisDecLeaf(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns \c true if and only if tree node corresponds to a regular matroid.
 */
TU_EXPORT
bool TUisDecRegular(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns \c true if and only if tree node corresponds to a graphic matroid.
 */
TU_EXPORT
bool TUisDecGraphic(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns \c true if and only if tree node corresponds to a cographic matroid.
 */
TU_EXPORT
bool TUisDecCographic(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns \c k if tree node corresponds to a k-decomposition, and 0 otherwise.
 */
TU_EXPORT
char TUisDecSum(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns the number of matrix rows associated to this decomposition tree.
 */
TU_EXPORT
int TUgetDecNumRows(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns the number of matrix columns associated to this decomposition tree.
 */
TU_EXPORT
int TUgetDecNumColumns(
  TU_DEC* dec /**< Decomposition tree */
);


/**
 * \brief Returns the rank of the lower-left submatrix of this node of the tree.
 *
 * Only valid if either flag \ref TU_DEC_TWO_SUM or \ref TU_DEC_THREE_SUM is set.
 */
TU_EXPORT
int TUgetDecRankLowerLeft(
  TU_DEC* dec /**< Decomposition tree */
);

/**
 * \brief Returns the rank of the top-right submatrix of this node of the tree.
 *
 * Only valid if either flag \ref TU_DEC_TWO_SUM or \ref TU_DEC_THREE_SUM is set.
 */
TU_EXPORT
int TUgetDecRankTopRight(
  TU_DEC* dec /**< Decomposition tree */
);


#ifdef __cplusplus
}
#endif

#endif /* TU_MATROID_H */