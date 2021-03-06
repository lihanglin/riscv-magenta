// Copyright 2016 The Fuchsia Authors
// Copyright (c) 2015-2016 Travis Geiselbrecht
// Copyright 2017 Slava Imameev
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#pragma once

#include <magenta/compiler.h>
#include <sys/types.h>
#include <arch/riscv/thread_state.h>
#include <arch/riscv/thread_info.h>

__BEGIN_CDECLS

struct thread_info;

struct arch_thread {

    //
    // threads cpu state
    //
    riscv_thread_state_t state;

    //
    // a thread info, in Linux the thread infor
    // is allocated on the stack, we can't do so
    // with Magenta as the stack is not aligned
    // on the page boundaries and you can't be sure
    // about the stack bottom just by having $sp
    //
    struct thread_info   ti;

    //
    // if non-NULL, address to return to on data fault
    //
    void *data_fault_resume;
};

__END_CDECLS
