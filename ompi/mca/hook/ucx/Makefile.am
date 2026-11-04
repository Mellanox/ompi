#
# Copyright (c) 2026      NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
# SPDX-License-Identifier: BSD-3-Clause-Open-MPI
#

AM_CPPFLAGS = $(hook_ucx_CPPFLAGS)

local_sources = \
	hook_ucx.h \
	hook_ucx_component.c \
	hook_ucx.c

# The early post-OPAL callback requires a static component.
noinst_LTLIBRARIES = libmca_hook_ucx.la
libmca_hook_ucx_la_SOURCES = $(local_sources)
libmca_hook_ucx_la_LIBADD = $(hook_ucx_LIBS)
libmca_hook_ucx_la_LDFLAGS = -module -avoid-version $(hook_ucx_LDFLAGS)
