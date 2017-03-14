-module(test_msb_ndx).
-include_lib("eqc/include/eqc.hrl").
-compile(export_all).

prop_zero() ->
    ?SETUP(fun () -> eqc_c:start(binary16),
                     fun() -> ok end
           end,
    ?FORALL({}, {},
            begin
                equals(binary16:msb_ndx(0))
            end)).
