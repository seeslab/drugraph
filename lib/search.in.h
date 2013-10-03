/* A GNU-like <search.h>.

   Copyright (C) 2007-2010 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef _GL_SEARCH_H

#if __GNUC__ >= 3
@PRAGMA_SYSTEM_HEADER@
#endif

/* The include_next requires a split double-inclusion guard.  */
#if @HAVE_SEARCH_H@
# @INCLUDE_NEXT@ @NEXT_SEARCH_H@
#endif

#ifndef _GL_SEARCH_H
#define _GL_SEARCH_H


/* The definitions of _GL_FUNCDECL_RPL etc. are copied here.  */

/* The definition of _GL_ARG_NONNULL is copied here.  */

/* The definition of _GL_WARN_ON_USE is copied here.  */


#if @GNULIB_TSEARCH@
# if @REPLACE_TSEARCH@
#  if !(defined __cplusplus && defined GNULIB_NAMESPACE)
#   define tsearch rpl_tsearch
#   define tfind rpl_tfind
#   define tdelete rpl_tdelete
#   define twalk rpl_twalk
#   define tdestroy rpl_tdestroy
#  endif
# endif

/* See <http://www.opengroup.org/susv3xbd/search.h.html>,
       <http://www.opengroup.org/susv3xsh/tsearch.html>
   for details.  */

# if !@HAVE_TSEARCH@
typedef enum
{
  preorder,
  postorder,
  endorder,
  leaf
}
VISIT;
# endif

# ifdef __cplusplus
extern "C" {
# endif
typedef int (*_gl_search_compar_fn) (const void *, const void *);
typedef void (*_gl_search_action_fn) (const void *, VISIT, int);
typedef void (*_gl_search_free_fn) (void *__nodep);
# ifdef __cplusplus
}
# endif

/* Searches an element in the tree *VROOTP that compares equal to KEY.
   If one is found, it is returned.  Otherwise, a new element equal to KEY
   is inserted in the tree and is returned.  */
# if @REPLACE_TSEARCH@
_GL_FUNCDECL_RPL (tsearch, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar)
                  _GL_ARG_NONNULL ((1, 2, 3)));
_GL_CXXALIAS_RPL (tsearch, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar));
# else
#  if !@HAVE_TSEARCH@
_GL_FUNCDECL_SYS (tsearch, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar)
                  _GL_ARG_NONNULL ((1, 2, 3)));
#  endif
_GL_CXXALIAS_SYS (tsearch, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar));
# endif
_GL_CXXALIASWARN (tsearch);

/* Searches an element in the tree *VROOTP that compares equal to KEY.
   If one is found, it is returned.  Otherwise, NULL is returned.  */
# if @REPLACE_TSEARCH@
_GL_FUNCDECL_RPL (tfind, void *,
                  (const void *key, void *const *vrootp,
                   _gl_search_compar_fn compar)
                  _GL_ARG_NONNULL ((1, 2, 3)));
_GL_CXXALIAS_RPL (tfind, void *,
                  (const void *key, void *const *vrootp,
                   _gl_search_compar_fn compar));
# else
#  if !@HAVE_TSEARCH@
_GL_FUNCDECL_SYS (tfind, void *,
                  (const void *key, void *const *vrootp,
                   _gl_search_compar_fn compar)
                  _GL_ARG_NONNULL ((1, 2, 3)));
#  endif
/* Need to cast, because on Cygwin 1.5.x systems, the second parameter is
                                         void **vrootp.  */
_GL_CXXALIAS_SYS_CAST (tfind, void *,
                       (const void *key, void *const *vrootp,
                        _gl_search_compar_fn compar));
# endif
_GL_CXXALIASWARN (tfind);

/* Searches an element in the tree *VROOTP that compares equal to KEY.
   If one is found, it is removed from the tree, and its parent node is
   returned.  Otherwise, NULL is returned.  */
# if @REPLACE_TSEARCH@
_GL_FUNCDECL_RPL (tdelete, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar)
                  _GL_ARG_NONNULL ((1, 2, 3)));
_GL_CXXALIAS_RPL (tdelete, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar));
# else
#  if !@HAVE_TSEARCH@
_GL_FUNCDECL_SYS (tdelete, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar)
                  _GL_ARG_NONNULL ((1, 2, 3)));
#  endif
_GL_CXXALIAS_SYS (tdelete, void *,
                  (const void *key, void **vrootp,
                   _gl_search_compar_fn compar));
# endif
_GL_CXXALIASWARN (tdelete);

/* Perform a depth-first, left-to-right traversal of the tree VROOT.
   The ACTION function is called:
     - for non-leaf nodes: 3 times, before the left subtree traversal,
       after the left subtree traversal but before the right subtree traversal,
       and after the right subtree traversal,
     - for leaf nodes: once.
   The arguments passed to ACTION are:
     1. the node; it can be casted to a 'const void * const *', i.e. into a
        pointer to the key,
     2. an indicator which visit of the node this is,
     3. the level of the node in the tree (0 for the root).  */
# if @REPLACE_TSEARCH@
_GL_FUNCDECL_RPL (twalk, void,
                  (const void *vroot, _gl_search_action_fn action)
                  _GL_ARG_NONNULL ((2)));
_GL_CXXALIAS_RPL (twalk, void,
                  (const void *vroot, _gl_search_action_fn action));
# else
#  if !@HAVE_TSEARCH@
_GL_FUNCDECL_SYS (twalk, void,
                  (const void *vroot, _gl_search_action_fn action)
                  _GL_ARG_NONNULL ((2)));
#  endif
_GL_CXXALIAS_SYS (twalk, void,
                  (const void *vroot, _gl_search_action_fn action));
# endif
_GL_CXXALIASWARN (twalk);



/** Tdestroy **/

# if @REPLACE_TSEARCH@
_GL_FUNCDECL_RPL (tdestroy, void,
                  (const void *vroot, _gl_search_free_fn action)
                  _GL_ARG_NONNULL ((2)));
_GL_CXXALIAS_RPL (tdestroy, void,
                  (const void *vroot, _gl_search_free_fn action));
# else
#  if !@HAVE_TSEARCH@
_GL_FUNCDECL_SYS (tdestroy, void,
                  (const void *vroot, _gl_search_free_fn action)
                  _GL_ARG_NONNULL ((2)));
#  endif
_GL_CXXALIAS_SYS (tdestroy, void,
                  (const void *vroot, _gl_search_free_fn action));
# endif
_GL_CXXALIASWARN (tdestroy);




#elif defined GNULIB_POSIXCHECK
# undef tsearch
# if HAVE_RAW_DECL_TSEARCH
_GL_WARN_ON_USE (tsearch, "tsearch is unportable - "
                 "use gnulib module tsearch for portability");
# endif
# undef tfind
# if HAVE_RAW_DECL_TFIND
_GL_WARN_ON_USE (tfind, "tfind is unportable - "
                 "use gnulib module tsearch for portability");
# endif
# undef tdelete
# if HAVE_RAW_DECL_TDELETE
_GL_WARN_ON_USE (tdelete, "tdelete is unportable - "
                 "use gnulib module tsearch for portability");
# endif
# undef twalk
# if HAVE_RAW_DECL_TWALK
_GL_WARN_ON_USE (twalk, "twalk is unportable - "
                 "use gnulib module tsearch for portability");
# endif
# undef tdestroy
# if HAVE_RAW_DECL_TDESTROY
_GL_WARN_ON_USE (tdestroy, "tdestroy is unportable - "
                 "use gnulib module tdestroy for portability");
# endif
#endif


#endif /* _GL_SEARCH_H */
#endif /* _GL_SEARCH_H */
