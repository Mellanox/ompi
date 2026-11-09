.. Copyright (c) 2026 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
.. $COPYRIGHT$
.. Additional copyrights may follow
.. $HEADER$
.. SPDX-License-Identifier: BSD-3-Clause-Open-MPI

HPC-X downstream branch
=======================

These settings apply to the ``v6.0.x_hpcx`` downstream branch.  They
are not defaults of the upstream Open MPI v6.0.x branch.

Collectives and platform selection
----------------------------------

When built, the UCC collective component is enabled by default with
priority 100.  The usual ``coll_ucc_enable`` and ``coll_ucc_priority``
MCA parameters remain available to override this policy.

The ``contrib/platform/mellanox/optimized`` platform disables the UCT
BTL, HAN and adapt collective components, and the persist partition
component.  It selects DSOs for the accelerator collective, CUDA
accelerator, smcuda BTL, GPU registration caches, UCC collective, and
UCX PML/OSC components when their dependencies are available.  The
accelerator collective uses its Open MPI 6 name, ``coll/accelerator``.

With no partition component selected, MPI initialization succeeds.
Partitioned send and receive initialization returns an error: the
internal ``OMPI_ERR_NOT_SUPPORTED`` currently maps to ``MPI_ERR_INTERN``.
Applications using ``MPI_ERRORS_RETURN`` can inspect this error; the
normal fatal error handler can still abort the application.  Building
without the platform's ``part-persist`` exclusion retains the option of
using the partition component.

When UCX is available, a static hook tests UCX memory events early in
MPI initialization, and the common UCX configuration defaults to using
UCX memory hooks instead of OPAL memory hooks.  The
``opal_common_ucx_opal_mem_hooks`` MCA parameter remains overridable.

Packaging
---------

The downstream RPM and Debian packaging defaults install Open MPI into
``/usr/mpi/gcc/openmpi-<version>`` to separate bundled libraries and data
from system packages.  The RPM ``install_in_opt`` choice takes precedence
over ``mofed_prefix``.  The package metadata retains the downstream UCX
runtime dependency and RPM epoch policy.

Package install/remove scripts manage compiler wrappers and launchers
through the distribution's ``mpi`` and ``mpirun`` alternatives groups.
Libraries remain under the versioned prefix.  ``ompi_info`` is not
registered as an alternative.

Optional third-party patch mechanism
------------------------------------

No third-party patch payloads are included by this carry-over, and the
upstream submodule pins are unchanged.  For future downstream fixes,
``autogen.pl`` recognizes ``contrib/patches/<name>/*.patch`` and applies
them to ``3rd-party/<name>`` before configuring third-party sources.
An absent or empty patch directory is a no-op.

Patches run in filename order with one leading path component stripped
and fuzzy application disabled.  A forward dry-run checks applicability;
a reverse dry-run recognizes an already-applied patch.  A mismatch or a
missing target stops autogen rather than silently continuing.

Application is per patch, not atomic across the series.  A later failure
can leave earlier patches applied.  When replacing a dependent series
that changes overlapping lines, start with a clean checkout at the
pinned dependency revision: individual reverse checks cannot identify
every overlapping series that has already been applied.
