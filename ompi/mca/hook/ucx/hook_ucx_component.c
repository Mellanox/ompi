/*
 * Copyright (c) 2026      NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "hook_ucx.h"

static int ompi_hook_ucx_component_open(void);
static int ompi_hook_ucx_component_close(void);
static int ompi_hook_ucx_component_register(void);

const char *mca_hook_ucx_component_version_string =
    "Open MPI 'ucx' hook MCA component version " OMPI_VERSION;

const ompi_hook_base_component_1_0_0_t mca_hook_ucx_component = {
    .hookm_version = {
        OMPI_HOOK_BASE_VERSION_1_0_0,

        .mca_component_name = "ucx",
        MCA_BASE_MAKE_VERSION(component, OMPI_MAJOR_VERSION, OMPI_MINOR_VERSION,
                              OMPI_RELEASE_VERSION),

        .mca_open_component = ompi_hook_ucx_component_open,
        .mca_close_component = ompi_hook_ucx_component_close,
        .mca_register_component_params = ompi_hook_ucx_component_register,
    },
    .hookm_data = {
        MCA_BASE_METADATA_PARAM_NONE
    },

    .hookm_mpi_init_top_post_opal = ompi_hook_ucx_mpi_init_top_post_opal,
};

static int ompi_hook_ucx_component_open(void)
{
    opal_output_verbose(10, ompi_hook_base_framework.framework_output,
                        "hook/ucx: component_open()");
    return OMPI_SUCCESS;
}

static int ompi_hook_ucx_component_close(void)
{
    opal_output_verbose(10, ompi_hook_base_framework.framework_output,
                        "hook/ucx: component_close()");
    return OMPI_SUCCESS;
}

static int ompi_hook_ucx_component_register(void)
{
    return OMPI_SUCCESS;
}
