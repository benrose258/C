__SYSCALL_64(0, sys_read, )
__SYSCALL_64(1, sys_write, )
__SYSCALL_64(2, sys_open, )
__SYSCALL_64(3, sys_close, )
__SYSCALL_64(4, sys_newstat, )
__SYSCALL_64(5, sys_newfstat, )
__SYSCALL_64(6, sys_newlstat, )
__SYSCALL_64(7, sys_poll, )
__SYSCALL_64(8, sys_lseek, )
__SYSCALL_64(9, sys_mmap, )
__SYSCALL_64(10, sys_mprotect, )
__SYSCALL_64(11, sys_munmap, )
__SYSCALL_64(12, sys_brk, )
__SYSCALL_64(13, sys_rt_sigaction, )
__SYSCALL_64(14, sys_rt_sigprocmask, )
__SYSCALL_64(15, sys_rt_sigreturn, ptregs)
__SYSCALL_64(16, sys_ioctl, )
__SYSCALL_64(17, sys_pread64, )
__SYSCALL_64(18, sys_pwrite64, )
__SYSCALL_64(19, sys_readv, )
__SYSCALL_64(20, sys_writev, )
__SYSCALL_64(21, sys_access, )
__SYSCALL_64(22, sys_pipe, )
__SYSCALL_64(23, sys_select, )
__SYSCALL_64(24, sys_sched_yield, )
__SYSCALL_64(25, sys_mremap, )
__SYSCALL_64(26, sys_msync, )
__SYSCALL_64(27, sys_mincore, )
__SYSCALL_64(28, sys_madvise, )
__SYSCALL_64(29, sys_shmget, )
__SYSCALL_64(30, sys_shmat, )
__SYSCALL_64(31, sys_shmctl, )
__SYSCALL_64(32, sys_dup, )
__SYSCALL_64(33, sys_dup2, )
__SYSCALL_64(34, sys_pause, )
__SYSCALL_64(35, sys_nanosleep, )
__SYSCALL_64(36, sys_getitimer, )
__SYSCALL_64(37, sys_alarm, )
__SYSCALL_64(38, sys_setitimer, )
__SYSCALL_64(39, sys_getpid, )
__SYSCALL_64(40, sys_sendfile64, )
__SYSCALL_64(41, sys_socket, )
__SYSCALL_64(42, sys_connect, )
__SYSCALL_64(43, sys_accept, )
__SYSCALL_64(44, sys_sendto, )
__SYSCALL_64(45, sys_recvfrom, )
__SYSCALL_64(46, sys_sendmsg, )
__SYSCALL_64(47, sys_recvmsg, )
__SYSCALL_64(48, sys_shutdown, )
__SYSCALL_64(49, sys_bind, )
__SYSCALL_64(50, sys_listen, )
__SYSCALL_64(51, sys_getsockname, )
__SYSCALL_64(52, sys_getpeername, )
__SYSCALL_64(53, sys_socketpair, )
__SYSCALL_64(54, sys_setsockopt, )
__SYSCALL_64(55, sys_getsockopt, )
__SYSCALL_64(56, sys_clone, ptregs)
__SYSCALL_64(57, sys_fork, ptregs)
__SYSCALL_64(58, sys_vfork, ptregs)
__SYSCALL_64(59, sys_execve, ptregs)
__SYSCALL_64(60, sys_exit, )
__SYSCALL_64(61, sys_wait4, )
__SYSCALL_64(62, sys_kill, )
__SYSCALL_64(63, sys_newuname, )
__SYSCALL_64(64, sys_semget, )
__SYSCALL_64(65, sys_semop, )
__SYSCALL_64(66, sys_semctl, )
__SYSCALL_64(67, sys_shmdt, )
__SYSCALL_64(68, sys_msgget, )
__SYSCALL_64(69, sys_msgsnd, )
__SYSCALL_64(70, sys_msgrcv, )
__SYSCALL_64(71, sys_msgctl, )
__SYSCALL_64(72, sys_fcntl, )
__SYSCALL_64(73, sys_flock, )
__SYSCALL_64(74, sys_fsync, )
__SYSCALL_64(75, sys_fdatasync, )
__SYSCALL_64(76, sys_truncate, )
__SYSCALL_64(77, sys_ftruncate, )
__SYSCALL_64(78, sys_getdents, )
__SYSCALL_64(79, sys_getcwd, )
__SYSCALL_64(80, sys_chdir, )
__SYSCALL_64(81, sys_fchdir, )
__SYSCALL_64(82, sys_rename, )
__SYSCALL_64(83, sys_mkdir, )
__SYSCALL_64(84, sys_rmdir, )
__SYSCALL_64(85, sys_creat, )
__SYSCALL_64(86, sys_link, )
__SYSCALL_64(87, sys_unlink, )
__SYSCALL_64(88, sys_symlink, )
__SYSCALL_64(89, sys_readlink, )
__SYSCALL_64(90, sys_chmod, )
__SYSCALL_64(91, sys_fchmod, )
__SYSCALL_64(92, sys_chown, )
__SYSCALL_64(93, sys_fchown, )
__SYSCALL_64(94, sys_lchown, )
__SYSCALL_64(95, sys_umask, )
__SYSCALL_64(96, sys_gettimeofday, )
__SYSCALL_64(97, sys_getrlimit, )
__SYSCALL_64(98, sys_getrusage, )
__SYSCALL_64(99, sys_sysinfo, )
__SYSCALL_64(100, sys_times, )
__SYSCALL_64(101, sys_ptrace, )
__SYSCALL_64(102, sys_getuid, )
__SYSCALL_64(103, sys_syslog, )
__SYSCALL_64(104, sys_getgid, )
__SYSCALL_64(105, sys_setuid, )
__SYSCALL_64(106, sys_setgid, )
__SYSCALL_64(107, sys_geteuid, )
__SYSCALL_64(108, sys_getegid, )
__SYSCALL_64(109, sys_setpgid, )
__SYSCALL_64(110, sys_getppid, )
__SYSCALL_64(111, sys_getpgrp, )
__SYSCALL_64(112, sys_setsid, )
__SYSCALL_64(113, sys_setreuid, )
__SYSCALL_64(114, sys_setregid, )
__SYSCALL_64(115, sys_getgroups, )
__SYSCALL_64(116, sys_setgroups, )
__SYSCALL_64(117, sys_setresuid, )
__SYSCALL_64(118, sys_getresuid, )
__SYSCALL_64(119, sys_setresgid, )
__SYSCALL_64(120, sys_getresgid, )
__SYSCALL_64(121, sys_getpgid, )
__SYSCALL_64(122, sys_setfsuid, )
__SYSCALL_64(123, sys_setfsgid, )
__SYSCALL_64(124, sys_getsid, )
__SYSCALL_64(125, sys_capget, )
__SYSCALL_64(126, sys_capset, )
__SYSCALL_64(127, sys_rt_sigpending, )
__SYSCALL_64(128, sys_rt_sigtimedwait, )
__SYSCALL_64(129, sys_rt_sigqueueinfo, )
__SYSCALL_64(130, sys_rt_sigsuspend, )
__SYSCALL_64(131, sys_sigaltstack, )
__SYSCALL_64(132, sys_utime, )
__SYSCALL_64(133, sys_mknod, )
__SYSCALL_64(135, sys_personality, )
__SYSCALL_64(136, sys_ustat, )
__SYSCALL_64(137, sys_statfs, )
__SYSCALL_64(138, sys_fstatfs, )
__SYSCALL_64(139, sys_sysfs, )
__SYSCALL_64(140, sys_getpriority, )
__SYSCALL_64(141, sys_setpriority, )
__SYSCALL_64(142, sys_sched_setparam, )
__SYSCALL_64(143, sys_sched_getparam, )
__SYSCALL_64(144, sys_sched_setscheduler, )
__SYSCALL_64(145, sys_sched_getscheduler, )
__SYSCALL_64(146, sys_sched_get_priority_max, )
__SYSCALL_64(147, sys_sched_get_priority_min, )
__SYSCALL_64(148, sys_sched_rr_get_interval, )
__SYSCALL_64(149, sys_mlock, )
__SYSCALL_64(150, sys_munlock, )
__SYSCALL_64(151, sys_mlockall, )
__SYSCALL_64(152, sys_munlockall, )
__SYSCALL_64(153, sys_vhangup, )
__SYSCALL_64(154, sys_modify_ldt, )
__SYSCALL_64(155, sys_pivot_root, )
__SYSCALL_64(156, sys_sysctl, )
__SYSCALL_64(157, sys_prctl, )
__SYSCALL_64(158, sys_arch_prctl, )
__SYSCALL_64(159, sys_adjtimex, )
__SYSCALL_64(160, sys_setrlimit, )
__SYSCALL_64(161, sys_chroot, )
__SYSCALL_64(162, sys_sync, )
__SYSCALL_64(163, sys_acct, )
__SYSCALL_64(164, sys_settimeofday, )
__SYSCALL_64(165, sys_mount, )
__SYSCALL_64(166, sys_umount, )
__SYSCALL_64(167, sys_swapon, )
__SYSCALL_64(168, sys_swapoff, )
__SYSCALL_64(169, sys_reboot, )
__SYSCALL_64(170, sys_sethostname, )
__SYSCALL_64(171, sys_setdomainname, )
__SYSCALL_64(172, sys_iopl, ptregs)
__SYSCALL_64(173, sys_ioperm, )
__SYSCALL_64(175, sys_init_module, )
__SYSCALL_64(176, sys_delete_module, )
__SYSCALL_64(179, sys_quotactl, )
__SYSCALL_64(186, sys_gettid, )
__SYSCALL_64(187, sys_readahead, )
__SYSCALL_64(188, sys_setxattr, )
__SYSCALL_64(189, sys_lsetxattr, )
__SYSCALL_64(190, sys_fsetxattr, )
__SYSCALL_64(191, sys_getxattr, )
__SYSCALL_64(192, sys_lgetxattr, )
__SYSCALL_64(193, sys_fgetxattr, )
__SYSCALL_64(194, sys_listxattr, )
__SYSCALL_64(195, sys_llistxattr, )
__SYSCALL_64(196, sys_flistxattr, )
__SYSCALL_64(197, sys_removexattr, )
__SYSCALL_64(198, sys_lremovexattr, )
__SYSCALL_64(199, sys_fremovexattr, )
__SYSCALL_64(200, sys_tkill, )
__SYSCALL_64(201, sys_time, )
__SYSCALL_64(202, sys_futex, )
__SYSCALL_64(203, sys_sched_setaffinity, )
__SYSCALL_64(204, sys_sched_getaffinity, )
__SYSCALL_64(206, sys_io_setup, )
__SYSCALL_64(207, sys_io_destroy, )
__SYSCALL_64(208, sys_io_getevents, )
__SYSCALL_64(209, sys_io_submit, )
__SYSCALL_64(210, sys_io_cancel, )
__SYSCALL_64(212, sys_lookup_dcookie, )
__SYSCALL_64(213, sys_epoll_create, )
__SYSCALL_64(216, sys_remap_file_pages, )
__SYSCALL_64(217, sys_getdents64, )
__SYSCALL_64(218, sys_set_tid_address, )
__SYSCALL_64(219, sys_restart_syscall, )
__SYSCALL_64(220, sys_semtimedop, )
__SYSCALL_64(221, sys_fadvise64, )
__SYSCALL_64(222, sys_timer_create, )
__SYSCALL_64(223, sys_timer_settime, )
__SYSCALL_64(224, sys_timer_gettime, )
__SYSCALL_64(225, sys_timer_getoverrun, )
__SYSCALL_64(226, sys_timer_delete, )
__SYSCALL_64(227, sys_clock_settime, )
__SYSCALL_64(228, sys_clock_gettime, )
__SYSCALL_64(229, sys_clock_getres, )
__SYSCALL_64(230, sys_clock_nanosleep, )
__SYSCALL_64(231, sys_exit_group, )
__SYSCALL_64(232, sys_epoll_wait, )
__SYSCALL_64(233, sys_epoll_ctl, )
__SYSCALL_64(234, sys_tgkill, )
__SYSCALL_64(235, sys_utimes, )
__SYSCALL_64(237, sys_mbind, )
__SYSCALL_64(238, sys_set_mempolicy, )
__SYSCALL_64(239, sys_get_mempolicy, )
__SYSCALL_64(240, sys_mq_open, )
__SYSCALL_64(241, sys_mq_unlink, )
__SYSCALL_64(242, sys_mq_timedsend, )
__SYSCALL_64(243, sys_mq_timedreceive, )
__SYSCALL_64(244, sys_mq_notify, )
__SYSCALL_64(245, sys_mq_getsetattr, )
__SYSCALL_64(246, sys_kexec_load, )
__SYSCALL_64(247, sys_waitid, )
__SYSCALL_64(248, sys_add_key, )
__SYSCALL_64(249, sys_request_key, )
__SYSCALL_64(250, sys_keyctl, )
__SYSCALL_64(251, sys_ioprio_set, )
__SYSCALL_64(252, sys_ioprio_get, )
__SYSCALL_64(253, sys_inotify_init, )
__SYSCALL_64(254, sys_inotify_add_watch, )
__SYSCALL_64(255, sys_inotify_rm_watch, )
__SYSCALL_64(256, sys_migrate_pages, )
__SYSCALL_64(257, sys_openat, )
__SYSCALL_64(258, sys_mkdirat, )
__SYSCALL_64(259, sys_mknodat, )
__SYSCALL_64(260, sys_fchownat, )
__SYSCALL_64(261, sys_futimesat, )
__SYSCALL_64(262, sys_newfstatat, )
__SYSCALL_64(263, sys_unlinkat, )
__SYSCALL_64(264, sys_renameat, )
__SYSCALL_64(265, sys_linkat, )
__SYSCALL_64(266, sys_symlinkat, )
__SYSCALL_64(267, sys_readlinkat, )
__SYSCALL_64(268, sys_fchmodat, )
__SYSCALL_64(269, sys_faccessat, )
__SYSCALL_64(270, sys_pselect6, )
__SYSCALL_64(271, sys_ppoll, )
__SYSCALL_64(272, sys_unshare, )
__SYSCALL_64(273, sys_set_robust_list, )
__SYSCALL_64(274, sys_get_robust_list, )
__SYSCALL_64(275, sys_splice, )
__SYSCALL_64(276, sys_tee, )
__SYSCALL_64(277, sys_sync_file_range, )
__SYSCALL_64(278, sys_vmsplice, )
__SYSCALL_64(279, sys_move_pages, )
__SYSCALL_64(280, sys_utimensat, )
__SYSCALL_64(281, sys_epoll_pwait, )
__SYSCALL_64(282, sys_signalfd, )
__SYSCALL_64(283, sys_timerfd_create, )
__SYSCALL_64(284, sys_eventfd, )
__SYSCALL_64(285, sys_fallocate, )
__SYSCALL_64(286, sys_timerfd_settime, )
__SYSCALL_64(287, sys_timerfd_gettime, )
__SYSCALL_64(288, sys_accept4, )
__SYSCALL_64(289, sys_signalfd4, )
__SYSCALL_64(290, sys_eventfd2, )
__SYSCALL_64(291, sys_epoll_create1, )
__SYSCALL_64(292, sys_dup3, )
__SYSCALL_64(293, sys_pipe2, )
__SYSCALL_64(294, sys_inotify_init1, )
__SYSCALL_64(295, sys_preadv, )
__SYSCALL_64(296, sys_pwritev, )
__SYSCALL_64(297, sys_rt_tgsigqueueinfo, )
__SYSCALL_64(298, sys_perf_event_open, )
__SYSCALL_64(299, sys_recvmmsg, )
__SYSCALL_64(300, sys_fanotify_init, )
__SYSCALL_64(301, sys_fanotify_mark, )
__SYSCALL_64(302, sys_prlimit64, )
__SYSCALL_64(303, sys_name_to_handle_at, )
__SYSCALL_64(304, sys_open_by_handle_at, )
__SYSCALL_64(305, sys_clock_adjtime, )
__SYSCALL_64(306, sys_syncfs, )
__SYSCALL_64(307, sys_sendmmsg, )
__SYSCALL_64(308, sys_setns, )
__SYSCALL_64(309, sys_getcpu, )
__SYSCALL_64(310, sys_process_vm_readv, )
__SYSCALL_64(311, sys_process_vm_writev, )
__SYSCALL_64(312, sys_kcmp, )
__SYSCALL_64(313, sys_finit_module, )
__SYSCALL_64(314, sys_sched_setattr, )
__SYSCALL_64(315, sys_sched_getattr, )
__SYSCALL_64(316, sys_renameat2, )
__SYSCALL_64(317, sys_seccomp, )
__SYSCALL_64(318, sys_getrandom, )
__SYSCALL_64(319, sys_memfd_create, )
__SYSCALL_64(320, sys_kexec_file_load, )
__SYSCALL_64(321, sys_bpf, )
__SYSCALL_64(322, sys_execveat, ptregs)
__SYSCALL_64(323, sys_userfaultfd, )
__SYSCALL_64(324, sys_membarrier, )
__SYSCALL_64(325, sys_mlock2, )
__SYSCALL_64(326, sys_copy_file_range, )
__SYSCALL_64(327, sys_preadv2, )
__SYSCALL_64(328, sys_pwritev2, )
__SYSCALL_64(329, sys_pkey_mprotect, )
__SYSCALL_64(330, sys_pkey_alloc, )
__SYSCALL_64(331, sys_pkey_free, )
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(512, compat_sys_rt_sigaction, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(513, sys32_x32_rt_sigreturn, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(514, compat_sys_ioctl, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(515, compat_sys_readv, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(516, compat_sys_writev, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(517, compat_sys_recvfrom, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(518, compat_sys_sendmsg, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(519, compat_sys_recvmsg, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(520, compat_sys_execve, ptregs)
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(521, compat_sys_ptrace, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(522, compat_sys_rt_sigpending, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(523, compat_sys_rt_sigtimedwait, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(524, compat_sys_rt_sigqueueinfo, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(525, compat_sys_sigaltstack, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(526, compat_sys_timer_create, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(527, compat_sys_mq_notify, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(528, compat_sys_kexec_load, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(529, compat_sys_waitid, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(530, compat_sys_set_robust_list, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(531, compat_sys_get_robust_list, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(532, compat_sys_vmsplice, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(533, compat_sys_move_pages, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(534, compat_sys_preadv64, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(535, compat_sys_pwritev64, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(536, compat_sys_rt_tgsigqueueinfo, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(537, compat_sys_recvmmsg, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(538, compat_sys_sendmmsg, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(539, compat_sys_process_vm_readv, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(540, compat_sys_process_vm_writev, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(541, compat_sys_setsockopt, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(542, compat_sys_getsockopt, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(543, compat_sys_io_setup, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(544, compat_sys_io_submit, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(545, compat_sys_execveat, ptregs)
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(546, compat_sys_preadv64v2, )
#endif
#ifdef CONFIG_X86_X32_ABI
__SYSCALL_64(547, compat_sys_pwritev64v2, )
#endif
__SYSCALL_64(548, sys_my_syscall, )
__SYSCALL_64(549, sys_my_syscall2, )