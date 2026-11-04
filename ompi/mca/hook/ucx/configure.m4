#
# Copyright (c) 2026      NVIDIA CORPORATION & AFFILIATES. All rights reserved.
#
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
# SPDX-License-Identifier: BSD-3-Clause-Open-MPI
#

# The early post-OPAL callback runs before dynamic hooks can be loaded.
AC_DEFUN([MCA_ompi_hook_ucx_COMPILE_MODE], [
    AC_MSG_CHECKING([for MCA component $2:$3 compile mode])
    $4="static"
    AC_MSG_RESULT([$$4])
])

AC_DEFUN([MCA_ompi_hook_ucx_CONFIG], [
    AC_CONFIG_FILES([ompi/mca/hook/ucx/Makefile])

    OMPI_CHECK_UCX([hook_ucx],
                   [hook_ucx_happy="yes"],
                   [hook_ucx_happy="no"])

    AS_IF([test "$hook_ucx_happy" = "yes"],
          [$1],
          [$2])

    AC_SUBST([hook_ucx_CPPFLAGS])
    AC_SUBST([hook_ucx_LDFLAGS])
    AC_SUBST([hook_ucx_LIBS])
])
