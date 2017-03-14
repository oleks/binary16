-module(test_msb_ndx).
-include_lib("eqc/include/eqc.hrl").
-compile(export_all).

prop_zero() ->
    ?SETUP(fun () -> eqc_c:start(binary16, [
                        {c_src, "../binary16.c"},
                        {additional_files, "../binary16.h"}]),
                     fun() -> ok end
           end,
           equals(0, binary16:msb_ndx(0))).
